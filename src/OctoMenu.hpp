#pragma once

#include "globals.hpp"

namespace octo::menu {

class OctoMenu {
public:
    static OctoMenu& get() {
        static OctoMenu instance;
        return instance;
    }

    void render();
    bool isVisible() const { return m_visible; }
    void toggle() { m_visible = !m_visible; }

private:
    OctoMenu() = default;
    ~OctoMenu() = default;
    OctoMenu(const OctoMenu&) = delete;
    OctoMenu& operator=(const OctoMenu&) = delete;

    bool m_visible = false;
};

void initMenuHooks();

} // namespace octo::menu
