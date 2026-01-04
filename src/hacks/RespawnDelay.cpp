#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/float-toggle.hpp>
#include <modules/hack/hack.hpp>

#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/CCDelayTime.hpp>

namespace octo::hacks::Player {

class $hack(RespawnDelay) {
    void init() override {
        auto tab = gui::MenuTab::find("tab.player");

        config::setIfEmpty("player.respawndelay.toggle", false);
        config::setIfEmpty("player.respawndelay", 1.f);

        tab->addFloatToggle("player.respawndelay", 0.f, 120.f, "%.2f s.")
           ->handleKeybinds()
           ->setDescription("Customize respawn delay");
    }

    [[nodiscard]] int32_t getPriority() const override { return 1; }
    [[nodiscard]] const char* getId() const override { return "Respawn Delay"; }
};

REGISTER_HACK(RespawnDelay)

class $modify(RespawnDelayPLHook, PlayLayer) {
    ALL_DELEGATES_AND_SAFE_PRIO("player.respawndelay.toggle")

    void destroyPlayer(PlayerObject* player, GameObject* object) override {
        PlayLayer::destroyPlayer(player, object);

        auto delay = config::get<float>("player.respawndelay", 1.f);
        if (auto* seq = this->getActionByTag(0x10)) {
            this->stopAction(seq);
            auto* newSeq = cocos2d::CCSequence::create(
                cocos2d::CCDelayTime::create(delay),
                cocos2d::CCCallFunc::create(this, callfunc_selector(PlayLayer::delayedResetLevel)),
                nullptr
            );
            newSeq->setTag(0x10);
            this->runAction(newSeq);
        }
    }
};

}
