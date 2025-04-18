#include <emmintrin.h>
#include <stdint.h>
#include <xmmintrin.h>
#include "commonhooks.hpp"
#include "th18.hpp"
#include "util.hpp"

bool CommonHooks::LeSanae = false;
bool CommonHooks::BulletFade = false;
bool CommonHooks::Spin = false;
bool CommonHooks::CopyingPlayfield = false;
bool CommonHooks::DrawingBullets = false;
int32_t CommonHooks::TitleScreenShake = 0;
float CommonHooks::SpinSin = 0.0f;
float CommonHooks::SpinCos = 1.0f;

extern "C" __thiscall int common_draw_sprite_playfield_hook(AnmManager* self, AnmVM* anm) {
    CommonHooks::CopyingPlayfield = true;
    auto ret = self->DrawSprite(anm);
    CommonHooks::CopyingPlayfield = false;
    return ret;
}

extern "C" __thiscall int common_draw_bullets_hook(BulletManager* self) {
    CommonHooks::DrawingBullets = true;
    auto ret = self->Draw();
    CommonHooks::DrawingBullets = false;
    return ret;
}

extern "C" __thiscall int common_add_vertices_hook(AnmManager* self, ZunVertex* vertices) {
    if (__builtin_expect(CommonHooks::LeSanae && !CommonHooks::CopyingPlayfield, 0)) {
        vertices[0].u = 0.0f;
        vertices[0].v = 0.0f;
        vertices[1].u = 1.0f;
        vertices[1].v = 0.0f;
        vertices[2].u = 0.0f;
        vertices[2].v = 1.0f;
        vertices[3].u = 1.0f;
        vertices[3].v = 1.0f;
    }
    if (__builtin_expect(CommonHooks::TitleScreenShake, 0)) {
        for (int i = 0; i < 4; i++) {
            vertices[i].x += Rand::Range(-CommonHooks::TitleScreenShake, CommonHooks::TitleScreenShake) * Window::Instance.game_scale;
            vertices[i].y += Rand::Range(-CommonHooks::TitleScreenShake, CommonHooks::TitleScreenShake) * Window::Instance.game_scale;
        }
    }
    if (__builtin_expect(CommonHooks::BulletFade && CommonHooks::DrawingBullets, 0)) {
        /*
        float player_x = Player::Instance->pos_float.x + Main::Instance.cameras[3].x + 192.0f + 12.0f;
        float player_y = Player::Instance->pos_float.y + Main::Instance.cameras[3].y + 12.0f;
        for (int i = 0; i < 4; i++) {
            float dist_x = player_x - vertices[i].x;
            float dist_y = player_y - vertices[i].y;
            uint32_t alpha = (vertices[i].color >> 24) * std::min((dist_x * dist_x + dist_y * dist_y) / 8192.0f, 1.0f);
            vertices[i].color = (vertices[i].color & 0xFFFFFF) | (alpha << 24);
        }
        */

        __m128 player_x = _mm_set1_ps(Player::Instance->pos_float.x + Main::Instance.cameras[3].x + 192.0f + 12.0f);
        __m128 player_y = _mm_set1_ps(Player::Instance->pos_float.y + Main::Instance.cameras[3].y + 12.0f);
        __m128 vertices_x = _mm_setr_ps(vertices[0].x, vertices[1].x, vertices[2].x, vertices[3].x);
        __m128 vertices_y = _mm_setr_ps(vertices[0].y, vertices[1].y, vertices[2].y, vertices[3].y);
        __m128i vertices_col = _mm_setr_epi32(vertices[0].color, vertices[1].color, vertices[2].color, vertices[3].color);
        __m128 dist_x = _mm_sub_ps(player_x, vertices_x);
        __m128 dist_y = _mm_sub_ps(player_y, vertices_y);
        __m128 dist_sq = _mm_add_ps(_mm_mul_ps(dist_x, dist_x), _mm_mul_ps(dist_y, dist_y));
        __m128 alpha_mul = _mm_min_ps(_mm_mul_ps(dist_sq, _mm_set1_ps(1.0f / 8192.0f)), _mm_set1_ps(1.0f));
        __m128i alpha = _mm_slli_epi32(_mm_cvtps_epi32(_mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi32(vertices_col, 24)), alpha_mul)), 24);
        __v4su new_col = _mm_or_si128(_mm_and_si128(vertices_col, _mm_set1_epi32(0xFFFFFF)), alpha); // No _mm_blendv_epi8 in SSE2 :(
        
        for (int i = 0; i < 4; i++)
            vertices[i].color = new_col[i];
    }
    if (__builtin_expect(CommonHooks::Spin && !CommonHooks::CopyingPlayfield, 0)) {
        float x_min = vertices[0].x;
        float x_max = vertices[0].x;
        float y_min = vertices[0].y;
        float y_max = vertices[0].y;
        for (int i = 1; i < 4; i++) {
            x_min = std::min(x_min, vertices[i].x);
            x_max = std::max(x_max, vertices[i].x);
            y_min = std::min(y_min, vertices[i].y);
            y_max = std::max(y_max, vertices[i].y);
        }

        float center_x = (x_min + x_max) / 2.0f;
        float center_y = (y_min + y_max) / 2.0f;

        for (int i = 0; i < 4; i++) {
            vertices[i].x -= center_x;
            vertices[i].y -= center_y;

            float temp_x = center_x + vertices[i].x * CommonHooks::SpinCos - vertices[i].y * CommonHooks::SpinSin;
            vertices[i].y = center_y + vertices[i].x * CommonHooks::SpinSin + vertices[i].y * CommonHooks::SpinCos;
            vertices[i].x = temp_x;
        }
    }
    return self->AddVertices(vertices);
}
