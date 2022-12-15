#include "Scenes.h"
#include "MenuScene.h"
#include "IntroScene.h"

USING_NS_CC;

Scene* Scenes::createScene()
{
    auto scene = Scene::create();

    auto layer = Scenes::create();

    scene->addChild(layer);

    return scene;
}

bool Scenes::init()
{
    if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
    {
        return false;
    }

    
        //this->scheduleOnce(schedule_selector(Scenes::LoginRegisterScene), 3); // after 3 seconds, go to LoginRegisterScene

    return true;
}

void Scenes::LoginRegisterScene(float dt) {
   /* auto scene = LoginRegisterScene::createScene();*/
    //Director::getInstance()->replaceScene(TransitionSlideInR::create(0.25f, scene)); // transition time of the scene
}