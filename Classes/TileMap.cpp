#include "TileMap.h"

bool TileMap::init()
{
    if (!Node::init())
    {
        return false;
    }

    // Charger la carte à tuiles
    loadTileMap();

    // scale tilemap
    enlargeTileMap(4.0f);

    gameLoop();

    // Ajouter une méthode update à la boucle de jeu
    this->scheduleUpdate();

    return true;
}

void TileMap::loadTileMap()
{
    // Chargement de la carte à tuiles à partir d'un fichier .tmx
    _tileMap = TMXTiledMap::create("tiled/level.tmx");

    // set to top position
    _tileMap->setPosition(Vec2(0, 120));

    // ajout de la carte à tuiles à la scène
    this->addChild(_tileMap);
}

void TileMap::enlargeTileMap(float scale)
{
    _tileMap->setScale(scale);
}

void TileMap::update(float delta)
{
    // Mise à jour de votre logique de jeu à chaque frame

    // ...
}

void TileMap::createStartPortal()
{
    // Création de l'objet EndPortal
    startPortal = StartPortal::create();

    // Obtain the object group named "Objects"
    TMXObjectGroup* objectGroup = _tileMap->getObjectGroup("Objects");

    // Obtain the object named "spawn" from the object group
    ValueMap spawn = objectGroup->getObject("Spawn");

    // Retrieve the x and y coordinates of "spawn"
    int x = spawn["x"].asInt();
    int y = spawn["y"].asInt();

    // Move the tile map by the necessary distance
    startPortal->setPosition(Vec2(x * 4, y * 4 + 120));

    //ajout de StartPortal à la scène
    this->addChild(startPortal);
}

void TileMap::createEndPortal()
{
    // Création de l'objet EndPortal
    endPortal = EndPortal::create();

    // Obtain the object group named "Objects"
    TMXObjectGroup* objectGroup = _tileMap->getObjectGroup("Objects");

    // Obtain the object named "Arrival" from the object group
    ValueMap arrival = objectGroup->getObject("Arrival");

    // Retrieve the x and y coordinates of "arrival"
    int x = arrival["x"].asInt();
    int y = arrival["y"].asInt();

    // Move the tile map by the necessary distance
    endPortal->setPosition(Vec2(x * 4, y * 4 + 120));

    // ajout de EndPortal à la scène
    this->addChild(endPortal);
}

void TileMap::gameLoop()
{
    // Create the portals (0s)
    createStartPortal();
    createEndPortal();

    // starting animation (1s)
    auto delayStart = DelayTime::create(1.0f);
    auto startPortalAppearingFunc = CallFunc::create(CC_CALLBACK_0(StartPortal::appearingPortalAnimation, startPortal));
    auto endPortalAppearingFunc = CallFunc::create(CC_CALLBACK_0(EndPortal::appearingPortalAnimation, endPortal));
    auto sequenceStart = Sequence::create(delayStart, startPortalAppearingFunc, endPortalAppearingFunc, nullptr);
    this->runAction(sequenceStart);

    //idle animation (1.8s)
    auto delayIdle = DelayTime::create(1.8f);
    auto startPortalIdleFunc = CallFunc::create(CC_CALLBACK_0(StartPortal::idlePortalAnimation, startPortal));
    auto endPortalIdleFunc = CallFunc::create(CC_CALLBACK_0(EndPortal::idlePortalAnimation, endPortal));
    auto sequenceIdle = Sequence::create(delayIdle, startPortalIdleFunc, endPortalIdleFunc, nullptr);
    this->runAction(sequenceIdle);

    // apparition des lemmings
}