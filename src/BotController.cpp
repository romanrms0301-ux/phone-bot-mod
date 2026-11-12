#include "BotController.hpp"
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

bool BotController::isEnabled() {
    const auto mod = Mod::get();
    if (!mod) {
        return false;
    }

    return mod->getSettingValue<bool>("bot-enabled");
}

void BotController::setEnabled(bool enabled) {
    const auto mod = Mod::get();
    if (!mod) {
        log::warn("Phone Bot: Mod no disponible, no se puede guardar la configuración.");
        return;
    }

    mod->setSettingValue("bot-enabled", enabled);
}

void BotController::logState() {
    const bool enabled = isEnabled();
    log::info("Phone Bot: estado actual = {}", enabled ? "activado" : "desactivado");
}

// Autoplay v2 (modo cubo): en cada frame, si el bot está activado, busca
// el obstáculo más cercano por delante a la altura del suelo y salta.
// v2 corrige v1: m_objects no viene ordenado por X, así que ya no se
// corta el escaneo al encontrar un objeto lejano; se busca el más cercano.
class $modify(BotPlayLayer, PlayLayer) {
    struct Fields {
        bool m_botHolding = false;
        float m_botHoldTimer = 0.f;
    };

    void update(float dt) {
        runBot(dt);
        PlayLayer::update(dt);
    }

    void runBot(float dt) {
        auto* player = m_player1;
        if (!player) {
            return;
        }

        if (!BotController::isEnabled() || m_isPaused || player->m_isDead) {
            if (m_fields->m_botHolding) {
                player->releaseButton(PlayerButton::Jump);
                m_fields->m_botHolding = false;
            }
            return;
        }

        // v2 solo cubo: en otros modos (nave, bola, etc.) no tocamos nada.
        if (player->m_isShip || player->m_isBird || player->m_isBall ||
            player->m_isDart || player->m_isRobot || player->m_isSpider ||
            player->m_isSwing || player->m_isSideways) {
            if (m_fields->m_botHolding) {
                player->releaseButton(PlayerButton::Jump);
                m_fields->m_botHolding = false;
            }
            return;
        }

        if (m_fields->m_botHolding) {
            m_fields->m_botHoldTimer -= dt;
            if (m_fields->m_botHoldTimer <= 0.f) {
                player->releaseButton(PlayerButton::Jump);
                m_fields->m_botHolding = false;
            }
            return;
        }

        if (!player->m_isOnGround || !m_objects) {
            return;
        }

        const float px = player->getPositionX();
        const float py = player->getPositionY();
        float nearestDx = 1000000.f;

        const unsigned int count = m_objects->count();
        for (unsigned int i = 0; i < count; ++i) {
            auto* obj = typeinfo_cast<GameObject*>(m_objects->objectAtIndex(i));
            if (!obj) {
                continue;
            }

            const float dx = obj->getPositionX() - px;
            if (dx < -5.f || dx > 150.f) {
                continue;
            }

            const float dy = obj->getPositionY() - py;
            if (dy < -70.f || dy > 70.f) {
                continue;
            }

            if (dx < nearestDx) {
                nearestDx = dx;
            }
        }

        if (nearestDx <= 130.f) {
            player->pushButton(PlayerButton::Jump);
            m_fields->m_botHolding = true;
            m_fields->m_botHoldTimer = 0.15f;
        }
    }
};
