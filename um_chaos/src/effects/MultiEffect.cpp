#include "effect.hpp"
#include "util.hpp"

class MultiEffect : public Effect {
public:
    MultiEffect() {
        int count = Rand::Range(2, 6);
        for (int i = 0; i < count; i++)
            Effect::EnableRandom();
    }
};
REGISTER_EFFECT(MultiEffect);
