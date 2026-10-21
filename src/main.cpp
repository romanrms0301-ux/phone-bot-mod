#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        auto winSize = CCDirector::sharedDirector()->getWinSize();

        auto phoneBtn = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("GJ_hamburgerBtn_001.png"),
            this,
            menu_selector(MyMenuLayer::onPhone)
        );
        phoneBtn->setPosition({50, 50});
        phoneBtn->setScale(0.8f);

        auto menu = this->getChildByID("bottom-menu");
        if (!menu) {
            auto newMenu = CCMenu::create();
            newMenu->setPosition({0,0});
            newMenu->addChild(phoneBtn);
            this->addChild(newMenu);
        } else {
            menu->addChild(phoneBtn);
            menu->updateLayout();
        }

        return true;
    }

    void onPhone(CCObject*) {
        FLAlertLayer::create(
            "Phone Bot Mod",
            "Ok bro, aqui va tu bot de celular! 📱\n\nPor ahora es el prototipo.\nLuego le metemos movimientos auto.",
            "OK"
        )->show();
    }
};
