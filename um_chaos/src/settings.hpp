#pragma once

#include <stdint.h>

class Settings {
public:
    static void Load();
    static void Save();

    static void LoadEffectDefaults();
    static void LoadTwitchDefaults();
    static void LoadDebugDefaults();

    static bool RandomEnabled;
    static uint32_t MinRandomTime;
    static uint32_t MaxRandomTime;
    static uint32_t EffectTimeMultiplier;

    static bool TwitchEnabled;
    static char TwitchUsername[26]; // Twitch usernames are 25 characters max
    static bool VotingEnabled;
    static uint32_t VoteDuration;
    static uint32_t MinVoteTime;
    static uint32_t MaxVoteTime;

    static bool DebugConsole;
    static bool MultiVote;
};

