#include "OctoMenu.hpp"
#include "globals.hpp"

// ImGui is still used to draw the window (cross-platform), but no modules/gui includes
#include <imgui.h>

namespace octo::menu {

void OctoMenu::render() {
    if (!m_visible) return;

    ImGui::PushStyleColor(ImGuiCol_WindowBg, IM_COL32(15, 15, 15, 220));
    ImGui::PushStyleColor(ImGuiCol_Header, IM_COL32(30, 30, 30, 255));
    ImGui::PushStyleColor(ImGuiCol_FrameBg, IM_COL32(25, 25, 25, 200));
    ImGui::PushStyleColor(ImGuiCol_SliderGrab, IM_COL32(90, 90, 90, 255));
    ImGui::PushStyleColor(ImGuiCol_CheckMark, IM_COL32(150, 150, 255, 255));

    ImGui::SetNextWindowSize(ImVec2(450, 600), ImGuiCond_FirstUseEver);
    ImGui::Begin("Octo Menu", nullptr, ImGuiWindowFlags_NoCollapse);

    // Player hacks
    ImGui::Text("Player Hacks");
    ImGui::Checkbox("Jump Hack", globals::player_jumphack);
    ImGui::SliderFloat("Respawn Delay", globals::player_respawndelay, 0.f, 120.f, "%.2f s");

    // Level hacks
    ImGui::Text("Level Hacks");
    ImGui::Checkbox("Hide Pause Menu", globals::level_hidepause);
    ImGui::Checkbox("0% Practice Completion", globals::level_zeropercentpractice);
    ImGui::Checkbox("Hitboxes on Death", globals::level_hitboxesondeath);

    // Global hacks
    ImGui::Text("Global Hacks");
    ImGui::Checkbox("Speedhack", globals::global_speedhack_toggle);
    ImGui::SliderFloat("Speed", globals::global_speedhack_value, 0.0001f, 1000.f, "%.4f");
    ImGui::Checkbox("Pitch Shift", globals::global_pitchshift_toggle);
    ImGui::SliderFloat("Pitch", globals::global_pitchshift_value, 0.5f, 2.f, "%.2f");
    ImGui::Checkbox("Audio Speed", globals::global_audiospeed_toggle);
    ImGui::Checkbox("Sync Audio w/ Speedhack", globals::global_audiospeed_sync);

    ImGui::End();
    ImGui::PopStyleColor(5);
}

// simple init hook, should be called in main mod init
void initMenuHooks() {
    // hook into ImGui frame rendering
    // This is pseudocode; tie this to your game loop / Geode render call
    // Example: geode::listenForGuiDraw([]{ OctoMenu::get().render(); });
}

} // namespace octo::menu
