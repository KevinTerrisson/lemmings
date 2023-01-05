#include "cocos2d.h"
#include "CCScheduler.h"

USING_NS_CC;

class SkillsMenu : public Node
{
public:
	virtual bool init();

	void loadSkillsMenu();

	void SkillsMenuInformation();

	void updateTime(float);

	void OnClick(Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(SkillsMenu);

private:
	bool isButtonPressed = false;

	Size _visibleSize;
	Vec2 _origin;

	int nbTime;
	Label* nbTimeLabel;
};