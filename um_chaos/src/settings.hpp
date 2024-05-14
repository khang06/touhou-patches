#pragma once

#include <stdint.h>

class Settings {
public:
    static void Load();
    static void Save();
    static void LoadEffectDefaults();
    static void LoadTwitchDefaults();

    static bool RandomEnabled;
    static uint32_t MinRandomTime;
    static uint32_t MaxRandomTime;
    static uint32_t EffectTimeMultiplier;

    static char TwitchUsername[26]; // Twitch usernames are 25 characters max
    static bool VotingEnabled;
};

