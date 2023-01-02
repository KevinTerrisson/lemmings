#include "cocos2d.h"

#include "TileMap.h"
#include "StartPortal.h"
#include "EndPortal.h"

USING_NS_CC;

class GameScene : public Scene
{
public:
    static Scene* createScene();

    virtual bool init();

    CREATE_FUNC(GameScene);

private:
    // Instance de la classe TileMap
    TileMap* _tileMap;
};