#include "AppDelegate.h"
#include "SceneManager.h"
#include "IntroScene.h"

USING_NS_CC;

extern AppDelegate* g_pApp;

// on "init" you need to initialize your instance
bool IntroScene::init()
{
    m_time = 0.0f;

    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // add a label shows "Lemmings"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Lemmings", "font/pixelArt.ttf", 120);
    auto fadeIn = FadeIn::create(2.0f);
    auto delay = DelayTime::create(1);
    auto fadeOut = FadeOut::create(0.5f);
    auto seq = Sequence::create(fadeIn, delay, fadeOut, nullptr);

    if (label == nullptr)
    {
        //problemLoading("'font/pixelArt.ttf'");
        //problemLoading("'sfx/Introduction.mp3'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
        label->setOpacity(0);

        // add the label as a child to this layer
        this->addChild(label, 1);

        label->runAction(seq);
    }

    scheduleUpdate();
    //retain();
    return true;
}

void IntroScene::update(float dt)
{
    m_time += dt;

    if (m_time > 5.0f)
    {
        g_pApp->m_pManager->RunMenuScene();
    }
}
