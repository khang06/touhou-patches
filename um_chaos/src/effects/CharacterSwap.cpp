#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"
#include <cstdint>

extern uint32_t sht_on_init[];
extern uint32_t sht_on_calc[];
extern uint32_t sht_on_draw[];
extern uint32_t sht_on_hit[];

class CharacterSwap : public Effect {
public:
    int timer = Rand::RangeEffectTime(10, 60);
    CodePatches patches;
    static int old_char_id;
    static ShtFile* orig_sht;
    static ShtFile* new_sht;

    static void LoadNewSht(int id) {
        static constexpr const char* sht_files[] = {"pl00.sht", "pl01.sht", "pl02.sht", "pl03.sht"};
        new_sht = (ShtFile*)GameUtil::LoadFile(sht_files[id], nullptr, 0);

        for (int i = 0; i < new_sht->sht_off_cnt; i++) {
            new_sht->sht_off[i] += (uint32_t)new_sht + 0x180;

            auto sht_arr = (ShtShooter*)new_sht->sht_off[i];
            while (sht_arr->fire_rate >= 0) {
                sht_arr->on_init = sht_on_init[sht_arr->on_init];
                sht_arr->on_calc = sht_on_calc[sht_arr->on_calc];
                sht_arr->on_draw = sht_on_draw[sht_arr->on_draw];
                sht_arr->on_hit = sht_on_hit[sht_arr->on_hit];
                sht_arr++;
            }
        }
    }

    static void ApplySht(ShtFile* sht) {
        auto player = Player::Instance;
        player->sht_file = sht;
        player->move_speed = sht->player_data[0] * 128.0f;
        player->move_speed_focused = sht->player_data[1] * 128.0f;
        player->diagonal_move_speed = sht->player_data[2] * 128.0f;
        player->diagonal_move_speed_focused = sht->player_data[3] * 128.0f;

        for (size_t i = 0; i < _countof(player->options); i++)
            player->options[i].calc = nullptr;
        player->HandlePowerUp();
    }

    static void ApplyAnm(int id) {
        auto anm = AnmManager::Instance->Preload(id == old_char_id ? 9 : (20 + id), nullptr);

        auto player = Player::Instance;
        player->main_anm = anm;
        player->option_anm = anm;

        player->anm_vm.~AnmVM();
        anm->MakeVM(&player->anm_vm, 0);
    }

    static int __thiscall PlayerInitHook(Player* self) {
        int new_char = Globals::Character;
        Globals::Character = old_char_id;
        self->Initialize();
        Globals::Character = new_char;
        ApplyAnm(Globals::Character);

        return 0;
    }

    static void __thiscall AnmDeletionHook(AnmManager* self, AnmLoaded* loaded) {
        self->QueueDeletionForLoaded(loaded);
        for (int i = 0; i < 4; i++)
            self->QueueDeletionForLoaded(self->preloaded[20 + i]);
    }

    CharacterSwap() {
        auto player = Player::Instance;
        orig_sht = player->sht_file;

        old_char_id = Globals::Character;

        // Kinda sucks
        while (true) {
            int new_char = Rand::Range(0, 3);
            if (new_char != old_char_id) {
                Globals::Character = new_char;
                break;
            }
        }

        static constexpr uint8_t nop6[] = {0x66, 0x0F, 0x1F, 0x44, 0x00, 0x00};
        patches.Add(0x45D853, (void*)&nop6, sizeof(nop6));
        ApplyAnm(Globals::Character);
        LoadNewSht(Globals::Character);
        ApplySht(new_sht);
        patches.Clear();

        patches.AddCall(0x45AFF5, (void*)PlayerInitHook);
        patches.AddCall(0x45B108, (void*)AnmDeletionHook);
    }

    virtual ~CharacterSwap() {
        static constexpr uint8_t nop6[] = {0x66, 0x0F, 0x1F, 0x44, 0x00, 0x00};
        patches.Add(0x45D853, (void*)&nop6, sizeof(nop6));
        Globals::Character = old_char_id;
        ApplyAnm(old_char_id);
        ApplySht(orig_sht);
        free(new_sht);
    }

    virtual bool Update() {
        return --timer > 0;
    }
};
REGISTER_EFFECT(CharacterSwap);

int CharacterSwap::old_char_id;
ShtFile* CharacterSwap::orig_sht;
ShtFile* CharacterSwap::new_sht;
