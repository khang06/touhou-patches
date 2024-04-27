#include "math.h"
#include "th18.hpp"
#include <cmath>

static int g_selected = 0;
static int g_alpha = 0;
static size_t g_frame_count = 0;

static const char* g_option_names[] = {
    "Min Time Between Effects",
    "Max Time Between Effects",
    "Effect Length Multiplier",
    "Restore Defaults",
    "Exit",
};

static const char* g_option_values[] = {
    "5s",
    "30s",
    "1.0x",
    "",
    "",
};


extern "C" void __thiscall manual_calc_hook(TitleScreen* title) {
    if (!title->transition_state) {
        g_selected = 0;
        g_alpha = 0;
        title->transition_state = 1;
    } else {
        g_alpha = min(g_alpha + 16, 255);
    }
    g_frame_count++;

    if (Input::Pressed & 0x10) {
        if (g_selected == 0)
            g_selected = _countof(g_option_names) - 1;
        else
            g_selected--;
        SoundManager::Instance.PlaySE(10, 0.0f);
    }

    if (Input::Pressed & 0x20) {
        if (g_selected == _countof(g_option_names) - 1)
            g_selected = 0;
        else
            g_selected++;
        SoundManager::Instance.PlaySE(10, 0.0f);
    }

    if (Input::Pressed & 0x1001) {
        title->SwitchMenuState(1);
        SoundManager::Instance.PlaySE(9, 0.0f);
    }
}

extern "C" void __thiscall manual_draw_hook(TitleScreen* title) {
    if (!title->transition_state || title->transition_state == 4)
        return;

    D3DVECTOR title_pos = { 320.0f, 80.0f, 0.0f };
    AsciiManager::Instance->style = 7;
    float time = g_frame_count / 15.0f;
    unsigned red = sinf(time) * 127 + 128;
    unsigned green = sinf(time + 2.0f) * 127 + 128;
    unsigned blue = sinf(time + 4.0f) * 127 + 128;
    AsciiManager::Instance->color = D3DCOLOR_ARGB(g_alpha, red, green, blue);
    AsciiManager::Instance->shadow_color = D3DCOLOR_ARGB(g_alpha, 0x00, 0x00, 0x00);
    AsciiManager::Instance->hor_align = 0;
    AsciiManager::Instance->ver_align = 0;
    AsciiManager::Instance->DrawShadowText(&title_pos, "Chaos Edition Settings");

    D3DVECTOR name_pos = { 150.0f, 125.0f, 0.0f };
    D3DVECTOR val_pos = { 640.0f - 150.0f, 125.0f, 0.0f };
    AsciiManager::Instance->style = 6;
    AsciiManager::Instance->ver_align = 1;
    for (int i = 0; i < _countof(g_option_names); i++) {
        AsciiManager::Instance->color = i == g_selected ? D3DCOLOR_ARGB(g_alpha, 0xFF, 0x80, 0x80) : D3DCOLOR_ARGB(g_alpha, 0xFF, 0xFF, 0xFF);

        AsciiManager::Instance->hor_align = 1;
        AsciiManager::Instance->DrawShadowText(&name_pos, "%s", g_option_names[i]);

        AsciiManager::Instance->hor_align = 2;
        AsciiManager::Instance->DrawShadowText(&val_pos, "%s", g_option_values[i]);

        name_pos.y += 24.0f;
        val_pos.y += 24.0f;
    }
    AsciiManager::Instance->color = 0xFFFFFFFF;
    AsciiManager::Instance->style = 0;
}
