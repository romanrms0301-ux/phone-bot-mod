include <Geode/Geode.hpp>
#include "BotController.hpp"

using namespace geode::prelude;
bool BotController::isEnabled() {
    const auto mod = Mod::get();
    if (!mod) {
        return false;
    }

$on_mod(Loaded) {
    BotController::logState();
    return mod->getSettingValue<bool>("bot-enabled", false);
}

    if (!BotController::isEnabled()) {
        log::info("Phone Bot cargado, pero permanece desactivado por la configuración.");
void BotController::setEnabled(bool enabled) {
    const auto mod = Mod::get();
    if (!mod) {
        log::warn("Phone Bot: Mod no disponible, no se puede guardar la configuración.");
        return;
    }

    log::info("Phone Bot cargado correctamente y activo");
    mod->setSettingValue("bot-enabled", enabled);
}
