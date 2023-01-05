// on "init" you need to initialize your instance
bool WinScene::init()
{
    m_time = 0.0f;

    if (!Scene::init())
    {
        return false;
    }

    //recuperation du temps de jeu
    auto director = cocos2d::Director::getInstance();
    float gameTime = director->getTotalFrames() * director->getAnimationInterval();

    _visibleSize = Director::getInstance()->getVisibleSize();
    _origin = Director::getInstance()->getVisibleOrigin();
    _center = Vec2(_origin.x + _visibleSize.width / 1.75, _origin.y + _visibleSize.height / 1.75);
    _time = Vec2(_origin.x + _visibleSize.width / 2, _origin.y + _visibleSize.height / 2);
    _lemmings = Vec2(_origin.x + _visibleSize.width / 1.86, _origin.y + _visibleSize.height / 2.30);
    _save = Vec2(_origin.x + _visibleSize.width / 1.6, _origin.y + _visibleSize.height / 2.75);
    _kill = Vec2(_origin.x + _visibleSize.width / 1.6, _origin.y + _visibleSize.height / 3.25);

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    ////// Image de fond //////
    auto background = Sprite::create("res/background.png");
    background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(background);
    //titel Victory
    auto Victory = Label::createWithTTF("You ", "font/pixelArt.ttf", 70);
    Victory->setPosition(_center);
    this->addChild(Victory);

    //titel Time
    auto Time = Label::createWithTTF("Time : " + std::to_string(gameTime), "font/pixelArt.ttf", 50);;
    Time->setPosition(_time);
    this->addChild(Time);

    //titel Lemming
    auto Lemmings = Label::createWithTTF("Lemmings :", "font/pixelArt.ttf", 50);
    Lemmings->setPosition(_lemmings);
    this->addChild(Lemmings);

    //titel kill
    auto Kill = Label::createWithTTF("Kill :", "font/pixelArt.ttf", 50);
    Kill->setPosition(_kill);
    this->addChild(Kill);

    //titel save
    auto Save = Label::createWithTTF("Save :", "font/pixelArt.ttf", 50);
    Save->setPosition(_save);
    this->addChild(Save);



    // Music Menu Theme
    auto music = AudioEngine::play2d("music/Menu.mp3", true, 0.3f);

    return true;
}