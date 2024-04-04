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
        winmm_dll_str: {
            type: "s",
            val: "winmm.dll",
        },
        timeGetTime_str: {
            type: "s",
            val: "timeGetTime",
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
        doublebullets_etcount_hook: {
            access: "rx",
            code: "",
        },
        "um_chaos.text": {
            access: "rx",
            code: "50c704240000000089e2b9<codecave:um_chaos.rdata>6a00e8[0x402060]68<codecave:um_chaos.bss>ff74240450ff35(<0x4CCDF0>+0x8)ff15<codecave:um_chaos_imports>58c36690ff15(<codecave:um_chaos_imports>+0x10)6839050000ff15(<codecave:um_chaos_imports>+0x14)6666666666662e0f1f840000000000ff15(<codecave:um_chaos_imports>+0x10)6839050000ff15(<codecave:um_chaos_imports>+0x14)6666666666662e0f1f840000000000e9[th_malloc]66662e0f1f840000000000e9[th_free]66662e0f1f840000000000e9[th_free]66662e0f1f840000000000ff25(<codecave:um_chaos_imports>+0x10)66906690669066906690e8[0x4432B0]68(<codecave:um_chaos.rdata>+0xc)e8([codecave:um_chaos.text]+0x3e0)83c404803d(<codecave:um_chaos.bss>+0x1011)00740ac605(<codecave:um_chaos.bss>+0x1010)0131c0c3ff15(<codecave:um_chaos_imports>+0x30)50e8([codecave:um_chaos.text]+0x430)83c404c605(<codecave:um_chaos.bss>+0x1010)0131c0c36690575689ce83b9f407000007753883bef807000007742f68(<codecave:um_chaos.rdata>+0x1a)e8([codecave:um_chaos.text]+0x3e0)83c404b00183bef80700000c740b833d(<codecave:um_chaos.bss>+0x808)00754431c0a2(<codecave:um_chaos.bss>+0x1011)c605(<codecave:um_chaos.bss>+0x1010)0089f15e5fe9[0x455040]66908b3d(<codecave:um_chaos.bss>+0x808)8d04fdf8ffffff4f5068(<codecave:um_chaos.bss>+0x814)68(<codecave:um_chaos.bss>+0x80c)e8[th_memmove]83c40c893d(<codecave:um_chaos.bss>+0x808)85ff74bcff35(<codecave:um_chaos.bss>+0x80c)68(<codecave:um_chaos.rdata>+0x6a)e8([codecave:um_chaos.text]+0x3e0)83c4088b0d(<codecave:um_chaos.bss>+0x810)85c974b88b016a01ff10ebb0803d(<codecave:um_chaos.bss>+0x1010)000f84e800000057568b35<codecave:um_chaos.data>83feff7452ff34f5(<codecave:um_chaos.bss>+0x8)68(<codecave:um_chaos.rdata>+0x7b)e8([codecave:um_chaos.text]+0x3e0)83c4088b3cf5(<codecave:um_chaos.bss>+0x8)ff14f5(<codecave:um_chaos.bss>+0xc)8b15(<codecave:um_chaos.bss>+0x808)8d4a01890d(<codecave:um_chaos.bss>+0x808)893cd5(<codecave:um_chaos.bss>+0x80c)8904d5(<codecave:um_chaos.bss>+0x810)c705<codecave:um_chaos.data>ffffffff85c97513e9870000008b0d(<codecave:um_chaos.bss>+0x808)85c90f847900000031f6eb0d6690468b3d(<codecave:um_chaos.bss>+0x808)39fe73688b0cf5(<codecave:um_chaos.bss>+0x810)8b01ff500484c075e5ff34f5(<codecave:um_chaos.bss>+0x80c)68(<codecave:um_chaos.rdata>+0x6a)e8([codecave:um_chaos.text]+0x3e0)83c4088b0cf5(<codecave:um_chaos.bss>+0x810)85c974068b016a01ff108d04f5(<codecave:um_chaos.bss>+0x80c)8d0cf5(<codecave:um_chaos.bss>+0x814)8b3d(<codecave:um_chaos.bss>+0x808)89f2f7d201fac1e203525150e8[th_memmove]83c40c4f893d(<codecave:um_chaos.bss>+0x808)39fe72985e5fb801000000c30f1f4400005553575681ec800000008b35(<codecave:um_chaos_imports>+0x1c)89e78b1d(<codecave:um_chaos_imports>+0x2c)8b2d(<codecave:um_chaos_imports>+0x28)66906a00ffd683c40450688000000057ffd383c40c85c074e96a0a6a0057ffd583c40ca3<codecave:um_chaos.data>ebd80f1f8400000000005756ff15(<codecave:um_chaos_imports>+0x4)8b3d(<codecave:um_chaos_imports>+0x1c)6a00ffd783c4048b35(<codecave:um_chaos_imports>+0x20)5068(<codecave:um_chaos.rdata>+0x26)68(<codecave:um_chaos.rdata>+0x28)ffd683c40c6a01ffd783c4045068(<codecave:um_chaos.rdata>+0x2f)68(<codecave:um_chaos.rdata>+0x31)ffd683c40c6a02ffd783c4045068(<codecave:um_chaos.rdata>+0x2f)68(<codecave:um_chaos.rdata>+0x31)ffd683c40c68(<codecave:um_chaos.rdata>+0x39)e8([codecave:um_chaos.text]+0x3e0)83c404ff35(<codecave:um_chaos.bss>+0x4)68(<codecave:um_chaos.rdata>+0x4c)e8([codecave:um_chaos.text]+0x3e0)83c408833d(<codecave:um_chaos.bss>+0x4)00742c31f66666662e0f1f840000000000ff34f5(<codecave:um_chaos.bss>+0x8)5668(<codecave:um_chaos.rdata>+0x60)e8([codecave:um_chaos.text]+0x3e0)83c40c463b35(<codecave:um_chaos.bss>+0x4)72e268(<codecave:um_chaos.rdata>+0x68)e8([codecave:um_chaos.text]+0x3e0)83c404ff35<0x568C30>ff15(<codecave:um_chaos_imports>+0x34)6a006a006a0068(<codecave:um_chaos.text>+0x290)6a006a00ff15(<codecave:um_chaos_imports>+0x8)e8[codecave:um_chaos.text]68(<codecave:um_chaos.text>+0x190)e8[0x401530]8048040268e803000050e8[0x401180]31c05e5fc390535756508b7c24148d5c2418891c246a01ff15(<codecave:um_chaos_imports>+0x1c)83c40489c6e8([codecave:um_chaos.text]+0x420)536a005756ff7004ff30ff15(<codecave:um_chaos_imports>+0x18)83c41c5e5f5bc36690669066906690b8(<codecave:um_chaos.bss>+0x1018)c3669066906690669066908b442404a3(<codecave:um_chaos.bss>+0x1020)c3660f1f440000a1(<codecave:um_chaos.bss>+0x1020)89c1c1e10d31c189cac1ea1131ca89d0c1e00531d0a3(<codecave:um_chaos.bss>+0x1020)c357568b4c240c8b742410a1(<codecave:um_chaos.bss>+0x1020)89c2c1e20d31c289d7c1ef1131d789f8c1e00531f8a3(<codecave:um_chaos.bss>+0x1020)29ce4631d2f7f601d189c85e5fc3660f1f84000000000050a1(<codecave:um_chaos.bss>+0x1020)89c1c1e10d31c189c8c1e81131c889c1c1e10531c1890d(<codecave:um_chaos.bss>+0x1020)c1e90981c90000803f660f6ec1f30f5805(<codecave:um_chaos.rdata>+0x8c)f30f110424d9042458c35553575683ec0889ce8b398b590439df744c8934248d6c24048b35(<codecave:um_chaos_imports>+0xc)908b47082b4704556a4050ff37ffd68b47048b4f0829c15150ff37e8[th_memcpy]83c40c8b47082b470455ff74240850ff37ffd683c71039df75c78b34248b3e85ff0f84a50000008b5e0439df75398b460829f83d001000007362eb720f1f4400005051e8([codecave:um_chaos.text]+0x90)83c408c7470400000000c7470800000000c7470c0000000083c71039df74278b4f0485c974f28b470c29c83d0010000072c78b51fc83c1fc29d183f920734d83c02389d1ebb38b3e8b460829f83d0010000072128b4ffc83c7fc29cf83ff20732b83c02389cf5057e8([codecave:um_chaos.text]+0x90)83c408c70600000000c7460400000000c746080000000083c4085e5f5b5dc3e8([codecave:um_chaos.text]+0x30)0f1f840000000000e9([codecave:um_chaos.text]+0x610)66662e0f1f84000000000055535683ec2089ce8b5c24388b6c2430c7042400000000c744240400000000c74424080000000085db74128d44240c89e15053e8([codecave:um_chaos.text]+0x780)8b0424eb0231c0535550e8[th_memcpy]83c40c8d44241c506a405355ff15(<codecave:um_chaos_imports>+0xc)53ff74243855e8[th_memcpy]83c40c8d44241c50ff7424205355ff15(<codecave:um_chaos_imports>+0xc)896c240c8b442408c744240800000000f20f100424c744240400000000c7042400000000f20f11442410894424188b46043b4608744189288b4c2418c744241800000000f20f10442410c744241400000000c744241000000000f20f11400489480c834604108b4c241085c9751e8b0c2485c97547eb6e8d54240c89f15250e8([codecave:um_chaos.text]+0x930)8b4c241085c974e28b44241829c83d0010000072128b51fc83c1fc29d183f920734883c02389d15051e8([codecave:um_chaos.text]+0x90)83c4088b0c2485c974298b44240829c83d0010000072128b51fc83c1fc29d183f920731883c02389d15051e8([codecave:um_chaos.text]+0x90)83c40883c4205e5b5dc20c00e8([codecave:um_chaos.text]+0x30)669066909055535756508b7c241885ff0f88d900000089ce8b098b4608890c2429c889c1d1e989ca81f2ffffff7f01c139f90f46cf8b5e0439d0bdffffff7f0f46e981fd00100000722083fddd0f83a10000008d452350e8([codecave:um_chaos.text]+0x70)83c4048d782383e7e08947fceb1385ed740d55e8([codecave:um_chaos.text]+0x70)83c40489c7eb0231ff2b1c248d041f8b4c241829d9516a0050e8[th_memset]83c40c8b068b4e0429c1515057e8[th_memmove]83c40c8b0e85c974288b460829c83d0010000072128b51fc83c1fc29d183f920733383c02389d15051e8([codecave:um_chaos.text]+0x90)83c408893e8b44241801f889460401fd896e0883c4045e5f5b5dc20800e8([codecave:um_chaos.text]+0x880)e8([codecave:um_chaos.text]+0x890)e8([codecave:um_chaos.text]+0x30)6690669066909068(<codecave:um_chaos.rdata>+0x90)e8([codecave:um_chaos.text]+0xa0)66906690669083ec08c7442404(<codecave:um_chaos.rdata>+0xa0)c70424(<codecave:um_chaos.rdata>+0xb8)89e1e8([codecave:um_chaos.text]+0x8b0)669066906690905683ec1489cea1(<codecave:um_chaos.bss>+0x100c)85c07405893424ffd08b0689f1ff50080f57c00f110424c744241000000000e8([codecave:um_chaos.text]+0x50)905689ce837c240800740956e8([codecave:um_chaos.text]+0x80)83c40489f05ec20400669066906690908b490485c9b8(<codecave:um_chaos.rdata>+0xc4)0f45c1c3669083ec140f57c00f110424c744241000000000e8([codecave:um_chaos.text]+0x50)6690669066906690905553575683ec1089cd8b198b790429dfc1ff04478b490829d9c1f90489c8d1e8baffffff0fbeffffff0f29c601c839f80f46c739f10f47c23d000000100f836302000089c1c1e1043d00010000897c2408894c2404895c240c72223dfeffff0f0f83400200008d412350e8([codecave:um_chaos.text]+0x70)83c4048d782383e7e08947fceb0b51e8([codecave:um_chaos.text]+0x70)83c40489c78b4424288b5c242489de2b74240cc1fe04c1e6048b08890c378b480cc7400c00000000f20f104004c7400800000000c7400400000000f20f11443704894c370c8b45008b4d0439d9892c240f84a800000039d8744531c9908b140889140f8b54080cc744080c00000000f20f10440804c744080800000000c744080400000000f20f11440f0489540f0c8d140883c21083c11039da75c18b4d0439d90f84a50000008d043e83c01c31d266666666662e0f1f8400000000008b2c13896c10f48b6c130cc744130c00000000f20f10441304c744130800000000c744130400000000f20f114410f8892c108d2c1383c51083c21039cd75c1eb4e39d8745031c9660f1f8400000000008b140889140f8b54080cc744080c00000000f20f10440804c744080800000000c744080400000000f20f11440f0489540f0c8d140883c21083c11039da75c18b2c248b5d0085db0f849e0000008b6d0439eb75428b2c248b450829d83d00100000736ce9790000000f1f8400000000005051e8([codecave:um_chaos.text]+0x90)83c408c7430400000000c7430800000000c7430c0000000083c31039eb74278b4b0485c974f28b430c29c83d0010000072c78b51fc83c1fc29d183f920735b83c02389d1ebb38b2c248b5d008b450829d83d0010000072128b4bfc83c3fc29cb83fb20733583c02389cb5053e8([codecave:um_chaos.text]+0x90)83c40801fe897d008b442408c1e00401f88945048b44240401f889450889f083c4105e5f5b5dc20800e8([codecave:um_chaos.text]+0x30)e8([codecave:um_chaos.text]+0x890)6690669090566a08e8([codecave:um_chaos.text]+0x70)83c40489c6c700(<codecave:um_chaos.rdata>+0xe8)68504600006858020000e8([codecave:um_chaos.text]+0x460)83c40889460489f05ec30f1f4000a1(<codecave:um_chaos.bss>+0x4)8d4801890d(<codecave:um_chaos.bss>+0x4)c704c5(<codecave:um_chaos.bss>+0x8)(<codecave:um_chaos.rdata>+0xd6)c704c5(<codecave:um_chaos.bss>+0xc)(<codecave:um_chaos.text>+0xbe0)c366906690669066906690905689ce837c240800740956e8([codecave:um_chaos.text]+0x80)83c40489f05ec2040066906690669090a1<0x4CF298>83c018eb0d660f1f4400008b400485c0740f8b1085d274f3c7423c00000000ebeaff49040f95c0c3669090566a08e8([codecave:um_chaos.text]+0x70)83c40489c6c700(<codecave:um_chaos.rdata>+0xf8)68580200006a78e8([codecave:um_chaos.text]+0x460)83c408894604a1<0x4CF2E4>8188b00000000004000089f05ec30f1f840000000000a1(<codecave:um_chaos.bss>+0x4)8d4801890d(<codecave:um_chaos.bss>+0x4)c704c5(<codecave:um_chaos.bss>+0x8)(<codecave:um_chaos.rdata>+0xf0)c704c5(<codecave:um_chaos.bss>+0xc)(<codecave:um_chaos.text>+0xc90)c366906690669066906690905689cec701(<codecave:um_chaos.rdata>+0xf8)a1<0x4CF2E4>81a0b0000000fffbffff837c240800740956e8([codecave:um_chaos.text]+0x80)83c40489f05ec204006690ff49040f95c0c36690669066906690905756506a0ce8([codecave:um_chaos.text]+0x70)83c40489c6c700(<codecave:um_chaos.rdata>+0x114)6a0a6a01e8([codecave:um_chaos.text]+0x460)83c40883f801751b682c0100006a0fe8([codecave:um_chaos.text]+0x460)f30f1005(<codecave:um_chaos.rdata>+0x8c)83c40889c7eb3168080700006858020000e8([codecave:um_chaos.text]+0x460)83c40889c7e8([codecave:um_chaos.text]+0x4a0)d91c24f30f100424f30f5905(<codecave:um_chaos.rdata>+0x100)f30f5805(<codecave:um_chaos.rdata>+0x104)897e04f30f114608f30f1105<0x4CCBF0>89f083c4045e5fc3660f1f440000a1(<codecave:um_chaos.bss>+0x4)8d4801890d(<codecave:um_chaos.bss>+0x4)c704c5(<codecave:um_chaos.bss>+0x8)(<codecave:um_chaos.rdata>+0x108)c704c5(<codecave:um_chaos.bss>+0xc)(<codecave:um_chaos.text>+0xd40)c366906690669066906690905689cec701(<codecave:um_chaos.rdata>+0x114)c705<0x4CCBF0>0000803f837c240800740956e8([codecave:um_chaos.text]+0x80)83c40489f05ec2040066906690669090f30f104108f30f1105<0x4CCBF0>ff49040f95c0c36690669066906690669066905683ec086a14e8([codecave:um_chaos.text]+0x70)83c40489c6c700(<codecave:um_chaos.rdata>+0x128)6884030000682c010000e8([codecave:um_chaos.text]+0x460)83c4088946048d4e08c7460800000000c7460c00000000c7461000000000c744240400000000c704240f1f840089e06a0850687d5c4400e8([codecave:um_chaos.text]+0x600)89f083c4085ec30f1f840000000000a1(<codecave:um_chaos.bss>+0x4)8d4801890d(<codecave:um_chaos.bss>+0x4)c704c5(<codecave:um_chaos.bss>+0x8)(<codecave:um_chaos.rdata>+0x11c)c704c5(<codecave:um_chaos.bss>+0xc)(<codecave:um_chaos.text>+0xe50)c366906690669066906690905689cec701(<codecave:um_chaos.rdata>+0x128)83c108e8([codecave:um_chaos.text]+0x4e0)837c240800740956e8([codecave:um_chaos.text]+0x80)83c40489f05ec20400669066906690669090ff49040f95c0c366906690669066909056506a14e8([codecave:um_chaos.text]+0x70)83c40489c6c700(<codecave:um_chaos.rdata>+0x13c)6884030000682c010000e8([codecave:um_chaos.text]+0x460)83c4088946048d4e08c7460800000000c7460c00000000c7461000000000c64424035c8d4424036a0150681d614400e8([codecave:um_chaos.text]+0x600)89f083c4045ec36690a1(<codecave:um_chaos.bss>+0x4)8d4801890d(<codecave:um_chaos.bss>+0x4)c704c5(<codecave:um_chaos.bss>+0x8)(<codecave:um_chaos.rdata>+0x130)c704c5(<codecave:um_chaos.bss>+0xc)(<codecave:um_chaos.text>+0xf30)c366906690669066906690905689cec701(<codecave:um_chaos.rdata>+0x13c)83c108e8([codecave:um_chaos.text]+0x4e0)837c240800740956e8([codecave:um_chaos.text]+0x80)83c40489f05ec20400669066906690669090ff49040f95c0c3669066906690669090566a08e8([codecave:um_chaos.text]+0x70)83c40489c6c700(<codecave:um_chaos.rdata>+0x14c)68080700006858020000e8([codecave:um_chaos.text]+0x460)83c40889460489f05ec30f1f4000a1(<codecave:um_chaos.bss>+0x4)8d4801890d(<codecave:um_chaos.bss>+0x4)c704c5(<codecave:um_chaos.bss>+0x8)(<codecave:um_chaos.rdata>+0x144)c704c5(<codecave:um_chaos.bss>+0xc)(<codecave:um_chaos.text>+0x1000)c366906690669066906690905689ce837c240800740956e8([codecave:um_chaos.text]+0x80)83c40489f05ec20400669066906690905689ce68000200006800feffffe8([codecave:um_chaos.text]+0x460)83c4088b0d<0x4CF410>01812c06000068000200006800feffffe8([codecave:um_chaos.text]+0x460)83c4088b0d<0x4CF410>018130060000ff4e040f95c05ec3669066906690669090566a08e8([codecave:um_chaos.text]+0x70)83c40489c6c700(<codecave:um_chaos.rdata>+0x188)68080700006858020000e8([codecave:um_chaos.text]+0x460)83c408894604c605(<codecave:um_chaos.bss>+0x1024)0189f05ec3666666662e0f1f840000000000a1(<codecave:um_chaos.bss>+0x4)8d4801890d(<codecave:um_chaos.bss>+0x4)c704c5(<codecave:um_chaos.bss>+0x8)(<codecave:um_chaos.rdata>+0x180)c704c5(<codecave:um_chaos.bss>+0xc)(<codecave:um_chaos.text>+0x10d0)c366662e0f1f8400000000008b442404c605(<codecave:um_chaos.bss>+0x1025)0150e8[0x481210]c605(<codecave:um_chaos.bss>+0x1025)00c204000f1f440000803d(<codecave:um_chaos.bss>+0x1024)000f84[0x47E800]803d(<codecave:um_chaos.bss>+0x1025)000f85[0x47E800]8b4424040f57c00f134014f30f1005(<codecave:um_chaos.rdata>+0x154)0f134030f20f1005(<codecave:um_chaos.rdata>+0x160)f20f11404cf20f1005(<codecave:um_chaos.rdata>+0x170)f20f114068e9[0x47E800]803d(<codecave:um_chaos.bss>+0x1025)00b8<codecave:um_chaos.bss>8d4c240c0f45c1803d(<codecave:um_chaos.bss>+0x1024)008b5424040f44c18b0aff306a0052ff9104010000c20c006690669066906690669066906690905689cec701(<codecave:um_chaos.rdata>+0x188)c605(<codecave:um_chaos.bss>+0x1024)00837c240800740956e8([codecave:um_chaos.text]+0x80)83c40489f05ec2040066906690669066906690ff49040f95c0c36690669066906690906a04e8([codecave:um_chaos.text]+0x70)83c404c700(<codecave:um_chaos.rdata>+0x19c)c36666666666662e0f1f840000000000a1(<codecave:um_chaos.bss>+0x4)8d4801890d(<codecave:um_chaos.bss>+0x4)c704c5(<codecave:um_chaos.bss>+0x8)(<codecave:um_chaos.rdata>+0x190)c704c5(<codecave:um_chaos.bss>+0xc)(<codecave:um_chaos.text>+0x1230)c366906690669066906690905689ce837c240800740956e8([codecave:um_chaos.text]+0x80)83c40489f05ec20400669066906690906a006820f000006812010000ff35<0x568C30>ff15(<codecave:um_chaos_imports>+0x38)31c0c3669066909056506a14e8([codecave:um_chaos.text]+0x70)83c40489c6c700(<codecave:um_chaos.rdata>+0x1b0)6884030000682c010000e8([codecave:um_chaos.text]+0x460)83c4088946048d4e08c7460800000000c7460c00000000c746100000000066c744240231c08d4424026a02506827b44500e8([codecave:um_chaos.text]+0x600)89f083c4045ec3a1(<codecave:um_chaos.bss>+0x4)8d4801890d(<codecave:um_chaos.bss>+0x4)c704c5(<codecave:um_chaos.bss>+0x8)(<codecave:um_chaos.rdata>+0x1a4)c704c5(<codecave:um_chaos.bss>+0xc)(<codecave:um_chaos.text>+0x12c0)c366906690669066906690905689cec701(<codecave:um_chaos.rdata>+0x1b0)83c108e8([codecave:um_chaos.text]+0x4e0)837c240800740956e8([codecave:um_chaos.text]+0x80)83c40489f05ec20400669066906690669090ff49040f95c0c36690669066906690906a04e8([codecave:um_chaos.text]+0x70)83c404c700(<codecave:um_chaos.rdata>+0x1c0)c36666666666662e0f1f840000000000a1(<codecave:um_chaos.bss>+0x4)8d4801890d(<codecave:um_chaos.bss>+0x4)c704c5(<codecave:um_chaos.bss>+0x8)(<codecave:um_chaos.rdata>+0x1b8)c704c5(<codecave:um_chaos.bss>+0xc)(<codecave:um_chaos.text>+0x1390)c366906690669066906690905689ce837c240800740956e8([codecave:um_chaos.text]+0x80)83c40489f05ec2040066906690669090a1<0x4CF410>c780ac7604000000000031c0c30000000000000000000000000000",
        },
        "um_chaos.data": {
            access: "rw",
            code: "ffffffff",
        },
        "um_chaos.rdata": {
            access: "r",
            code: "6c6573616e61652e706e670047616d6520737461727465640a0047616d6520656e6465640a007200434f4e494e24007700434f4e4f55542400554d3a43452041707220203420323032340a004c6f6164656420257a7520656666656374730a00257a752025730a000a0044697361626c696e672025732e2e2e0a00456e61626c696e672025732e2e2e0a0000000080bf766563746f7220746f6f206c6f6e6700626164206172726179206e6577206c656e67746800000000(<codecave:um_chaos.text>+0x8e0)(<codecave:um_chaos.text>+0x900)(<codecave:um_chaos.text>+0x910)756e6b6e6f776e20657863657074696f6e00436172644e6f436f6f6c646f776e00000000(<codecave:um_chaos.text>+0xc40)(<codecave:um_chaos.text>+0xc60)467265657a650000(<codecave:um_chaos.text>+0xd00)(<codecave:um_chaos.text>+0xd30)0000e03f0000803e47616d655370656564000000(<codecave:um_chaos.text>+0xe00)(<codecave:um_chaos.text>+0xe30)4974656d4e6f477261760000(<codecave:um_chaos.text>+0xef0)(<codecave:um_chaos.text>+0xf20)4974656d526570656c000000(<codecave:um_chaos.text>+0xfc0)(<codecave:um_chaos.text>+0xff0)4a69747465720000(<codecave:um_chaos.text>+0x1060)(<codecave:um_chaos.text>+0x1080)0000803f0000000000000000000000000000803f00000000000000000000803f0000803f00000000000000004c6553616e616500(<codecave:um_chaos.text>+0x11f0)(<codecave:um_chaos.text>+0x1220)4d696e696d697a6500000000(<codecave:um_chaos.text>+0x1280)(<codecave:um_chaos.text>+0x12a0)4e6f566572746963616c0000(<codecave:um_chaos.text>+0x1350)(<codecave:um_chaos.text>+0x1380)5265737061776e00(<codecave:um_chaos.text>+0x13e0)(<codecave:um_chaos.text>+0x1400)0000000000000000",
        },
        "um_chaos.CRT$XCU": {
            access: "r",
            code: "(<codecave:um_chaos.text>+0x13b0)(<codecave:um_chaos.text>+0x1320)(<codecave:um_chaos.text>+0x1250)(<codecave:um_chaos.text>+0x1110)(<codecave:um_chaos.text>+0x1030)(<codecave:um_chaos.text>+0xf90)(<codecave:um_chaos.text>+0xec0)(<codecave:um_chaos.text>+0xdd0)(<codecave:um_chaos.text>+0xcd0)(<codecave:um_chaos.text>+0xc10)",
        },
        "um_chaos.bss": {
            access: "rw",
            size: 4136,
        },
        um_chaos_patch_init: {
            access: "rx",
            code: "555357565068<option:kernel32_dll_str>e8[th_GetModuleHandleA]68<option:LoadLibraryA_str>50e8[th_GetProcAddress]89042431edbb<codecave:um_chaos_dlls>8b35<codecave:um_chaos_dlls>660f1f44000056e8[th_GetModuleHandleA]89c785c0750b56ff54240489c785c0743c8b730439f5741f6690ff34ad<codecave:um_chaos_import_names>57e8[th_GetProcAddress]85c0742b8904ad<codecave:um_chaos_imports>4539ee75e38b730883c30885f675b983c4045e5f5b5de92c000000505668<option:dll_load_failed_str>eb0d50ff34ad<codecave:um_chaos_import_names>68<option:import_failed_str>e8[th_GetLastError]894424086a1068<option:um_chaos_name_str>e8[log_mboxf]cc5331db0f1f8400000000000f1f440000ff149d<codecave:um_chaos.CRT$XCU>4381fb0a00000075f05bc3",
            "export": true,
        },
        um_chaos_dlls: {
            access: "r",
            code: "<option:d3dx9_43_dll_str>01000000<option:kernel32_dll_str>06000000<option:ucrtbase_dll_str>0c000000<option:winmm_dll_str>0d000000<option:user32_dll_str>0f00000000000000",
        },
        um_chaos_import_names: {
            access: "r",
            code: "<option:D3DXCreateTextureFromFileInMemory_str><option:AllocConsole_str><option:CreateThread_str><option:VirtualProtect_str><option:DebugBreak_str><option:ExitProcess_str><option:__stdio_common_vfprintf_str><option:__acrt_iob_func_str><option:freopen_str><option:__stdio_common_vfscanf_str><option:strtol_str><option:fgets_str><option:timeGetTime_str><option:SetForegroundWindow_str><option:PostMessageA_str>",
        },
        um_chaos_imports: {
            access: "rw",
            size: 60,
        },
    },
    binhacks: {
        um_chaos_entry_hook: {
            addr: "0x453F34",
            code: "E9 [codecave:um_chaos.text+0x2e0]",
        },
        um_chaos_threadproc_hook: {
            addr: "0x443804",
            code: "<codecave:um_chaos.text+0xb0>",
        },
        um_chaos_switch_mode_hook: {
            addr: "0x453600",
            code: "E8 [codecave:um_chaos.text+0xf0]",
        },
        lesanae_add_vertices_hook: {
            addr: "0x47E6B5",
            code: "E8 [codecave:um_chaos.text+0x1160]",
        },
        lesanae_draw_sprite_hook1: {
            addr: "0x4555B9",
            code: "E8 [codecave:um_chaos.text+0x1140]",
        },
        lesanae_draw_sprite_hook2: {
            addr: "0x455A29",
            code: "E8 [codecave:um_chaos.text+0x1140]",
        },
        lesanae_draw_sprite_hook3: {
            addr: "0x455B80",
            code: "E8 [codecave:um_chaos.text+0x1140]",
        },
        lesanae_draw_sprite_hook4: {
            addr: "0x455CB7",
            code: "E8 [codecave:um_chaos.text+0x1140]",
        },
        lesanae_set_texture_hook1: {
            addr: "0x47E1B6",
            code: "E8 [codecave:um_chaos.text+0x11b0] 90",
        },
        lesanae_set_texture_hook2: {
            addr: "0x480835",
            code: "E8 [codecave:um_chaos.text+0x11b0] 90",
        },
        lesanae_set_texture_hook3: {
            addr: "0x480D92",
            code: "E8 [codecave:um_chaos.text+0x11b0] 90",
        },
        lesanae_set_texture_hook4: {
            addr: "0x481002",
            code: "E8 [codecave:um_chaos.text+0x11b0] 90",
        },
        lesanae_set_texture_hook5: {
            addr: "0x481171",
            code: "E8 [codecave:um_chaos.text+0x11b0] 90",
        },
    },
}