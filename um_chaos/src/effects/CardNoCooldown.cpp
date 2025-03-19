#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class CardNoCooldown : public Effect {
public:
    int timer = Rand::RangeEffectTime(10, 60);

    virtual bool Update() {
        auto* cur = &AbilityManager::Instance->card_list;
        while (cur) {
            if (cur->entry)
                cur->entry->recharge_timer.set(0);
            cur = cur->next;
        }

        return --timer > 0;
    }
};
REGISTER_EFFECT(CardNoCooldown);
