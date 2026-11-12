#pragma once

#include <Geode/Geode.hpp>

// Control del bot (autoplay v1, modo cubo).
// La lógica de juego vive en BotController.cpp, enganchada a
// PlayLayer::update; aquí solo va la interfaz pública del controlador.
class BotController {
public:
    // Lee el ajuste "bot-enabled" de mod.json.
    static bool isEnabled();

    // Guarda el ajuste "bot-enabled".
    static void setEnabled(bool enabled);

    // Escribe en el log el estado actual del bot.
    static void logState();
};
