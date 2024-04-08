#include "effect.hpp"
#include "th18.hpp"

class OpenShop : public Effect {
public:
    virtual bool Update() {
        auto shop = new AbilityShop;
        AbilityShop::Instance = shop;
        memset(shop, 0, sizeof(AbilityShop));

        D3DVECTOR idk = {448.0f, 32.0f, 0.0f};
        shop->Init(&idk);

        return false;
    }
};
REGISTER_EFFECT(OpenShop);
