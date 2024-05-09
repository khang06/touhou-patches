#include <d3d9.h>
#include "assets.hpp"
#include "commonhooks.hpp"
#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class LeSanae : public Effect {
public:
    int timer = Rand::RangeFrames(10, 2 * 60);

    LeSanae() {
        CommonHooks::LeSanae = true;

        if (Assets::LeSanaeIcon) {
            SendMessageA(Main::Window, WM_SETICON, ICON_SMALL, (LPARAM)Assets::LeSanaeIcon);
            SendMessageA(Main::Window, WM_SETICON, ICON_BIG, (LPARAM)Assets::LeSanaeIcon);
        }
    }

    virtual ~LeSanae() {
        CommonHooks::LeSanae = false;

        if (Assets::GameIcon) {
            SendMessageA(Main::Window, WM_SETICON, ICON_SMALL, (LPARAM)Assets::GameIcon);
            SendMessageA(Main::Window, WM_SETICON, ICON_BIG, (LPARAM)Assets::GameIcon);
        }
    }

    virtual bool Update() {
        return --timer > 0;
    }
};
REGISTER_EFFECT(LeSanae);

extern "C" __stdcall HRESULT lesanae_set_texture_hook(IDirect3DDevice9* self, DWORD stage, IDirect3DBaseTexture9* tex) {
    return self->SetTexture(0, (!CommonHooks::LeSanae || CommonHooks::CopyingPlayfield) ? tex : Assets::LeSanae);
}
