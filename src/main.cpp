#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/PauseLayer.hpp>
using namespace geode::prelude;

class $modify(BotPlayLayer, PlayLayer) {
    void update(float dt) {
        PlayLayer::update(dt);
        if (!Mod::get()->getSettingValue<bool>("bot-enabled")) return;
        if (!m_player1) return;
        if (m_player1->m_isOnGround) {
            m_player1->pushButton(PlayerButton::Jump);
        }
    }
};

class $modify(BotPause, PauseLayer) {
    void customSetup() {
        PauseLayer::customSetup();
        auto mod = Mod::get();
        bool enabled = mod->getSettingValue<bool>("bot-enabled");
        auto toggler = CCMenuItemToggler::createWithStandardSprites(
            this, menu_selector(BotPause::onToggle), 0.7f
        );
        toggler->toggle(enabled);
        toggler->setPosition({50, 50});
        auto menu = CCMenu::create();
        menu->addChild(toggler);
        menu->setPosition({0,0});
        this->addChild(menu);
    }
    void onToggle(CCObject* s) {
        auto mod = Mod::get();
        bool cur = mod->getSettingValue<bool>("bot-enabled");
        mod->setSettingValue("bot-enabled", !cur);
        Notification::create(!cur ? "Bot ON" : "Bot OFF", NotificationIcon::Success)->show();
    }
};
