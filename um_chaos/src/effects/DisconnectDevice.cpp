#include <Windows.h>
#include "effect.hpp"
#include "util.hpp"

class DisconnectDevice : public Effect {
public:
    int timer = Rand::RangeEffectTime(0.25f, 0.75f);
    CodePatches patches;

    DisconnectDevice() {
        PlaySoundA("DeviceDisconnect", NULL, SND_ALIAS | SND_ASYNC | SND_NODEFAULT | SND_SYSTEM);

        static constexpr uint8_t patch[] = {0x0F, 0x1F, 0x44, 0x00, 0x00}; // 5-byte nop
        patches.Add(0x462961, (void*)&patch, sizeof(patch));
    }

    virtual ~DisconnectDevice() {
        PlaySoundA("DeviceConnect", NULL, SND_ALIAS | SND_ASYNC | SND_NODEFAULT | SND_SYSTEM);
    }

    virtual bool Update() {
        return --timer > 0;
    }
};
REGISTER_EFFECT(DisconnectDevice);
