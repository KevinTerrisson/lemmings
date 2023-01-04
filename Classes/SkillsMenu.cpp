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
    auto Bomb = MenuItemImage::create("res/BombButton.png", "res/BombButton.png", CC_CALLBACK_1(SkillsMenu::OnClick, this));

    auto menu = Menu::create(Bomb, /*Back, */ nullptr);
  
    this->addChild(menu);
}

void SkillsMenu::OnClick(Ref* pSender)
{
    // changing cursor icon
    /*
    auto director = cocos2d::Director::getInstance();
    auto cursorSprite = cocos2d::Sprite::create("myCursor.png");
    director->getOpenGLView()->setCursor(cursorSprite);
    */

    auto director = cocos2d::Director::getInstance();
    auto cursorSprite = cocos2d::Sprite::create("myCursor.png");

    auto mouseListener = cocos2d::EventListenerMouse::create();
    mouseListener->onMouseMove = [](cocos2d::EventMouse* event) {
        // R�cup�rez la position du curseur
        cocos2d::Vec2 cursorPos = event->getLocation();
        // D�placez le sprite de curseur � la position du curseur
        cursorSprite->setPosition(cursorPos);
    };

    // Ajoutez le gestionnaire d'�v�nements de la souris � la file d'attente d'�v�nements
    director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouseListener, this);
}