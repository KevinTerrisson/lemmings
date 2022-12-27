#include "cocos2d.h"
#include "GameScene.h"
#include "AudioEngine.h"

USING_NS_CC;

class MenuScene : public Scene
{
public:
	static Scene* createScene();

	virtual bool init();
	MenuItemImage* startMenu;
	MenuItemImage* exitMenu;
	void changeScene(Ref* pSender);
	void exitGame(Ref* pSender);

    virtual void update(float dt);

    // implement the "static create()" method manually
    CREATE_FUNC(MenuScene);

    float m_time;
};