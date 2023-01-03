#include "EndPortal.h"

bool EndPortal::init()
{
    if (!Sprite::init())
    {
        return false;
    }

    return true;
}

void EndPortal::appearingPortalAnimation()
{
    this->stopAllActions();

    // Load the sprite sheet that contains the frames for the portal animation
    auto spritecache = SpriteFrameCache::getInstance();
    spritecache->addSpriteFramesWithFile("assets/end-portal/appearing/end-portal-appearing.plist");

    // Create the sprite and add it to the scene
    auto portalSprite = Sprite::createWithSpriteFrameName("end-portal-appearing-0.png");
    this->addChild(portalSprite);

    // Create an animation using the frames from the sprite sheet
    Vector<SpriteFrame*> frames;
    for (int i = 0; i <= 7; i++)
    {
        auto frame = spritecache->getSpriteFrameByName(StringUtils::format("end-portal-appearing-%d.png", i));
        frames.pushBack(frame);
    }

    auto animation = Animation::createWithSpriteFrames(frames, 0.1f);
    auto animate = Animate::create(animation);

    // Run the animation forever
    portalSprite->runAction(animate);
}

void EndPortal::disappearingPortalAnimation()
{
    this->stopAllActions();

    // Load the sprite sheet that contains the frames for the portal animation
    auto spritecache = SpriteFrameCache::getInstance();
    spritecache->addSpriteFramesWithFile("assets/end-portal/disappearing/end-portal-disappearing.plist");

    // Create the sprite and add it to the scene
    auto portalSprite = Sprite::createWithSpriteFrameName("end-portal-disappearing-0.png");
    this->addChild(portalSprite);

    // Create an animation using the frames from the sprite sheet
    Vector<SpriteFrame*> frames;
    for (int i = 0; i <= 5; i++)
    {
        auto frame = spritecache->getSpriteFrameByName(StringUtils::format("end-portal-disappearing-%d.png", i));
        frames.pushBack(frame);
    }

    auto animation = Animation::createWithSpriteFrames(frames, 0.1f);
    auto animate = Animate::create(animation);

    // Run the animation forever
    portalSprite->runAction(animate);
}

void EndPortal::idlePortalAnimation()
{
    this->stopAllActions();

    // Load the sprite sheet that contains the frames for the portal animation
    auto spritecache = SpriteFrameCache::getInstance();
    spritecache->addSpriteFramesWithFile("assets/end-portal/idle/end-portal-idle.plist");

    // Create the sprite and add it to the scene
    auto portalSprite = Sprite::createWithSpriteFrameName("end-portal-idle-0.png");
    this->addChild(portalSprite);

    // Create an animation using the frames from the sprite sheet
    Vector<SpriteFrame*> frames;
    for (int i = 0; i <= 7; i++)
    {
        auto frame = spritecache->getSpriteFrameByName(StringUtils::format("end-portal-idle-%d.png", i));
        frames.pushBack(frame);
    }

    auto animation = Animation::createWithSpriteFrames(frames, 0.1f);
    auto animate = Animate::create(animation);

    // Run the animation forever
    portalSprite->runAction(RepeatForever::create(animate));
}