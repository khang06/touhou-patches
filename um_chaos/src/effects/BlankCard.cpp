#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class BlankCard : public Effect {
public:
    BlankCard() {
        CardInfo* cards[8] = {};
        int card_count;
        int max_cards = Rand::Range(3, 8);

        AbilityManager::Instance->ClearCards(0);
        memset(AbilityManager::Instance->equipped, 0, sizeof(AbilityManager::equipped));
        AbilityManager::Instance->equipped[17] = 1; // Shanghai Doll is crashy when enabled like this
        for (card_count = 0; card_count < max_cards; card_count++) {
            if (!CardInfo::RandomCard(&cards[card_count], 1, 14, cards, card_count))
                break;
        }
        AbilityManager::Instance->equipped[17] = 0;

        for (int i = 0; i < card_count; i++)
            AbilityManager::Instance->EquipCard(cards[i]->id, 2);
    }
};
REGISTER_EFFECT(BlankCard);
