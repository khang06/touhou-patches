#include <Windows.h>
#include "effect.hpp"
#include "th18.hpp"

class Minimize : public Effect {
public:
    virtual bool Update() {
        PostMessage(Main::Window, WM_SYSCOMMAND, SC_MINIMIZE, 0);
        return false;
    }
};
REGISTER_EFFECT(Minimize);
