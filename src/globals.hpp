#pragma once

#include <Geode/Geode.hpp>
#include <Geode/binding/PlayerObject.hpp>

namespace octo::globals {

// --- Player/Level shared ---
inline bool jump = false;                  // JumpHack
inline PlayerObject* lastKiller = nullptr; // HitboxesOnDeath

// --- Hitboxes ---
inline bool showHitboxes = false;
inline bool hitboxesOnDeath = false;

// --- Speed / Audio ---
inline float currentSpeed = 1.f;
inline bool speedhackEnabled = false;
inline bool audioSpeedEnabled = false;
inline bool audioSpeedSyncWithSpeedhack = false;

// --- PitchShift ---
inline float pitch = 1.f;
inline bool pitchShiftEnabled = false;

// --- RespawnDelay ---
inline float respawnDelay = 1.f;

// --- Pause Menu ---
inline bool hidePauseMenu = false;

// --- ZeroPercentPractice ---
inline bool zeroPercentPractice = false;

} // namespace octo::globals
