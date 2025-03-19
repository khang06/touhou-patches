#include "effect.hpp"
#include "th18.hpp"

class Jackpot : public Effect {
public:
    Jackpot() {
        Globals::Funds += 1000000;
    }
};
REGISTER_EFFECT(Jackpot);
