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
    // Récupération de la position actuelle du sprite
    Vec2 position = this->getPosition();

    // Mise à jour de la coordonnée y en fonction de la vitesse de chute
    position.y -= _dropSpeed;

    // Affectation de la nouvelle position au sprite
    this->setPosition(position);
}

void Lemmings::advance()
{
    // Récupération de la position actuelle du sprite
    Vec2 position = this->getPosition();

    // Mise à jour de la coordonnée y en fonction de la vitesse de course avant
    position.x += _runSpeed;

    // Affectation de la nouvelle position au sprite
    this->setPosition(position);
}

void Lemmings::backOff()
{
    // Récupération de la position actuelle du sprite
    Vec2 position = this->getPosition();

    // Mise à jour de la coordonnée y en fonction de la vitesse de course arriere
    position.x -= _runSpeed;

    // Affectation de la nouvelle position au sprite
    this->setPosition(position);
}

void Lemmings::output()
{
    // Récupération de la position actuelle du sprite
    Vec2 position = this->getPosition();

    // Mise à jour de la coordonnée y en fonction de la vitesse de chute
    position.y += _runSpeed;

    // Affectation de la nouvelle position au sprite
    this->setPosition(position);
}

void Lemmings::disappears()
{
    this->removeFromParent();
}
