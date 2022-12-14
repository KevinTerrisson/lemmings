#include "IntroScene.h"
#include "AudioEngine.h"

USING_NS_CC;

Scene* IntroScene::createScene()
{
    return IntroScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
}

// on "init" you need to initialize your instance
bool IntroScene::init()
{
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
    auto fadeOut = FadeOut::create(1.0f);
    auto delay = DelayTime::create(1);
    auto seq = Sequence::create(delay, fadeIn, delay, fadeOut, nullptr);

    if (label == nullptr)
    {
        problemLoading("'font/pixelArt.ttf'");
        problemLoading("'sfx/Introduction.mp3'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
        label->setOpacity(0);

        // add the label as a child to this layer
        this->addChild(label, 1);

        auto music = AudioEngine::play2d("sfx/Introduction.mp3", false);

        label->runAction(seq);
    }

    return true;
}
