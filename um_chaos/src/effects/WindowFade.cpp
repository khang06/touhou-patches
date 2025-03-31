#include <Windows.h>
#include "effect.hpp"
#include "th18.hpp"

class WindowFade : public Effect {
public:
    int timer = 30 * 60;

    WindowFade() {
        SetWindowLongA(Main::Window, GWL_EXSTYLE, GetWindowLongA(Main::Window, GWL_EXSTYLE) | WS_EX_LAYERED);
    }

    virtual bool Update() {
        SetLayeredWindowAttributes(Main::Window, 0, timer >> 3, LWA_ALPHA);
        return --timer > 0;
    }

    virtual ~WindowFade() {
        SetWindowLongA(Main::Window, GWL_EXSTYLE, GetWindowLongA(Main::Window, GWL_EXSTYLE) & ~WS_EX_LAYERED);
    }

    static bool Allowed() {
        return !Window::IsFullscreen();
    }
};
REGISTER_EFFECT(WindowFade);
