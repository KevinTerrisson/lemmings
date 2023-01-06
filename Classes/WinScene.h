#include "cocos2d.h"
#include "AudioEngine.h"
#include "ui/UIButton.h"

USING_NS_CC;

class WinScene : public Scene
{
public:
    static Scene* createScene();

    virtual bool init();

    void getContext();

    void displayText();
    void displayBackground();
    void playMusic();

    // implement the "static create()" method manually
    CREATE_FUNC(WinScene);

    float m_time;

private:
    float gameTime;

    Size _visibleSize;
    Vec2 _origin;
    Vec2 _center;
    Vec2 _victory;
    Vec2 _time;
    Vec2 _lemmings;
    Vec2 _save;
    Vec2 _kill;
};