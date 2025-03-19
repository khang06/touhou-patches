#include "effect.hpp"

class ClearEffects : public Effect {
public:
    ClearEffects() {
        while (Effect::EnabledCount != 0)
            Effect::Disable(0);
    }
};
REGISTER_EFFECT(ClearEffects);
