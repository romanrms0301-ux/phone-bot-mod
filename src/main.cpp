#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
using namespace geode::prelude;
class $modify(MyPlayLayer, PlayLayer) {
    bool init(GJGameLevel* l, bool p1, bool p2) {
        if (!PlayLayer::init(l, p1, p2)) return false;
        log::info("Phone Bot Mod Loaded!");
        return true;
    }
};
