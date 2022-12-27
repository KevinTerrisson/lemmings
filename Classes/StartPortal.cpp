#include "StartPortal.h"

bool StartPortal::init()
{
    if (!Sprite::init())
    {
        return false;
    }

    createPortal();

    return true;
}

void StartPortal::createPortal()
{
    // Création du sprite à partir de l'image "start_portal.png"
    this->initWithFile("assets/start_portal.png");

    // Détermination de la taille de l'écran
    auto visibleSize = Director::getInstance()->getVisibleSize();

    // Définition de la position du sprite au milieu de l'écran
    this->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
}