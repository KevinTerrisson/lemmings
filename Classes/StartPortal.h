#include "cocos2d.h"

USING_NS_CC;

class StartPortal : public Sprite
{
public:
	virtual bool init();

	void createPortal();

	// implement the "static create()" method manually
	CREATE_FUNC(StartPortal);
};