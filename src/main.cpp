#include <Geode/Geode.hpp>
#include "BotController.hpp"

using namespace geode::prelude;

$on_mod(Loaded) {
    BotController::logState();

    if (!BotController::isEnabled()) {
        log::info("Phone Bot cargado, pero permanece desactivado por la configuración.");
        return;
    }

    log::info("Phone Bot cargado correctamente y activo");
}
