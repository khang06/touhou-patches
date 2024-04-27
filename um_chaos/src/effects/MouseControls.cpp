#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

// Hack to make NoVertical work with MouseControls
extern bool g_novertical_enabled;

class MouseControls : public Effect {
public:
    size_t timer = Rand::RangeFrames(10, 2 * 60);
    CodePatches patches;

    MouseControls() {
        patches.AddCall(0x45C0CC, (void*)CalcMoveHook);

        POINT p = {
            .x = (LONG)GameToWindowX(PlayfieldToGameX(Player::Instance->pos_float.x + 192.0f)),
            .y = (LONG)GameToWindowY(PlayfieldToGameY(Player::Instance->pos_float.y))
        };
        ClientToScreen(Main::Window, &p);
        SetCursorPos(p.x, p.y);
    }

    virtual bool Update() {
        return --timer != 0;
    }

    // Not in Update because I still have input latency standards, even for a joke!
    static int __thiscall CalcMoveHook(Player* self) {
        self->CalcMove();

        // Don't try to use the mouse position if the window got minimized
        if (IsIconic(Main::Window))
            return 0;

        POINT p;
        GetCursorPos(&p);
        ScreenToClient(Main::Window, &p);
        float px = GameToPlayfieldX(WindowToGameX(p.x)) - 192.0f;
        float py = GameToPlayfieldY(WindowToGameY(p.y));

        self->pos_float.x = px;
        self->pos_x = px * 128.0f;
        if (!g_novertical_enabled) {
            self->pos_float.y = py;
            self->pos_y = py * 128.0f;
        }

        return 0;
    }
};
REGISTER_EFFECT(MouseControls);
