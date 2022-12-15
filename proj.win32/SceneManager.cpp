#include "SceneManager.h"
#include "MenuScene.h"
#include "IntroScene.h"

USING_NS_CC;

Scene* SceneManager::createScene()
{
    auto sceneManager = SceneManager::create();

    return sceneManager;
}

bool SceneManager::init()
{
    m_pMenu = Scene::create();

    this->scheduleOnce(CC_SCHEDULE_SELECTOR(Scenes::MenuScene), 3.0); // after 3 seconds, go to MenuScene

    return true;
}

void SceneManager::MenuScene(float dt) {
    auto menuScene = MenuScene::createScene();
    Director::getInstance()->replaceScene(TransitionSlideInR::create(0.25f, menuScene)); // transition time of the scene
}