#include "cocos2d.h"

USING_NS_CC;

class Box : public Sprite
{
public:
    virtual bool init();

    void loadBox();

    // effects
    void boxDestruction();

    // implement the "static create()" method manually
    CREATE_FUNC(Box);
};