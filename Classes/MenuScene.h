#pragma once

#ifndef MenuScene_h
#define MenuScene_h

#include "cocos2d.h"

class MenuScene : cocos2d::Scene {
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	cocos2d::MenuItemImage* startMenu;
	cocos2d::MenuItemImage* exitMenu;
	void changeScene(Ref* pSender);
	void exitGame(Ref* pSender);

	CREATE_FUNC(MenuScene);
};

#endif // MenuScene.h