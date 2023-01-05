#include "cocos2d.h"

#include "StartPortal.h"
#include "EndPortal.h"
#include "Lemmings.h"
#include "Obstacle.h"

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
    bool exit();

    //collisions
    bool collideGround();
    bool collideWall();

    //void collideObstacle();

    // game
    void gameLoop();
    void update(float delta);

    // implement the "static create()" method manually
    CREATE_FUNC(TileMap);

private:
    // map
    TMXTiledMap* _tileMap;

    // layers
    TMXLayer* _groundCollisions;
    TMXLayer* _wallCollisions;
    TMXLayer* _obstacleCollisions;

    // lemmings
    Lemmings* _lemmings;
    bool direction;

    //portals
    StartPortal* _startPortal;
    EndPortal* _endPortal;

    // coordonates
    int xSpawn;
    int ySpawn;

    int xArrival;
    int yArrival;

    int xLemmings;
    int yLemmings;

    //window
    int windowOffset;
};