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

    createSkillsMenu();

    return true;
}

void GameScene::createSkillsMenu()
{
    // Cr�ation de l'objet SkillsMenu
    _skillsMenu = SkillsMenu::create();

    // Move the tile map by the necessary distance
    _skillsMenu->setPosition(Vec2(-900, -480));

    // ajout de EndPortal � la sc�ne
    this->addChild(_skillsMenu);
}