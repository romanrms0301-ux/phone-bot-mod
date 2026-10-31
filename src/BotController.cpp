#include "BotController.hpp"

using namespace geode::prelude;

bool BotController::isEnabled() {
    auto mod = Mod::get();
    if (!mod) {
        return false;
    }

    return mod->getSettingValue<bool>("bot-enabled");
}

void BotController::setEnabled(bool enabled) {
    auto mod = Mod::get();
    if (!mod) {
        return;
    }

    mod->setSettingValue("bot-enabled", enabled);
}

void BotController::logState() {
    const bool enabled = isEnabled();
    log::info("Phone Bot: estado actual = {}", enabled ? "activado" : "desactivado");
}
