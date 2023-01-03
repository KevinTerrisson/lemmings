#include "cocos2d.h"

USING_NS_CC;

class Lemmings : public Sprite
{
public:
    virtual bool init();

    void loadLemmings();

    void update(float delta);

    //movements
    void drop();
    void advance();
    void backOff();

    // implement the "static create()" method manually
    CREATE_FUNC(Lemmings);

private:
    int _dropSpeed;
    int _runSpeed;
};