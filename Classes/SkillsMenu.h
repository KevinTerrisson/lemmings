#include "cocos2d.h"

USING_NS_CC;

class SkillsMenu : public Node
{
public:
	virtual bool init();

	void loadSkillsMenu();

	void SkillsMenuInformation();

	void OnClick(Ref* pSender);

	bool clickedSkill();

	// implement the "static create()" method manually
	CREATE_FUNC(SkillsMenu);

private:
	bool isButtonPressed;

	Size _visibleSize;
	Vec2 _origin;

	float gameTime;
};