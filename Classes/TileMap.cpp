#include "TileMap.h"

bool TileMap::init()
{
    if (!Node::init())
    {
        return false;
    }

    // offset for UI
    windowOffset = 120;

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

    // get layers
    _groundCollisions = _tileMap->getLayer("Ground");
    _wallCollisions = _tileMap->getLayer("Wall");
    _obstacleCollisions = _tileMap->getLayer("Obstacle");

    // hide collisions layers
    _groundCollisions->setVisible(false);
    _wallCollisions->setVisible(true);
    _obstacleCollisions->setVisible(true);

    // set to top position
    _tileMap->setPosition(Vec2(0, windowOffset));

    // ajout de la carte à tuiles à la scène
    this->addChild(_tileMap);
}

void TileMap::enlargeTileMap(float scale)
{
    _tileMap->setScale(scale);
}

void TileMap::createStartPortal()
{
    // Création de l'objet EndPortal
    _startPortal = StartPortal::create();

    // Obtain the object group named "Objects"
    TMXObjectGroup* objectGroup = _tileMap->getObjectGroup("Objects");

    // Obtain the object named "spawn" from the object group
    ValueMap spawn = objectGroup->getObject("Spawn");

    // Retrieve the x and y coordinates of "spawn"
    xSpawn = spawn["x"].asInt();
    xSpawn = xSpawn * 4;
    ySpawn = spawn["y"].asInt();
    ySpawn = ySpawn * 4;

    // Move the tile map by the necessary distance
    _startPortal->setPosition(Vec2(xSpawn, ySpawn + windowOffset));

    //ajout de StartPortal à la scène
    this->addChild(_startPortal);
}

void TileMap::createEndPortal()
{
    // Création de l'objet EndPortal
    _endPortal = EndPortal::create();

    // Obtain the object group named "Objects"
    TMXObjectGroup* objectGroup = _tileMap->getObjectGroup("Objects");

    // Obtain the object named "Arrival" from the object group
    ValueMap arrival = objectGroup->getObject("Arrival");

    // Retrieve the x and y coordinates of "arrival"
    xArrival = arrival["x"].asInt();
    xArrival = xArrival * 4;
    yArrival = arrival["y"].asInt();
    yArrival = yArrival * 4;

    // Move the tile map by the necessary distance
    _endPortal->setPosition(Vec2(xArrival , yArrival + windowOffset));

    // ajout de EndPortal à la scène
    this->addChild(_endPortal);
}

void TileMap::createLemmings()
{
    // Création de l'objet Lemmings
    _lemmings = Lemmings::create();

    // Obtain the object group named "Objects"
    TMXObjectGroup* objectGroup = _tileMap->getObjectGroup("Objects");

    // Obtain the object named "spawn" from the object group
    ValueMap spawn = objectGroup->getObject("Spawn");

    // Retrieve the x and y coordinates of "spawn"
    xLemmings = spawn["x"].asInt();
    xLemmings = xLemmings * 4;
    yLemmings = spawn["y"].asInt();
    yLemmings = yLemmings * 4;

    // Move the tile map by the necessary distance
    _lemmings->setPosition(Vec2(xLemmings , yLemmings + windowOffset));

    direction = true;

    // ajout de EndPortal à la scène
    this->addChild(_lemmings);
}

bool TileMap::exit()
{
    if (xLemmings >= xArrival)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void TileMap::gameLoop()
{
    // Create the portals
    createStartPortal();
    createEndPortal();

    // create a sequence with the actions and callbacks
    auto createLemmingsAction = CallFunc::create([this]() { this->createLemmings(); });

    auto startPortalAppearing = CallFunc::create(CC_CALLBACK_0(StartPortal::appearingPortalAnimation, _startPortal));
    auto startPortalIdle = CallFunc::create(CC_CALLBACK_0(StartPortal::idlePortalAnimation, _startPortal));

    auto endPortalAppearing = CallFunc::create(CC_CALLBACK_0(EndPortal::appearingPortalAnimation, _endPortal));
    auto endPortalIdle = CallFunc::create(CC_CALLBACK_0(EndPortal::idlePortalAnimation, _endPortal));

    auto delayStartingAnimation = DelayTime::create(1.0f);
    auto delayIdleAnimation = DelayTime::create(0.8f);

    // set sequence
    auto seq = Sequence::create
    (
        delayStartingAnimation,
        startPortalAppearing,
        endPortalAppearing,
        delayIdleAnimation,
        startPortalIdle,
        endPortalIdle,
        createLemmingsAction,
        nullptr
    );

    // run it
    runAction(seq);
}

bool TileMap::collideGround()
{
    // deplacement vers le bas
    Vec2 lemmingsPos = _lemmings->getPosition();
    lemmingsPos.x /= 64.0f;
    lemmingsPos.y /= 64.0f;
    lemmingsPos.y = 17.4f - lemmingsPos.y;
    bool tileGid = _groundCollisions->getTileGIDAt(lemmingsPos);
    if (tileGid) {
        // touche le sol
        return true;
    }
}

bool TileMap::collideWall()
{
    // deplacement horizontal
    Vec2 lemmingsPos = _lemmings->getPosition();
    lemmingsPos.x /= 64.0f;
    lemmingsPos.y /= 64.0f;
    bool tileGid = _wallCollisions->getTileGIDAt(lemmingsPos);
    if (tileGid) {
        // touche le mur
        return true;
    }
}

// Fonction update qui sera appelée à chaque frame
void TileMap::update(float delta)
{
    if (_lemmings)
    {
        // recuperation de la position du lemmings
        xLemmings = _lemmings->getPosition().x;
        yLemmings = _lemmings->getPosition().y;

        collideGround();
        collideWall();
        exit();

        if (!collideGround() && !exit())
        {
            _lemmings->drop();
        }

        if (collideGround() && !exit())
        {
            if (direction)
            {
                _lemmings->advance();
                if (collideWall())
                {
                    direction = false;
                }
            }
            else
            {
                _lemmings->backOff();
                if (collideWall())
                {
                    direction = true;
                }
            }
        }

        if (exit())
        {
            if (yLemmings >= yArrival + windowOffset)
            {
                _lemmings->disappears();
                _lemmings = nullptr;
            }
            else
            {
                _lemmings->output();
            }
        }
    }
}