#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class BlankCard : public Effect {
public:
    BlankCard() {
        CardInfo* cards[8] = {};
        int card_count;
        int max_cards = Rand::Range(3, 8);
        int equipment_count = 0;

        AbilityManager::Instance->ClearCards(0);
        memset(AbilityManager::Instance->equipped, 0, sizeof(AbilityManager::equipped));
        for (auto& equipment : Player::Instance->equipment) {
            if (equipment.anm_id)
                AnmManager::QueueDeletionByID(equipment.anm_id);
            memset(&equipment, 0, sizeof(equipment));
        }

        for (card_count = 0; card_count < max_cards; card_count++) {
            if (!CardInfo::RandomCard(&cards[card_count], 1, 14, cards, card_count))
                break;
        }

        for (int i = 0; i < card_count; i++)
            AbilityManager::Instance->EquipCard(cards[i]->id, 2);

        auto* cur = AbilityManager::Instance->card_list.next;
        while (cur) {
            if (cur->entry)
                cur->entry->OnLevelUp();
            cur = cur->next;
        }
    }
};
REGISTER_EFFECT(BlankCard);
