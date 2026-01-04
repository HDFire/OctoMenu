#include <Geode/modify/CCScheduler.hpp>
#include "globals.hpp"

class $modify(OctoSpeedhackScheduler, cocos2d::CCScheduler) {
    ENABLE_SAFE_HOOKS_ALL()

    void update(float dt) override {
        float speed = g_speedhack;
        if (speed <= 0.f) speed = 1.f;

        dt *= speed;

        CCScheduler::update(dt);
    }
};
