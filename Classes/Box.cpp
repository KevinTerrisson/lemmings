#include "Box.h"

bool Box::init()
{
    if (!Sprite::init())
    {
        return false;
    }

    loadBox();

    return true;
}

void Box::loadBox()
{
    auto box = Sprite::create("Assets/Box.png");

    // set anchor
    box->setAnchorPoint(Vec2(0, 0));

    // Add the box to the layer
    this->addChild(box);
}

void Box::boxDestruction()
{
    this->removeFromParent();
}