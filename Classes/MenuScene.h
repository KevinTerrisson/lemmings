#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "cocos2d.h"

class MenuScene : public cocos2d::Scene
{
public:
    virtual bool init();
    virtual void update(float dt);

    // implement the "static create()" method manually
    CREATE_FUNC(MenuScene);

    float m_time;
};

#endif // __MENU_SCENE_H__