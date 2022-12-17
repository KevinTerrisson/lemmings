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

void SceneManager::OnIntroScene()
{
    RunMenuScene();
}
