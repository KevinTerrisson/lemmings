#include "WinScene.h"

Scene* WinScene::createScene()
{
    // 'scene' est un autre pointeur vers une Scene
    auto scene = Scene::create();

    // 'layer' est un pointeur vers votre propre classe
    auto layer = WinScene::create();

    // ajouter la couche à la scène
    scene->addChild(layer);

    // retourner la scène
    return scene;
}

bool WinScene::init()
{
    if (!Scene::init())
    {
        return false;
    }

    m_time = 0.0f;

    _visibleSize = Director::getInstance()->getVisibleSize();
    _origin = Director::getInstance()->getVisibleOrigin();
    _center = Vec2(_origin.x + _visibleSize.width / 2, _origin.y + _visibleSize.height / 2);
    _victory = _center + Vec2(200, 0);
    _time = _center + Vec2(200, -100);
    _lemmings = _center + Vec2(200, -200);
    _save = _center + Vec2(200, -300);
    _kill = _center + Vec2(200, -400);

    getContext();

    displayBackground();
    displayText();

    return true;
}

void WinScene::getContext()
{
    //recuperation du temps de jeu
    auto director = cocos2d::Director::getInstance();
    float gameTime = director->getTotalFrames() * director->getAnimationInterval();
}

void WinScene::displayText()
{
    //titel Victory
    auto victory = Label::createWithTTF("You ", "font/pixelArt.ttf", 70);
    victory->setPosition(_victory);
    this->addChild(victory);

    //titel Time
    auto time = Label::createWithTTF("Time : " + std::to_string(gameTime), "font/pixelArt.ttf", 50);;
    time->setPosition(_time);
    this->addChild(time);

    //titel Lemming
    auto lemmings = Label::createWithTTF("Lemmings :", "font/pixelArt.ttf", 50);
    lemmings->setPosition(_lemmings);
    this->addChild(lemmings);

    //titel kill
    auto kill = Label::createWithTTF("Kill :", "font/pixelArt.ttf", 50);
    kill->setPosition(_kill);
    this->addChild(kill);

    //titel save
    auto save = Label::createWithTTF("Save :", "font/pixelArt.ttf", 50);
    save->setPosition(_save);
    this->addChild(save);
}

void WinScene::displayBackground()
{
    //Image de fond
    auto background = Sprite::create("res/background.png");
    background->setPosition(_center);
    this->addChild(background);
}