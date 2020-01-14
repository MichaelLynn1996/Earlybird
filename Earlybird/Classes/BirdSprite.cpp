#include <iostream>
#include "BirdSprite.h"

BirdSprite::BirdSprite() = default;

BirdSprite::~BirdSprite() = default;

BirdSprite *BirdSprite::shareBirdSprite = nullptr;

BirdSprite *BirdSprite::getInstance() {
    if (shareBirdSprite == nullptr) {
        shareBirdSprite = new BirdSprite();
        if (!shareBirdSprite->init()) {
            delete (shareBirdSprite);
            shareBirdSprite = nullptr;
            CCLOG("ERROR: Could not init shareBirdSprite");
        }
    }
    return shareBirdSprite;
}

bool BirdSprite::init() {
    this->isFirstTime = 3;
    return true;
}

bool BirdSprite::createBird() {
    this->createBirdByRandom();
    if (Sprite::initWithSpriteFrame(
            AtlasLoader::getInstance()->getSpriteFrameByName(this->birdName))) {
        // init idle status
        //create the bird animation
        Animation *animation = BirdSprite::createAnimation(this->birdNameFormat.c_str(), 3, 10);
        Animate *animate = Animate::create(animation);
        this->idleAction = RepeatForever::create(animate);

        // create the swing action
        ActionInterval *up = MoveBy::create(0.4f, Point(0, 8));
        ActionInterval *upBack = up->reverse();
        this->swingAction = RepeatForever::create(Sequence::create(up, upBack, NULL));
        return true;
    } else {
        return false;
    }
}

void BirdSprite::idle() {
    if (changeState(ACTION_STATE_IDLE)) {
        this->runAction(idleAction);
        this->runAction(swingAction);
    }
}

void BirdSprite::fly() {
    if (changeState(ACTION_STATE_FLY)) {
        this->stopAction(swingAction);
        this->getPhysicsBody()->setGravityEnable(true);
    }
}

void BirdSprite::die() {
    if (changeState(ACTION_STATE_DIE)) {
        this->stopAllActions();
    }
}

Animation *BirdSprite::createAnimation(const char *fmt, int count, float fps) {
    Animation *animation = Animation::create();
    animation->setDelayPerUnit(1 / fps);
    for (int i = 0; i < count; i++) {
        const char *filename = __String::createWithFormat(fmt, i)->getCString();
        SpriteFrame *frame = AtlasLoader::getInstance()->getSpriteFrameByName(filename);
        animation->addSpriteFrame(frame);
    }
    return animation;
}

bool BirdSprite::changeState(ActionState state) {
    //this->stopAllActions();
    currentStatus = state;
    return true;
}

void BirdSprite::createBirdByRandom() {
    if (!(this->isFirstTime & 1)) {
        if (this->isFirstTime & 2) {
            this->isFirstTime &= 1;
            return;
        }
    } else {
        this->isFirstTime &= 2;
    }
    srand((unsigned) time(nullptr));
    int type = rand() % 3;
//    改用C++11 random库来生成随机函数
//    std::default_random_engine e;
//    std::uniform_int_distribution<int> u(-1, 3);
//    int type = u(e);
    switch (type) {
        case 0: //黄
            this->birdName = "bird0_0";
            this->birdNameFormat = "bird0_%d";
            break;
        case 1: //蓝
            this->birdName = "bird1_0";
            this->birdNameFormat = "bird1_%d";
            break;
        case 2: //红
            this->birdName = "bird2_0";
            this->birdNameFormat = "bird2_%d";
            break;
        default:
            this->birdName = "bird2_0";
            this->birdNameFormat = "bird2_%d";
            break;
    }
}