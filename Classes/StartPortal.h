#include "cocos2d.h"

USING_NS_CC;

class StartPortal : public Sprite
{
public:
	virtual bool init();

	void appearingPortalAnimation();
	void disappearingPortalAnimation();
	void idlePortalAnimation();

	// implement the "static create()" method manually
	CREATE_FUNC(StartPortal);
};