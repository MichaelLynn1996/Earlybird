#pragma once

#include "AtlasLoader.h"
#include "SimpleAudioEngine.h"
#include "2d/CCMenuItem.h"
#include "GameScene.h"
#include "time.h"
#include "cocos2d.h"
#include "BirdSprite.h"

using namespace cocos2d;
using namespace std;
using namespace CocosDenshion;

class WelcomeLayer : public Layer {
public:
    WelcomeLayer(void);

    ~WelcomeLayer(void);

    virtual bool init();
    // implement the "static create()" method manually
    CREATE_FUNC(WelcomeLayer);

private:
    /**
     * The start button has been pressed will call this function
     */
    void menuStartCallback(Ref *sender);

    /**
     * This method is make the land have a scroll animation
     * 通常我们采用两个精灵（land1，land2），不断交替地移动他们的X轴坐标。即当一张图片移出左边视野以后，
     * 就设置它的X轴坐标为右边最大值，这样它又可以开始第二次的从右往左移动了。如此交替反复滚动，
     * 就实现了我们所看到的地面滚动的效果了。
     */
    void scrollLand(float dt);

    Sprite *land1;
    Sprite *land2;
    BirdSprite *bird;
};