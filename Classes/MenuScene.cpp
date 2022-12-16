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

    // add a label shows "Lemmings"
    // create and initialize a label

    auto label = Label::createWithTTF("MENU", "font/pixelArt.ttf", 120);

    if (label == nullptr)
    {
        //problemLoading("'font/pixelArt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));

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