#include "WinScene.h"

USING_NS_CC;

Scene* WinScene::createScene()
{
    return WinScene::create();
}

// on "init" you need to initialize your instance
bool WinScene::init()
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
    background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(background);


    // Music Menu Theme
    auto music = AudioEngine::play2d("music/Menu.mp3", true, 0.3f);

    return true;
}