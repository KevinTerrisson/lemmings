#pragma once

#include "cocos2d.h"

class IntroScene;
class MenuScene;

class SceneManager : public cocos2d::Node
{
public:
    CREATE_FUNC(SceneManager);

    bool RunIntroScene();
    bool RunMenuScene();

    void OnIntroScene();

    IntroScene* m_introScene;
    MenuScene* m_menuScene;

private:
};