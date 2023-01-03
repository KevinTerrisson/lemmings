#include "Lemmings.h"

bool StartSpawn::init()
{
    if (!Sprite::init())
    {
        return false;
    }

    ApparitonLemmings();
    //disparitionLemmings();

    return true;
}

void StartSpawn::ApparitonLemmings()
{
	auto Lemmings = Sprite::create("teste.png");
	Lemmings->setPosition(Vec2(1250, 500));
}

void StartSpawn::disparitionLemmings()
{
}
