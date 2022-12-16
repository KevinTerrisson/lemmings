#include "MenuScene.h"
#include "AudioEngine.h"

USING_NS_CC;

// on "init" you need to initialize your instance
bool MenuScene::init()
{
    m_time = 0.0f;

    if (!Scene::init())
    {
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

    if (label == nullptr)
    {
        //problemLoading("'font/pixelArt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));


void MenuScene::changeScene(Ref* pSender) {
    //auto scene = IntroScene::createScene();
    //Director::getInstance()->pushScene(TransitionFade::create(1.0f, scene));
}

void MenuScene::exitGame(Ref* pSender) {
    Director::getInstance()->end();
    
        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    //retain();
    return true;
}

void MenuScene::update(float dt)
{
    m_time += dt;

}