#include "LoadingScene.h"

LoadingScene::LoadingScene() {}

LoadingScene::~LoadingScene() {}

bool LoadingScene::init() {
    return Scene::init();
}

void LoadingScene::onEnter() {
    // add background to current scene
    Sprite *background = Sprite::create("splash.png");
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    background->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
    this->addChild(background);

    // start Async method load the atlas.png
    Director::getInstance()->getTextureCache()->addImageAsync("atlas.png", CC_CALLBACK_1(
            LoadingScene::loadingCallBack, this));
}

void LoadingScene::loadingCallBack(Texture2D *texture) {
    AtlasLoader::getInstance()->loadAtlas("atlas.txt", texture);

    // After loading the texture , preload all the sound
    SimpleAudioEngine::getInstance()->preloadEffect("sfx_die.ogg");
    SimpleAudioEngine::getInstance()->preloadEffect("sfx_hit.ogg");
    SimpleAudioEngine::getInstance()->preloadEffect("sfx_point.ogg");
    SimpleAudioEngine::getInstance()->preloadEffect("sfx_swooshing.ogg");
    SimpleAudioEngine::getInstance()->preloadEffect("sfx_wing.ogg");

    // After load all the things, change the scene to new one
    //auto scene = HelloWorld::createScene();
    //跳转到下一个界面
    auto scene = WelcomeScene::create();
    TransitionScene *transition = TransitionFade::create(1, scene);
    Director::getInstance()->replaceScene(transition);
}