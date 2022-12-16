#pragma once

#ifndef __LEVEL_SCENE_H__
#define __LEVEL_SCENE_H__

#include "cocos2d.h"

class LevelScene : public cocos2d::Scene
{
    virtual bool init();

    CREATE_FUNC(LevelScene);

};

#endif // __LEVEL_SCENE_H__