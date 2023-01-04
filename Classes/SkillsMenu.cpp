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
        // Récupérez la position du curseur
        cocos2d::Vec2 cursorPos = event->getLocation();
        // Déplacez le sprite de curseur à la position du curseur
        cursorSprite->setPosition(cursorPos);
    };

    // Ajoutez le gestionnaire d'événements de la souris à la file d'attente d'événements
    director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouseListener, this);
}