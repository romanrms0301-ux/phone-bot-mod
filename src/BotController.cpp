#include "BotController.hpp"

using namespace geode::prelude;

bool BotController::isEnabled() {
    if (const auto mod = Mod::get(); mod) {
        return mod->getSettingValue<bool>("bot-enabled", false);
    }

    return false;
}

void BotController::setEnabled(bool enabled) {
    if (const auto mod = Mod::get(); mod) {
        mod->setSettingValue("bot-enabled", enabled);
    }
}

void BotController::logState() {
    const bool enabled = isEnabled();
    log::info("Phone Bot: estado actual = {}", enabled ? "activado" : "desactivado");
}
