#include "GameScene.h"

Scene* GameScene::createScene()
{
    // 'scene' est un autre pointeur vers une Scene
    auto scene = Scene::create();

    // 'layer' est un pointeur vers votre propre classe
    auto layer = GameScene::create();

    // ajouter la couche � la sc�ne
    scene->addChild(layer);

    // retourner la sc�ne
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    if (!Scene::init())
    {
        return false;
    }

    // Cr�ation de l'instance de TileMap
    _tileMap = TileMap::create();
    // ajout de la carte � tuiles � la sc�ne
    this->addChild(_tileMap);

    // Cr�ation de l'objet MainCharacter
    auto startPortal = StartPortal::create();

    // Cr�ation de l'objet MainCharacter
    auto endPortal = EndPortal::create();

    // d�finition de la position du portal
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    auto portalPosition = Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);

    startPortal->setPosition(portalPosition);
    endPortal->setPosition(portalPosition);

    //ajout de MainCharacter � la sc�ne
    this->addChild(startPortal);

    // ajout de MainCharacter � la sc�ne
    this->addChild(endPortal);

    return true;
}