#include "MenuScene.h"
#include "IntroScene.h"

USING_NS_CC;

Scene* MenuScene::createScene() {
    return MenuScene::create();
}

bool MenuScene::init() {
    if (!Scene::init()) {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    ////// Image de fond //////
    auto background = Sprite::create("res/background.png");
    background->setPosition(Vec2(visibleSize.width/2 + origin.x , visibleSize.height/2 + origin.y));
    this->addChild(background);

    ////// Images des boutons //////
    startMenu = MenuItemImage::create("res/jouer.png", "res/jouer-select.png", CC_CALLBACK_1(MenuScene::changeScene, this));
    exitMenu = MenuItemImage::create("res/quitter.png", "res/quitter-select.png", CC_CALLBACK_1(MenuScene::exitGame, this));
    auto menu = Menu::create(startMenu, exitMenu, nullptr);
    menu->setPosition(Point::ZERO);
    startMenu->setPosition((visibleSize.width / 6 + origin.x) * 3.5, visibleSize.height / 5 + origin.y);
    exitMenu->setPosition((visibleSize.width / 6 + origin.x) * 5, visibleSize.height / 5 + origin.y); //-exitMenu->getContentSize().height - 20);
    this->addChild(menu);

    return true;
}

void MenuScene::changeScene(Ref* pSender) {
    auto scene = IntroScene::createScene();
    Director::getInstance()->pushScene(TransitionFade::create(1.0f, scene));
}

void MenuScene::exitGame(Ref* pSender) {
    Director::getInstance()->end();
}