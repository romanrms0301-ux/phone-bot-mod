#include "BotController.hpp"

bool BotController::isEnabled() {
    return Mod::get()->getSettingValue<bool>("bot-enabled");
}

void BotController::setEnabled(bool enabled) {
    Mod::get()->setSettingValue("bot-enabled", enabled);
}

void BotController::logState() {
    const bool enabled = isEnabled();
    log::info("Phone Bot: estado actual = {}", enabled ? "activado" : "desactivado");
}
