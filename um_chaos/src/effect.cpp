#include "effect.hpp"

size_t Effect::AllCount;
EffectInfo Effect::Infos[Effect::MAX_EFFECTS];
size_t Effect::EnabledCount;
EnabledEffect Effect::Enabled[Effect::MAX_EFFECTS];

void Effect::Enable(size_t id) {
    Util::Log("Enabling %s...\n", Infos[id].name);
    Infos[id].enabled = true;
    Enabled[EnabledCount++] =  {
        .name = Infos[id].name,
        .id = id,
        .frames_active = 0,
        .inner = Infos[id].init(),
    };
}

void Effect::EnableRandom() {
    static size_t choices[Effect::MAX_EFFECTS];
    size_t choices_count = 0;
    for (size_t i = 0; i < Effect::AllCount; i++) {
        if (!Effect::Infos[i].enabled)
            choices[choices_count++] = i;
    }
    if (choices_count)
        Effect::Enable(choices[Rand::Range(0, choices_count - 1)]);
}

void Effect::Disable(size_t idx) {
    Util::Log("Disabling %s...\n", Enabled[idx].name);
    Infos[Enabled[idx].id].enabled = false;
    delete Enabled[idx].inner;
    memmove(&Enabled[idx], &Enabled[idx + 1], (EnabledCount - idx - 1) * sizeof(EnabledEffect));
    EnabledCount--;
}

void Effect::UpdateAll() {
    for (size_t i = 0; i < EnabledCount;) {
        Enabled[i].frames_active++;
        if (!Enabled[i].inner->Update())
            Disable(i);
        else
            i++;
    }
}

void Effect::DrawAll() {
    for (size_t i = 0; i < EnabledCount; i++)
        Enabled[i].inner->Draw();
}
