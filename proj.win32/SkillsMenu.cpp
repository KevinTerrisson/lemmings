#include "SkillsMenu.h"

USING_NS_CC;

// on "init" you need to initialize your instance
bool SkillsMenu::init()
{
    if (!Node::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    Bomb = MenuItemImage::create("res/bomb.png", "res/bomb.png", CC_CALLBACK_1(SkillsMenu::OnClick, this));
    Bomb->setPosition(visibleSize.width + origin.x, visibleSize.height + origin.y);
}

void SkillsMenu::OnClick(Ref* pSender)
{
    // changing cursor icon

}