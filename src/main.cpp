#include <Geode/Geode.hpp>
#include "BotController.hpp"

using namespace geode::prelude;

// Punto de entrada del mod. El autoplay (hook a PlayLayer::update)
// vive en BotController.cpp; aquí solo se registra el estado inicial
// según el ajuste "bot-enabled" de mod.json.
$on_mod(Loaded) {
    BotController::logState();
    if (!BotController::isEnabled()) {
        log::info("Phone Bot cargado, pero permanece desactivado por la configuración.");
    } else {
        log::info("Phone Bot cargado correctamente y activo (autoplay v1, modo cubo).");
    }
}
