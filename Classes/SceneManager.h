#pragma once

#include "cocos2d.h"

class IntroScene;
class MenuScene;
class LevelScene;

class SceneManager : public cocos2d::Node
{
public:
    CREATE_FUNC(SceneManager);

    bool RunIntroScene();
    bool RunMenuScene();
    bool RunLevelScene();

    void OnIntroScene(float dt);

    IntroScene* m_introScene;
    MenuScene* m_menuScene;
    LevelScene* m_levelScene;

private:
};