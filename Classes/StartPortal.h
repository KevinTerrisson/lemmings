#include "cocos2d.h"

USING_NS_CC;

class StartPortal : public Sprite
{
public:
	virtual bool init();

	void createAppearingPortal();
	void createDisappearingPortal();
	void createIdlePortal();

	// implement the "static create()" method manually
	CREATE_FUNC(StartPortal);
};