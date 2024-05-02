#include <Windows.h>
#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class BouncingWindow : public Effect {
public:
    static constexpr int VELOCITY = 2;

    int timer = Rand::RangeFrames(10, 60);
    RECT monitor_bounds;
    int x_vel = VELOCITY;
    int y_vel = VELOCITY;

    BouncingWindow() {
        HMONITOR monitor = MonitorFromWindow(Main::Window, MONITOR_DEFAULTTONEAREST);
        MONITORINFO info = {
            .cbSize = sizeof(MONITORINFO)
        };

        GetMonitorInfo(monitor, &info);
        memcpy(&monitor_bounds, &info.rcMonitor, sizeof(RECT));
    }

    virtual bool Update() {
        // Don't try to move the window if the window got minimized or the game is in fullscreen
        if (!IsIconic(Main::Window) && !Window::IsFullscreen()) {
            RECT window_rect;
            GetWindowRect(Main::Window, &window_rect);

            if (window_rect.left < monitor_bounds.left)
                x_vel = VELOCITY;
            if (window_rect.right > monitor_bounds.right)
                x_vel = -VELOCITY;
            if (window_rect.top < monitor_bounds.top)
                y_vel = VELOCITY;
            if (window_rect.bottom > monitor_bounds.bottom)
                y_vel = -VELOCITY;

            SetWindowPos(Main::Window, NULL, window_rect.left + x_vel, window_rect.top + y_vel, 0, 0, SWP_NOSIZE | SWP_NOREDRAW);
        }
        return --timer > 0;
    }
};
REGISTER_EFFECT(BouncingWindow);
