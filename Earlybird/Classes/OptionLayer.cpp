//
//  OptionLayer.cpp
//  parasite-city
//
//  Created by Zhou.Zeyong on 14-2-18.
//
//

#include "OptionLayer.h"


OptionLayer::OptionLayer() = default;

OptionLayer::~OptionLayer() = default;

bool OptionLayer::init() {
    if (Layer::init()) {
        //对触摸事件的监听
        auto dispatcher = Director::getInstance()->getEventDispatcher();
        auto listener = EventListenerTouchAllAtOnce::create();
        listener->onTouchesBegan = CC_CALLBACK_2(OptionLayer::onTouchesBegan, this);
        dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

        return true;
    } else {
        return false;
    }
}

void OptionLayer::onTouchesBegan(const std::vector<Touch *> &touches, Event *event) {
    this->delegator->onTouch();
}