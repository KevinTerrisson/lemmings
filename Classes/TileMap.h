#include "cocos2d.h"

#include "StartPortal.h"
#include "EndPortal.h"

USING_NS_CC;

class TileMap : public Node
{
public:
    virtual bool init();

    void loadTileMap();
    void enlargeTileMap(float scale);
    void createStartPortal();
    void createEndPortal();

    void gameLoop();

    void update(float delta);

    // implement the "static create()" method manually
    CREATE_FUNC(TileMap);

private:
    TMXTiledMap* _tileMap;
};