#include "LevelScene.h"
#include "AppDelegate.h"
#include "SceneManager.h"
#include "AudioEngine.h"

USING_NS_CC;

Scene* LevelScene::createScene()
{
    return LevelScene::create();
}

// on "init" you need to initialize your instance
bool LevelScene::init()
{
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // create and initialize a label

    auto label = Label::createWithTTF("Game Window", "font/pixelArt.ttf", 120);

    if (label == nullptr)
    {
        //problemLoading("'font/pixelArt.ttf'");
        //problemLoading("'sfx/Introduction.mp3'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    return true;
}