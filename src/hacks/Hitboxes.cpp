#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/LevelObject.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include <Geode/binding/CCDrawNode.hpp>

namespace octo::hacks::Level {

inline bool g_showHitboxes = false;

class $hack(Hitboxes) {
    void init() override {
        auto tab = gui::MenuTab::find("tab.level");
        tab->addToggle("level.hitboxes")
           ->setDescription("Show hitboxes while playing")
           ->handleKeybinds()
           ->toggleCallback([](bool v){ g_showHitboxes = v; });
    }

    [[nodiscard]] const char* getId() const override { return "Hitboxes"; }
};

REGISTER_HACK(Hitboxes)

class $modify(HitboxLayerHook, PlayLayer) {
    void updateVisibility(float dt) override {
        PlayLayer::updateVisibility(dt);

        if (!g_showHitboxes) return;

        for (auto obj : this->m_objects) {
            if (!obj) continue;

            auto pos = obj->getPosition();
            auto size = obj->getHitboxSize();

            auto node = cocos2d::CCDrawNode::create();
            node->drawRect(
                cocos2d::CCPoint(pos.x - size.width/2, pos.y - size.height/2),
                cocos2d::CCPoint(pos.x + size.width/2, pos.y + size.height/2),
                cocos2d::ccc4f(1.f, 0.f, 0.f, 0.5f)
            );
            this->addChild(node);
        }
    }
};

}
