#pragma once
#include "cocos2d.h"
#ifndef __LEVEL_ONE_SCENE_H__
#define __LEVEL_ONE_SCENE_H__


class LevelOneScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

};

#endif // __LEVEL_ONE_SCENE_H__
