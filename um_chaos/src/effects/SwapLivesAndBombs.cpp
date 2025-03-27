#include "effect.hpp"
#include "th18.hpp"

class SwapLivesAndBombs : public Effect {
public:
    SwapLivesAndBombs() {
        std::swap(Globals::Bombs, Globals::Lives);
        std::swap(Globals::BombPieces, Globals::LifePieces);

        auto gui = Gui::Instance;
        gui->UpdateLives(Globals::Lives, Globals::LifePieces, Globals::MaxLives);
        gui->UpdateBombs(Globals::Bombs, Globals::BombPieces, Globals::MaxBombs);
    }
};
REGISTER_EFFECT(SwapLivesAndBombs);
