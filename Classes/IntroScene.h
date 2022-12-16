#ifndef __INTRO_SCENE_H__
#define __INTRO_SCENE_H__

#include "cocos2d.h"

class IntroScene : public cocos2d::Scene
{
public:
    virtual bool init();
    virtual void update(float dt);

    // implement the "static create()" method manually
    CREATE_FUNC(IntroScene);

    float m_time;
};

#endif // __INTRO_SCENE_H__