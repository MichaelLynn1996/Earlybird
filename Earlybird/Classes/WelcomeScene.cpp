#include "WelcomeScene.h"

WelcomeScene::WelcomeScene() = default;;

WelcomeScene::~WelcomeScene() = default;;

bool WelcomeScene::init() {
    bool bRet = false;
    do {
        CC_BREAK_IF(!Scene::init());
        //WelcomeScene对应的WelcomeLayer
        auto _welcomeLayer = WelcomeLayer::create();
        //auto _welcomeLayer = StatusLayer::create();
        CC_BREAK_IF(!_welcomeLayer);
        this->addChild(_welcomeLayer);
        bRet = true;
    } while (0);
    return bRet;
}


