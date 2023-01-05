#include "cocos2d.h"

USING_NS_CC;

class SkillsMenu : public Node
{
public:
	virtual bool init();

	void loadSkillsMenu();

	void OnClick(Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(SkillsMenu);

private:
	bool isButtonPressed = false;
};