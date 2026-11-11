#pragma once

#include <Geode/Geode.hpp>

class BotController {
public:
    static bool isEnabled();
    static void setEnabled(bool enabled);
    static void logState();
};
