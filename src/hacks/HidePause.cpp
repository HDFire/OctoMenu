#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

#include <Geode/modify/PauseLayer.hpp>

namespace octo::hacks::Level {

class $hack(HidePause) {
    void init() override {
        auto tab = gui::MenuTab::find("tab.level");
        tab->addToggle("level.hidepause")
           ->handleKeybinds()
           ->setDescription("Hide pause menu");
    }

    [[nodiscard]] const char* getId() const override { return "Hide Pause Menu"; }
};

REGISTER_HACK(HidePause)

class $modify(HPMPauseLayerHook, PauseLayer) {
    void customSetup() override {
        createHideScheduler(this);
        PauseLayer::customSetup();
    }

    static void createHideScheduler(PauseLayer* pauseLayer) {
        pauseLayer->schedule(schedule_selector(HPMPauseLayerHook::updatePauseMenu));
        pauseLayer->setVisible(!config::get<"level.hidepause", bool>(false));
    }

    void updatePauseMenu(float dt) {
        auto hidePause = config::get<"level.hidepause", bool>(false);
        if (hidePause == this->isVisible()) {
            this->setVisible(!hidePause);
        }
    }
};

}
