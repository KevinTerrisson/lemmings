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

        auto map = TMXTiledMap::create("lemmings / Resources / tiled / map.tmx.tmx"); // appelle map 
        addChild(map, 0, 99);

    }

    return true;
}