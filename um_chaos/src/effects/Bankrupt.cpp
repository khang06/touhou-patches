#include "effect.hpp"
#include "th18.hpp"

class Bankrupt : public Effect {
public:
    Bankrupt() {
        Globals::Funds = 0;
    }
};
REGISTER_EFFECT(Bankrupt);
