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

    // Planification de l'ex�cution de la fonction update � chaque frame
    this->scheduleUpdate();

    return true;
}

void Lemmings::loadLemmings()
{
    auto mySprite = Sprite::create("Assets/sprite.png");

    this->addChild(mySprite);
}

// Fonction update qui sera appel�e � chaque frame
void Lemmings::update(float delta)
{
    drop();
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

    // Mise � jour de la coordonn�e y en fonction de la vitesse de chute
    position.x += _runSpeed;

    // Affectation de la nouvelle position au sprite
    this->setPosition(position);
}

void Lemmings::backOff()
{
    // R�cup�ration de la position actuelle du sprite
    Vec2 position = this->getPosition();

    // Mise � jour de la coordonn�e y en fonction de la vitesse de chute
    position.x -= _runSpeed;

    // Affectation de la nouvelle position au sprite
    this->setPosition(position);
}

void Lemmings::explosion()
{
    //  explosion
}