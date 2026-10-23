#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(MyPlayLayer, PlayLayer) {
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects)) {
            return false;
        }

        // Tu bot de teléfono - solo un ejemplo que no crashea
        // Aquí puedes poner tu código de clickbot después
        
        log::info("Phone Bot Mod Loaded!");
        
        return true;
    }
};
