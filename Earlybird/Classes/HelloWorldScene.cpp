#include "HelloWorldScene.h"

HelloWorldScene::HelloWorldScene() = default;

HelloWorldScene::~HelloWorldScene() = default;

bool HelloWorldScene::init() {
    return Scene::init();
}

void HelloWorldScene::onEnter() {
    // add background to current scene
    Sprite *background = Sprite::create("splash.png");
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    background->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
    this->addChild(background);

    // start Async method load the atlas.png
    // 资源包括图片素材的载入和音乐素材的载入
    Director::getInstance()->getTextureCache()->addImageAsync("atlas.png", CC_CALLBACK_1(
            HelloWorldScene::loadingCallBack, this));
}

void HelloWorldScene::loadingCallBack(Texture2D *texture) {
    AtlasLoader::getInstance()->loadAtlas("atlas.txt", texture);

    // After loading the texture , preload all the sound
    SimpleAudioEngine::getInstance()->preloadEffect("sfx_die.ogg");
    SimpleAudioEngine::getInstance()->preloadEffect("sfx_hit.ogg");
    SimpleAudioEngine::getInstance()->preloadEffect("sfx_point.ogg");
    SimpleAudioEngine::getInstance()->preloadEffect("sfx_swooshing.ogg");
    SimpleAudioEngine::getInstance()->preloadEffect("sfx_wing.ogg");

    // After load all the things, change the scene to new one
    //auto scene = HelloWorld::createScene();
    // 载入完成后跳转到下一个界面
    auto scene = WelcomeScene::create();
    TransitionScene *transition = TransitionFade::create(1, scene);
    Director::getInstance()->replaceScene(transition);
}