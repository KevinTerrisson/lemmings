#include "cocos2d.h"

USING_NS_CC;

class Obstacle : public Sprite
{
public:
    virtual bool init();

    void loadObstacle();

    // implement the "static create()" method manually
    CREATE_FUNC(Obstacle);
};