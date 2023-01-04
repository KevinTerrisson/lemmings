#include "cocos2d.h"

#include "TileMap.h"
#include "SkillsMenu.h"

USING_NS_CC;

class GameScene : public Scene
{
public:
    static Scene* createScene();

    virtual bool init();

    // skills menu
    void createSkillsMenu();

    CREATE_FUNC(GameScene);

private:
    // Instance de la classe TileMap
    TileMap* _tileMap;


    SkillsMenu* _skillsMenu;
};