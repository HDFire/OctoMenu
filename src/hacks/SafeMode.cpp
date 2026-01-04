#include <Geode/modify/GameStatsManager.hpp>
#include <Geode/modify/LevelSettings.hpp>
#include "globals.hpp"

static bool isCheatingActive() {
    return g_noclip; // only noclip counts as "cheat" for SafeMode
}

class $modify(OctoSafeModeLS, LevelSettings) {
    ENABLE_SAFE_HOOKS_ALL()
    bool isSafeMode() { return g_safeMode || isCheatingActive(); }
};

class $modify(OctoSafeModeGSM, GameStatsManager) {
    ENABLE_SAFE_HOOKS_ALL()
    void setStat(const char* key, int value) { if(!isCheatingActive()) GameStatsManager::setStat(key,value); }
    void incrementStat(const char* key, int amount) { if(!isCheatingActive()) GameStatsManager::incrementStat(key,amount); }
};
