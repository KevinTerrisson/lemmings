#pragma once

#include "cocos2d.h"

class SceneManager : public cocos2d::Node
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(SceneManager);
private:
    void MenuScene(float dt);
    void MenuScene();

    Scene* m_pMenu;
};