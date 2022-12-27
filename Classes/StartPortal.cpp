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
    // Cr�ation du sprite � partir de l'image "start_portal.png"
    this->initWithFile("assets/start_portal.png");

    // D�termination de la taille de l'�cran
    auto visibleSize = Director::getInstance()->getVisibleSize();

    // D�finition de la position du sprite au milieu de l'�cran
    this->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
}