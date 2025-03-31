#include "effect.hpp"
#include "th18.hpp"

class RandomMusic : public Effect {
public:
    RandomMusic() {
        static constexpr const char* songs[] = {
            "th18_01.wav",
            "th18_03.wav",
            "th18_04.wav",
            "th18_05.wav",
            "th18_06.wav",
            "th18_07.wav",
            "th18_08.wav",
            "th18_09.wav",
            "th18_10.wav",
            "th18_11.wav",
            "th18_12.wav",
            "th18_13.wav",
            "th18_14.wav",
            "th18_15.wav",
            "th18_16.wav",
            "th18_17.wav",
            "th18_18.wav",
            "th128_08.wav",
        };
        SoundManager::Instance.SendMsg(1, 0, songs[Rand::Range(0, _countof(songs) - 1)]);
        //SoundManager::Instance.SendMsg(4, 0, "dummy");
        SoundManager::Instance.SendMsg(2, 0, "dummy");
    }
};
REGISTER_EFFECT(RandomMusic);
