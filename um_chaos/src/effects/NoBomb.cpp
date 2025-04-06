#include "effect.hpp"
#include "util.hpp"

class NoBomb : public Effect {
public:
    int timer = Rand::RangeEffectTime(10, 60);
    CodePatches patches;
    static AnmVM* disable_vm;

    NoBomb() {
        static constexpr uint8_t patch[] = {0x33, 0xC0, 0xC3}; // xor eax, eax; ret
        patches.Add(0x420420, (void*)&patch, sizeof(patch));

        if (disable_vm)
            disable_vm->pending_interrupt = 1;
    }

    virtual ~NoBomb() {
        if (disable_vm)
            disable_vm->pending_interrupt = 2;
    }

    virtual bool Update() {
        return --timer > 0;
    }
};
REGISTER_EFFECT(NoBomb);

AnmVM* NoBomb::disable_vm = nullptr;

extern "C" Gui* Gui_Create_hook() {
    Gui* ret = Gui::Create();

    uint32_t id;
    auto anm = AnmManager::Instance->Preload(18, "chaos.anm");
    NoBomb::disable_vm = AnmManager::AllocateVM();
    anm->MakeVM(NoBomb::disable_vm, 6);
    AnmManager::AddToUIBack(&id, NoBomb::disable_vm);

    return ret;
}

extern "C" void __thiscall Gui_dtor_hook(Gui* self) {
    self->~Gui();
    AnmVM::QueueDeletion(NoBomb::disable_vm);
    NoBomb::disable_vm = nullptr;
}
