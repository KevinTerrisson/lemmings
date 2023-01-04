#include "SkillsMenu.h"


USING_NS_CC;

// on "init" you need to initialize your instance
bool SkillsMenu::init()
{
    if (!Node::init())
    {
        return false;
    }

    loadSkillsMenu();

    return true;
}

void SkillsMenu::loadSkillsMenu()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //auto Back = Sprite::create("res/SkillsMenuBackground");
    auto Bomb = MenuItemImage::create("res/BombButton.png", "res/BombButton2.png", CC_CALLBACK_1(SkillsMenu::OnClick, this));

    auto menu = Menu::create(Bomb, /*Back, */ nullptr);
  
    this->addChild(menu);
}

void SkillsMenu::OnClick(Ref* pSender)
{
    //action
}