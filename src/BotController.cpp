#include "BotController.hpp"

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
