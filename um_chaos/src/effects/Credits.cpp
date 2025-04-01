#include <d3d9.h>
#include "effect.hpp"
#include "util.hpp"

struct CreditsString {
    float x_pos;
    float y_pos;
    float width;
    float speed;
    float scale;
    const char* str;
};

class Credits : public Effect {
public:
    int timer = Rand::RangeEffectTime(10, 60);
    int next_credit_time = 0;
    std::vector<CreditsString> strings;

    virtual bool Update() {
        if (timer > 0 && next_credit_time-- <= 0) {
            next_credit_time = Rand::Range(5, 30);

            const char* credit = CREDITS[Rand::Range(0, CREDITS_COUNT - 1)];
            float scale = Rand::NextFloat() * 4.0f + 1.0f;
            strings.emplace_back(
                640.0f,
                Rand::NextFloat() * 480.0f,
                strlen(credit) * 6.0f * scale,
                Rand::NextFloat() * 4.0f + 0.5f,
                scale,
                credit
            );
        }
        
        for (auto& str : strings)
            str.x_pos -= str.speed;
        std::erase_if(strings, [](const CreditsString& str) { return str.x_pos + str.width < 0; });

        return --timer > 0 || !strings.empty();
    }
    
    virtual void Draw() {
        AsciiManager::Instance->color = D3DCOLOR_ARGB(0xFF, 0xFF, 0xFF, 0xFF);
        AsciiManager::Instance->style = 1;
        AsciiManager::Instance->ver_align = 0;
        AsciiManager::Instance->hor_align = 1;
        for (const auto& str : strings) {
            D3DVECTOR pos = {str.x_pos, str.y_pos, 0.0f};
            AsciiManager::Instance->scale_x = str.scale;
            AsciiManager::Instance->scale_y = str.scale;
            AsciiManager::Instance->DrawShadowText(&pos, "%s", str.str);
        }
        AsciiManager::Instance->scale_x = 1.0f;
        AsciiManager::Instance->scale_y = 1.0f;
    }
};
REGISTER_EFFECT(Credits);
