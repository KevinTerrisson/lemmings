#include "cocos2d.h"
#include "AudioEngine.h"

USING_NS_CC;

class WinScene : public Scene
{
 public:
	static Scene* createScene();

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(WinScene);

	float m_time;
};

