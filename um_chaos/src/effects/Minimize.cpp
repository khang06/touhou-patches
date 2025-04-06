#include <Windows.h>
#include "effect.hpp"
#include "th18.hpp"

class Minimize : public Effect {
public:
    Minimize() {
        PostMessage(Main::Window, WM_SYSCOMMAND, SC_MINIMIZE, 0);
    }

    static bool Allowed() {
        return !Window::IsFullscreen();
    }
};
REGISTER_EFFECT(Minimize);
