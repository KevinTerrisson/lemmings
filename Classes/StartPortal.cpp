#include "StartPortal.h"

bool StartPortal::init()
{
    if (!Sprite::init())
    {
        return false;
    }

    //createAppearingPortal();
    //createDisappearingPortal();
    createIdlePortal();

    return true;
}

void StartPortal::createAppearingPortal()
{
    // Load the sprite sheet that contains the frames for the portal animation
    auto spritecache = SpriteFrameCache::getInstance();
    spritecache->addSpriteFramesWithFile("assets/start-portal/appearing/start-portal-appearing.plist");

    // Create the sprite and add it to the scene
    auto portalSprite = Sprite::createWithSpriteFrameName("start-portal-appearing-0.png");
    this->addChild(portalSprite);

    // Create an animation using the frames from the sprite sheet
    Vector<SpriteFrame*> frames;
    for (int i = 0; i <= 7; i++)
    {
        auto frame = spritecache->getSpriteFrameByName(StringUtils::format("start-portal-appearing-%d.png", i));
        frames.pushBack(frame);
    }

    auto animation = Animation::createWithSpriteFrames(frames, 0.1f);
    auto animate = Animate::create(animation);

    // Run the animation forever
    portalSprite->runAction(animate);
}

void StartPortal::createDisappearingPortal()
{
    // Load the sprite sheet that contains the frames for the portal animation
    auto spritecache = SpriteFrameCache::getInstance();
    spritecache->addSpriteFramesWithFile("assets/start-portal/disappearing/start-portal-disappearing.plist");

    // Create the sprite and add it to the scene
    auto portalSprite = Sprite::createWithSpriteFrameName("start-portal-disappearing-0.png");
    this->addChild(portalSprite);

    // Create an animation using the frames from the sprite sheet
    Vector<SpriteFrame*> frames;
    for (int i = 0; i <= 5; i++)
    {
        auto frame = spritecache->getSpriteFrameByName(StringUtils::format("start-portal-disappearing-%d.png", i));
        frames.pushBack(frame);
    }

    auto animation = Animation::createWithSpriteFrames(frames, 0.1f);
    auto animate = Animate::create(animation);

    // Run the animation forever
    portalSprite->runAction(animate);
}

void StartPortal::createIdlePortal()
{
    // Load the sprite sheet that contains the frames for the portal animation
    auto spritecache = SpriteFrameCache::getInstance();
    spritecache->addSpriteFramesWithFile("assets/start-portal/idle/start-portal-idle.plist");

    // Create the sprite and add it to the scene
    auto portalSprite = Sprite::createWithSpriteFrameName("start-portal-idle-0.png");
    this->addChild(portalSprite);

    // Create an animation using the frames from the sprite sheet
    Vector<SpriteFrame*> frames;
    for (int i = 0; i <= 7; i++)
    {
        auto frame = spritecache->getSpriteFrameByName(StringUtils::format("start-portal-idle-%d.png", i));
        frames.pushBack(frame);
    }

    auto animation = Animation::createWithSpriteFrames(frames, 0.1f);
    auto animate = Animate::create(animation);

    // Run the animation forever
    portalSprite->runAction(RepeatForever::create(animate));
}