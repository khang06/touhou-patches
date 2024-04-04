#include "effect.hpp"

size_t Effect::AllCount;
EffectInfo Effect::Infos[Effect::MAX_EFFECTS];
size_t Effect::EnabledCount;
EnabledEffect Effect::Enabled[Effect::MAX_EFFECTS];
