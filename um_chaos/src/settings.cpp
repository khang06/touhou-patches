#include <stdio.h>
#include <math.h>
#include <shlwapi.h>
#include "settings.hpp"
#include "th18.hpp"

// Using the non-wide APIs could break stuff for people who put their games in Unicode paths
// I don't want to deal with wide conversion for ASCII-only strings, so this seems like the best solution
extern "C" {
    __declspec(dllimport) DWORD __stdcall GetModuleFileNameU(HMODULE hmodule, LPSTR lpFilename, DWORD nSize);
    __declspec(dllimport) UINT __stdcall GetPrivateProfileIntU(LPCSTR lpAppName, LPCSTR lpKeyName, INT nDefault, LPCSTR lpFileName);
    __declspec(dllimport) UINT __stdcall GetPrivateProfileStringU(LPCSTR lpAppName, LPCSTR lpKeyName, LPCSTR lpDefault, LPSTR lpReturnedString, DWORD nSize, LPCSTR lpFileName);
    __declspec(dllimport) UINT __stdcall WritePrivateProfileStringU(LPCSTR lpAppName, LPCSTR lpKeyName, LPCSTR lpString, LPCSTR lpFileName);
}


#define LOAD_SETTING_INT(x) Settings::x = (decltype(Settings::x))GetPrivateProfileIntU("Settings", #x, (int)Settings::x, config_path)
#define LOAD_SETTING_STR(x) GetPrivateProfileStringU("Settings", #x, Settings::x, Settings::x, sizeof(Settings::x), config_path)

#define SAVE_SETTING_INT(x) snprintf(temp, sizeof(temp) - 1, "%u", Settings::x); WritePrivateProfileStringU("Settings", #x, temp, config_path)
#define SAVE_SETTING_STR(x) WritePrivateProfileStringU("Settings", #x, Settings::x, config_path)

void Settings::Load() {
    Settings::LoadEffectDefaults();
    Settings::LoadTwitchDefaults();

    char config_path[1024] = {};
	if (!GetModuleFileNameU(NULL, config_path, MAX_PATH))
		return;
	PathRemoveFileSpecA(config_path); // Using the non-Unicode APIs for these *should* be fine...
	PathAppendA(config_path, "\\chaos.ini");

    LOAD_SETTING_INT(RandomEnabled);
    LOAD_SETTING_INT(MinRandomTime);
    LOAD_SETTING_INT(MaxRandomTime);
    LOAD_SETTING_INT(EffectTimeMultiplier);

    LOAD_SETTING_STR(TwitchUsername);
    LOAD_SETTING_INT(VotingEnabled);
}

void Settings::Save() {
    char temp[128] = {};
    char config_path[1024] = {};
	if (!GetModuleFileNameU(NULL, config_path, MAX_PATH))
		return;
	PathRemoveFileSpecA(config_path);
	PathAppendA(config_path, "\\chaos.ini");

    SAVE_SETTING_INT(RandomEnabled);
    SAVE_SETTING_INT(MinRandomTime);
    SAVE_SETTING_INT(MaxRandomTime);
    SAVE_SETTING_INT(EffectTimeMultiplier);

    SAVE_SETTING_STR(TwitchUsername);
    SAVE_SETTING_INT(VotingEnabled);
}

void Settings::LoadEffectDefaults() {
    Settings::RandomEnabled = true;
    Settings::MinRandomTime = 5;
    Settings::MaxRandomTime = 30;
    Settings::EffectTimeMultiplier = 10;
}

void Settings::LoadTwitchDefaults() {
    memset(Settings::TwitchUsername, 0, sizeof(Settings::TwitchUsername));
    Settings::VotingEnabled = false;
}

bool Settings::RandomEnabled;
uint32_t Settings::MinRandomTime;
uint32_t Settings::MaxRandomTime;
uint32_t Settings::EffectTimeMultiplier;
char Settings::TwitchUsername[26];
bool Settings::VotingEnabled;

struct SettingsPage;

static SettingsPage* g_cur_page = nullptr;
static size_t g_button_count = 0;
static int g_selected = 0;
static int g_alpha = 0;
static size_t g_frame_count = 0;
static bool g_take_over_input = false;
static BYTE g_cur_kbd[256] = {};
static BYTE g_last_kbd[256] = {};

struct SettingsButton {
    const char* label;
    char value[128];
    void (*update_value)(TitleScreen*, SettingsButton*) = [](TitleScreen*, SettingsButton*) {};
    void (*input_handler)(TitleScreen*, SettingsButton*, uint32_t) = [](TitleScreen*, SettingsButton*, uint32_t) {};
};

struct SettingsPage {
    const char* title;
    SettingsButton buttons[16];
};

static void change_page(TitleScreen* title, SettingsPage* target) {
    g_selected = 0;
    g_cur_page = target;
    for (g_button_count = 0; g_button_count < _countof(target->buttons); g_button_count++) {
        auto& button = target->buttons[g_button_count];
        if (button.label == nullptr)
            break;
        button.update_value(title, &button);
    }
}

extern SettingsPage g_effect_page;
extern SettingsPage g_twitch_page;
SettingsPage g_main_page = {
    .title = "Chaos Edition Settings",
    .buttons = {
        {
            .label = "Effect Settings",
            .input_handler = [](TitleScreen* title, SettingsButton*, uint32_t input) {
                if (input & (INPUT_SHOOT | INPUT_ENTER)) {
                    change_page(title, &g_effect_page);
                    SoundManager::Instance.PlaySE(7, 0.0f);
                }
            }
        },
        {
            .label = "Twitch Settings",
            .input_handler = [](TitleScreen* title, SettingsButton*, uint32_t input) {
                if (input & (INPUT_SHOOT | INPUT_ENTER)) {
                    change_page(title, &g_twitch_page);
                    SoundManager::Instance.PlaySE(7, 0.0f);
                }
            }
        },
        {
            .label = "Back",
            .input_handler = [](TitleScreen* title, SettingsButton*, uint32_t input) {
                if (input & (INPUT_SHOOT | INPUT_BOMB | INPUT_ENTER)) {
                    Settings::Save();
                    title->SwitchMenuState(1);
                    SoundManager::Instance.PlaySE(9, 0.0f);
                }
            }
        }
    },
};

SettingsPage g_effect_page = {
    .title = "Effect Settings",
    .buttons = {
        {
            .label = "Random Effects",
            .update_value = [](TitleScreen*, SettingsButton* button) {
                strcpy(button->value, Settings::RandomEnabled ? "ON" : "OFF");
            },
            .input_handler = [](TitleScreen* title, SettingsButton* button, uint32_t input) {
                if (input & (INPUT_SHOOT | INPUT_LEFT | INPUT_RIGHT | INPUT_ENTER)) {
                    Settings::RandomEnabled = !Settings::RandomEnabled;
                    button->update_value(title, button);
                    SoundManager::Instance.PlaySE(1, 0.0f);
                }
            }
        },
        {
            .label = "Min Time Between Effects",
            .update_value = [](TitleScreen*, SettingsButton* button) {
                snprintf(button->value, sizeof(button->value) - 1, "%us", Settings::MinRandomTime);
            },
            .input_handler = [](TitleScreen* title, SettingsButton* button, uint32_t input) {
                if (input & INPUT_LEFT && Settings::MinRandomTime != 0) {
                    Settings::MinRandomTime--;
                    button->update_value(title, button);
                    SoundManager::Instance.PlaySE(1, 0.0f);
                }
                if (input & INPUT_RIGHT && Settings::MinRandomTime < Settings::MaxRandomTime) {
                    Settings::MinRandomTime++;
                    button->update_value(title, button);
                    SoundManager::Instance.PlaySE(1, 0.0f);
                }
            }
        },
        {
            .label = "Max Time Between Effects",
            .update_value = [](TitleScreen*, SettingsButton* button) {
                snprintf(button->value, sizeof(button->value) - 1, "%us", Settings::MaxRandomTime);
            },
            .input_handler = [](TitleScreen* title, SettingsButton* button, uint32_t input) {
                if (input & INPUT_LEFT && Settings::MaxRandomTime > Settings::MinRandomTime) {
                    Settings::MaxRandomTime--;
                    button->update_value(title, button);
                    SoundManager::Instance.PlaySE(1, 0.0f);
                }
                if (input & INPUT_RIGHT && Settings::MaxRandomTime < UINT32_MAX) {
                    Settings::MaxRandomTime++;
                    button->update_value(title, button);
                    SoundManager::Instance.PlaySE(1, 0.0f);
                }
            }
        },
        {
            .label = "Effect Length Multiplier",
            .update_value = [](TitleScreen*, SettingsButton* button) {
                snprintf(button->value, sizeof(button->value) - 1, "%.1fx", Settings::EffectTimeMultiplier / 10.0f);
            },
            .input_handler = [](TitleScreen* title, SettingsButton* button, uint32_t input) {
                if (input & INPUT_LEFT && Settings::EffectTimeMultiplier > 0) {
                    Settings::EffectTimeMultiplier--;
                    button->update_value(title, button);
                    SoundManager::Instance.PlaySE(1, 0.0f);
                }
                if (input & INPUT_RIGHT && Settings::EffectTimeMultiplier < (1 << 23) - 1) {
                    Settings::EffectTimeMultiplier++;
                    button->update_value(title, button);
                    SoundManager::Instance.PlaySE(1, 0.0f);
                }
            }
        },
        {
            .label = ""
        },
        {
            .label = "Restore Defaults",
            .input_handler = [](TitleScreen* title, SettingsButton*, uint32_t input) {
                if (input & (INPUT_SHOOT | INPUT_BOMB | INPUT_ENTER)) {
                    Settings::LoadEffectDefaults();
                    for (size_t i = 0; i < g_button_count; i++)
                        g_cur_page->buttons[i].update_value(title, &g_cur_page->buttons[i]);
                    SoundManager::Instance.PlaySE(7, 0.0f);
                }
            }
        },
        {
            .label = "Back",
            .input_handler = [](TitleScreen* title, SettingsButton*, uint32_t input) {
                if (input & (INPUT_SHOOT | INPUT_BOMB | INPUT_ENTER)) {
                    change_page(title, &g_main_page);
                    SoundManager::Instance.PlaySE(9, 0.0f);
                }
            }
        }
    }
};

static int g_back_repeat = 0;
static inline bool key_pressed(size_t idx) {
    return (g_cur_kbd[idx] & (g_cur_kbd[idx] ^ g_last_kbd[idx])) & 0x80;
}

SettingsPage g_twitch_page = {
    .title = "Twitch Settings",
    .buttons = {
        {
            .label = "Channel Username",
            .update_value = [](TitleScreen*, SettingsButton* button) {
                strncpy(button->value, Settings::TwitchUsername, sizeof(button->value) - 1);
            },
            .input_handler = [](TitleScreen* title, SettingsButton* button, uint32_t input) {
                if (g_take_over_input) {
                    memcpy(g_last_kbd, g_cur_kbd, 256);
                    GetKeyboardState(g_cur_kbd);

                    bool back_repeat_tick = false;
                    if (g_cur_kbd[VK_BACK] & 0x80) {
                        if (++g_back_repeat >= 26) {
                            back_repeat_tick = true;
                            g_back_repeat -= 4;
                        }
                    } else {
                        g_back_repeat = 0;
                    }

                    size_t value_len = strlen(Settings::TwitchUsername);
                    if ((back_repeat_tick || key_pressed(VK_BACK)) && value_len) {
                        Settings::TwitchUsername[value_len - 1] = '\0';
                        value_len--;
                        SoundManager::Instance.PlaySE(1, 0.0f);
                        button->update_value(title, button);
                    }

                    constexpr int VALID_KEYS[] = {
                        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                        VK_OEM_MINUS,
                    };
                    for (int key : VALID_KEYS) {
                        if (key_pressed(key) && Settings::TwitchUsername[sizeof(Settings::TwitchUsername) - 2] == '\0') {
                            if (key == VK_OEM_MINUS) {
                                if (g_cur_kbd[VK_SHIFT] & 0x80) {
                                    Settings::TwitchUsername[value_len] = '_';
                                    SoundManager::Instance.PlaySE(1, 0.0f);
                                }
                            } else if (key >= 'A' && key <= 'Z') {
                                Settings::TwitchUsername[value_len] = (g_cur_kbd[VK_SHIFT] & 0x80) ? key : (key | 0x20);
                                SoundManager::Instance.PlaySE(1, 0.0f);
                            } else {
                                Settings::TwitchUsername[value_len] = key;
                                SoundManager::Instance.PlaySE(1, 0.0f);
                            }
                            button->update_value(title, button);
                        }
                    }

                    if (key_pressed(VK_RETURN) || key_pressed(VK_ESCAPE)) {
                        g_take_over_input = false;
                        SoundManager::Instance.PlaySE(7, 0.0f);
                    }
                } else if (input & (INPUT_SHOOT | INPUT_ENTER)) {
                    g_take_over_input = true;
                    GetKeyboardState(g_cur_kbd);
                    memcpy(g_last_kbd, g_cur_kbd, 256);
                    SoundManager::Instance.PlaySE(1, 0.0f);
                }
            }
        },
        {
            .label = "Effect Voting",
            .update_value = [](TitleScreen*, SettingsButton* button) {
                strcpy(button->value, Settings::VotingEnabled ? "ON" : "OFF");
            },
            .input_handler = [](TitleScreen* title, SettingsButton* button, uint32_t input) {
                if (input & (INPUT_SHOOT | INPUT_LEFT | INPUT_RIGHT | INPUT_ENTER)) {
                    Settings::VotingEnabled = !Settings::VotingEnabled;
                    button->update_value(title, button);
                    SoundManager::Instance.PlaySE(1, 0.0f);
                }
            }
        },
        {
            .label = ""
        },
        {
            .label = "Restore Defaults",
            .input_handler = [](TitleScreen* title, SettingsButton*, uint32_t input) {
                if (input & (INPUT_SHOOT | INPUT_BOMB | INPUT_ENTER)) {
                    Settings::LoadTwitchDefaults();
                    for (size_t i = 0; i < g_button_count; i++)
                        g_cur_page->buttons[i].update_value(title, &g_cur_page->buttons[i]);
                    SoundManager::Instance.PlaySE(7, 0.0f);
                }
            }
        },
        {
            .label = "Back",
            .input_handler = [](TitleScreen* title, SettingsButton*, uint32_t input) {
                if (input & (INPUT_SHOOT | INPUT_BOMB | INPUT_ENTER)) {
                    change_page(title, &g_main_page);
                    SoundManager::Instance.PlaySE(9, 0.0f);
                }
            }
        }
    }
};

extern "C" void __thiscall manual_calc_hook(TitleScreen* title) {
    if (!title->transition_state) {
        change_page(title, &g_main_page);
        g_alpha = 0;
        title->transition_state = 1;
    } else {
        g_alpha = min(g_alpha + 16, 255);
    }
    g_frame_count++;

    uint32_t pressed = Input::Pressed | Input::Repeat;

    if (pressed & INPUT_UP && !g_take_over_input) {
        do  {
            if (g_selected == 0)
                g_selected = g_button_count - 1;
            else
                g_selected--;
        } while (g_cur_page->buttons[g_selected].label[0] == '\0');
        SoundManager::Instance.PlaySE(10, 0.0f);
    }

    if (pressed & INPUT_DOWN && !g_take_over_input) {
        do {
            if (g_selected == g_button_count - 1)
                g_selected = 0;
            else
                g_selected++;
        } while (g_cur_page->buttons[g_selected].label[0] == '\0');
        SoundManager::Instance.PlaySE(10, 0.0f);
    }

    auto& button = g_cur_page->buttons[g_selected];
    if (pressed & ~(INPUT_UP | INPUT_DOWN) || g_take_over_input)
        button.input_handler(title, &button, pressed & ~(INPUT_UP | INPUT_DOWN));

    if (pressed & INPUT_BOMB && !g_take_over_input) {
        g_selected = g_button_count - 1;
        SoundManager::Instance.PlaySE(9, 0.0f);
    }
}

extern "C" void __thiscall manual_draw_hook(TitleScreen* title) {
    if (!title->transition_state || title->transition_state == 4 || !g_cur_page)
        return;

    constexpr D3DVECTOR title_pos = { 320.0f, 80.0f, 0.0f };
    AsciiManager::Instance->style = 7;
    float time = g_frame_count / 15.0f;
    unsigned red = sinf(time) * 127 + 128;
    unsigned green = sinf(time + 2.0f) * 127 + 128;
    unsigned blue = sinf(time + 4.0f) * 127 + 128;
    AsciiManager::Instance->color = D3DCOLOR_ARGB(g_alpha, red, green, blue);
    AsciiManager::Instance->shadow_color = D3DCOLOR_ARGB(g_alpha, 0x00, 0x00, 0x00);
    AsciiManager::Instance->hor_align = 0;
    AsciiManager::Instance->ver_align = 0;
    AsciiManager::Instance->DrawShadowText(&title_pos, "%s", g_cur_page->title);

    D3DVECTOR name_pos = { 125.0f, 125.0f, 0.0f };
    D3DVECTOR val_pos = { 640.0f - 125.0f, 125.0f, 0.0f };
    AsciiManager::Instance->style = 6;
    AsciiManager::Instance->ver_align = 1;
    for (int i = 0; i < g_button_count; i++) {
        AsciiManager::Instance->color = i == g_selected ?
                                            (g_take_over_input ? D3DCOLOR_ARGB(g_alpha, 0xFF, 0x80, 0x00) : D3DCOLOR_ARGB(g_alpha, 0xFF, 0x80, 0x80)) :
                                            D3DCOLOR_ARGB(g_alpha, 0xFF, 0xFF, 0xFF);

        AsciiManager::Instance->hor_align = 1;
        AsciiManager::Instance->DrawShadowText(&name_pos, "%s", g_cur_page->buttons[i].label);

        AsciiManager::Instance->hor_align = 2;
        AsciiManager::Instance->DrawShadowText(&val_pos, "%s", g_cur_page->buttons[i].value);

        name_pos.y += 24.0f;
        val_pos.y += 24.0f;
    }
    AsciiManager::Instance->color = 0xFFFFFFFF;
    AsciiManager::Instance->style = 0;
}
