#include <new>
#include "th18.hpp"
#include "util.hpp"

CodePatches g_patches;

// Kill me
// This was zero's idea and not mine
// https://github.com/Schotsl/Uwuifier
static constexpr const char8_t* FACES[] = {
    u8"(・`ω´・)",
    u8";;w;;",
    u8"OwO",
    u8"UwU",
    u8">w<",
    u8"^w^",
    u8"ÚwÚ",
    u8"^-^",
    u8":3",
    u8"x3",
};
static constexpr const char* EXCLAMATIONS[] = {
    "!?",
    "?!!",
    "?!?1",
    "!!11",
    "?!?!",
};
static constexpr const char* ACTIONS[] = {
    "*blushes*",
    "*whispers to self*",
    "*cries*",
    "*screams*",
    "*sweats*",
    "*twerks*",
    "*runs away*",
    "*screeches*",
    "*walks away*",
    "*sees bulge*",
    "*looks at you*",
    "*notices buldge*",
    "*starts twerking*",
    "*huggles tightly*",
    "*boops your nose*",
};
void uwuify(char* src) {
    // 100% secure
    char temp[2048] = {};
    char* temp_write = temp;

    // I don't feel like dealing with std::regex
    // Hopefully this won't break non-English languages?
    for (char* p = src; *p != '\0'; p++) {
        char upper = *p & 0xDF;
        if (p != src && (*(p - 1) & 0xDF) == 'N' && (upper == 'A' || upper == 'E' || upper == 'I' || /* upper == 'O' || */ upper == 'U')) {
            *temp_write++ = 'Y' | (*p & 0x20);
        } else if (*p == '!') {
            for (auto str = EXCLAMATIONS[Rand::Range(0, _countof(EXCLAMATIONS) - 1)]; *str != '\0'; str++)
                *temp_write++ = *str;
        } else if ((p == src || *(p - 1) == ' ') && (*p & 0x80) == 0) {
            char lower = (upper == 'R' || upper == 'L') ? 'w' : (*p | 0x20);
            if (Rand::NextFloat() <= 0.05f) {
                for (auto str = (char*)FACES[Rand::Range(0, _countof(FACES) - 1)]; *str != '\0'; str++)
                    *temp_write++ = *str;
                *temp_write++ = ' ';
            } else if (Rand::NextFloat() <= 0.075f) {
                for (auto str = ACTIONS[Rand::Range(0, _countof(ACTIONS) - 1)]; *str != '\0'; str++)
                    *temp_write++ = *str;
                *temp_write++ = ' ';
            } else if (Rand::NextFloat() <= 0.01f) {
                int count = Rand::Range(0, 2);
                for (int i = 0; i < count; i++) {
                    *temp_write++ = lower;
                    *temp_write++ = '-';
                }
            }
            *temp_write++ = lower;
        } else if (upper == 'R' || upper == 'L') {
            *temp_write++ = 'W' | (*p & 0x20);
        } else {
            *temp_write++ = *p;
        }
    }

    strncpy(src, temp, 255);
}

extern "C" char* __fastcall uwuify_hook(char* input) {
    input = MsgVM::DecryptString(input);
    uwuify(input);
    return input;
}

extern "C" char* __fastcall aaaaaaaaaa_hook(char* input) {
    input = MsgVM::DecryptString(input);

    char* cur = input;
    while (*cur)
        *cur++ = 'A';

    return input;
}

extern "C" MsgVM* __thiscall msgvm_ctor_hook(MsgVM* self, uint32_t idk) {
    Util::Log("Dialogue started\n");

    auto rand = Rand::Range(1, 10);
    if (rand == 1) {
        // uwuify :3
        g_patches.AddCall(0x43F09C, (void*)uwuify_hook);
        g_patches.AddCall(0x43E9E0, (void*)uwuify_hook);
    } else if (rand == 2) {
        // AAAAAAAAAAAA
        g_patches.AddCall(0x43F09C, (void*)aaaaaaaaaa_hook);
        g_patches.AddCall(0x43E9E0, (void*)aaaaaaaaaa_hook);
    }

    return new (self) MsgVM(idk);
}

extern "C" void __thiscall msgvm_dtor_hook(MsgVM* self) {
    Util::Log("Dialogue ended\n");

    g_patches.Clear();

    self->~MsgVM();
}
