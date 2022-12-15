#include "Level_one_scene.h"

USING_NS_CC;

Scene* Level_one_scene::createScene()
{
    return Level_one_scene::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
}

bool Level_one_scene::init()
{
    if (!Scene::init())
    {
        _tileMap = new CCTMXTiledMap();
        _tileMap->initWithTMXFile("TileMap.tmx");
        _background = _tileMap->layerNamed("Background");

        this->addChild(_tileMap);

    }

    return true;
}