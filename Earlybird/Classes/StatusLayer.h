#pragma once

#include "cocos2d.h"
#include "AtlasLoader.h"
#include "GameLayer.h"
#include "GameScene.h"
#include "Number.h"
#include "SimpleAudioEngine.h"
#include <cstdlib>

using namespace std;
using namespace cocos2d;
using namespace CocosDenshion;

const string NUMBER_SCORE = "number_score";
const string NUMBER_FONT = "font";
const int CURRENT_SCORE_SPRITE_TAG = 10001;

/**
 * 状态层：游戏过程中分数的显示，根据游戏的不同阶段，显示游戏状态（开始、游戏进行中、游戏结束）
 */
class StatusLayer : public Layer, public StatusDelegate {
public:
    StatusLayer(void);

    ~StatusLayer(void);

    virtual bool init();

    CREATE_FUNC(StatusLayer);

    void onGameStart();

    void onGamePlaying(int score);

    void onGameEnd(int curScore, int bestScore);

private:
    void showReadyStatus();

    void showStartStatus();

    void showOverStatus(int curScore, int bestScore);

    void loadWhiteSprite();

    void blinkFullScreen();

    void fadeInGameOver();

    void jumpToScorePanel();

    void fadeInRestartBtn();

    void refreshScoreCallback();

    void refreshScoreExecutor(float dt);

    string getMedalsName(int score);

    Sprite *blink;

    void setBlinkSprite();

    void blinkAction();

    void menuRestartCallback(Ref *sender);

    void menuEndCallback(Ref *sender);

    Sprite *scoreSprite;

    Sprite *getreadySprite;

    Sprite *tutorialSprite;

    Sprite *whiteSprite;

    int currentScore;

    int bestScore;

    int tmpScore;

    bool isNewRecord;

    Point originPoint;

    Size visibleSize;
};
