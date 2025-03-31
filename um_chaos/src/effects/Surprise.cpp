#include "assets.hpp"
#include "effect.hpp"
#include "th18.hpp"

class Surprise : public Effect {
public:
    size_t frames_active = 0;

    HWND overlay = NULL;
    float overlay_x = 0.0f;
    float overlay_y = 0.0f;    

    Surprise() {
        HMONITOR monitor = MonitorFromWindow(Main::Window, MONITOR_DEFAULTTONEAREST);
        MONITORINFO info = {
            .cbSize = sizeof(MONITORINFO)
        };
        GetMonitorInfo(monitor, &info);

        POINT p = {
            .x = (LONG)GameToWindowX(PlayfieldToGameX(192.0f)),
            .y = 0,
        };
        ClientToScreen(Main::Window, &p);

        overlay_x = p.x - 337 * 2;
        overlay_y = info.rcMonitor.bottom;

        overlay = CreateWindowExA(
            WS_EX_TOPMOST | WS_EX_LAYERED | WS_EX_TOOLWINDOW,
            "FollowerMouseClass",
            "FollowerMouse",
            WS_VISIBLE,
            -32000, -32000,
            337 * 4, 256 * 4,
            NULL, NULL, NULL, NULL
        );

        SetForegroundWindow(Main::Window);
        
        HDC dc = CreateCompatibleDC(NULL);
        SelectObject(dc, Assets::Kogasa);
        SIZE size = {
            .cx = 337 * 4,
            .cy = 256 * 4,
        };
        POINT pos = {
            .x = 0,
            .y = 0,
        };
        BLENDFUNCTION blend = {
            .BlendOp = AC_SRC_OVER,
            .BlendFlags = 0,
            .SourceConstantAlpha = 255,
            .AlphaFormat = AC_SRC_ALPHA,
        };
        UpdateLayeredWindow(overlay, NULL, NULL, &size, dc, &pos, 0, &blend, ULW_ALPHA);
        DeleteDC(dc);

        for (int i = 0; i < 54; i++) {
            if (i == 49) // This goes on for too long
                continue;
            SoundManager::Instance.PlaySE(i, 0.0f);
        }
    }

    virtual ~Surprise() {
        DestroyWindow(overlay);
    }

    virtual bool Update() {
        ShowWindow(overlay, SW_SHOWNOACTIVATE);
        UpdateWindow(overlay);
        
        int offset = min(frames_active++ * 128, 1024);
        if (frames_active > 60)
            offset = 1024 - (frames_active - 60) * 32;
        SetWindowPos(overlay, HWND_TOP, overlay_x, overlay_y - offset, 0, 0, SWP_NOSIZE | SWP_NOACTIVATE);

        MSG msg;
        while (PeekMessageA(&msg, overlay, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
        }

        return frames_active < 120;
    }
};
REGISTER_EFFECT(Surprise);
