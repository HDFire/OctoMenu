#include <Geode/modify/GameStatsManager.hpp>
#include "globals.hpp"

class $modify(MusicUnlockGSMHook, GameStatsManager) {
    ENABLE_SAFE_HOOKS_ALL()
    bool isItemUnlocked(UnlockType type, int key) {
        if(GameStatsManager::isItemUnlocked(type,key)) return true;
        if(!g_unlockMusic) return false;
        return type==UnlockType::GJItem && (key==16 || key==17);
    }
};
