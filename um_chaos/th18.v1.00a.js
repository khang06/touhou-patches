{
    options: {
        d3dx9_43_dll_str: {
            type: "s",
            val: "d3dx9_43.dll",
        },
        D3DXCreateTextureFromFileInMemory_str: {
            type: "s",
            val: "D3DXCreateTextureFromFileInMemory",
        },
        kernel32_dll_str: {
            type: "s",
            val: "kernel32.dll",
        },
        AllocConsole_str: {
            type: "s",
            val: "AllocConsole",
        },
        CreateThread_str: {
            type: "s",
            val: "CreateThread",
        },
        VirtualProtect_str: {
            type: "s",
            val: "VirtualProtect",
        },
        DebugBreak_str: {
            type: "s",
            val: "DebugBreak",
        },
        ExitProcess_str: {
            type: "s",
            val: "ExitProcess",
        },
        ActivateActCtx_str: {
            type: "s",
            val: "ActivateActCtx",
        },
        CreateActCtxW_str: {
            type: "s",
            val: "CreateActCtxW",
        },
        GetSystemDirectoryW_str: {
            type: "s",
            val: "GetSystemDirectoryW",
        },
        GetProcAddress_str: {
            type: "s",
            val: "GetProcAddress",
        },
        GetModuleHandleA_str: {
            type: "s",
            val: "GetModuleHandleA",
        },
        DeactivateActCtx_str: {
            type: "s",
            val: "DeactivateActCtx",
        },
        Sleep_str: {
            type: "s",
            val: "Sleep",
        },
        QueryPerformanceCounter_str: {
            type: "s",
            val: "QueryPerformanceCounter",
        },
        GetLastError_str: {
            type: "s",
            val: "GetLastError",
        },
        ucrtbase_dll_str: {
            type: "s",
            val: "ucrtbase.dll",
        },
        __stdio_common_vfprintf_str: {
            type: "s",
            val: "__stdio_common_vfprintf",
        },
        __acrt_iob_func_str: {
            type: "s",
            val: "__acrt_iob_func",
        },
        freopen_str: {
            type: "s",
            val: "freopen",
        },
        __stdio_common_vfscanf_str: {
            type: "s",
            val: "__stdio_common_vfscanf",
        },
        strtol_str: {
            type: "s",
            val: "strtol",
        },
        fgets_str: {
            type: "s",
            val: "fgets",
        },
        _invalid_parameter_noinfo_noreturn_str: {
            type: "s",
            val: "_invalid_parameter_noinfo_noreturn",
        },
        _invoke_watson_str: {
            type: "s",
            val: "_invoke_watson",
        },
        free_str: {
            type: "s",
            val: "free",
        },
        malloc_str: {
            type: "s",
            val: "malloc",
        },
        _wcsicmp_str: {
            type: "s",
            val: "_wcsicmp",
        },
        strncmp_str: {
            type: "s",
            val: "strncmp",
        },
        user32_dll_str: {
            type: "s",
            val: "user32.dll",
        },
        SetForegroundWindow_str: {
            type: "s",
            val: "SetForegroundWindow",
        },
        PostMessageA_str: {
            type: "s",
            val: "PostMessageA",
        },
        LoadIconA_str: {
            type: "s",
            val: "LoadIconA",
        },
        MessageBoxA_str: {
            type: "s",
            val: "MessageBoxA",
        },
        GetClassInfoExA_str: {
            type: "s",
            val: "GetClassInfoExA",
        },
        SetCursor_str: {
            type: "s",
            val: "SetCursor",
        },
        LoadCursorA_str: {
            type: "s",
            val: "LoadCursorA",
        },
        ScreenToClient_str: {
            type: "s",
            val: "ScreenToClient",
        },
        GetCursorPos_str: {
            type: "s",
            val: "GetCursorPos",
        },
        SetCursorPos_str: {
            type: "s",
            val: "SetCursorPos",
        },
        ClientToScreen_str: {
            type: "s",
            val: "ClientToScreen",
        },
        SendMessageA_str: {
            type: "s",
            val: "SendMessageA",
        },
        CreateIconFromResource_str: {
            type: "s",
            val: "CreateIconFromResource",
        },
        IsIconic_str: {
            type: "s",
            val: "IsIconic",
        },
        SetWindowPos_str: {
            type: "s",
            val: "SetWindowPos",
        },
        GetWindowRect_str: {
            type: "s",
            val: "GetWindowRect",
        },
        GetMonitorInfoA_str: {
            type: "s",
            val: "GetMonitorInfoA",
        },
        MonitorFromWindow_str: {
            type: "s",
            val: "MonitorFromWindow",
        },
        advapi32_dll_str: {
            type: "s",
            val: "advapi32.dll",
        },
        RegCloseKey_str: {
            type: "s",
            val: "RegCloseKey",
        },
        RegOpenKeyA_str: {
            type: "s",
            val: "RegOpenKeyA",
        },
        um_chaos_name_str: {
            type: "s",
            val: "um_chaos",
        },
        LoadLibraryA_str: {
            type: "s",
            val: "LoadLibraryA",
        },
        dll_load_failed_str: {
            type: "s",
            val: "Failed to load DLL %s (code: 0x%p)",
        },
        import_failed_str: {
            type: "s",
            val: "Failed to load import %s (code: 0x%p)",
        },
    },
    codecaves: {
        doublebulletcount_cave1: {
            access: "rx",
            code: "8B843E040A0000 D1E0 89843E040A0000 E9[0x436417]",
        },
        doublebulletcount_cave2: {
            access: "rx",
            code: "8B86040A0000 D1E0 8986040A0000 E9[0x436417]",
        },
        doublebulletcount_cave3: {
            access: "rx",
            code: "8B840F040A0000 D1E0 89840F040A0000 E9[0x436417]",
        },
        eclwaitmultiplier_diffwait_cave: {
            access: "rx",
            code: "F30F590D<codecave:um_chaos.data+0x4> E9[0x42CDC0]",
        },
        eclwaitmultiplier_wait_cave: {
            access: "rx",
            code: "F30F590D<codecave:um_chaos.data+0x4> F30F5CC1 F30F1107 E9[0x48D22E]",
        },
        eclwaitmultiplier_waitf_cave: {
            access: "rx",
            code: "F30F5905<codecave:um_chaos.data+0x4> F30F5CC8 F30F110F E9[0x48D22E]",
        },
        bulletwrap_etnew_cave: {
            access: "rx",
            code: "66C7840EE00500000010 C6840ED005000001 C6840ED40500000F C684B9184E000001 E9[0x436417]",
        },
        slippery_cave: {
            access: "rx",
            code: "8B10 8915<codecave:um_chaos.bss+0x2080> 8B11 8915<codecave:um_chaos.bss+0x2084> 8B15D0F24C00 E9[0x45B3E4]",
        },
        custom_anm_jump_table_cave: {
            access: "r",
            code: "51B8470061B84700F6874700EF874700B2874700078947003689470077894700578E4700988E4700ED8E47002E8F4700838F4700C98F47001E90470066904700BB90470003914700C8894700328A4700B18A4700168B4700958B4700FE8B47007D8C4700EA8C4700698D4700D68D470083914700D49147002F92470085924700DB9247003193470087934700DD93470034944700C89447004487470062874700B69547000196470060964700AB9647000A97470055974700AC974700F79747004E98470099984700F49847003B994700F3B64700<codecave:custom_anm_handler_cave>",
        },
        custom_anm_handler_cave: {
            access: "rx",
            code: "E8[codecave:um_chaos.text+0x960] E9[0x47B6F3]",
        },
        title_draw_jump_table_cave: {
            access: "r",
            code: "A6584600045A4600D1594600C0594600E2594600F3594600155A4600265A46002B5A4600<codecave:title_draw_cave>",
        },
        title_draw_cave: {
            access: "rx",
            code: "E8[codecave:um_chaos.text+0x10c0] E9[0x4659B4]",
        },
        "um_chaos.text": {
            access: "rx",
            code: "8b0d(<codecave:um_chaos.bss>+0x10)85c97448a1(<codecave:um_chaos.bss>+0x18)29c83d0010000072128b51fc83c1fc29d183f920732e83c02389d15051e8([codecave:um_chaos.text]+0x2c0)83c408c705(<codecave:um_chaos.bss>+0x10)00000000c705(<codecave:um_chaos.bss>+0x14)00000000c705(<codecave:um_chaos.bss>+0x18)00000000c3ff15(<codecave:um_chaos_imports>+0x54)0f1f80000000008b0d(<codecave:um_chaos.bss>+0x1c)85c97448a1(<codecave:um_chaos.bss>+0x24)29c83d0010000072128b51fc83c1fc29d183f920732e83c02389d15051e8([codecave:um_chaos.text]+0x2c0)83c408c705(<codecave:um_chaos.bss>+0x1c)00000000c705(<codecave:um_chaos.bss>+0x20)00000000c705(<codecave:um_chaos.bss>+0x24)00000000c3ff15(<codecave:um_chaos_imports>+0x54)0f1f80000000005683ec088b4c2410c744240400000000c704240000000089e26a00e8[0x402060]89c68d44240450ff74240456ff35(<0x4CCDF0>+0x8)ff15<codecave:um_chaos_imports>56ff15(<codecave:um_chaos_imports>+0x5c)83c4048b44240483c4085ec30f1f4400005756508b4c2410c704240000000089e26a00e8[0x402060]89c668000003006a01ff74240850ff15(<codecave:um_chaos_imports>+0x9c)89c756ff15(<codecave:um_chaos_imports>+0x5c)83c40489f883c4045e5fc3905553575683ec08c7042400000000c7442404000000008d542404b9<codecave:um_chaos.rdata>6a00e8[0x402060]89c689e050ff74240856ff35(<0x4CCDF0>+0x8)ff15<codecave:um_chaos_imports>8b2d(<codecave:um_chaos_imports>+0x5c)56ffd583c4048b0424a3<codecave:um_chaos.bss>c704240000000089e6b9<codecave:um_chaos.rdata>89f26a00e8[0x402060]89c768000003006a01ff74240850ff15(<codecave:um_chaos_imports>+0x9c)89c357ffd583c404891d(<codecave:um_chaos.bss>+0x4)c7042400000000c7442404000000008d542404b9(<codecave:um_chaos.rdata>+0xc)6a00e8[0x402060]89c756ff74240850ff35(<0x4CCDF0>+0x8)ff15<codecave:um_chaos_imports>57ffd583c4048b0424a3(<codecave:um_chaos.bss>+0x8)68(<codecave:um_chaos.rdata>+0x1b)6800004000ff15(<codecave:um_chaos_imports>+0x74)a3(<codecave:um_chaos.bss>+0xc)83c4085e5f5b5dc3660f1f840000000000c705(<codecave:um_chaos.bss>+0x10)00000000c705(<codecave:um_chaos.bss>+0x14)00000000c705(<codecave:um_chaos.bss>+0x18)0000000068<codecave:um_chaos.text>e8([codecave:um_chaos.text]+0x2d0)83c404c705(<codecave:um_chaos.bss>+0x1c)00000000c705(<codecave:um_chaos.bss>+0x20)00000000c705(<codecave:um_chaos.bss>+0x24)0000000068(<codecave:um_chaos.text>+0x60)e8([codecave:um_chaos.text]+0x2d0)83c404c3906690669066906690ff25(<codecave:um_chaos_imports>+0x60)662e0f1f840000000000ff25(<codecave:um_chaos_imports>+0x5c)662e0f1f840000000000ff25(<codecave:um_chaos_imports>+0x5c)662e0f1f84000000000031c0c3666666662e0f1f840000000000ff25(<codecave:um_chaos_imports>+0x10)66906690669066906690b9(<codecave:um_chaos.bss>+0x1c34)e9([codecave:um_chaos.text]+0x1690)660f1f4400005589e583e4f883ec08e8[0x4432B0]68(<codecave:um_chaos.rdata>+0x30)e8([codecave:um_chaos.text]+0xdc0)83c404803d(<codecave:um_chaos.bss>+0x1c41)00752b89e050ff15(<codecave:um_chaos_imports>+0x34)ff3424e8([codecave:um_chaos.text]+0x1580)83c404680000f041680000a040e8([codecave:um_chaos.text]+0x15f0)83c408a3(<codecave:um_chaos.bss>+0x1c44)c605(<codecave:um_chaos.bss>+0x1c40)0131c089ec5dc30f1f4000575689ce83b9f407000007753883bef807000007742f68(<codecave:um_chaos.rdata>+0x3e)e8([codecave:um_chaos.text]+0xdc0)83c404b00183bef80700000c740b833d(<codecave:um_chaos.bss>+0xc2c)00754231c0a2(<codecave:um_chaos.bss>+0x1c41)c605(<codecave:um_chaos.bss>+0x1c40)0089f15e5fe9[0x455040]66908b3d(<codecave:um_chaos.bss>+0xc2c)4f89f8c1e0045068(<codecave:um_chaos.bss>+0xc40)68(<codecave:um_chaos.bss>+0xc30)e8[th_memmove]83c40c893d(<codecave:um_chaos.bss>+0xc2c)85ff74beff35(<codecave:um_chaos.bss>+0xc30)68(<codecave:um_chaos.rdata>+0x182)e8([codecave:um_chaos.text]+0xdc0)83c408a1(<codecave:um_chaos.bss>+0xc34)8d0440c60485(<codecave:um_chaos.bss>+0x34)008b0d(<codecave:um_chaos.bss>+0xc3c)85c974aa8b016a01ff10eba26690a1(<codecave:um_chaos.bss>+0x2068)85c0740648a3(<codecave:um_chaos.bss>+0x2068)803d(<codecave:um_chaos.bss>+0x1c40)000f848c020000833d<0x4CF2A4>000f857f02000055535756ff0d(<codecave:um_chaos.bss>+0x1c44)74668b3d<codecave:um_chaos.data>83ffff0f84280100008d047f803c85(<codecave:um_chaos.bss>+0x34)000f842a0100008b35(<codecave:um_chaos.bss>+0xc2c)85f60f849001000089f0f7d8bd01000000bb(<codecave:um_chaos.bss>+0xc30)6666666666662e0f1f840000000000397b040f842502000083c3108d0c28414583f90175eae95a0100008b0d(<codecave:um_chaos.bss>+0x28)85c90f849d00000083f9010f855c02000031d231c0f6c10174158d0c52803c8d(<codecave:um_chaos.bss>+0x34)007508891485(<codecave:um_chaos.bss>+0x1c48)4085c0747248506a00e8([codecave:um_chaos.text]+0x15b0)83c4088b3485(<codecave:um_chaos.bss>+0x1c48)8d3cb500000000ffb47f(<codecave:um_chaos.bss>+0x2c)68(<codecave:um_chaos.rdata>+0x193)e8([codecave:um_chaos.text]+0xdc0)83c408c6847f(<codecave:um_chaos.bss>+0x34)018b9c7f(<codecave:um_chaos.bss>+0x2c)ff947f(<codecave:um_chaos.bss>+0x30)8b0d(<codecave:um_chaos.bss>+0xc2c)8d51018915(<codecave:um_chaos.bss>+0xc2c)c1e1048999(<codecave:um_chaos.bss>+0xc30)89b1(<codecave:um_chaos.bss>+0xc34)c781(<codecave:um_chaos.bss>+0xc38)000000008981(<codecave:um_chaos.bss>+0xc3c)680000f041680000a040e8([codecave:um_chaos.text]+0x15f0)83c408a3(<codecave:um_chaos.bss>+0x1c44)8b3d<codecave:um_chaos.data>83ffff0f85d8feffff8b35(<codecave:um_chaos.bss>+0xc2c)85f60f858d000000e9250100008d3485(<codecave:um_chaos.bss>+0x34)8d1cbd00000000ffb45b(<codecave:um_chaos.bss>+0x2c)68(<codecave:um_chaos.rdata>+0x193)e8([codecave:um_chaos.text]+0xdc0)83c408c606018bac5b(<codecave:um_chaos.bss>+0x2c)ff945b(<codecave:um_chaos.bss>+0x30)8b0d(<codecave:um_chaos.bss>+0xc2c)8d71018935(<codecave:um_chaos.bss>+0xc2c)c1e10489a9(<codecave:um_chaos.bss>+0xc30)89b9(<codecave:um_chaos.bss>+0xc34)c781(<codecave:um_chaos.bss>+0xc38)000000008981(<codecave:um_chaos.bss>+0xc3c)c705<codecave:um_chaos.data>ffffffff85f67519e9b100000031f6c705<codecave:um_chaos.data>ffffffff85f60f849d00000031f6eb140f1f440000468b3d(<codecave:um_chaos.bss>+0xc2c)39fe0f838500000089f7c1e704ff87(<codecave:um_chaos.bss>+0xc38)8b8f(<codecave:um_chaos.bss>+0xc3c)8b01ff500484c075d78d9f(<codecave:um_chaos.bss>+0xc3c)ffb7(<codecave:um_chaos.bss>+0xc30)68(<codecave:um_chaos.rdata>+0x182)e8([codecave:um_chaos.text]+0xdc0)83c4088b87(<codecave:um_chaos.bss>+0xc34)8d0440c60485(<codecave:um_chaos.bss>+0x34)008b0b85c974068b016a01ff108d87(<codecave:um_chaos.bss>+0xc30)8d8f(<codecave:um_chaos.bss>+0xc40)8b3d(<codecave:um_chaos.bss>+0xc2c)89f2f7d201fac1e204525150e8[th_memmove]83c40c4f893d(<codecave:um_chaos.bss>+0xc2c)39fe0f827bffffff5e5f5b5db801000000c3ff3368(<codecave:um_chaos.rdata>+0x182)e8([codecave:um_chaos.text]+0xdc0)83c4088b43048d0440c60485(<codecave:um_chaos.bss>+0x34)008b4b0c85c974068b016a01ff108d43108b35(<codecave:um_chaos.bss>+0xc2c)89f129e9c1e104515053e8[th_memmove]83c40c4e8935(<codecave:um_chaos.bss>+0xc2c)c705<codecave:um_chaos.data>ffffffff85f60f85fbfeffffeb9689cb83e3fe31d2be(<codecave:um_chaos.bss>+0x40)31c0eb10669083c20283c61839d30f8488fdffff807ef400740c803e0075e7eb120f1f440000891485(<codecave:um_chaos.bss>+0x1c48)40803e0075d38d7a01893c85(<codecave:um_chaos.bss>+0x1c48)40ebc6660f1f440000a1<0x4CF2AC>85c00f84890100005553575683ec18833d(<0x4CCDF0>+0x7f4)040f858c0000008b0d(<0x568C30>+0x2040)c1e90283e11f83f909777bba070300000fa3ca7371c744240800000000c744240400008040c7042400008040c744241400000000c74424100000a041c744240c00008040c7804492010006000000c7802892010000ffffff89e168(<codecave:um_chaos.rdata>+0x64)5150e8[0x419CB0]83c40c8d44240c68(<codecave:um_chaos.rdata>+0x8d)50ff35<0x4CF2AC>e8[0x419CB0]83c40ca1<0x4CF2AC>c7804492010001000000833d(<codecave:um_chaos.bss>+0xc2c)000f84c100000031f6bf(<codecave:um_chaos.bss>+0xc38)bbffffffff89e566666666662e0f1f8400000000000f57c0f30f2ac6c7042400008040f30f5905(<codecave:um_chaos.rdata>+0x28)f30f5805(<codecave:um_chaos.rdata>+0x2c)f30f11442404c7442408000000008b070fbae002b90000000019c981c90000ffff83f83d0f43cba1<0x4CF2AC>898828920100ff77f868(<codecave:um_chaos.rdata>+0xb9)5550e8[0x419CB0]83c41046a1(<codecave:um_chaos.bss>+0xc2c)83c71039c672918b0d<0x4CF2AC>c78128920100ffffffff85c0742c31f6bf(<codecave:um_chaos.bss>+0xc3c)660f1f4400008b0f8b01ff50084683c7103b35(<codecave:um_chaos.bss>+0xc2c)72edeb0ac78028920100ffffffff83c4185e5f5b5db801000000c30f1f40005553575681ec800000008b35(<codecave:um_chaos_imports>+0x40)89e78b1d(<codecave:um_chaos_imports>+0x50)8b2d(<codecave:um_chaos_imports>+0x4c)66906a00ffd683c40450688000000057ffd383c40c85c074e96a0a6a0057ffd583c40ca3<codecave:um_chaos.data>ebd80f1f8400000000005589e583e4f883ec0889e050ff15(<codecave:um_chaos_imports>+0x34)ff3424e8([codecave:um_chaos.text]+0x1580)83c4040f57d2b9<0x56AD80>6a33e8[0x476C70]c705(<codecave:um_chaos.bss>+0x2068)3c00000089ec5dc3660f1f4400005553575683ec08e8[0x42DC20]85c00f840c010000a1<0x4CF2D0>8b98880100008b0389d968(<codecave:um_chaos.rdata>+0xbc)ff1085c074176a106a0068(<codecave:um_chaos.rdata>+0xc6)6a00ff15(<codecave:um_chaos_imports>+0x78)ff15(<codecave:um_chaos_imports>+0x10)a1(<codecave:um_chaos.bss>+0x10)3b05(<codecave:um_chaos.bss>+0x14)7405a3(<codecave:um_chaos.bss>+0x14)8b0d(<codecave:um_chaos.bss>+0x1c)3b0d(<codecave:um_chaos.bss>+0x20)7406890d(<codecave:um_chaos.bss>+0x20)837b080089c289ce0f84c200000031ff8b35(<codecave:um_chaos_imports>+0x68)31ed895c2404eb330f1f80000000008b0c24a1(<codecave:um_chaos.bss>+0x14)3b05(<codecave:um_chaos.bss>+0x18)746b89088305(<codecave:um_chaos.bss>+0x14)044583c7088b5c24043b6b088b35(<codecave:um_chaos_imports>+0x68)73688b9b8c0000008b0c3b01fb6a0668(<codecave:um_chaos.rdata>+0xe2)894c240851ffd683c40c85c074b46a0568(<codecave:um_chaos.rdata>+0xe9)ff742408ffd683c40c85c075b98b0c24a1(<codecave:um_chaos.bss>+0x20)3b05(<codecave:um_chaos.bss>+0x24)741289088305(<codecave:um_chaos.bss>+0x20)04eb9eb9(<codecave:um_chaos.bss>+0x10)eb05b9(<codecave:um_chaos.bss>+0x1c)5350e8([codecave:um_chaos.text]+0xe10)eb8931c0eb358b35(<codecave:um_chaos.bss>+0x20)8b0d(<codecave:um_chaos.bss>+0x1c)8b15(<codecave:um_chaos.bss>+0x14)a1(<codecave:um_chaos.bss>+0x10)29c229cec1fe02c1fa02565268(<codecave:um_chaos.rdata>+0xef)e8([codecave:um_chaos.text]+0xdc0)83c40ca1<0x4CF2D0>83c4085e5f5b5dc36666666666662e0f1f840000000000817c2404c7faffff0f85[0x437360]8b8104120000c20400660f1f840000000000e8[0x4637D0]e9[0x464860]660f1f440000575683ec0cff15(<codecave:um_chaos_imports>+0x4)8b3d(<codecave:um_chaos_imports>+0x40)6a00ffd783c4048b35(<codecave:um_chaos_imports>+0x44)5068(<codecave:um_chaos.rdata>+0x11e)68(<codecave:um_chaos.rdata>+0x120)ffd683c40c6a01ffd783c4045068(<codecave:um_chaos.rdata>+0x127)68(<codecave:um_chaos.rdata>+0x129)ffd683c40c6a02ffd783c4045068(<codecave:um_chaos.rdata>+0x127)68(<codecave:um_chaos.rdata>+0x129)ffd683c40c68(<codecave:um_chaos.rdata>+0x131)e8([codecave:um_chaos.text]+0xdc0)83c404ff35(<codecave:um_chaos.bss>+0x28)68(<codecave:um_chaos.rdata>+0x144)e8([codecave:um_chaos.text]+0xdc0)83c408833d(<codecave:um_chaos.bss>+0x28)00742731f6bf(<codecave:um_chaos.bss>+0x2c)0f1f4000ff375668(<codecave:um_chaos.rdata>+0x158)e8([codecave:um_chaos.text]+0xdc0)83c40c4683c70c3b35(<codecave:um_chaos.bss>+0x28)72e468(<codecave:um_chaos.rdata>+0x160)e8([codecave:um_chaos.text]+0xdc0)83c404ff35<0x568C30>ff15(<codecave:um_chaos_imports>+0x6c)6a006a006a0068(<codecave:um_chaos.text>+0x910)6a006a00ff15(<codecave:um_chaos_imports>+0x8)e8([codecave:um_chaos.text]+0x150)b9(<codecave:um_chaos.bss>+0x1c34)68(<codecave:um_chaos.text>+0x9a0)68cf2f4400e8([codecave:um_chaos.text]+0x1a50)c7442408(<codecave:um_chaos.text>+0xb10)8d442408b9(<codecave:um_chaos.bss>+0x1c34)6a04506850654b00e8([codecave:um_chaos.text]+0x1840)c7442404081200008d442404b9(<codecave:um_chaos.bss>+0x1c34)6a045068c4cc4200e8([codecave:um_chaos.text]+0x1840)c6442403568d442403b9(<codecave:um_chaos.bss>+0x1c34)6a015068cdcc4200e8([codecave:um_chaos.text]+0x1840)68(<codecave:um_chaos.text>+0x410)e8[0x401530]8048040268e803000050e8[0x401180]68(<codecave:um_chaos.text>+0x770)e8[0x401530]804804026a5750e8[0x401230]31c083c40c5e5fc36666666666662e0f1f84000000000081ec5c020000c7042400000000c744240420000000c74424080c000000c744240c(<codecave:um_chaos.rdata>+0x162)c7442410000000008d44245489442414c74424187c000000c744241c00000000c744242000000000680401000050ff15(<codecave:um_chaos_imports>+0x20)3d03010000775866c744445400008d44240450ff15(<codecave:um_chaos_imports>+0x1c)a3(<codecave:um_chaos.bss>+0x2060)89e15150ff15(<codecave:um_chaos_imports>+0x18)0f57c00f114424440f114424380f11442428c7442424300000008d4424245068(<codecave:um_chaos.rdata>+0x17a)6a00ff15(<codecave:um_chaos_imports>+0x7c)ff34246a00ff15(<codecave:um_chaos_imports>+0x2c)81c45c020000c390c705(<codecave:um_chaos.bss>+0x1c34)00000000c705(<codecave:um_chaos.bss>+0x1c38)00000000c705(<codecave:um_chaos.bss>+0x1c3c)0000000068(<codecave:um_chaos.text>+0x2f0)e8([codecave:um_chaos.text]+0x2d0)83c404c366906690535756508b7c24148d5c2418891c246a01ff15(<codecave:um_chaos_imports>+0x40)83c40489c6e8([codecave:um_chaos.text]+0xe00)536a005756ff7004ff30ff15(<codecave:um_chaos_imports>+0x3c)83c41c5e5f5bc36690669066906690b8(<codecave:um_chaos.bss>+0x2048)c3669066906690669066905553575683ec0889ce8b398b690429fdc1fd02458b410829f8c1f80289c3d1ebb9ffffff3fbaffffff3f29da01c339eb0f46dd39d00f47d981fb000000400f83e40000008d049d0000000081fb00040000893c24722381fbf8ffff3f0f83c600000083c02350e8([codecave:um_chaos.text]+0x2a0)83c4048d782383e7e08947fceb1385db740d50e8([codecave:um_chaos.text]+0x2a0)83c40489c7eb0231ff8b4424208b4c241c2b0c24c1f9028d148f8914248b0089048f8b068b4e04894c24048b4c241c29c1515057e8[th_memmove]8b54242883c40c3954240474168b042483c0048b4e0429d1515250e8[th_memmove]83c40c8b0e85c974288b460829c83d0010000072128b51fc83c1fc29d183f920732f83c02389d15051e8([codecave:um_chaos.text]+0x2c0)83c408893e8d04af8946048d049f8946088b042483c4085e5f5b5dc20800e8([codecave:um_chaos.text]+0xf50)ff15(<codecave:um_chaos_imports>+0x54)6690669066906690669066909083ec08c7442404(<codecave:um_chaos.rdata>+0x1a3)c70424(<codecave:um_chaos.rdata>+0x1b8)89e1e8([codecave:um_chaos.text]+0xf70)669066906690905683ec1489cea1(<codecave:um_chaos.bss>+0x1c30)85c07405893424ffd08b0689f1ff50080f57c00f110424c744241000000000ff15(<codecave:um_chaos_imports>+0x58)5689ce837c240800740956e8([codecave:um_chaos.text]+0x2b0)83c40489f05ec20400669066906690908b490485c9b8(<codecave:um_chaos.rdata>+0x1c4)0f45c1c3669083ec140f57c00f110424c744241000000000ff15(<codecave:um_chaos_imports>+0x58)66906690669066905689ce8379200074198b0d(<codecave:um_chaos.bss>+0x2054)81f9ef000000b8ef0000000f4cc183c010eb13c705(<codecave:um_chaos.bss>+0x2050)00000000c746200100000031c0ff05(<codecave:um_chaos.bss>+0x2058)a3(<codecave:um_chaos.bss>+0x2054)a1<0x4CA21C>a8107525a820754fa901100000741889f16a01e8[0x4646E0]0f57d2b9<0x56AD80>6a09e8[0x476C70]5ec3a1(<codecave:um_chaos.bss>+0x2050)83e801b9040000000f43c8890d(<codecave:um_chaos.bss>+0x2050)0f57d2b9<0x56AD80>6a0ae8[0x476C70]a1<0x4CA21C>a82074b1a1(<codecave:um_chaos.bss>+0x2050)8d480131d283f8040f45d18915(<codecave:um_chaos.bss>+0x2050)0f57d2b9<0x56AD80>6a0ae8[0x476C70]a1<0x4CA21C>a9011000007587eb9d90f74120fbffffff7501c35553575683ec34c744243000000000c744242c0000a042c74424280000a043a1<0x4CF2AC>c7804492010007000000f30f1005(<codecave:um_chaos.bss>+0x2058)660f5605(<codecave:um_chaos.rdata>+0x1e0)f20f5c05(<codecave:um_chaos.rdata>+0x1f0)f20f5ac0f30f5e05(<codecave:um_chaos.rdata>+0x1f8)f30f11442418f30f5ac083ec08f20f110424e8[th_sin]83c408d95c2424f30f100d(<codecave:um_chaos.rdata>+0x1fc)f30f10442424f30f59c1f30f5805(<codecave:um_chaos.rdata>+0x200)f30f2cc089c1c1f91ff30f5c05(<codecave:um_chaos.rdata>+0x204)f30f2cd821cb09c3f30f1005(<codecave:um_chaos.rdata>+0x208)f30f58442418f30f5ac083ec08f20f110424e8[th_sin]83c408d95c2420f30f10442420f30f100d(<codecave:um_chaos.rdata>+0x1fc)f30f59c1f30f5805(<codecave:um_chaos.rdata>+0x200)f30f2cc089c1c1f91ff30f5c05(<codecave:um_chaos.rdata>+0x204)f30f2cf021ce09c6f30f10442418f30f5805(<codecave:um_chaos.rdata>+0x20c)f30f5ac083ec08f20f110424e8[th_sin]83c408d95c241cf30f1005(<codecave:um_chaos.rdata>+0x1fc)f30f5944241cf30f5805(<codecave:um_chaos.rdata>+0x200)f30f2cc089c2c1fa1ff30f5c05(<codecave:um_chaos.rdata>+0x204)f30f2cc821d109c1a1(<codecave:um_chaos.bss>+0x2054)c1e0180fb6d3c1e210c1e6080fb7f609d60fb6c909f109c18b15<0x4CF2AC>898a2892010089822c920100c7825092010000000000c78254920100000000008d44242868(<codecave:um_chaos.rdata>+0x238)5052e8[0x419CB0]83c40cc744241400000000c74424100000fa42c744240c00001643c744240800000000c74424040000fa42c704240000f543a1<0x4CF2AC>c7804492010006000000c78054920100010000008b0d(<codecave:um_chaos.bss>+0x2054)c1e118833d(<codecave:um_chaos.bss>+0x2050)00bd8080ff00baffffff000f44d5bbffffff0009ca899028920100c78050920100010000008d74240c68(<codecave:um_chaos.rdata>+0x24f)68(<codecave:um_chaos.rdata>+0xb9)5650e8[0x419CB0]83c410a1<0x4CF2AC>c780509201000200000089e768(<codecave:um_chaos.rdata>+0x2b0)68(<codecave:um_chaos.rdata>+0xb9)5750e8[0x419CB0]83c410f30f100d(<codecave:um_chaos.rdata>+0x210)f30f10442410f30f58c1f30f11442410f30f10442404f30f58c1f30f11442404833d(<codecave:um_chaos.bss>+0x2050)01b8ffffff000f44c58b0d(<codecave:um_chaos.bss>+0x2054)c1e11809c1a1<0x4CF2AC>898828920100c780509201000100000068(<codecave:um_chaos.rdata>+0x268)68(<codecave:um_chaos.rdata>+0xb9)5650e8[0x419CB0]83c410a1<0x4CF2AC>c780509201000200000068(<codecave:um_chaos.rdata>+0x2b3)68(<codecave:um_chaos.rdata>+0xb9)5750e8[0x419CB0]83c410f30f10442410f30f100d(<codecave:um_chaos.rdata>+0x210)f30f58c1f30f11442410f30f10442404f30f58c1f30f11442404833d(<codecave:um_chaos.bss>+0x2050)02b8ffffff000f44c58b0d(<codecave:um_chaos.bss>+0x2054)c1e11809c1a1<0x4CF2AC>898828920100c780509201000100000068(<codecave:um_chaos.rdata>+0x281)68(<codecave:um_chaos.rdata>+0xb9)5650e8[0x419CB0]83c410a1<0x4CF2AC>c780509201000200000068(<codecave:um_chaos.rdata>+0x2b7)68(<codecave:um_chaos.rdata>+0xb9)5750e8[0x419CB0]83c410f30f10442410f30f100d(<codecave:um_chaos.rdata>+0x210)f30f58c1f30f11442410f30f10442404f30f58c1f30f11442404833d(<codecave:um_chaos.bss>+0x2050)03b8ffffff000f44c58b0d(<codecave:um_chaos.bss>+0x2054)c1e11809c1a1<0x4CF2AC>898828920100c780509201000100000068(<codecave:um_chaos.rdata>+0x29a)68(<codecave:um_chaos.rdata>+0xb9)5650e8[0x419CB0]83c410a1<0x4CF2AC>c780509201000200000068(<codecave:um_chaos.rdata>+0x2bc)68(<codecave:um_chaos.rdata>+0xb9)5750e8[0x419CB0]83c410f30f10442410f30f100d(<codecave:um_chaos.rdata>+0x210)f30f58c1f30f584c2404f30f11442410f30f114c2404833d(<codecave:um_chaos.bss>+0x2050)040f44dda1(<codecave:um_chaos.bss>+0x2054)c1e01809d88b0d<0x4CF2AC>898128920100c781509201000100000068(<codecave:um_chaos.rdata>+0x2ab)68(<codecave:um_chaos.rdata>+0xb9)5651e8[0x419CB0]83c410a1<0x4CF2AC>c780509201000200000068(<codecave:um_chaos.rdata>+0x2bc)68(<codecave:um_chaos.rdata>+0xb9)5750e8[0x419CB0]83c410a1<0x4CF2AC>c78028920100ffffffffc780449201000000000083c4345e5f5b5dc36690669066908b442404a3(<codecave:um_chaos.bss>+0x205c)c3660f1f440000a1(<codecave:um_chaos.bss>+0x205c)89c1c1e10d31c189cac1ea1131ca89d0c1e00531d0a3(<codecave:um_chaos.bss>+0x205c)c357568b4c240c8b742410a1(<codecave:um_chaos.bss>+0x205c)89c2c1e20d31c289d7c1ef1131d789f8c1e00531f8a3(<codecave:um_chaos.bss>+0x205c)29ce4631d2f7f601d189c85e5fc3660f1f84000000000056f30f10442408f30f104c240c0f14c80f590d(<codecave:um_chaos.rdata>+0x2c0)f30f5bc1a1(<codecave:um_chaos.bss>+0x205c)89c1c1e10d31c189cac1ea1131ca89d0c1e00531d0a3(<codecave:um_chaos.bss>+0x205c)660f7ec6660f70c055660f7ec129ce4631d2f7f601d189c85ec36666662e0f1f84000000000050a1(<codecave:um_chaos.bss>+0x205c)89c1c1e10d31c189c8c1e81131c889c1c1e10531c1890d(<codecave:um_chaos.bss>+0x205c)c1e90981c90000803f660f6ec1f30f5805(<codecave:um_chaos.rdata>+0x2d0)f30f110424d9042458c353575689cee8([codecave:um_chaos.text]+0x1760)8b3e85ff0f84a70000008b5e0439df753b8b460829f83d001000007364eb740f1f80000000005051e8([codecave:um_chaos.text]+0x2c0)83c408c7470400000000c7470800000000c7470c0000000083c71039df74278b4f0485c974f28b470c29c83d0010000072c78b51fc83c1fc29d183f920734983c02389d1ebb38b3e8b460829f83d0010000072128b4ffc83c7fc29cf83ff20732783c02389cf5057e8([codecave:um_chaos.text]+0x2c0)83c408c70600000000c7460400000000c74608000000005e5f5bc3ff15(<codecave:um_chaos_imports>+0x54)66662e0f1f8400000000005553575683ec088b398b590439df0f84be000000890c248d6c24048b35(<codecave:um_chaos_imports>+0xc)6666666666662e0f1f8400000000008b47082b4704556a4050ff37ffd68b47048b4f0829c15150ff37e8[th_memcpy]83c40c8b47082b470455ff74240850ff37ffd683c71039df75c78b34248b3e8b5e0439df7531eb5b660f1f8400000000005051e8([codecave:um_chaos.text]+0x2c0)83c408c7470400000000c7470800000000c7470c0000000083c71039df74278b4f0485c974f28b470c29c83d0010000072c78b51fc83c1fc29d183f920731483c02389d1ebb38b0689460483c4085e5f5b5dc3ff15(<codecave:um_chaos_imports>+0x54)e9([codecave:um_chaos.text]+0x1850)66662e0f1f84000000000055535683ec2089ce8b5c24388b6c2430c7042400000000c744240400000000c74424080000000085db74128d44240c89e15053e8([codecave:um_chaos.text]+0x1a80)8b0424eb0231c0535550e8[th_memcpy]83c40c8d44241c506a405355ff15(<codecave:um_chaos_imports>+0xc)53ff74243855e8[th_memcpy]83c40c8d44241c50ff7424205355ff15(<codecave:um_chaos_imports>+0xc)896c240c8b442408c744240800000000f20f100424c744240400000000c7042400000000f20f11442410894424188b46043b4608744189288b4c2418c744241800000000f20f10442410c744241400000000c744241000000000f20f11400489480c834604108b4c241085c9751e8b0c2485c97547eb6e8d54240c89f15250e8([codecave:um_chaos.text]+0x1b90)8b4c241085c974e28b44241829c83d0010000072128b51fc83c1fc29d183f920734883c02389d15051e8([codecave:um_chaos.text]+0x2c0)83c4088b0c2485c974298b44240829c83d0010000072128b51fc83c1fc29d183f920731883c02389d15051e8([codecave:um_chaos.text]+0x2c0)83c40883c4205e5b5dc20c00ff15(<codecave:um_chaos_imports>+0x54)0f1f400083ec088b44240c8b542410c6442403e929c283c2fb895424048d5424036a055250e8([codecave:um_chaos.text]+0x1850)83c408c208000f1f400083ec088b44240c8b542410c6442403e929c283c2fb895424048d5424036a055250e8([codecave:um_chaos.text]+0x1850)83c408c208000f1f400083ec088b44240c8b542410c6442403e829c283c2fb895424048d5424036a055250e8([codecave:um_chaos.text]+0x1850)83c408c208000f1f400083ec088b44240c8b542410c6442403e829c283c2fb895424048d5424036a055250e8([codecave:um_chaos.text]+0x1850)83c408c208006690669055535756508b7c241885ff0f88d900000089ce8b098b4608890c2429c889c1d1e989ca81f2ffffff7f01c139f90f46cf8b5e0439d0bdffffff7f0f46e981fd00100000722083fddd0f83a10000008d452350e8([codecave:um_chaos.text]+0x2a0)83c4048d782383e7e08947fceb1385ed740d55e8([codecave:um_chaos.text]+0x2a0)83c40489c7eb0231ff2b1c248d041f8b4c241829d9516a0050e8[th_memset]83c40c8b068b4e0429c1515057e8[th_memmove]83c40c8b0e85c974288b460829c83d0010000072128b51fc83c1fc29d183f920733383c02389d15051e8([codecave:um_chaos.text]+0x2c0)83c408893e8b44241801f889460401fd896e0883c4045e5f5b5dc20800e8([codecave:um_chaos.text]+0x1b80)e8([codecave:um_chaos.text]+0xf50)ff15(<codecave:um_chaos_imports>+0x54)66906690669068(<codecave:um_chaos.rdata>+0x2d4)e8([codecave:um_chaos.text]+0x2e0)6690669066905553575683ec1089cd8b198b790429dfc1ff04478b490829d9c1f90489c8d1e8baffffff0fbeffffff0f29c601c839f80f46c739f10f47c23d000000100f836402000089c1c1e1043d00010000897c2408894c2404895c240c72223dfeffff0f0f83410200008d412350e8([codecave:um_chaos.text]+0x2a0)83c4048d782383e7e08947fceb0b51e8([codecave:um_chaos.text]+0x2a0)83c40489c78b4424288b5c242489de2b74240cc1fe04c1e6048b08890c378b480cc7400c00000000f20f104004c7400800000000c7400400000000f20f11443704894c370c8b45008b4d0439d9892c240f84a800000039d8744531c9908b140889140f8b54080cc744080c00000000f20f10440804c744080800000000c744080400000000f20f11440f0489540f0c8d140883c21083c11039da75c18b4d0439d90f84a50000008d043e83c01c31d266666666662e0f1f8400000000008b2c13896c10f48b6c130cc744130c00000000f20f10441304c744130800000000c744130400000000f20f114410f8892c108d2c1383c51083c21039cd75c1eb4e39d8745031c9660f1f8400000000008b140889140f8b54080cc744080c00000000f20f10440804c744080800000000c744080400000000f20f11440f0489540f0c8d140883c21083c11039da75c18b2c248b5d0085db0f849e0000008b6d0439eb75428b2c248b450829d83d00100000736ce9790000000f1f8400000000005051e8([codecave:um_chaos.text]+0x2c0)83c408c7430400000000c7430800000000c7430c0000000083c31039eb74278b4b0485c974f28b430c29c83d0010000072c78b51fc83c1fc29d183f920735b83c02389d1ebb38b2c248b5d008b450829d83d0010000072128b4bfc83c3fc29cb83fb20733583c02389cb5053e8([codecave:um_chaos.text]+0x2c0)83c40801fe897d008b442408c1e00401f88945048b44240401f889450889f083c4105e5f5b5dc20800ff15(<codecave:um_chaos_imports>+0x54)e8([codecave:um_chaos.text]+0xf50)669066905683ec286a20e8([codecave:um_chaos.text]+0x2a0)83c40489c6c700(<codecave:um_chaos.rdata>+0x2f4)68000070426800002041e8([codecave:um_chaos.text]+0x15f0)83c408894604c7461802000000c7461c020000006a02ff35<0x568C30>ff15(<codecave:um_chaos_imports>+0xb0)0f57c00f114424140f11442404c744242400000000c704242800000089e15150ff15(<codecave:um_chaos_imports>+0xac)0f104424040f11460889f083c4285ec30f1f00a1(<codecave:um_chaos.bss>+0x28)8d4801890d(<codecave:um_chaos.bss>+0x28)c1e002c78440(<codecave:um_chaos.bss>+0x2c)(<codecave:um_chaos.rdata>+0x2e4)c78440(<codecave:um_chaos.bss>+0x30)(<codecave:um_chaos.text>+0x1e40)c68440(<codecave:um_chaos.bss>+0x34)00c35689ce837c240800740956e8([codecave:um_chaos.text]+0x2b0)83c40489f05ec20400669066906690905683ec1089ceff35<0x568C30>ff15(<codecave:um_chaos_imports>+0xa0)85c0751aa1(<0x568C30>+0x2040)c1e80283e01f83f8097715b9070300000fa3c1730bff4e040f95c083c4105ec389e050ff35<0x568C30>ff15(<codecave:um_chaos_imports>+0xa8)8b04243b46087c298b4c24083b4e107f308b4c24043b4e0c7c378b54240c3b56147e3ec7461cfeffffffbafeffffffeb33c74618020000008b4c24083b4e107ed0c74618feffffff8b4c24043b4e0c7dc9c7461c020000008b54240c3b56147fc28b561c01ca0346186a096a006a0052506a00ff35<0x568C30>ff15(<codecave:um_chaos_imports>+0xa4)e962ffffff6690c3669066906690669066906690669090566a14e8([codecave:um_chaos.text]+0x2a0)83c40489c6c700(<codecave:um_chaos.rdata>+0x30c)68000070426800002041e8([codecave:um_chaos.text]+0x15f0)83c4088946048d4e08c7460800000000c7460c00000000c746100000000068<<codecave:bulletwrap_etnew_cave>>689d3e4300e8([codecave:um_chaos.text]+0x19f0)89f05ec3666666662e0f1f840000000000a1(<codecave:um_chaos.bss>+0x28)8d4801890d(<codecave:um_chaos.bss>+0x28)c1e002c78440(<codecave:um_chaos.bss>+0x2c)(<codecave:um_chaos.rdata>+0x300)c78440(<codecave:um_chaos.bss>+0x30)(<codecave:um_chaos.text>+0x1ff0)c68440(<codecave:um_chaos.bss>+0x34)00c35689cec701(<codecave:um_chaos.rdata>+0x30c)83c108e8([codecave:um_chaos.text]+0x1690)837c240800740956e8([codecave:um_chaos.text]+0x2b0)83c40489f05ec20400669066906690669090ff49040f95c0c3669066906690669090566a08e8([codecave:um_chaos.text]+0x2a0)83c40489c6c700(<codecave:um_chaos.rdata>+0x328)68000096436800002041e8([codecave:um_chaos.text]+0x15f0)83c40889460489f05ec30f1f4000a1(<codecave:um_chaos.bss>+0x28)8d4801890d(<codecave:um_chaos.bss>+0x28)c1e002c78440(<codecave:um_chaos.bss>+0x2c)(<codecave:um_chaos.rdata>+0x318)c78440(<codecave:um_chaos.bss>+0x30)(<codecave:um_chaos.text>+0x20c0)c68440(<codecave:um_chaos.bss>+0x34)00c35689ce837c240800740956e8([codecave:um_chaos.text]+0x2b0)83c40489f05ec2040066906690669090a1<0x4CF298>83c018eb0d660f1f4400008b400485c0740f8b1085d274f3c7423c00000000ebeaff49040f95c0c36690906a04e8([codecave:um_chaos.text]+0x2a0)83c404c700(<codecave:um_chaos.rdata>+0x340)c36666666666662e0f1f840000000000a1(<codecave:um_chaos.bss>+0x28)8d4801890d(<codecave:um_chaos.bss>+0x28)c1e002c78440(<codecave:um_chaos.bss>+0x2c)(<codecave:um_chaos.rdata>+0x334)c78440(<codecave:um_chaos.bss>+0x30)(<codecave:um_chaos.text>+0x2170)c68440(<codecave:um_chaos.bss>+0x34)00c35689ce837c240800740956e8([codecave:um_chaos.text]+0x2b0)83c40489f05ec20400669066906690908b0d<0x4CF2BC>6a00e8[0x4297A0]8b0d<0x4CF3F4>6a006a01e8[0x449090]31c0c39057566a14e8([codecave:um_chaos.text]+0x2a0)83c40489c6c700(<codecave:um_chaos.rdata>+0x360)680000f0426800002041e8([codecave:um_chaos.text]+0x15f0)83c4088946048d7e08c7460800000000c7460c00000000c746100000000089f968<<codecave:doublebulletcount_cave1>>6877424300e8([codecave:um_chaos.text]+0x19f0)89f968<<codecave:doublebulletcount_cave2>>68d1464300e8([codecave:um_chaos.text]+0x19f0)89f968<<codecave:doublebulletcount_cave3>>682a484300e8([codecave:um_chaos.text]+0x19f0)89f968<<codecave:doublebulletcount_cave1>>68d1434300e8([codecave:um_chaos.text]+0x19f0)89f05e5fc3660f1f440000a1(<codecave:um_chaos.bss>+0x28)8d4801890d(<codecave:um_chaos.bss>+0x28)c1e002c78440(<codecave:um_chaos.bss>+0x2c)(<codecave:um_chaos.rdata>+0x34c)c78440(<codecave:um_chaos.bss>+0x30)(<codecave:um_chaos.text>+0x2200)c68440(<codecave:um_chaos.bss>+0x34)00c35689cec701(<codecave:um_chaos.rdata>+0x360)83c108e8([codecave:um_chaos.text]+0x1690)837c240800740956e8([codecave:um_chaos.text]+0x2b0)83c40489f05ec20400669066906690669090ff49040f95c0c36690669066906690905756506a14e8([codecave:um_chaos.text]+0x2a0)83c40489c6c700(<codecave:um_chaos.rdata>+0x388)680000f0426800002041e8([codecave:um_chaos.text]+0x15f0)83c4088946048d7e08c7460800000000c7460c00000000c7461000000000e8([codecave:um_chaos.text]+0x1650)d91c24f30f100424f30f5905(<codecave:um_chaos.rdata>+0x36c)f30f5805(<codecave:um_chaos.rdata>+0x370)f30f1105(<codecave:um_chaos.data>+0x4)89f968<<codecave:eclwaitmultiplier_diffwait_cave>>68ad5f4300e8([codecave:um_chaos.text]+0x1a50)89f968<<codecave:eclwaitmultiplier_diffwait_cave>>68d65f4300e8([codecave:um_chaos.text]+0x1a50)89f968<<codecave:eclwaitmultiplier_diffwait_cave>>68855f4300e8([codecave:um_chaos.text]+0x1a50)89f968<<codecave:eclwaitmultiplier_wait_cave>>683bb74800e8([codecave:um_chaos.text]+0x19f0)89f968<<codecave:eclwaitmultiplier_waitf_cave>>6855b74800e8([codecave:um_chaos.text]+0x19f0)89f083c4045e5fc36666662e0f1f840000000000a1(<codecave:um_chaos.bss>+0x28)8d4801890d(<codecave:um_chaos.bss>+0x28)c1e002c78440(<codecave:um_chaos.bss>+0x2c)(<codecave:um_chaos.rdata>+0x374)c78440(<codecave:um_chaos.bss>+0x30)(<codecave:um_chaos.text>+0x2300)c68440(<codecave:um_chaos.bss>+0x34)00c35689cec701(<codecave:um_chaos.rdata>+0x388)83c108e8([codecave:um_chaos.text]+0x1690)837c240800740956e8([codecave:um_chaos.text]+0x2b0)83c40489f05ec20400669066906690669090ff49040f95c0c36690669066906690906a04e8([codecave:um_chaos.text]+0x2a0)83c404c700(<codecave:um_chaos.rdata>+0x3a0)c36666666666662e0f1f840000000000a1(<codecave:um_chaos.bss>+0x28)8d4801890d(<codecave:um_chaos.bss>+0x28)c1e002c78440(<codecave:um_chaos.bss>+0x2c)(<codecave:um_chaos.rdata>+0x394)c78440(<codecave:um_chaos.bss>+0x30)(<codecave:um_chaos.text>+0x2440)c68440(<codecave:um_chaos.bss>+0x34)00c35689ce837c240800740956e8([codecave:um_chaos.text]+0x2b0)83c40489f05ec20400669066906690905553575683ec78c7442404000000008d44240450ff35(<codecave:um_chaos.bss>+0x2060)ff15(<codecave:um_chaos_imports>+0x18)64a1180000008b40308b780c8b5f0c83c70c39fb0f847c01000085db0f84740100008b2d(<codecave:um_chaos_imports>+0x64)0f1f84000000000068(<codecave:um_chaos.rdata>+0x3ac)ff7330ffd583c40885c0751268(<codecave:um_chaos.rdata>+0x3c6)ff7318ff15(<codecave:um_chaos_imports>+0x24)85c075138b1b39fb0f843901000085db75cfe93001000089c6c704240000000089e05068(<codecave:um_chaos.rdata>+0x3d9)6802000080ff15(<codecave:um_chaos_imports>+0xb8)89c78b042485c0740750ff15(<codecave:um_chaos_imports>+0xb4)e8[0x444D80]b9<0x56AD80>68(<codecave:um_chaos.rdata>+0x40e)6a006a06e8[0x477A50]660f1f440000b9<0x56AD80>e8[0x476D20]84c075f28b1d(<codecave:um_chaos_imports>+0x84)688a7f00006a00ffd38b2d(<codecave:um_chaos_imports>+0x80)50ffd568f4010000ff15(<codecave:um_chaos_imports>+0x30)68007f00006a00ffd350ffd50f1005(<codecave:um_chaos.rdata>+0x45c)0f114424680f57c00f114424180f114424280f114424580f114424480f11442438c744240860000000a1<0x568C30>8944240cc744241000004000c744241410000000c7442424(<codecave:um_chaos.rdata>+0x46c)c7442428(<codecave:um_chaos.rdata>+0x4a6)31c083ff0183d0018944242cc744241c(<codecave:um_chaos.rdata>+0x54a)8d44246889442430c7442420(<codecave:um_chaos.rdata>+0x55c)8d4424086a006a006a0050ffd6b9<0x56AD80>68(<codecave:um_chaos.rdata>+0x570)6a006a07e8[0x477A50]ff7424046a00ff15(<codecave:um_chaos_imports>+0x2c)31c083c4785e5f5b5dc3566a1ce8([codecave:um_chaos.text]+0x2a0)83c40489c6c700(<codecave:um_chaos.rdata>+0x5ec)680000f0426800002041e8([codecave:um_chaos.text]+0x15f0)83c408894604a1<0x4CF410>f20f108020060000f20f1146088b8028060000894610f20f1005(<codecave:um_chaos.rdata>+0x580)f20f11461489f05ec36666662e0f1f840000000000a1(<codecave:um_chaos.bss>+0x28)8d4801890d(<codecave:um_chaos.bss>+0x28)c1e002c78440(<codecave:um_chaos.bss>+0x2c)(<codecave:um_chaos.rdata>+0x5e0)c78440(<codecave:um_chaos.bss>+0x30)(<codecave:um_chaos.text>+0x2670)c68440(<codecave:um_chaos.bss>+0x34)00c35689ce837c240800740956e8([codecave:um_chaos.text]+0x2b0)83c40489f05ec2040066906690669090f30f104114f30f1049180f2ec1760ef30f5805(<codecave:um_chaos.rdata>+0x594)f30f5fc1eb110f2ec87611f30f5805(<codecave:um_chaos.rdata>+0x590)f30f5dc1f30f114114a1<0x4CF410>f20f108020060000f20f1049080f5cc10f5905(<codecave:um_chaos.rdata>+0x5a0)0f58c10f1341088b410483f81d7707c741180000c845488941040f95c0c3669090575683ec1cf20f1005(<codecave:um_chaos.rdata>+0x608)f20f114424140f1005(<codecave:um_chaos.rdata>+0x5f8)0f11442404f30f100d(<0x568C30>+0x2070)f30f1041140f105908a1(<0x4CCDF0>+0x1c8)f30f10510cf30f5815(<codecave:um_chaos.rdata>+0x5b0)f20f1060540f16d30fc6d3e20f59d40f5815(<codecave:um_chaos.rdata>+0x5c0)f30f59c10f5815(<codecave:um_chaos.rdata>+0x5d0)0fc6c9000f59ca0fc6c0000f28d10f5cd00f1315(<codecave:um_chaos.data>+0x8)0f28da0fc6da55f30f111d(<codecave:um_chaos.data>+0x28)f30f1115(<codecave:um_chaos.data>+0x40)0f58c1f30f1105(<codecave:um_chaos.data>+0x24)0f28c80fc6c855f30f110d(<codecave:um_chaos.data>+0x44)0f1305(<codecave:um_chaos.data>+0x5c)8b3d<0x4CA428>83e7088b35(<0x4CCDF0>+0x8)c70424000000008b0689e1516a0056ff90000100008b06684401000056ff90640100008b06ff35(<codecave:um_chaos.bss>+0x8)6a0056ff900401000089f9c1e90283c10285ffb806000000ba0c0000000f44d08b068d7c24046a1c68(<codecave:um_chaos.data>+0x8)6a655751526a006a0456ff90500100008b06ff34246a0056ff900401000083c41c5e5fc36690566a08e8([codecave:um_chaos.text]+0x2a0)83c40489c6c700(<codecave:um_chaos.rdata>+0x618)680000a040680000803fe8([codecave:um_chaos.text]+0x15f0)83c408894604a1<0x4CF2E4>8188b000000000040000e8[0x444D80]b9<0x56AD80>68(<codecave:um_chaos.rdata>+0x40e)6a006a06e8[0x477A50]90b9<0x56AD80>e8[0x476D20]84c075f289f05ec366666666662e0f1f840000000000a1(<codecave:um_chaos.bss>+0x28)8d4801890d(<codecave:um_chaos.bss>+0x28)c1e002c78440(<codecave:um_chaos.bss>+0x2c)(<codecave:um_chaos.rdata>+0x610)c78440(<codecave:um_chaos.bss>+0x30)(<codecave:um_chaos.text>+0x28d0)c68440(<codecave:um_chaos.bss>+0x34)00c35689cec701(<codecave:um_chaos.rdata>+0x618)a1<0x4CF2E4>81a0b0000000fffbffffb9<0x56AD80>68(<codecave:um_chaos.rdata>+0x570)6a006a07e8[0x477A50]837c240800740956e8([codecave:um_chaos.text]+0x2b0)83c40489f05ec20400669066906690669066906690669090ff49040f95c0c366906690669066909056506a14e8([codecave:um_chaos.text]+0x2a0)83c40489c6c700(<codecave:um_chaos.rdata>+0x634)680000f0426800002041e8([codecave:um_chaos.text]+0x15f0)83c4088946048d4e08c7460800000000c7460c00000000c7461000000000c6442403eb8d4424036a015068debc4500e8([codecave:um_chaos.text]+0x1840)89f083c4045ec36690a1(<codecave:um_chaos.bss>+0x28)8d4801890d(<codecave:um_chaos.bss>+0x28)c1e002c78440(<codecave:um_chaos.bss>+0x2c)(<codecave:um_chaos.rdata>+0x624)c78440(<codecave:um_chaos.bss>+0x30)(<codecave:um_chaos.text>+0x29d0)c68440(<codecave:um_chaos.bss>+0x34)00c35689cec701(<codecave:um_chaos.rdata>+0x634)83c108e8([codecave:um_chaos.text]+0x1690)837c240800740956e8([codecave:um_chaos.text]+0x2b0)83c40489f05ec20400669066906690669090ff49040f95c0c36690669066906690905756506a0ce8([codecave:um_chaos.text]+0x2a0)83c40489c6c700(<codecave:um_chaos.rdata>+0x64c)6a026a01e8([codecave:um_chaos.text]+0x15b0)83c40883f801751e680000a040680000803ee8([codecave:um_chaos.text]+0x15f0)f30f1005(<codecave:um_chaos.rdata>+0x2d0)83c40889c7eb3168000070426800002041e8([codecave:um_chaos.text]+0x15f0)83c40889c7e8([codecave:um_chaos.text]+0x1650)d91c24f30f100424f30f5905(<codecave:um_chaos.rdata>+0x36c)f30f5805(<codecave:um_chaos.rdata>+0x370)897e04f30f114608f30f1105<0x4CCBF0>89f083c4045e5fc30f1f00a1(<codecave:um_chaos.bss>+0x28)8d4801890d(<codecave:um_chaos.bss>+0x28)c1e002c78440(<codecave:um_chaos.bss>+0x2c)(<codecave:um_chaos.rdata>+0x640)c78440(<codecave:um_chaos.bss>+0x30)(<codecave:um_chaos.text>+0x2aa0)c68440(<codecave:um_chaos.bss>+0x34)00c35689cec701(<codecave:um_chaos.rdata>+0x64c)c705<0x4CCBF0>0000803f837c240800740956e8([codecave:um_chaos.text]+0x2b0)83c40489f05ec2040066906690669090f30f104108f30f1105<0x4CCBF0>ff49040f95c0c36690669066906690669066905683ec086a14e8([codecave:um_chaos.text]+0x2a0)83c40489c6c700(<codecave:um_chaos.rdata>+0x664)680000f0426800002041e8([codecave:um_chaos.text]+0x15f0)83c4088946048d4e08c7460800000000c7460c00000000c7461000000000c744240400000000c704240f1f840089e06a0850687d5c4400e8([codecave:um_chaos.text]+0x1840)89f083c4085ec30f1f840000000000a1(<codecave:um_chaos.bss>+0x28)8d4801890d(<codecave:um_chaos.bss>+0x28)c1e002c78440(<codecave:um_chaos.bss>+0x2c)(<codecave:um_chaos.rdata>+0x658)c78440(<codecave:um_chaos.bss>+0x30)(<codecave:um_chaos.text>+0x2bb0)c68440(<codecave:um_chaos.bss>+0x34)00c35689cec701(<codecave:um_chaos.rdata>+0x664)83c108e8([codecave:um_chaos.text]+0x1690)837c240800740956e8([codecave:um_chaos.text]+0x2b0)83c40489f05ec20400669066906690669090ff49040f95c0c366906690669066909056506a14e8([codecave:um_chaos.text]+0x2a0)83c40489c6c700(<codecave:um_chaos.rdata>+0x69c)680000f0426800002041e8([codecave:um_chaos.text]+0x15f0)83c4088946048d4e08c7460800000000c7460c00000000c7461000000000c64424035c8d4424036a0150681d614400e8([codecave:um_chaos.text]+0x1840)a1<0x4CF410>f30f1080887904000f5605(<codecave:um_chaos.rdata>+0x670)f30f11808879040089f083c4045ec3660f1f440000a1(<codecave:um_chaos.bss>+0x28)8d4801890d(<codecave:um_chaos.bss>+0x28)c1e002c78440(<codecave:um_chaos.bss>+0x2c)(<codecave:um_chaos.rdata>+0x690)c78440(<codecave:um_chaos.bss>+0x30)(<codecave:um_chaos.text>+0x2c90)c68440(<codecave:um_chaos.bss>+0x34)00c35689cec701(<codecave:um_chaos.rdata>+0x69c)a1<0x4CF410>f30f1080887904000f5405(<codecave:um_chaos.rdata>+0x680)f30f11808879040083c108e8([codecave:um_chaos.text]+0x1690)837c240800740956e8([codecave:um_chaos.text]+0x2b0)83c40489f05ec2040066906690669066906690669090ff49040f95c0c3669066906690669090566a08e8([codecave:um_chaos.text]+0x2a0)83c40489c6c700(<codecave:um_chaos.rdata>+0x6b0)680000f0426800002041e8([codecave:um_chaos.text]+0x15f0)83c40889460489f05ec30f1f4000a1(<codecave:um_chaos.bss>+0x28)8d4801890d(<codecave:um_chaos.bss>+0x28)c1e002c78440(<codecave:um_chaos.bss>+0x2c)(<codecave:um_chaos.rdata>+0x6a8)c78440(<codecave:um_chaos.bss>+0x30)(<codecave:um_chaos.text>+0x2da0)c68440(<codecave:um_chaos.bss>+0x34)00c35689ce837c240800740956e8([codecave:um_chaos.text]+0x2b0)83c40489f05ec20400669066906690905689ce68000100006800ffffffe8([codecave:um_chaos.text]+0x15b0)83c4088b0d<0x4CF410>01812c06000068000100006800ffffffe8([codecave:um_chaos.text]+0x15b0)83c4088b0d<0x4CF410>018130060000ff4e040f95c05ec366906690669066909057566a08e8([codecave:um_chaos.text]+0x2a0)83c40489c6c700(<codecave:um_chaos.rdata>+0x6e8)680000f0426800002041e8([codecave:um_chaos.text]+0x15f0)83c408894604c605(<codecave:um_chaos.bss>+0x2064)01a1(<codecave:um_chaos.bss>+0x4)85c0742b8b3d(<codecave:um_chaos_imports>+0x98)506a006880000000ff35<0x568C30>ffd7ff35(<codecave:um_chaos.bss>+0x4)6a016880000000ff35<0x568C30>ffd789f05e5fc30f1f8000000000a1(<codecave:um_chaos.bss>+0x28)8d4801890d(<codecave:um_chaos.bss>+0x28)c1e002c78440(<codecave:um_chaos.bss>+0x2c)(<codecave:um_chaos.rdata>+0x6e0)c78440(<codecave:um_chaos.bss>+0x30)(<codecave:um_chaos.text>+0x2e70)c68440(<codecave:um_chaos.bss>+0x34)00c38b442404c605(<codecave:um_chaos.bss>+0x2065)0150e8[0x481210]c605(<codecave:um_chaos.bss>+0x2065)00c204000f1f440000575689ce8b7c240c803d(<codecave:um_chaos.bss>+0x2064)007436803d(<codecave:um_chaos.bss>+0x2065)00752d0f57c00f134714f30f1005(<codecave:um_chaos.rdata>+0x6bc)0f134730f20f1005(<codecave:um_chaos.rdata>+0x6c0)f20f11474cf20f1005(<codecave:um_chaos.rdata>+0x6d0)f20f114768a1(<codecave:um_chaos.bss>+0x2068)85c00f844901000050f7d850e8([codecave:um_chaos.text]+0x15b0)83c4080f57c0f30f2ac0f30f5905(<0x568C30>+0x2070)f30f5807f30f1107a1(<codecave:um_chaos.bss>+0x2068)50f7d850e8([codecave:um_chaos.text]+0x15b0)83c4080f57c0f30f2ac0f30f5905(<0x568C30>+0x2070)f30f584704f30f114704a1(<codecave:um_chaos.bss>+0x2068)50f7d850e8([codecave:um_chaos.text]+0x15b0)83c4080f57c0f30f2ac0f30f5905(<0x568C30>+0x2070)f30f58471cf30f11471ca1(<codecave:um_chaos.bss>+0x2068)50f7d850e8([codecave:um_chaos.text]+0x15b0)83c4080f57c0f30f2ac0f30f5905(<0x568C30>+0x2070)f30f584720f30f114720a1(<codecave:um_chaos.bss>+0x2068)50f7d850e8([codecave:um_chaos.text]+0x15b0)83c4080f57c0f30f2ac0f30f5905(<0x568C30>+0x2070)f30f584738f30f114738a1(<codecave:um_chaos.bss>+0x2068)50f7d850e8([codecave:um_chaos.text]+0x15b0)83c4080f57c0f30f2ac0f30f5905(<0x568C30>+0x2070)f30f58473cf30f11473ca1(<codecave:um_chaos.bss>+0x2068)50f7d850e8([codecave:um_chaos.text]+0x15b0)83c4080f57c0f30f2ac0f30f5905(<0x568C30>+0x2070)f30f584754f30f114754a1(<codecave:um_chaos.bss>+0x2068)50f7d850e8([codecave:um_chaos.text]+0x15b0)83c4080f57c0f30f2ac0f30f5905(<0x568C30>+0x2070)f30f584758f30f11475889f15e5fe9[0x47E800]662e0f1f840000000000803d(<codecave:um_chaos.bss>+0x2065)00b8<codecave:um_chaos.bss>8d4c240c0f45c1803d(<codecave:um_chaos.bss>+0x2064)008b5424040f44c18b0aff306a0052ff9104010000c20c0066906690669066906690669066909053575689ce8b7c2410c701(<codecave:um_chaos.rdata>+0x6e8)c605(<codecave:um_chaos.bss>+0x2064)00a1(<codecave:um_chaos.bss>+0xc)85c0742b8b1d(<codecave:um_chaos_imports>+0x98)506a006880000000ff35<0x568C30>ffd3ff35(<codecave:um_chaos.bss>+0xc)6a016880000000ff35<0x568C30>ffd385ff740956e8([codecave:um_chaos.text]+0x2b0)83c40489f05e5f5bc2040090ff49040f95c0c36690669066906690906a04e8([codecave:um_chaos.text]+0x2a0)83c404c700(<codecave:um_chaos.rdata>+0x700)c36666666666662e0f1f840000000000a1(<codecave:um_chaos.bss>+0x28)8d4801890d(<codecave:um_chaos.bss>+0x28)c1e002c78440(<codecave:um_chaos.bss>+0x2c)(<codecave:um_chaos.rdata>+0x6f4)c78440(<codecave:um_chaos.bss>+0x30)(<codecave:um_chaos.text>+0x3190)c68440(<codecave:um_chaos.bss>+0x34)00c35689ce837c240800740956e8([codecave:um_chaos.text]+0x2b0)83c40489f05ec20400669066906690906a006820f000006812010000ff35<0x568C30>ff15(<codecave:um_chaos_imports>+0x70)31c0c366906690905683ec086a14e8([codecave:um_chaos.text]+0x2a0)83c40489c6c700(<codecave:um_chaos.rdata>+0x740)680000f0426800002041e8([codecave:um_chaos.text]+0x15f0)83c4088946048d4e08c7460800000000c7460c00000000c746100000000068(<codecave:um_chaos.text>+0x3350)68ccc04500e8([codecave:um_chaos.text]+0x1a50)a1<0x4CF410>f30f108820060000f30f2a05(<0x568C30>+0x205c)f30f580d(<codecave:um_chaos.rdata>+0x70c)f20f1015(<0x568C30>+0x2068)0f28da0fc6da550f5bdbf30f5ec3f30f1098240600000f14cb0f580d(<codecave:um_chaos.rdata>+0x5d0)f30f101d(<0x568C30>+0x2070)0fc6db000f59d9f30f7e0d(<0x568C30>+0x2050)660ffad10f5bca0f590d(<codecave:um_chaos.rdata>+0x710)0f58cb0fc6c0000f59c1f30f5bc00f13042489e050ff35<0x568C30>ff15(<codecave:um_chaos_imports>+0x94)ff742404ff742404ff15(<codecave:um_chaos_imports>+0x90)89f083c4085ec366666666662e0f1f840000000000a1(<codecave:um_chaos.bss>+0x28)8d4801890d(<codecave:um_chaos.bss>+0x28)c1e002c78440(<codecave:um_chaos.bss>+0x2c)(<codecave:um_chaos.rdata>+0x730)c78440(<codecave:um_chaos.bss>+0x30)(<codecave:um_chaos.text>+0x3220)c68440(<codecave:um_chaos.bss>+0x34)00c35553575683ec0889cee8[0x45B170]ff35<0x568C30>ff15(<codecave:um_chaos_imports>+0xa0)85c00f850901000089e757ff15(<codecave:um_chaos_imports>+0x8c)57ff35<0x568C30>ff15(<codecave:um_chaos_imports>+0x88)f30f2a1424a1(<0x568C30>+0x206c)f30f2ac0f30f2a0d(<0x568C30>+0x205c)8b0d(<0x568C30>+0x2068)2b0d(<0x568C30>+0x2050)f30f2ad9f30f5ec1f30f591d(<codecave:um_chaos.rdata>+0x720)f30f59d0f30f58d3f30f100d(<0x568C30>+0x2070)f30f5ed1f30f5815(<codecave:um_chaos.rdata>+0x724)f30f5815(<codecave:um_chaos.rdata>+0x728)8b5424048b0d(<0x568C30>+0x2054)f30f119620060000f30f5915(<codecave:um_chaos.rdata>+0x200)f30f2cfa89fbf30f5c15(<codecave:um_chaos.rdata>+0x204)c1fb1ff30f2cea21dd09fd89ae2c060000803d(<codecave:um_chaos.bss>+0x206c)00755b0f57d2f30f2ad229c80f57dbf30f2ad8f30f591d(<codecave:um_chaos.rdata>+0x720)f30f59d0f30f58d3f30f5ed1f30f5815(<codecave:um_chaos.rdata>+0x72c)f30f119624060000f30f5915(<codecave:um_chaos.rdata>+0x200)f30f2cc289c1f30f5c15(<codecave:um_chaos.rdata>+0x204)f30f2cd2c1f91f21ca09c289963006000031c083c4085e5f5b5dc366906690669066906690905689cec701(<codecave:um_chaos.rdata>+0x740)83c108e8([codecave:um_chaos.text]+0x1690)837c240800740956e8([codecave:um_chaos.text]+0x2b0)83c40489f05ec20400669066906690669090ff49040f95c0c366906690669066909056506a14e8([codecave:um_chaos.text]+0x2a0)83c40489c6c700(<codecave:um_chaos.rdata>+0x754)680000f0426800002041e8([codecave:um_chaos.text]+0x15f0)83c4088946048d4e08c7460800000000c7460c00000000c7461000000000c64424029066c7042433d289e06a03506803b44500e8([codecave:um_chaos.text]+0x1840)89f083c4045ec366666666662e0f1f840000000000a1(<codecave:um_chaos.bss>+0x28)8d4801890d(<codecave:um_chaos.bss>+0x28)c1e002c78440(<codecave:um_chaos.bss>+0x2c)(<codecave:um_chaos.rdata>+0x74c)c78440(<codecave:um_chaos.bss>+0x30)(<codecave:um_chaos.text>+0x34d0)c68440(<codecave:um_chaos.bss>+0x34)00c35689cec701(<codecave:um_chaos.rdata>+0x754)83c108e8([codecave:um_chaos.text]+0x1690)837c240800740956e8([codecave:um_chaos.text]+0x2b0)83c40489f05ec20400669066906690669090ff49040f95c0c36690669066906690905683ec146a14e8([codecave:um_chaos.text]+0x2a0)83c40489c6c700(<codecave:um_chaos.rdata>+0x770)680000f0426800002041e8([codecave:um_chaos.text]+0x15f0)83c4088946048d4e08c7460800000000c7460c00000000c74610000000000f1005(<codecave:um_chaos.rdata>+0x77c)0f110424c744240f7604000089e06a1350681ab44500e8([codecave:um_chaos.text]+0x1840)c605(<codecave:um_chaos.bss>+0x206c)0189f083c4145ec3666666662e0f1f840000000000a1(<codecave:um_chaos.bss>+0x28)8d4801890d(<codecave:um_chaos.bss>+0x28)c1e002c78440(<codecave:um_chaos.bss>+0x2c)(<codecave:um_chaos.rdata>+0x763)c78440(<codecave:um_chaos.bss>+0x30)(<codecave:um_chaos.text>+0x35b0)c68440(<codecave:um_chaos.bss>+0x34)00c35689cec701(<codecave:um_chaos.rdata>+0x770)c605(<codecave:um_chaos.bss>+0x206c)0083c108e8([codecave:um_chaos.text]+0x1690)837c240800740956e8([codecave:um_chaos.text]+0x2b0)83c40489f05ec204006690ff49040f95c0c36690669066906690906a04e8([codecave:um_chaos.text]+0x2a0)83c404c700(<codecave:um_chaos.rdata>+0x798)c36666666666662e0f1f840000000000a1(<codecave:um_chaos.bss>+0x28)8d4801890d(<codecave:um_chaos.bss>+0x28)c1e002c78440(<codecave:um_chaos.bss>+0x2c)(<codecave:um_chaos.rdata>+0x78f)c78440(<codecave:um_chaos.bss>+0x30)(<codecave:um_chaos.text>+0x36a0)c68440(<codecave:um_chaos.bss>+0x34)00c35689ce837c240800740956e8([codecave:um_chaos.text]+0x2b0)83c40489f05ec20400669066906690905683ec0c683c0e0000e8([codecave:um_chaos.text]+0x2a0)83c40489c6a3<0x4CF2A4>683c0e00006a0050e8[th_memset]83c40cc744240800000000c744240400000042c704240000e04389e089f150e8[0x4171B0]31c083c40c5ec3566a14e8([codecave:um_chaos.text]+0x2a0)83c40489c6c700(<codecave:um_chaos.rdata>+0x7c0)680000f0426800002041e8([codecave:um_chaos.text]+0x15f0)83c4088946048d4e08c7460800000000c7460c00000000c746100000000068(<codecave:um_chaos.text>+0x37f0)6814b34800e8([codecave:um_chaos.text]+0x1a50)89f05ec3666666662e0f1f840000000000a1(<codecave:um_chaos.bss>+0x28)8d4801890d(<codecave:um_chaos.bss>+0x28)c1e002c78440(<codecave:um_chaos.bss>+0x2c)(<codecave:um_chaos.rdata>+0x7b0)c78440(<codecave:um_chaos.bss>+0x30)(<codecave:um_chaos.text>+0x3760)c68440(<codecave:um_chaos.bss>+0x34)00c353575689ce8b7c241057e8[th_strlen]83c40483f8040f82c40000000fb74c38fd81f15f6100000fb65438ff83f2746609ca742583f8050f82a30000000fb74c38fc81f15f6100000fb64438fe83f0746609c80f85870000006a0468(<codecave:um_chaos.rdata>+0x7d0)57ff15(<codecave:um_chaos_imports>+0x68)83c40c85c0742f6a0568(<codecave:um_chaos.rdata>+0x7d5)57ff15(<codecave:um_chaos_imports>+0x68)83c40c85c0b9(<codecave:um_chaos.bss>+0x20)b8(<codecave:um_chaos.bss>+0x14)0f44c1b9(<codecave:um_chaos.bss>+0x1c)bb(<codecave:um_chaos.bss>+0x10)0f44d9eb0abb(<codecave:um_chaos.bss>+0x1c)b8(<codecave:um_chaos.bss>+0x20)8b002b03c1f80248506a00e8([codecave:um_chaos.text]+0x15b0)83c4088b0b8b1c81535768(<codecave:um_chaos.rdata>+0x7db)e8([codecave:um_chaos.text]+0xdc0)83c40c8b86041200004083e00f89860412000089df89f157e8[0x48D920]5e5f5bc204006690905689cec701(<codecave:um_chaos.rdata>+0x7c0)83c108e8([codecave:um_chaos.text]+0x1690)837c240800740956e8([codecave:um_chaos.text]+0x2b0)83c40489f05ec20400669066906690669090ff49040f95c0c366906690669066909057566a14e8([codecave:um_chaos.text]+0x2a0)83c40489c6c700(<codecave:um_chaos.rdata>+0x804)680000f0426800002041e8([codecave:um_chaos.text]+0x15f0)83c4088946048d7e08c7460800000000c7460c00000000c746100000000089f968(<codecave:um_chaos.text>+0x39c0)6845404300e8([codecave:um_chaos.text]+0x1a50)89f968(<codecave:um_chaos.text>+0x39e0)6855404300e8([codecave:um_chaos.text]+0x1a50)89f05e5fc30f1f840000000000a1(<codecave:um_chaos.bss>+0x28)8d4801890d(<codecave:um_chaos.bss>+0x28)c1e002c78440(<codecave:um_chaos.bss>+0x2c)(<codecave:um_chaos.rdata>+0x7f2)c78440(<codecave:um_chaos.bss>+0x30)(<codecave:um_chaos.text>+0x3920)c68440(<codecave:um_chaos.bss>+0x34)00c36a2b6a00e8([codecave:um_chaos.text]+0x15b0)83c4088b0c85(<codecave:um_chaos.rdata>+0x810)890d(<codecave:um_chaos.bss>+0x2070)c2040066906690ff35(<codecave:um_chaos.bss>+0x2070)6a00e8([codecave:um_chaos.text]+0x15b0)83c408c20400669066906690669066906690905689cec701(<codecave:um_chaos.rdata>+0x804)83c108e8([codecave:um_chaos.text]+0x1690)837c240800740956e8([codecave:um_chaos.text]+0x2b0)83c40489f05ec20400669066906690669090ff49040f95c0c36690669066906690906a14e8([codecave:um_chaos.text]+0x2a0)83c40489c1e9([codecave:um_chaos.text]+0x3a90)6666666666662e0f1f840000000000a1(<codecave:um_chaos.bss>+0x28)8d4801890d(<codecave:um_chaos.bss>+0x28)c1e002c78440(<codecave:um_chaos.bss>+0x2c)(<codecave:um_chaos.rdata>+0x8c0)c78440(<codecave:um_chaos.bss>+0x30)(<codecave:um_chaos.text>+0x3a40)c68440(<codecave:um_chaos.bss>+0x34)00c3575689cec701(<codecave:um_chaos.rdata>+0x8cc)6800002041680000a040e8([codecave:um_chaos.text]+0x15f0)83c4088946048d7e08c7460800000000c7460c00000000c746100000000089f968(<codecave:um_chaos.text>+0x3b70)680bd34000e8([codecave:um_chaos.text]+0x1a50)89f968(<codecave:um_chaos.text>+0x3b70)6813d74000e8([codecave:um_chaos.text]+0x1a50)89f968(<codecave:um_chaos.text>+0x3b70)68a7914200e8([codecave:um_chaos.text]+0x1a50)89f968(<codecave:um_chaos.text>+0x3b70)6843924200e8([codecave:um_chaos.text]+0x1a50)89f968(<codecave:um_chaos.text>+0x3b70)68eed04200e8([codecave:um_chaos.text]+0x1a50)89f968(<codecave:um_chaos.text>+0x3b70)6893044300e8([codecave:um_chaos.text]+0x1a50)89f968(<codecave:um_chaos.text>+0x3b70)6824064300e8([codecave:um_chaos.text]+0x1a50)89f968(<codecave:um_chaos.text>+0x3b70)6845504300e8([codecave:um_chaos.text]+0x1a50)89f968(<codecave:um_chaos.text>+0x3b70)680ac24500e8([codecave:um_chaos.text]+0x1a50)89f05e5fc366906690669066906690905553575683ec2089ce8b6c24488b7c244c8b5c2450c744240413000000c7042401000000e8([codecave:um_chaos.text]+0x15b0)895c241c897c2418896c2414f30f10442444f30f11442410f30f10442440f30f1144240c8b4c243c894c24088b4c2438894c240489042489f1e8[0x446F40]5e5f5b5dc2200066905689cec701(<codecave:um_chaos.rdata>+0x8cc)83c108e8([codecave:um_chaos.text]+0x1690)837c240800740956e8([codecave:um_chaos.text]+0x2b0)83c40489f05ec20400669066906690669090ff49040f95c0c366906690669066909056506a14e8([codecave:um_chaos.text]+0x2a0)83c40489c6c700(<codecave:um_chaos.rdata>+0x8e4)68000070426800002041e8([codecave:um_chaos.text]+0x15f0)83c4088946048d4e08c7460800000000c7460c00000000c7461000000000c6442403b08d4424036a015068af554500e8([codecave:um_chaos.text]+0x1840)89f083c4045ec36690a1(<codecave:um_chaos.bss>+0x28)8d4801890d(<codecave:um_chaos.bss>+0x28)c1e002c78440(<codecave:um_chaos.bss>+0x2c)(<codecave:um_chaos.rdata>+0x8d8)c78440(<codecave:um_chaos.bss>+0x30)(<codecave:um_chaos.text>+0x3c20)c68440(<codecave:um_chaos.bss>+0x34)00c35689cec701(<codecave:um_chaos.rdata>+0x8e4)83c108e8([codecave:um_chaos.text]+0x1690)837c240800740956e8([codecave:um_chaos.text]+0x2b0)83c40489f05ec20400669066906690669090ff49040f95c0c36690669066906690906a04e8([codecave:um_chaos.text]+0x2a0)83c404c700(<codecave:um_chaos.rdata>+0x8f8)c36666666666662e0f1f840000000000a1(<codecave:um_chaos.bss>+0x28)8d4801890d(<codecave:um_chaos.bss>+0x28)c1e002c78440(<codecave:um_chaos.bss>+0x2c)(<codecave:um_chaos.rdata>+0x8f0)c78440(<codecave:um_chaos.bss>+0x30)(<codecave:um_chaos.text>+0x3cf0)c68440(<codecave:um_chaos.bss>+0x34)00c35689ce837c240800740956e8([codecave:um_chaos.text]+0x2b0)83c40489f05ec2040066906690669090a1<0x4CF410>c780ac76040000000000c7803c06000000000000c7803806000000000000c7807c77040000008c43c780787704001801000031c0c36690669066906a04e8([codecave:um_chaos.text]+0x2a0)83c404c700(<codecave:um_chaos.rdata>+0x914)c36666666666662e0f1f840000000000a1(<codecave:um_chaos.bss>+0x28)8d4801890d(<codecave:um_chaos.bss>+0x28)c1e002c78440(<codecave:um_chaos.bss>+0x2c)(<codecave:um_chaos.rdata>+0x904)c78440(<codecave:um_chaos.bss>+0x30)(<codecave:um_chaos.text>+0x3da0)c68440(<codecave:um_chaos.bss>+0x34)00c3b9(<codecave:um_chaos.bss>+0x2074)e9([codecave:um_chaos.text]+0x1690)660f1f440000c705(<codecave:um_chaos.bss>+0x2074)00000000c705(<codecave:um_chaos.bss>+0x2078)00000000c705(<codecave:um_chaos.bss>+0x207c)0000000068(<codecave:um_chaos.text>+0x3df0)e8([codecave:um_chaos.text]+0x2d0)83c404c3669066905689ce837c240800740956e8([codecave:um_chaos.text]+0x2b0)83c40489f05ec204006690669066909056a1<0x4CF410>8bb0ac76040083fe01751eb9(<codecave:um_chaos.bss>+0x2074)68(<codecave:um_chaos.text>+0x3e90)68c6bd4100e8([codecave:um_chaos.text]+0x1a50)c705(<0x4CCDF0>+0x7f8)0c00000083fe010f95c05ec3669066906690669090b9(<codecave:um_chaos.bss>+0x2074)e8([codecave:um_chaos.text]+0x1760)c2040066909057566a0ce8([codecave:um_chaos.text]+0x2a0)83c40489c6c700(<codecave:um_chaos.rdata>+0x928)680000f041680000a040e8([codecave:um_chaos.text]+0x15f0)83c4088946046a026a00e8([codecave:um_chaos.text]+0x15b0)83c4088d3c4508000000897e080f57d2b9<0x56AD80>6a34e8[0x476C70]a1(<0x4CCDF0>+0x1c8)89b89404000089f05e5fc36690a1(<codecave:um_chaos.bss>+0x28)8d4801890d(<codecave:um_chaos.bss>+0x28)c1e002c78440(<codecave:um_chaos.bss>+0x2c)(<codecave:um_chaos.rdata>+0x920)c78440(<codecave:um_chaos.bss>+0x30)(<codecave:um_chaos.text>+0x3ea0)c68440(<codecave:um_chaos.bss>+0x34)00c35689cec701(<codecave:um_chaos.rdata>+0x928)8b4108408b0d(<0x4CCDF0>+0x1c8)898194040000837c240800740956e8([codecave:um_chaos.text]+0x2b0)83c40489f05ec2040090ff49040f95c0c3669066906690669090575683ec146a14e8([codecave:um_chaos.text]+0x2a0)83c40489c6c700(<codecave:um_chaos.rdata>+0x940)680000f0426800002041e8([codecave:um_chaos.text]+0x15f0)83c4088946048d7e08c7460800000000c7460c00000000c7461000000000c705(<codecave:um_chaos.bss>+0x2080)00000000c705(<codecave:um_chaos.bss>+0x2084)000000000f1005(<codecave:um_chaos.rdata>+0x94c)0f110424c744241000000000c7442401(<codecave:um_chaos.bss>+0x2080)c7442406(<codecave:um_chaos.bss>+0x2084)89e089f96a145068cab34500e8([codecave:um_chaos.text]+0x1840)89f968<<codecave:slippery_cave>>68deb34500e8([codecave:um_chaos.text]+0x19f0)89f083c4145e5fc366662e0f1f840000000000a1(<codecave:um_chaos.bss>+0x28)8d4801890d(<codecave:um_chaos.bss>+0x28)c1e002c78440(<codecave:um_chaos.bss>+0x2c)(<codecave:um_chaos.rdata>+0x934)c78440(<codecave:um_chaos.bss>+0x30)(<codecave:um_chaos.text>+0x3f70)c68440(<codecave:um_chaos.bss>+0x34)00c35689cec701(<codecave:um_chaos.rdata>+0x940)83c108e8([codecave:um_chaos.text]+0x1690)837c240800740956e8([codecave:um_chaos.text]+0x2b0)83c40489f05ec20400669066906690669090ff49040f95c0c366906690669066909056506a14e8([codecave:um_chaos.text]+0x2a0)83c40489c6c700(<codecave:um_chaos.rdata>+0x970)680000f0426800002041e8([codecave:um_chaos.text]+0x15f0)83c4088946048d4e08c7460800000000c7460c00000000c746100000000066c744240266908d4424026a02506878c94500e8([codecave:um_chaos.text]+0x1840)a1<0x4CF410>83889c77040010c7807c7904000000004089f083c4045ec3662e0f1f840000000000a1(<codecave:um_chaos.bss>+0x28)8d4801890d(<codecave:um_chaos.bss>+0x28)c1e002c78440(<codecave:um_chaos.bss>+0x2c)(<codecave:um_chaos.rdata>+0x960)c78440(<codecave:um_chaos.bss>+0x30)(<codecave:um_chaos.text>+0x4090)c68440(<codecave:um_chaos.bss>+0x34)00c35689cec701(<codecave:um_chaos.rdata>+0x970)a1<0x4CF410>83a09c770400efc7807c7904000000803f83c108e8([codecave:um_chaos.text]+0x1690)837c240800740956e8([codecave:um_chaos.text]+0x2b0)83c40489f05ec20400669090ff49040f95c0c3000000000000000000",
        },
        "um_chaos.data": {
            access: "rw",
            code: "ffffffff0000803f0000000000000000000000000000803f000000ff00000000000000000000000000000000000000000000803f000000ff0000803f000000000000000000000000000000000000803f000000ff000000000000803f0000000000000000000000000000803f000000ff0000803f0000803f0000000000000000000000000000803f000000cd00000000000000000000a04400000000000000000000803f000000cd6f12833a000000000000000000007044000000000000803f000000cd000000006f12833a0000a04400007044000000000000803f000000cd6f12833a6f12833a",
        },
        "um_chaos.rdata": {
            access: "r",
            code: "6c6573616e61652e706e6700666c6173686c696768742e706e67004944495f49434f4e3300000000000020c10000eb4347616d6520737461727465640a0047616d6520656e6465640a000000000080400000804000000000000080400000a04100000000536f6d652065666665637473206f6e6c7920776f726b20696e2077696e646f776564206d6f64652100596f752063616e20737769746368206d6f646573206279207072657373696e6720416c742b456e7465722e002573006368616f732e65636c004661696c656420746f206c6f6164206368616f732e65636c203a280053544147455f00424f53535f004c6f6164656420257a752073746167652061747461636b7320616e6420257a7520626f73732061747461636b730a007200434f4e494e24007700434f4e4f55542400554d3a43452041707220323720323032340a004c6f6164656420257a7520656666656374730a00257a752025730a000a007300680065006c006c00330032002e0064006c006c0000004c697374426f780044697361626c696e672025732e2e2e0a00456e61626c696e672025732e2e2e0a00626164206172726179206e6577206c656e67746800(<codecave:um_chaos.text>+0xfa0)(<codecave:um_chaos.text>+0xfc0)(<codecave:um_chaos.text>+0xfd0)756e6b6e6f776e20657863657074696f6e0000000000000000000000000000000000304300000000000030430000000000003043000070410000fe42000000430000004f00000040000080400000c0410000a0430000a04200000000000016430000fa42000000000000f5430000fa42000000004368616f732045646974696f6e2053657474696e6773004d696e2054696d65204265747765656e2045666665637473004d61782054696d65204265747765656e204566666563747300456666656374204c656e677468204d756c7469706c69657200526573746f72652044656661756c747300457869740035730033307300312e3078000000000000007042000070420000000000000000000080bf766563746f7220746f6f206c6f6e6700426f756e63696e6757696e646f770000(<codecave:um_chaos.text>+0x1ef0)(<codecave:um_chaos.text>+0x1f10)(<codecave:um_chaos.text>+0x1fe0)42756c6c6574577261700000(<codecave:um_chaos.text>+0x2080)(<codecave:um_chaos.text>+0x20b0)(<codecave:um_chaos.text>+0x1fe0)436172644e6f436f6f6c646f776e0000(<codecave:um_chaos.text>+0x2120)(<codecave:um_chaos.text>+0x2140)(<codecave:um_chaos.text>+0x1fe0)436c656172416c6c00000000(<codecave:um_chaos.text>+0x21c0)(<codecave:um_chaos.text>+0x21e0)(<codecave:um_chaos.text>+0x1fe0)446f75626c6542756c6c6574436f756e74000000(<codecave:um_chaos.text>+0x22c0)(<codecave:um_chaos.text>+0x22f0)(<codecave:um_chaos.text>+0x1fe0)0000c03f0000003f45636c576169744d756c7469706c696572000000(<codecave:um_chaos.text>+0x2400)(<codecave:um_chaos.text>+0x2430)(<codecave:um_chaos.text>+0x1fe0)46616b654372617368000000(<codecave:um_chaos.text>+0x2490)(<codecave:um_chaos.text>+0x24b0)(<codecave:um_chaos.text>+0x1fe0)63006f006d00630074006c00330032002e0064006c006c0000005461736b4469616c6f67496e64697265637400534f4654574152455c4d6963726f736f66745c57696e646f7773204e545c43757272656e7456657273696f6e5c416544656275670050617573650043006c006f007300650020007400680065002000700072006f006700720061006d0000004400650062007500670020007400680065002000700072006f006700720061006d00000002000000(<codecave:um_chaos.rdata>+0x414)03000000(<codecave:um_chaos.rdata>+0x438)74006800310038002e0065007800650020006800610073002000730074006f007000700065006400200077006f0072006b0069006e006700000041002000700072006f0062006c0065006d00200063006100750073006500640020007400680065002000700072006f006700720061006d00200074006f002000730074006f007000200077006f0072006b0069006e006700200063006f00720072006500630074006c0079002e00200050006c006500610073006500200063006c006f007300650020007400680065002000700072006f006700720061006d002e00000074006800310038002e0065007800650000004900440049005f00490043004f004e0033000000556e50617573650000000000000000000000c84500803b44000000000000000000002043000020c300000000000000007e58843e7e58843e0000000000000000000060c30000000000000000000000000000404300006043000000000000000000000042000080410000000000000000466c6173686c696768740000(<codecave:um_chaos.text>+0x2700)(<codecave:um_chaos.text>+0x2720)(<codecave:um_chaos.text>+0x2790)000001000200010002000300040005000600050006000700467265657a650000(<codecave:um_chaos.text>+0x2970)(<codecave:um_chaos.text>+0x29c0)(<codecave:um_chaos.text>+0x1fe0)467265657a654f7074696f6e73000000(<codecave:um_chaos.text>+0x2a60)(<codecave:um_chaos.text>+0x2a90)(<codecave:um_chaos.text>+0x1fe0)47616d655370656564000000(<codecave:um_chaos.text>+0x2b60)(<codecave:um_chaos.text>+0x2b90)(<codecave:um_chaos.text>+0x1fe0)4974656d4e6f477261760000(<codecave:um_chaos.text>+0x2c50)(<codecave:um_chaos.text>+0x2c80)(<codecave:um_chaos.text>+0x1fe0)00000080000000800000008000000080ffffff7fffffff7fffffff7fffffff7f4974656d526570656c000000(<codecave:um_chaos.text>+0x2d40)(<codecave:um_chaos.text>+0x2d90)(<codecave:um_chaos.text>+0x1fe0)4a69747465720000(<codecave:um_chaos.text>+0x2e00)(<codecave:um_chaos.text>+0x2e20)(<codecave:um_chaos.text>+0x1fe0)0000803f000000000000803f00000000000000000000803f0000803f00000000000000004c6553616e616500(<codecave:um_chaos.text>+0x3120)(<codecave:um_chaos.text>+0x3180)(<codecave:um_chaos.text>+0x1fe0)4d696e696d697a6500000000(<codecave:um_chaos.text>+0x31e0)(<codecave:um_chaos.text>+0x3200)(<codecave:um_chaos.text>+0x1fe0)000040430000003f0000003f0000000000000000000000bf000000c2000040c3000080c14d6f757365436f6e74726f6c73000000(<codecave:um_chaos.text>+0x3490)(<codecave:um_chaos.text>+0x34c0)(<codecave:um_chaos.text>+0x1fe0)4e6f466f63757300(<codecave:um_chaos.text>+0x3570)(<codecave:um_chaos.text>+0x35a0)(<codecave:um_chaos.text>+0x1fe0)33d2904e6f566572746963616c000000(<codecave:um_chaos.text>+0x3660)(<codecave:um_chaos.text>+0x3690)(<codecave:um_chaos.text>+0x1fe0)8b008944240831c08944241083bfcc760400004f70656e53686f7000(<codecave:um_chaos.text>+0x36f0)(<codecave:um_chaos.text>+0x3710)(<codecave:um_chaos.text>+0x1fe0)0000e043000000420000000052616e646f6d41747461636b00000000(<codecave:um_chaos.text>+0x38e0)(<codecave:um_chaos.text>+0x3910)(<codecave:um_chaos.text>+0x1fe0)5f617400426f7373004d426f7373004f766572726964696e6720257320776974682025730a0052616e646f6d42756c6c6574547970650000(<codecave:um_chaos.text>+0x3a00)(<codecave:um_chaos.text>+0x3a30)(<codecave:um_chaos.text>+0x1fe0)0f0000000f0000000f0000000f0000000f0000000f0000000f0000000f0000000f0000000f0000000f0000000f0000000f0000000f0000000f0000000f0000000f00000003000000070000000700000007000000070000000700000007000000070000000000000000000000000000000000000007000000070000000700000003000000070000000f0000000f0000000f0000000f0000000f000000000000000000000000000000000000000700000052616e646f6d4974656d7300(<codecave:um_chaos.text>+0x3be0)(<codecave:um_chaos.text>+0x3c10)(<codecave:um_chaos.text>+0x1fe0)526563757273697665424700(<codecave:um_chaos.text>+0x3cb0)(<codecave:um_chaos.text>+0x3ce0)(<codecave:um_chaos.text>+0x1fe0)5265737061776e00(<codecave:um_chaos.text>+0x3d40)(<codecave:um_chaos.text>+0x3d60)(<codecave:um_chaos.text>+0x1fe0)52657374617274537461676500000000(<codecave:um_chaos.text>+0x3e30)(<codecave:um_chaos.text>+0x3e50)(<codecave:um_chaos.text>+0x1fe0)5365696a61000000(<codecave:um_chaos.text>+0x3f30)(<codecave:um_chaos.text>+0x3f60)(<codecave:um_chaos.text>+0x1fe0)536c69707065727900000000(<codecave:um_chaos.text>+0x4050)(<codecave:um_chaos.text>+0x4080)(<codecave:um_chaos.text>+0x1fe0)b841414141b94141414166660f1f840000000000596f7547726f77426967676572000000(<codecave:um_chaos.text>+0x4140)(<codecave:um_chaos.text>+0x4180)(<codecave:um_chaos.text>+0x1fe0)00000000",
        },
        "um_chaos.CRT$XCU": {
            access: "r",
            code: "(<codecave:um_chaos.text>+0x4110)(<codecave:um_chaos.text>+0x4020)(<codecave:um_chaos.text>+0x3f00)(<codecave:um_chaos.text>+0x3dc0)(<codecave:um_chaos.text>+0x3e00)(<codecave:um_chaos.text>+0x3d10)(<codecave:um_chaos.text>+0x3c80)(<codecave:um_chaos.text>+0x3a60)(<codecave:um_chaos.text>+0x3990)(<codecave:um_chaos.text>+0x37c0)(<codecave:um_chaos.text>+0x36c0)(<codecave:um_chaos.text>+0x3630)(<codecave:um_chaos.text>+0x3540)(<codecave:um_chaos.text>+0x3320)(<codecave:um_chaos.text>+0x31b0)(<codecave:um_chaos.text>+0x2ee0)(<codecave:um_chaos.text>+0x2dd0)(<codecave:um_chaos.text>+0x2d10)(<codecave:um_chaos.text>+0x2c20)(<codecave:um_chaos.text>+0x2b30)(<codecave:um_chaos.text>+0x2a30)(<codecave:um_chaos.text>+0x2940)(<codecave:um_chaos.text>+0x26d0)(<codecave:um_chaos.text>+0x2460)(<codecave:um_chaos.text>+0x23d0)(<codecave:um_chaos.text>+0x2290)(<codecave:um_chaos.text>+0x2190)(<codecave:um_chaos.text>+0x20f0)(<codecave:um_chaos.text>+0x2050)(<codecave:um_chaos.text>+0x1ec0)(<codecave:um_chaos.text>+0xd90)(<codecave:um_chaos.text>+0x240)",
        },
        "um_chaos.bss": {
            access: "rw",
            size: 8328,
        },
        um_chaos_patch_init: {
            access: "rx",
            code: "555357565068<option:kernel32_dll_str>e8[th_GetModuleHandleA]68<option:LoadLibraryA_str>50e8[th_GetProcAddress]89042431edbb<codecave:um_chaos_dlls>8b35<codecave:um_chaos_dlls>660f1f44000056e8[th_GetModuleHandleA]89c785c0750b56ff54240489c785c0743c8b730439f5741f6690ff34ad<codecave:um_chaos_import_names>57e8[th_GetProcAddress]85c0742b8904ad<codecave:um_chaos_imports>4539ee75e38b730883c30885f675b983c4045e5f5b5de92c000000505668<option:dll_load_failed_str>eb0d50ff34ad<codecave:um_chaos_import_names>68<option:import_failed_str>e8[th_GetLastError]894424086a1068<option:um_chaos_name_str>e8[log_mboxf]cc5331db0f1f8400000000000f1f440000ff149d<codecave:um_chaos.CRT$XCU>4381fb2000000075f05be8([codecave:um_chaos.text]+0xcd0)c3",
            "export": true,
        },
        um_chaos_dlls: {
            access: "r",
            code: "<option:d3dx9_43_dll_str>01000000<option:kernel32_dll_str>0f000000<option:ucrtbase_dll_str>1b000000<option:user32_dll_str>2d000000<option:advapi32_dll_str>2f00000000000000",
        },
        um_chaos_import_names: {
            access: "r",
            code: "<option:D3DXCreateTextureFromFileInMemory_str><option:AllocConsole_str><option:CreateThread_str><option:VirtualProtect_str><option:DebugBreak_str><option:ExitProcess_str><option:ActivateActCtx_str><option:CreateActCtxW_str><option:GetSystemDirectoryW_str><option:GetProcAddress_str><option:GetModuleHandleA_str><option:DeactivateActCtx_str><option:Sleep_str><option:QueryPerformanceCounter_str><option:GetLastError_str><option:__stdio_common_vfprintf_str><option:__acrt_iob_func_str><option:freopen_str><option:__stdio_common_vfscanf_str><option:strtol_str><option:fgets_str><option:_invalid_parameter_noinfo_noreturn_str><option:_invoke_watson_str><option:free_str><option:malloc_str><option:_wcsicmp_str><option:strncmp_str><option:SetForegroundWindow_str><option:PostMessageA_str><option:LoadIconA_str><option:MessageBoxA_str><option:GetClassInfoExA_str><option:SetCursor_str><option:LoadCursorA_str><option:ScreenToClient_str><option:GetCursorPos_str><option:SetCursorPos_str><option:ClientToScreen_str><option:SendMessageA_str><option:CreateIconFromResource_str><option:IsIconic_str><option:SetWindowPos_str><option:GetWindowRect_str><option:GetMonitorInfoA_str><option:MonitorFromWindow_str><option:RegCloseKey_str><option:RegOpenKeyA_str>",
        },
        um_chaos_imports: {
            access: "rw",
            size: 188,
        },
    },
    binhacks: {
        um_chaos_entry_hook: {
            addr: "0x453F34",
            code: "E9 [codecave:um_chaos.text+0xb40]",
        },
        um_chaos_threadproc_hook: {
            addr: "0x443804",
            code: "<codecave:um_chaos.text+0x300>",
        },
        um_chaos_switch_mode_hook: {
            addr: "0x453600",
            code: "E8 [codecave:um_chaos.text+0x360]",
        },
        lesanae_add_vertices_hook: {
            addr: "0x47E6B5",
            code: "E8 [codecave:um_chaos.text+0x2f30]",
        },
        lesanae_draw_sprite_hook1: {
            addr: "0x4555B9",
            code: "E8 [codecave:um_chaos.text+0x2f10]",
        },
        lesanae_draw_sprite_hook2: {
            addr: "0x455A29",
            code: "E8 [codecave:um_chaos.text+0x2f10]",
        },
        lesanae_draw_sprite_hook3: {
            addr: "0x455B80",
            code: "E8 [codecave:um_chaos.text+0x2f10]",
        },
        lesanae_draw_sprite_hook4: {
            addr: "0x455CB7",
            code: "E8 [codecave:um_chaos.text+0x2f10]",
        },
        lesanae_set_texture_hook1: {
            addr: "0x47E1B6",
            code: "E8 [codecave:um_chaos.text+0x30e0] 90",
        },
        lesanae_set_texture_hook2: {
            addr: "0x480835",
            code: "E8 [codecave:um_chaos.text+0x30e0] 90",
        },
        lesanae_set_texture_hook3: {
            addr: "0x480D92",
            code: "E8 [codecave:um_chaos.text+0x30e0] 90",
        },
        lesanae_set_texture_hook4: {
            addr: "0x481002",
            code: "E8 [codecave:um_chaos.text+0x30e0] 90",
        },
        lesanae_set_texture_hook5: {
            addr: "0x481171",
            code: "E8 [codecave:um_chaos.text+0x30e0] 90",
        },
        custom_anm_jump_table_ptr: {
            addr: "0x478740",
            code: "<codecave:custom_anm_jump_table_cave>",
        },
        custom_anm_jump_table_idx: {
            addr: "0x47B9BA",
            code: "35",
        },
        scorefile_init_hook: {
            addr: "0x452CDE",
            code: "E8 [codecave:um_chaos.text+0xb30]",
        },
        title_draw_jump_table_ptr: {
            addr: "0x4658A2",
            code: "<codecave:title_draw_jump_table_cave>",
        },
        title_draw_jump_table_idx: {
            addr: "0x465A6C",
            code: "09",
        },
        title_calc_hook: {
            addr: "0x4654ED",
            code: "E8[codecave:um_chaos.text+0xff0] E9[0x46568B]",
        },
    },
}