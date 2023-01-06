#include "Lemmings.h"

bool Lemmings::init()
{
    if (!Sprite::init())
    {
        return false;
    }

    // set speed
    _dropSpeed = 5;
    _runSpeed = 3;

    loadLemmings();

    return true;
}

void Lemmings::loadLemmings()
{
    auto lemmings = Sprite::create("Assets/sprite.png");

    this->addChild(lemmings);
}

void Lemmings::drop()
{
    // R�cup�ration de la position actuelle du sprite
    Vec2 position = this->getPosition();

    // Mise � jour de la coordonn�e y en fonction de la vitesse de chute
    position.y -= _dropSpeed;

    // Affectation de la nouvelle position au sprite
    this->setPosition(position);
}

void Lemmings::advance()
{
    // R�cup�ration de la position actuelle du sprite
    Vec2 position = this->getPosition();

    // Mise � jour de la coordonn�e y en fonction de la vitesse de course avant
    position.x += _runSpeed;

    // Affectation de la nouvelle position au sprite
    this->setPosition(position);
}

void Lemmings::backOff()
{
    // R�cup�ration de la position actuelle du sprite
    Vec2 position = this->getPosition();

    // Mise � jour de la coordonn�e y en fonction de la vitesse de course arriere
    position.x -= _runSpeed;

    // Affectation de la nouvelle position au sprite
    this->setPosition(position);
}

void Lemmings::output()
{
    // R�cup�ration de la position actuelle du sprite
    Vec2 position = this->getPosition();

    // Mise � jour de la coordonn�e y en fonction de la vitesse de chute
    position.y += _runSpeed;

    // Affectation de la nouvelle position au sprite
    this->setPosition(position);
}

void Lemmings::disappears()
{
    this->removeFromParent();
}
