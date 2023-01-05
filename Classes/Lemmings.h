#include "cocos2d.h"
#include "ui/UIWidget.h"

USING_NS_CC;

class Lemmings : public Sprite
{
public:
    virtual bool init();

    void loadLemmings();

    // movements
    void drop();
    void advance();
    void backOff();

    // output
    void output();

    // effects
    void disappears();
    void explosion();

    // action
    void onClick();

    // implement the "static create()" method manually
    CREATE_FUNC(Lemmings);

private:
    int _dropSpeed;
    int _runSpeed;
};