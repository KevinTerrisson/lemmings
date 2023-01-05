#include "Obstacle.h"

bool Obstacle::init()
{
    if (!Sprite::init())
    {
        return false;
    }

    loadObstacle();

    return true;
}

void Obstacle::loadObstacle()
{

}