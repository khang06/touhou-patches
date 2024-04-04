#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class CardNoCooldown : public Effect {
public:
    // Not sure if people will even notice this being active...
    size_t timer = Rand::Range(10 * 60, 5 * 60 * 60);

    virtual bool Update() {
        auto* cur = &AbilityManager::Instance->card_list;
        while (cur) {
            if (cur->entry)
                cur->entry->recharge_timer.cur_float = 0.0f;
            cur = cur->next;
        }

        return --timer != 0;
    }
};
DEFINE_EFFECT(CardNoCooldown);
