#include <Geode/modify/FMODAudioEngine.hpp>
#include "globals.hpp"

class $modify(OctoAudioSpeedFMOD, FMODAudioEngine) {
    ENABLE_SAFE_HOOKS_ALL()

    void update(float dt) override {
        FMODAudioEngine::update(dt);

        if (!g_audioSpeed && !(g_audioSpeedSync && g_speedhack != 1.f)) return;

        float speed = g_audioSpeed ? g_audioSpeedValue : (g_audioSpeedSync ? g_speedhack : 1.f);
        FMOD::ChannelGroup* masterGroup;
        if (m_system->getMasterChannelGroup(&masterGroup) != FMOD_OK) return;
        masterGroup->setPitch(speed);
    }
};
