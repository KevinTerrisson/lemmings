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

    onClick();

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

void Lemmings::explosion()
{
    //  explosion
}

void Lemmings::onClick()
{
    bool _lemmingClicked = true;

    // Cr�er un objet EventListenerTouch
    auto touchListener = EventListenerTouchOneByOne::create();

    // D�finir l'�couteur d'�v�nement de toucher pour d�tecter un "clic" sur le sprite
    touchListener->onTouchBegan = [](Touch* touch, Event* event)
    {
        // R�cup�rer le sprite qui a �t� cliqu�
        auto target = static_cast<Sprite*>(event->getCurrentTarget());

        // Obtenir la position du toucher par rapport au sprite
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);

        // V�rifier si le toucher est dans le rectangle du sprite
        if (rect.containsPoint(locationInNode))
        {
            // Le sprite a �t� cliqu�, ex�cuter l'action ici
            return true;
        }

        return false;
    };

    // Ajouter l'objet EventListenerTouch � l'�v�nement dispatcher
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
}