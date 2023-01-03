#pragma once
#include "cocos2d.h"

USING_NS_CC;

class StartSpawn : public Sprite
{
	virtual bool init();

	void ApparitonLemmings();
	void disparitionLemmings();

	CREATE_FUNC(StartSpawn);

};

