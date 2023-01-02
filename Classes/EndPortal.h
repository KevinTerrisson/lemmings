#include "cocos2d.h"

USING_NS_CC;

class EndPortal : public Sprite
{
public:
	virtual bool init();

	void createAppearingPortal();
	void createDisappearingPortal();
	void createIdlePortal();

	// implement the "static create()" method manually
	CREATE_FUNC(EndPortal);
};