#include "UserRecord.h"

UserRecord::UserRecord() = default;

UserRecord::~UserRecord() = default;

bool UserRecord::init() {
    return true;
}

UserRecord *UserRecord::shareUserRecord = nullptr;

UserRecord *UserRecord::getInstance() {
    if (shareUserRecord == nullptr) {
        shareUserRecord = new UserRecord();
        if (!shareUserRecord->init()) {
            delete (shareUserRecord);
            shareUserRecord = nullptr;
        }
    }
    return shareUserRecord;
}

void UserRecord::saveIntegerToUserDefault(const char *key, int score) {
    UserDefault::getInstance()->setIntegerForKey(key, score);
}


int UserRecord::readIntegerFromUserDefault(const char *key) {
    int score = UserDefault::getInstance()->getIntegerForKey(key);
    return score;
}

void UserRecord::destroyInstance() {
    CC_SAFE_DELETE(shareUserRecord);
}
