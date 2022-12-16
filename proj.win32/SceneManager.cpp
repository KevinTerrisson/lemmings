#include "SceneManager.h"
#include "MenuScene.h"
#include "IntroScene.h"
#include "LevelScene.h"

USING_NS_CC;

bool SceneManager::RunIntroScene()
{
    m_introScene = IntroScene::create();
    Director::getInstance()->runWithScene(m_introScene);

    return true;
}

bool SceneManager::RunMenuScene()
{
    m_menuScene = MenuScene::create();
    Director::getInstance()->replaceScene((Scene*)m_menuScene);

    return true;
}

bool SceneManager::RunLevelScene()
{
    m_levelScene = LevelScene::create();
    Director::getInstance()->replaceScene((Scene*)m_levelScene);

    return true;
}

void SceneManager::OnIntroScene(float dt) // test de supr float dt sur version stable
{
    RunMenuScene();
}
