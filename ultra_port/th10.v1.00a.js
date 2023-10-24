{
    codecaves: {
        double_bullet_count: {
            access: "rx",
            //code: "E8[0x44FDB0] D1E0 E9[0x410482]",
            code: "E8[0x44FDB0] C1E002 E9[0x410482]",
        },
        double_bullet_count_difficulty_1: {
            access: "rx",
            code: "E8[0x44FDB0] 8BC8 D1E9 03C1 83E101 7401 40 E9[0x410585]",
        },
        double_bullet_count_difficulty_2: {
            access: "rx",
            code: "E8[0x44FDB0] 8BC8 D1E9 03C1 E9[0x4105C3]",
        },
        patch_ecl_time_sub_difficulty: {
            access: "rx",
            code: "E8[0x412A00] 8BC8 C1E902 2BC1 C3",
        },
        no_idea_what_this_is: {
            access: "rx",
            code: "F605A04C470010 7403 33C0 C3 A110784700 83785C00 7506 B801000000 C3 A16C4C4700 C3",
        }
    },
    binhacks: {
        double_bullet_count_jmp: {
            addr: "0x41047D",
            code: "E9[codecave:double_bullet_count]",
        },
        double_bullet_count_difficulty_1_jmp: {
            addr: "0x410580",
            code: "E9[codecave:double_bullet_count_difficulty_1]",
        },
        double_bullet_count_difficulty_2_jmp: {
            addr: "0x4105BE",
            code: "E9[codecave:double_bullet_count_difficulty_2]",
        },
        patch_ecl_time_sub_difficulty_skip: {
            addr: "0x411CAB",
            code: "EB1A",
        },
        patch_ecl_time_sub_difficulty_call: {
            addr: "0x411CCB",
            code: "E8[codecave:patch_ecl_time_sub_difficulty]",
        },
        no_idea_what_this_is_call: {
            addr: "0x416C3D",
            code: "E8[codecave:no_idea_what_this_is] 85C0 7510",
        }
    },
}