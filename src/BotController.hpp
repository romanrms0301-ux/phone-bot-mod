pragma once
include "BotController.hpp"

#include <Geode/Geode.hpp>
bool BotController::isEnabled() {
    return Mod::get()->getSettingValue<bool>("bot-enabled");
}

class BotController {
public:
    static bool isEnabled();
    static void setEnabled(bool enabled);
    static void logState();
};
void BotController::setEnabled(bool enabled) {
    Mod::get()->setSettingValue("bot-enabled", enabled);
}

void BotController::logState() {
    const bool enabled = isEnabled();
    log::info("Phone Bot: estado actual = {}", enabled ? "activado" : "desactivado");
}
