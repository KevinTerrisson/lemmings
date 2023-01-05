#include "cocos2d.h"

#include "StartPortal.h"
#include "EndPortal.h"
#include "Lemmings.h"
#include "Box.h"
#include "WinScene.h"
#include "SkillsMenu.h"

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

    // Skills
    void createSkills();

    // Obstacle
    void createBox();

    //collisions
    bool collideGround();
    bool collideWall();
    bool collideBox();

    // game
    void gameLoop();
    void update(float delta);

    // implement the "static create()" method manually
    CREATE_FUNC(TileMap);

private:
    // Map
    TMXTiledMap* _tileMap;

    // Layers
    TMXLayer* _groundCollisions;
    TMXLayer* _wallCollisions;
    TMXLayer* _boxCollisions;
   
    // Lemmings
    Lemmings* _lemmings;
    bool direction;

    // Portals
    StartPortal* _startPortal;
    EndPortal* _endPortal;

    // Obstacle
    Box* _box;
    bool destroy;

    // Skills
    SkillsMenu* _skills;

    // Coordonates
    int xSpawn;
    int ySpawn;

    int xArrival;
    int yArrival;

    int xLemmings;
    int yLemmings;

    int xBox;
    int yBox;

    // Window
    int windowOffset;
};