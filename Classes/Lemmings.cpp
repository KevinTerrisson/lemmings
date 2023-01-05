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

void Lemmings::explosion()
{
    //  explosion
}

void Lemmings::onClick()
{
    bool _lemmingClicked = true;

    // Créer un objet EventListenerTouch
    auto touchListener = EventListenerTouchOneByOne::create();

    // Définir l'écouteur d'événement de toucher pour détecter un "clic" sur le sprite
    touchListener->onTouchBegan = [](Touch* touch, Event* event)
    {
        // Récupérer le sprite qui a été cliqué
        auto target = static_cast<Sprite*>(event->getCurrentTarget());

        // Obtenir la position du toucher par rapport au sprite
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);

        // Vérifier si le toucher est dans le rectangle du sprite
        if (rect.containsPoint(locationInNode))
        {
            // Le sprite a été cliqué, exécuter l'action ici
            return true;
        }

        return false;
    };

    // Ajouter l'objet EventListenerTouch à l'événement dispatcher
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
}