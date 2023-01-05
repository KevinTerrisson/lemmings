#include "SkillsMenu.h"


USING_NS_CC;

// on "init" you need to initialize your instance
bool SkillsMenu::init()
{
    if (!Node::init())
    {
        return false;
    }

    _visibleSize = Director::getInstance()->getVisibleSize();
    _origin = Director::getInstance()->getVisibleOrigin();

    loadSkillsMenu();

    SkillsMenuInformation();

    cocos2d::Scheduler* scheduler = cocos2d::Director::getInstance()->getScheduler();
    scheduler->schedule(CC_CALLBACK_1(SkillsMenu::updateTime, this), this, 1.0f, -1, 0.0f, false, "updateTime");

    return true;
}

void SkillsMenu::loadSkillsMenu()
{
    auto Bomb = MenuItemImage::create("res/BombButton.png", "res/BombButton2.png", CC_CALLBACK_1(SkillsMenu::OnClick, this));
    //auto Back = Sprite::create("res/SkillsMenuBackground");

    auto menu = Menu::create(Bomb, /*Back, */ nullptr);
  
    this->addChild(menu);
}

void SkillsMenu::SkillsMenuInformation()
{
    nbTime = 500;

    // temps restant
    auto out = Label::createWithTTF("out", "font/pixelArt.ttf", 50);
    out->setPosition(Vec2(_origin.x + _visibleSize.width / 2 + 500, _origin.y + _visibleSize.height / 2));

    auto nbLemmings = Label::createWithTTF("0", "font/pixelArt.ttf", 50);
    nbLemmings->setPosition(Vec2(_origin.x + _visibleSize.width / 2 + 600, _origin.y + _visibleSize.height / 2));

    // pourcentage de lemmings passé à l'arrivé
    auto in = Label::createWithTTF("in", "font/pixelArt.ttf", 50);
    in->setPosition(Vec2(_origin.x + _visibleSize.width / 2 + 750, _origin.y + _visibleSize.height / 2));

    auto pourcentLemmingsIn = Label::createWithTTF("0", "font/pixelArt.ttf", 50);
    pourcentLemmingsIn->setPosition(Vec2(_origin.x + _visibleSize.width / 2 + 850, _origin.y + _visibleSize.height / 2));

    auto pourcent = Label::createWithTTF("%", "font/pixelArt.ttf", 50);
    pourcent->setPosition(Vec2(_origin.x + _visibleSize.width / 2 + 900, _origin.y + _visibleSize.height / 2));

    // nombre de lemmings sur le terrain
    auto time = Label::createWithTTF("time", "font/pixelArt.ttf", 50);
    time->setPosition(Vec2(_origin.x + _visibleSize.width / 2 + 1050, _origin.y + _visibleSize.height / 2));

    auto nbTimeLabel = Label::createWithTTF(StringUtils::toString(nbTime), "font/pixelArt.ttf", 50);
    nbTimeLabel->setPosition(Vec2(_origin.x + _visibleSize.width / 2 + 1200, _origin.y + _visibleSize.height / 2));


    std::array<Label*, 7> labels = { out, nbLemmings, in, pourcentLemmingsIn, pourcent, time, nbTimeLabel };

    for (auto label : labels) {
        this->addChild(label);
    }
}

void SkillsMenu::updateTime(float dt)
{
    nbTime--;
    nbTimeLabel->setString(StringUtils::toString(time));
}

void SkillsMenu::OnClick(Ref* pSender)
{
    // Pour changer l'état du bouton
    isButtonPressed = !isButtonPressed;

    auto button = dynamic_cast<MenuItemImage*>(pSender);
    if (isButtonPressed)
    {
        // changement de l'image du bouton pour la version "pressed"
        button->setNormalImage(Sprite::create("res/BombButton2.png"));
        button->setSelectedImage(Sprite::create("res/BombButton2.png"));
    }
    else
    {
        // changement de l'image du bouton pour la version originale
        button->setNormalImage(Sprite::create("res/BombButton.png"));
        button->setSelectedImage(Sprite::create("res/BombButton2.png"));
    }

    // suite des action
}