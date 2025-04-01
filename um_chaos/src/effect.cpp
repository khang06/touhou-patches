#include "effect.hpp"
#include "util.hpp"

size_t Effect::AllCount;
EffectInfo Effect::Infos[Effect::MAX_EFFECTS];
size_t Effect::EnabledCount;
EnabledEffect Effect::Enabled[Effect::MAX_EFFECTS];
size_t Effect::PossibleChoices[Effect::MAX_EFFECTS];

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
    size_t choices_count = Effect::UpdatePossibleChoices();
    if (choices_count)
        Effect::Enable(Effect::PossibleChoices[Rand::Range(0, choices_count - 1)]);
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

bool Effect::VoteChoices(size_t *vote_choices, size_t vote_count) {
    size_t choices_count = Effect::UpdatePossibleChoices();
    if (choices_count < vote_count)
        return false;

    for (size_t i = choices_count; i > 1; i--)
        std::swap(Effect::PossibleChoices[i - 1], Effect::PossibleChoices[Rand::Range(0, choices_count - 1)]);
    for (size_t i = 0; i < vote_count; i++)
        Effect::Infos[Effect::PossibleChoices[i]].vote_choice = true;
    memcpy(vote_choices, Effect::PossibleChoices, vote_count * sizeof(size_t));
    return true;
}

size_t Effect::UpdatePossibleChoices() {
    Util::Log("Updating possible choices...\n");
    size_t choices_count = 0;
    for (size_t i = 0; i < Effect::AllCount; i++) {
        auto& effect = Effect::Infos[i];
        if (effect.enabled) {
            Util::Log("Skipping %s because it's already enabled\n", effect.name);
            continue;
        }
        if (effect.vote_choice) {
            Util::Log("Skipping %s because it's a vote choice\n", effect.name);
            continue;
        }
        if (effect.allowed && !effect.allowed()) {
            Util::Log("Skipping %s because it doesn't want to be enabled\n", effect.name);
            continue;
        }
        Effect::PossibleChoices[choices_count++] = i;
    }
    for (int i = 0; i < choices_count - 2; i++) {
        int j = Rand::Range(i, choices_count - 1 - 2);
        std::swap(Effect::PossibleChoices[i], Effect::PossibleChoices[j]);
    }
    return choices_count;
}
