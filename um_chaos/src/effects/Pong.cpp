#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

#define WRITE_RECT(offset, px, py, width, height)   vertices[offset].x = px - width; \
                                                    vertices[offset].y = py - height; \
                                                    vertices[offset + 1].x = px + width; \
                                                    vertices[offset + 1].y = py - height; \
                                                    vertices[offset + 2].x = px - width; \
                                                    vertices[offset + 2].y = py + height; \
                                                    vertices[offset + 3].x = px + width; \
                                                    vertices[offset + 3].y = py + height;

// Code's not great
class Pong : public Effect {
public:
    static constexpr float OUTLINE = 1.0f;

    static constexpr float BALL_SIZE = 8.0f;
    static constexpr float PADDLE_WIDTH = 48.0f;
    static constexpr float PADDLE_HEIGHT = 4.0f;

    static constexpr float VELOCITY = 1.5f;
    static constexpr float VELOCITY_SQ = VELOCITY * VELOCITY;

    int timer = Rand::RangeEffectTime(10, 60);
    D3DVECTOR ball_pos = {0.0f, 32.0f, 0.0f};
    D3DVECTOR ball_vel;

    Pong() {
        auto& player = Player::Instance->pos_float;
        float angle = atan2f(player.y - ball_pos.y, player.x - ball_pos.x);
        ball_vel.x = cosf(angle) * VELOCITY_SQ;
        ball_vel.y = sinf(angle) * VELOCITY_SQ;
    }

    virtual bool Update() {
        if (ball_pos.x < -192.0f + BALL_SIZE) {
            ball_vel.x = abs(ball_vel.x);
            ball_pos.x = -192.0f + BALL_SIZE;
        }
        if (ball_pos.x > 192.0f - BALL_SIZE) {
            ball_vel.x = -abs(ball_vel.x);
            ball_pos.x = 192.0f - BALL_SIZE;
        }
        if (ball_pos.y < BALL_SIZE) {
            ball_vel.y = abs(ball_vel.y);
            ball_pos.y = BALL_SIZE;
        }
        if (ball_pos.y > 512.0f) { // Intentionally offscreen
            Player::Instance->Kill();
            return false;
        }

        // TODO: This won't account for the player moving too quickly and having the ball clip through the paddle
        auto& player = Player::Instance->pos_float;
        if (abs(player.x - ball_pos.x) < BALL_SIZE + PADDLE_WIDTH && abs(player.y - ball_pos.y + 16.0f) < BALL_SIZE + PADDLE_HEIGHT) {
            float angle = (ball_pos.x - player.x) / 40.0f;
            ball_vel.x = sinf(angle) * VELOCITY_SQ;
            ball_vel.y = -cosf(angle) * VELOCITY_SQ;
            ball_pos.y = player.y + 16.0f - PADDLE_HEIGHT - BALL_SIZE;
        }

        ball_pos.x += ball_vel.x;
        ball_pos.y += ball_vel.y;

        for (auto cur = BulletManager::Instance->list_dummy_head.next; cur != nullptr; cur = cur->next) {
            // TODO: I don't have the bullet hitbox in the struct
            auto bullet = cur->entry;
            if (abs(bullet->position.x - ball_pos.x) < BALL_SIZE && abs(bullet->position.y - ball_pos.y) < BALL_SIZE)
                bullet->Destroy(0);
        }

        return --timer > 0;
    }

    virtual void Draw() {
        float ball_size = BALL_SIZE * Window::Instance.game_scale;
        float ball_inner = (BALL_SIZE - OUTLINE) * Window::Instance.game_scale;

        float paddle_width = PADDLE_WIDTH * Window::Instance.game_scale;
        float paddle_height = PADDLE_HEIGHT * Window::Instance.game_scale;
        float paddle_width_inner = (PADDLE_WIDTH - OUTLINE) * Window::Instance.game_scale;
        float paddle_height_inner = (PADDLE_HEIGHT - OUTLINE) * Window::Instance.game_scale;

        static constexpr uint16_t indices[24] = {
            0, 1, 2,
            1, 2, 3,

            4, 5, 6,
            5, 6, 7,

            8, 9, 10,
            9, 10, 11,

            12, 13, 14,
            13, 14, 15,
        };
        static ZunVertex vertices[16] = {
            {0, 0, 0, 1, 0xFF000000, 0, 0},
            {0, 0, 0, 1, 0xFF000000, 1, 0},
            {0, 0, 0, 1, 0xFF000000, 0, 1},
            {0, 0, 0, 1, 0xFF000000, 1, 1},

            {0, 0, 0, 1, 0xFFFFFFFF, 0, 0},
            {0, 0, 0, 1, 0xFFFFFFFF, 1, 0},
            {0, 0, 0, 1, 0xFFFFFFFF, 0, 1},
            {0, 0, 0, 1, 0xFFFFFFFF, 1, 1},
            
            {0, 0, 0, 1, 0xFF000000, 0, 0},
            {0, 0, 0, 1, 0xFF000000, 1, 0},
            {0, 0, 0, 1, 0xFF000000, 0, 1},
            {0, 0, 0, 1, 0xFF000000, 1, 1},

            {0, 0, 0, 1, 0xFFFFFFFF, 0, 0},
            {0, 0, 0, 1, 0xFFFFFFFF, 1, 0},
            {0, 0, 0, 1, 0xFFFFFFFF, 0, 1},
            {0, 0, 0, 1, 0xFFFFFFFF, 1, 1},
        };

        auto& player = Player::Instance->pos_float;
        float bx = PlayfieldToGameX(ball_pos.x * Main::Instance.screen_anm4->scale_x + 192.0f);
        float by = PlayfieldToGameY((ball_pos.y - 224.0f) * Main::Instance.screen_anm4->scale_y + 224.0f);
        float px = PlayfieldToGameX(player.x * Main::Instance.screen_anm4->scale_x + 192.0f);
        float py = PlayfieldToGameY((player.y - 224.0f + 16.0f) * Main::Instance.screen_anm4->scale_y + 224.0f);
        WRITE_RECT(0, bx, by, ball_size, ball_size);
        WRITE_RECT(4, bx, by, ball_inner, ball_inner);
        WRITE_RECT(8, px, py, paddle_width, paddle_height);
        WRITE_RECT(12, px, py, paddle_width_inner, paddle_height_inner);

        auto d3d9_dev = Main::Instance.d3d9_device;
        DWORD z_enable;
        IDirect3DBaseTexture9* prev_tex = nullptr;
        AnmManager::Instance->FlushSprites();
        d3d9_dev->GetRenderState(D3DRS_ZENABLE, &z_enable);
        d3d9_dev->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
        d3d9_dev->GetTexture(0, &prev_tex);
        d3d9_dev->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);
        d3d9_dev->SetTexture(0, NULL);
        d3d9_dev->DrawIndexedPrimitiveUP(D3DPT_TRIANGLELIST, 0, 24, 8, indices, D3DFMT_INDEX16, vertices, sizeof(ZunVertex));
        d3d9_dev->SetTexture(0, prev_tex);
        d3d9_dev->SetRenderState(D3DRS_ZENABLE, z_enable);
    }
};
REGISTER_EFFECT(Pong);
