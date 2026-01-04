#include <Geode/modify/GameManager.hpp>
#include <Geode/modify/GameStatsManager.hpp>
#include "globals.hpp"

class $modify(UnlockIconsGMHook, GameManager) {
    ENABLE_SAFE_HOOKS_ALL()
    bool isColorUnlocked(int key, UnlockType type) { return GameManager::isColorUnlocked(key,type)||g_unlockIcons; }
    bool isIconUnlocked(int key, IconType type) { return GameManager::isIconUnlocked(key,type)||g_unlockIcons; }
};

class $modify(UnlockIconsGSMHook, GameStatsManager) {
    ENABLE_SAFE_HOOKS_ALL()
    bool isItemUnlocked(UnlockType type, int key) {
        if(GameStatsManager::isItemUnlocked(type,key)) return true;
        if(!g_unlockIcons) return false;
        return type==UnlockType::GJItem && key>=18 && key<=20;
    }
};
