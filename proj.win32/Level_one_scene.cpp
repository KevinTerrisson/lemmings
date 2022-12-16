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

        auto map = TMXTiledMap::create("map.tmx");
        addChild(map, 0, 99); // with a tag of '99'

       /* _tileMap = new CCTMXTiledMap();
        _tileMap->initWithTMXFile("map.tmx");
        _background = _tileMap->layerNamed("Background");

        this->addChild(_tileMap);*/

    }

    return true;
}