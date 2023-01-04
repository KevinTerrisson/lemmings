#include "cocos2d.h"

#include "StartPortal.h"
#include "EndPortal.h"
#include "Lemmings.h"

USING_NS_CC;

class TileMap : public Node
{
public:
    //init
    virtual bool init();

    // map
    void loadTileMap();
    void enlargeTileMap(float scale);

    // portals
    void createStartPortal();
    void createEndPortal();

    // lemmings
    void createLemmings();

    // game
    void gameLoop();
    void update(float delta);

    // implement the "static create()" method manually
    CREATE_FUNC(TileMap);

private:
    TMXTiledMap* _tileMap;

    Lemmings* _lemmings;

    StartPortal* _startPortal;
    EndPortal* _endPortal;
};