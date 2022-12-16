#pragma once
#include "cocos2d.h"
#ifndef __LEVEL_ONE_SCENE_H__
#define __LEVEL_ONE_SCENE_H__


class Level_one_scene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

};

#endif // __LEVEL_ONE_SCENE_H__
