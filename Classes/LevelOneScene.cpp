#include "LevelOneScene.h"


USING_NS_CC;

Scene* LevelOneScene::createScene()
{
    return LevelOneScene::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
}

bool LevelOneScene::init()
{
    if (!Scene::init())
    {

        auto map = TMXTiledMap::create("lemmings / Resources / tiled / map.tmx");
        addChild(map, 0, 99); // with a tag of '99'

       /* _tileMap = new CCTMXTiledMap();
        _tileMap->initWithTMXFile("map.tmx");
        _background = _tileMap->layerNamed("Background");

        this->addChild(_tileMap);*/

    }

    return true;
}