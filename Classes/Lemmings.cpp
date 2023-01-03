#include "Lemmings.h"

bool Lemmings::init()
{
    if (!Sprite::init())
    {
        return false;
    }

    // set speed
    _dropSpeed = 3;
    _runSpeed = 1;

    loadLemmings();

    // Planification de l'exécution de la fonction update à chaque frame
    this->scheduleUpdate();

    return true;
}

void Lemmings::loadLemmings()
{
    auto mySprite = Sprite::create("Assets/sprite.png");

    this->addChild(mySprite);
}

// Fonction update qui sera appelée à chaque frame
void Lemmings::update(float delta)
{
    drop();
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

    // Mise à jour de la coordonnée y en fonction de la vitesse de chute
    position.x += _runSpeed;

    // Affectation de la nouvelle position au sprite
    this->setPosition(position);
}

void Lemmings::backOff()
{
    // Récupération de la position actuelle du sprite
    Vec2 position = this->getPosition();

    // Mise à jour de la coordonnée y en fonction de la vitesse de chute
    position.x -= _runSpeed;

    // Affectation de la nouvelle position au sprite
    this->setPosition(position);
}

void Lemmings::explosion()
{
    //  explosion
}