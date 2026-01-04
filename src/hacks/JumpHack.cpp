#include <Geode/modify/GJBaseGameLayer.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include "globals.hpp"

static bool jump = false;

class $modify(OctoJumpHackBGL, GJBaseGameLayer) {
    ENABLE_SAFE_HOOKS_ALL()

    void update(float dt) override {
        if (g_jumpHack && jump) {
            if (m_player1) m_player1->m_isOnGround = true;
            if (m_player2) m_player2->m_isOnGround = true;
        }

        GJBaseGameLayer::update(dt);

        if (g_jumpHack && jump) {
            if (m_player1) m_player1->m_isOnGround = true;
            if (m_player2) m_player2->m_isOnGround = true;
            jump = false;
        }
    }
};

class $modify(OctoJumpHackPO, PlayerObject) {
    ENABLE_SAFE_HOOKS_ALL()

    bool pushButton(PlayerButton p0) override {
        if (g_jumpHack) jump = true;
        return PlayerObject::pushButton(p0);
    }
};
