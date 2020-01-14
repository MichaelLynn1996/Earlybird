#pragma once

#include "cocos2d.h"
#include "AtlasLoader.h"
#include "time.h"

using namespace cocos2d;
using namespace std;

/**
 * 背景层：主要是游戏背景的显示
 */
class BackgroundLayer : public Layer {
public:
    BackgroundLayer(void);

    ~BackgroundLayer(void);

    virtual bool init();

    CREATE_FUNC(BackgroundLayer);

    static float getLandHeight();
};