#include "cocos2d.h"
#include "StartPortal.h"
#include "EndPortal.h"
#include "Lemmings.h"

USING_NS_CC;

class TileMap : public Node
{
public:
    virtual bool init();

    void loadTileMap();
    void enlargeTileMap(float scale);
    void createStartPortal();
    void createEndPortal();
    void ApparitonLemmings();

    void gameLoop();

    void update(float delta);

    // implement the "static create()" method manually
    CREATE_FUNC(TileMap);

private:
    TMXTiledMap* _tileMap;
};