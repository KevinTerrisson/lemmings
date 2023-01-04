#include "cocos2d.h"

USING_NS_CC;

class SkillsMenu : public Node
{
public:
	virtual bool init();

	MenuItemImage* Bomb;
	void OnClick(Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(SkillsMenu);
};