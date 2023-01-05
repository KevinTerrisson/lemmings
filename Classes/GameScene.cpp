#include "GameScene.h"

Scene* GameScene::createScene()
{
    // 'scene' est un autre pointeur vers une Scene
    auto scene = Scene::create();

    // 'layer' est un pointeur vers votre propre classe
    auto layer = GameScene::create();

    // ajouter la couche à la scène
    scene->addChild(layer);

    // retourner la scène
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    if (!Scene::init())
    {
        return false;
    }

    // Création de l'instance de TileMap
    _tileMap = TileMap::create();
    // ajout de la carte à tuiles à la scène
    this->addChild(_tileMap);

    createSkillsMenu();

    return true;
}

void GameScene::createSkillsMenu()
{
    // Création de l'objet SkillsMenu
    _skillsMenu = SkillsMenu::create();

    // Move the tile map by the necessary distance
    _skillsMenu->setPosition(Vec2(-900, -480));

    // ajout de EndPortal à la scène
    this->addChild(_skillsMenu);
}