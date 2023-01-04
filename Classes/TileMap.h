#include "cocos2d.h"

#include "StartPortal.h"
#include "EndPortal.h"
#include "Lemmings.h"
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

    // skills menu
    void createSkillsMenu();

    // game
    void gameLoop();

    // implement the "static create()" method manually
    CREATE_FUNC(TileMap);

private:
    TMXTiledMap* _tileMap;

    StartPortal* _startPortal;
    EndPortal* _endPortal;

    Lemmings* _lemmings;

    SkillsMenu* _skillsMenu;
};