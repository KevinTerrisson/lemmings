#include "cocos2d.h"

USING_NS_CC;

class TileMap : public Node
{
public:
    virtual bool init();

    void loadTileMap();
    void enlargeTileMap(float scale);

    // implement the "static create()" method manually
    CREATE_FUNC(TileMap);

private:
    TMXTiledMap* _tileMap;
};