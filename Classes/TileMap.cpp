#include "TileMap.h"

bool TileMap::init()
{
    if (!Node::init())
    {
        return false;
    }

    // Charger la carte � tuiles
    loadTileMap();

    // scale tilemap
    enlargeTileMap(4.0f);

    return true;
}

void TileMap::loadTileMap()
{
    // Chargement de la carte � tuiles � partir d'un fichier .tmx
    _tileMap = TMXTiledMap::create("tiled/level.tmx");

    // ajout de la carte � tuiles � la sc�ne
    this->addChild(_tileMap);
}

void TileMap::enlargeTileMap(float scale)
{
    _tileMap->setScale(scale);
}