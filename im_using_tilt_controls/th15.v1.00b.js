{
    options: {
        tilt_controls_const_0: {
            type: "s",
            val: "127.0.0.1",
        },
        tilt_controls_const_1: {
            type: "s",
            val: "bind failed with code: %d",
        },
        tilt_controls_const_2: {
            type: "s",
            val: "ImUsingTiltControls",
        },
        tilt_controls_const_3: {
            type: "s",
            val: "recvfrom failed with code: %d",
        },
        tilt_controls_const_4: {
            type: "s",
            val: "sendto failed with code: %d",
        },
        kernel32_dll_str: {
            type: "s",
            val: "kernel32.dll",
        },
        CreateThread_str: {
            type: "s",
            val: "CreateThread",
        },
        VirtualProtect_str: {
            type: "s",
            val: "VirtualProtect",
        },
        ws2_32_dll_str: {
            type: "s",
            val: "ws2_32.dll",
        },
        WSAStartup_str: {
            type: "s",
            val: "WSAStartup",
        },
        recvfrom_str: {
            type: "s",
            val: "recvfrom",
        },
        bind_str: {
            type: "s",
            val: "bind",
        },
        socket_str: {
            type: "s",
            val: "socket",
        },
        htons_str: {
            type: "s",
            val: "htons",
        },
        inet_pton_str: {
            type: "s",
            val: "inet_pton",
        },
        sendto_str: {
            type: "s",
            val: "sendto",
        },
        WSAGetLastError_str: {
            type: "s",
            val: "WSAGetLastError",
        },
        winmm_dll_str: {
            type: "s",
            val: "winmm.dll",
        },
        timeGetTime_str: {
            type: "s",
            val: "timeGetTime",
        },
        "zlib-ng_dll_str": {
            type: "s",
            val: "zlib-ng.dll",
        },
        crc32_z_str: {
            type: "s",
            val: "crc32_z",
        },
        d3dx9_43_dll_str: {
            type: "s",
            val: "d3dx9_43.dll",
        },
        D3DXMatrixPerspectiveFovLH_str: {
            type: "s",
            val: "D3DXMatrixPerspectiveFovLH",
        },
        D3DXMatrixLookAtLH_str: {
            type: "s",
            val: "D3DXMatrixLookAtLH",
        },
        D3DXMatrixTranslation_str: {
            type: "s",
            val: "D3DXMatrixTranslation",
        },
        D3DXMatrixRotationQuaternion_str: {
            type: "s",
            val: "D3DXMatrixRotationQuaternion",
        },
        D3DXMatrixRotationYawPitchRoll_str: {
            type: "s",
            val: "D3DXMatrixRotationYawPitchRoll",
        },
        D3DXMatrixMultiply_str: {
            type: "s",
            val: "D3DXMatrixMultiply",
        },
        D3DXQuaternionInverse_str: {
            type: "s",
            val: "D3DXQuaternionInverse",
        },
        D3DXQuaternionMultiply_str: {
            type: "s",
            val: "D3DXQuaternionMultiply",
        },
        tilt_controls_name_str: {
            type: "s",
            val: "tilt_controls",
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
        "tilt_controls.text0": {
            access: "rx",
            code: "5683ec1489e05068<option:tilt_controls_const_0>6a02ff15(<codecave:tilt_controls_imports>+0x1c)8b35(<codecave:tilt_controls_imports>+0x18)6855a40000ffd666c744240402006855a40000ffd666894424068b042489442408c744241000000000c744240c000000006888680000ffd68b0c2466c705(<codecave:tilt_controls.bss2>+0x11c)020066a3(<codecave:tilt_controls.bss2>+0x11e)890d(<codecave:tilt_controls.bss2>+0x120)c705(<codecave:tilt_controls.bss2>+0x128)00000000c705(<codecave:tilt_controls.bss2>+0x124)000000006a116a026a02ff15(<codecave:tilt_controls_imports>+0x14)a3<codecave:tilt_controls.bss2>8d4c24046a105150ff15(<codecave:tilt_controls_imports>+0x10)85c0791bff15(<codecave:tilt_controls_imports>+0x24)5068<option:tilt_controls_const_1>6a1068<option:tilt_controls_const_2>e8[log_mboxf]83c41083c4145ec36666666666662e0f1f84000000000081ec80000000f30f1015(<codecave:tilt_controls.data1>+0x4)0f2805<codecave:tilt_controls_comdat_pool>0f28ea0f57e8f30f1035(<codecave:tilt_controls.bss2>+0x4)f30f109c248c0000000f28cb0f57c8f30f10a424900000000f14cc0f57e00f28c10f16c30f16e3f30f103d<codecave:tilt_controls.data1>0fc6cc240f28de0f1114240fc6da000f59cb0f117c24300f28e70f14e50f28f80fc6e401f30f109c24880000000f28d30fc6d0900f59d40f58d1f30f1005(<codecave:tilt_controls.bss2>+0x8)0f28c80f117424100f16ce0f570d<codecave:tilt_controls_comdat_pool>0f28e10f28f0f20f10e00fc6cc200fc6fb090f59f90f58fa0f593d(<codecave:tilt_controls_comdat_pool>+0x10)f30f108c24940000000f57d20f2ecaf30f10ac249c000000f30f109c2498000000751a7a180f2eda75137a110f2eea750c7a0a0f10442430e94c0200000f1024240f104424100f14e00f28d3f30f59d30f28d9f30f59d9f30f58da0f28d5f30f59d5f30f58d3f30f5ad2f20f51d2f20f5ad2f30f101d(<codecave:tilt_controls_comdat_pool>+0x20)f30f5eda0f115c24400f106c24300f14cd0f117424200f2805(<codecave:tilt_controls_comdat_pool>+0x30)f30f10c30f59c10f28f00fc6e4410f5925(<codecave:tilt_controls_comdat_pool>+0x40)0f116424500f10442420f30f58c00f28d00f114424700f104c2420f30f59c9f30f59d60f28c60fc6e455f30f59e1f30f5ce2f30f59edf30f101d(<codecave:tilt_controls_comdat_pool>+0x50)f30f59eb0f28f5f30f593424f30f58f40f114424600f28e00fc6e055f30f59c4f30f596c2410f30f58e80f105424500fc6d2fff30f59d1f30f58d50f106c24100f100c240f14e90f59ed0f28cd0fc6cd55f30f59cbf30f10842498000000f30f109c249c0000000f14c30f16c00f28d80f104424400fc6c0000f59c30f11442440f30f59e0f30f5cf40f105c2470f30f59d8f30f5cd30fc6f2220f104424600f28d00f2825<codecave:tilt_controls_comdat_pool>0f57d40f16c20f106424500f59c40f5cf40fc6c6d80f105424300f101c240f14d30f105c24100f16dd0fc6d3240f105c24200fc6dd300fc6eb840f5915(<codecave:tilt_controls_comdat_pool>+0x60)0fc6ca300f28dd0fc6ed210f59ea0fc6d1840fc6db640f59da0fc6c0d80f58d80f107424200f58eb0f28cc0fc6cc4e0f570d<codecave:tilt_controls_comdat_pool>0fc6ccd80fc6c9d80f104424400f59c80f58cd0f28d10f59d10fc6d2550f28d9f30f59d9f30f58da0f28d10fc6d1fff30f59d2f30f58d30f28d9660f15d9f30f59dbf30f58da0f57d2f30f5ad3f20f51d2f20f5ad2f30f101d(<codecave:tilt_controls_comdat_pool>+0x20)f30f5eda0f104424300fc6db000f59d9f30f100d(<codecave:tilt_controls.data1>+0x8)0fc6c9000f59cb0f5cf90f28cff30f10a42484000000f30f59ccf30f58c80f28d70fc6d755f30f59d4f30f5814240f28df0fc6dffff30f59dcf30f585c24100f12fff30f59fcf30f58fe0f28e2f30f59e20f28e9f30f59e9f30f58ec0f28e3f30f59e3f30f58e50f28eff30f59eff30f58ec0f57e4f30f5ae5f20f51e4f20f5ae4f30f102d(<codecave:tilt_controls_comdat_pool>+0x20)f30f5eecf30f59cdf30f110d<codecave:tilt_controls.data1>f30f59d5f30f1115(<codecave:tilt_controls.data1>+0x4)f30f59ddf30f111d(<codecave:tilt_controls.bss2>+0x4)f30f59eff30f112d(<codecave:tilt_controls.bss2>+0x8)81c480000000c30f1f8400000000005589e553575683e4f881ec40040000c744241c100000008d74243c68000400006a0056e8[th_memset]83c40cc7442410000000008d5c242c8b3d(<codecave:tilt_controls_imports>+0xc)c74424040000000066662e0f1f8400000000008d44241c50536a00680004000056ff35<codecave:tilt_controls.bss2>ffd783f864740a83f8ff75e0e99d020000817c243c4453555375d10fb74424403de903000075c566837c24425475bd817c244c0200100075b3837c245c0074ac8b4424448944240cc7442444000000006a64566a00ff15(<codecave:tilt_controls_imports>+0x2c)83c40c3944240c7588807c2451020f9405(<codecave:tilt_controls.bss2>+0x10)f20f10464c0f5a8c2494000000f20f1105(<codecave:tilt_controls.bss2>+0x24)660f590d(<codecave:tilt_controls_comdat_pool>+0x70)660f5ac18b4654f30f108c249c000000f30f5ac9a3(<codecave:tilt_controls.bss2>+0x2c)f20f590d(<codecave:tilt_controls_comdat_pool>+0x80)f20f5ac9660f1305(<codecave:tilt_controls.bss2>+0x30)f30f110d(<codecave:tilt_controls.bss2>+0x38)8b4c241089c88b54240409d00f84bf010000895424048b9424800000008b8424840000008954240c31ca89c13344240409d00f8499010000803d(<codecave:tilt_controls.bss2>+0xc)017539c705<codecave:tilt_controls.data1>f304353fc705(<codecave:tilt_controls.data1>+0x4)f304353fc705(<codecave:tilt_controls.bss2>+0x4)00000000c705(<codecave:tilt_controls.bss2>+0x8)00000000c705(<codecave:tilt_controls.data1>+0x8)00002041c605(<codecave:tilt_controls.bss2>+0xc)008b44240c2b442410660f6ed01b4c2404660f6ed9660f62d3660fd6542420df6c2420d97c240a0fb744240a0d000300006689442416d96c2416c1e91fd8048d(<codecave:tilt_controls_comdat_pool>+0x88)d96c240ad95c2418f30f10542418f30f5ad2f20f5915(<codecave:tilt_controls_comdat_pool>+0x90)f20f5ae2f30f1015(<codecave:tilt_controls.bss2>+0x24)660f28d80fc6d855a1(<codecave:tilt_controls.bss2>+0x28)ba0000008031d08b0d(<codecave:tilt_controls.bss2>+0x2c)31d183ec1c894c241889442414f30f11542410f30f114c240cf30f115c2408f30f11442404f30f11642420f30f112424e8([codecave:tilt_controls.text0]+0xd0)83c41cf30f1005(<codecave:tilt_controls.data1>+0x4)f30f100d(<codecave:tilt_controls.bss2>+0x4)a1<codecave:tilt_controls.data1>b90000008031c8a3(<codecave:tilt_controls.bss2>+0x14)f30f1105(<codecave:tilt_controls.bss2>+0x18)f30f110d(<codecave:tilt_controls.bss2>+0x1c)a1(<codecave:tilt_controls.bss2>+0x8)31c8a3(<codecave:tilt_controls.bss2>+0x20)f30f100d(<codecave:tilt_controls.data1>+0x8)0f57c0f30f5ac1660f2e05(<codecave:tilt_controls_comdat_pool>+0x98)7646f30f580d(<codecave:tilt_controls_comdat_pool>+0xa0)f30f594c2404f30f5ac9f20f590d(<codecave:tilt_controls_comdat_pool>+0xa8)f20f58c1f20f5ac0f30f1105(<codecave:tilt_controls.data1>+0x8)f30f5ac0f20f100d(<codecave:tilt_controls_comdat_pool>+0x98)660f2ec8760ac705(<codecave:tilt_controls.data1>+0x8)cdcccc3d8b842480000000894424108b84248400000089442404e93efdffffff15(<codecave:tilt_controls_imports>+0x24)5068<option:tilt_controls_const_3>6a1068<option:tilt_controls_const_2>e8[log_mboxf]83c410b8010000008d65f45e5f5b5dc204000f1f40008b8108fc870185c00f84880200005553575681ec5001000089ce8d0c008d0c4985c90f849c0000008b0d(<codecave:tilt_controls.bss2>+0x3c)85c9742f51e8[th_free]83c4048b8608fc87018d0c008d3c49c1e0048d04c050e8[th_malloc]83c404a3(<codecave:tilt_controls.bss2>+0x3c)85ff7516eb63c1e0048d04c050e8[th_malloc]83c404a3(<codecave:tilt_controls.bss2>+0x3c)31c08b0d(<codecave:tilt_controls.bss2>+0x3c)31d2908bbe10fcbf018b5c0708895908f20f100407f20f11018bbe10fcbf018b5c0718895914f20f10440710f20f11410c428bbe08fc870101ff8d3c7f83c01c83c11839fa72bc89e368(<codecave:tilt_controls.bss2>+0x14)53ff15(<codecave:tilt_controls_imports>+0x48)8dbc24100100005357ff15(<codecave:tilt_controls_imports>+0x3c)a1<0x4E77D8>8b088d54241052680001000050ff91b4000000a1<0x4E77D8>8b0868(<codecave:tilt_controls.bss2>+0x40)680001000050ff91b0000000a1<0x4E77D8>8b088d9c24d0000000536a0250ff91b4000000a1<0x4E77D8>8b08576a0250ff91b0000000a1<0x4E77D8>8b088dac2490000000556a0350ff91b4000000a1<0x4E77D8>8b0868(<codecave:tilt_controls.bss2>+0x80)6a0350ff91b0000000a1<0x4E77D8>8b088d7c2450576a1050ff91b4000000a1<0x4E77D8>8b0868(<codecave:tilt_controls.bss2>+0xc0)6a1050ff91b000000080beabfb870101742fa1<0x4E77D8>8b086a046a046a0050ff910c010000a1<0x4E77D8>8b086a046a016a0050ff910c010000c686abfb870101a1<0x4E77D8>8b086a006a066a0050ff910c010000a1<0x4E77D8>8b086a006a036a0050ff910c010000a1<0x4E77D8>8b08684201000050ff9164010000a1<0x4E77D8>8b8e08fc870101c98b106a18ff35(<codecave:tilt_controls.bss2>+0x3c)516a0450ff924c010000ff86cc0000008b8610fcbf0189860cfcbf01c78608fc870100000000a1<0x4E77D8>8b088d54241052680001000050ff91b0000000a1<0x4E77D8>8b08536a0250ff91b0000000a1<0x4E77D8>8b08556a0350ff91b0000000a1<0x4E77D8>8b08576a1050ff91b000000081c4500100005e5f5b5db801000000c30f1f400053575681ec50010000ff15(<codecave:tilt_controls_imports>+0x28)b9e8030000030d(<codecave:tilt_controls.bss2>+0x118)39c8766b0f2805(<codecave:tilt_controls_comdat_pool>+0xb0)0f11442440c744245002001000c644245401c744245500000000c7442458000000008d7424406a1c566a00ff15(<codecave:tilt_controls_imports>+0x2c)83c40c894424486a1068(<codecave:tilt_controls.bss2>+0x11c)6a006a1c56ff35<codecave:tilt_controls.bss2>ff15(<codecave:tilt_controls_imports>+0x20)83f8ff0f8453010000ff15(<codecave:tilt_controls_imports>+0x28)a3(<codecave:tilt_controls.bss2>+0x118)8d74244068100100006a0056e8[th_memset]83c40ca1<0x4E77F4>85c0742d8b0850ff516485c07823a1<0x4E77F4>8b0856681001000050ff512485c0780e807c2474007907c605(<codecave:tilt_controls.bss2>+0xc)010f1005<codecave:tilt_controls.rdata31>0f1104240f1005(<codecave:tilt_controls.rdata31>+0x10)0f114424200f1005(<codecave:tilt_controls.rdata31>+0x20)0f114424108d7c243068(<codecave:tilt_controls.bss2>+0x14)57ff15(<codecave:tilt_controls_imports>+0x48)89e38b35(<codecave:tilt_controls_imports>+0x4c)535753ffd668(<codecave:tilt_controls.bss2>+0x14)5053ffd68d5c2420535753ffd668(<codecave:tilt_controls.bss2>+0x14)5053ffd68d5c2410535753ffd668(<codecave:tilt_controls.bss2>+0x14)5053ffd6f30f104c2408f30f110d(<codecave:tilt_controls.bss2>+0x100)f30f1014240f2805<codecave:tilt_controls_comdat_pool>0f57d0f605<0x4E6D10>08b8dc050000b9ee0200000f44c8f30f1115(<codecave:tilt_controls.bss2>+0x104)f30f2ad9f30f10642404f30f1125(<codecave:tilt_controls.bss2>+0x108)f30f10642420f30f106c24180f14ec0f57e40fc2e5010f14ca0fc6db000f59d90f57c30f54c40f55e30f56e0f30f5bc40f1305(<codecave:tilt_controls.bss2>+0x110)b80100000081c4500100005e5f5bc3ff15(<codecave:tilt_controls_imports>+0x24)5068<option:tilt_controls_const_4>6a1068<option:tilt_controls_const_2>e8[log_mboxf]83c410ebd466905553575681ecf40200008d842464010000506802020000ff15(<codecave:tilt_controls_imports>+0x8)e8[codecave:tilt_controls.text0]6a006a006a0068(<codecave:tilt_controls.text0>+0x4e0)6a006a00ff15<codecave:tilt_controls_imports>68(<codecave:tilt_controls.text0>+0xac0)e8[0x4017E0]804804026a0150e8[0x401390]f30f1005<0x4E78C4>f20f100d(<codecave:tilt_controls_comdat_pool>+0xc0)660f56c1f20f5cc1f20f5ac0f30f5e05(<codecave:tilt_controls_comdat_pool>+0xc8)f30f5ac0f20f100d(<codecave:tilt_controls_comdat_pool>+0xd0)f20f59c8f20f1015(<codecave:tilt_controls_comdat_pool>+0xd8)f20f58caf20f5ac9f20f5905(<codecave:tilt_controls_comdat_pool>+0xe0)f20f58c2f20f5ac083ec108d9c2434010000891c24f30f114c2408f30f11442404c744240c00000000ff15(<codecave:tilt_controls_imports>+0x38)8dbc24e40000006a0068db0fc93f68db0fc93f57ff15(<codecave:tilt_controls_imports>+0x40)8b35(<codecave:tilt_controls_imports>+0x44)575368(<codecave:tilt_controls.bss2>+0x40)ffd6f30f1005(<0x4E78C4>+0x4)f20f100d(<codecave:tilt_controls_comdat_pool>+0xc0)660f56c1f20f5cc1f20f5ac0f30f5e05(<codecave:tilt_controls_comdat_pool>+0xe8)f30f5ac0f20f5e05(<codecave:tilt_controls_comdat_pool>+0xf0)f20f5ac0f30f114424180f57c0f20f1144241cf20f1144240cc744241400000000c744240800000000c74424040000803fc704240000000089e08d4c240c8d5424188d9c24a400000050515253ff15(<codecave:tilt_controls_imports>+0x34)83ec140f2805(<codecave:tilt_controls_comdat_pool>+0x100)0f114424048d7c2478893c24ff15(<codecave:tilt_controls_imports>+0x30)8d6c24246a006a00689a9999be55ff15(<codecave:tilt_controls_imports>+0x38)575368(<codecave:tilt_controls.bss2>+0x80)ffd65568(<codecave:tilt_controls.bss2>+0x80)68(<codecave:tilt_controls.bss2>+0x80)ffd60f57c00f1105(<codecave:tilt_controls.bss2>+0xc4)0f1105(<codecave:tilt_controls.bss2>+0xd8)0f1105(<codecave:tilt_controls.bss2>+0xec)c705(<codecave:tilt_controls.bss2>+0xfc)0000803fc705(<codecave:tilt_controls.bss2>+0xe8)0000803fc705(<codecave:tilt_controls.bss2>+0xd4)0000803fc705(<codecave:tilt_controls.bss2>+0xc0)0000803f31c081c4f40200005e5f5b5dc3",
        },
        "tilt_controls.data1": {
            access: "rw",
            code: "f304353ff304353f00002041",
        },
        "tilt_controls.bss2": {
            access: "rw",
            size: 300,
        },
        "tilt_controls.rdata31": {
            access: "r",
            code: "0000803f000000000000000000000000000000000000803f000000000000000000000000000000000000803f00000000000000000000803f00000000",
        },
        tilt_controls_comdat_pool: {
            access: "r",
            code: "000000800000008000000080000000800000003f0000003f0000003f0000003f0000803f00000000000000000000000000000000000000400000000000000000000000400000804000000040000080400000804000000000000000000000000000008040000000410000804000000041399d52a246df913f399d52a246df913f399d52a246df913f000000000000805f8dedb5a0f7c6b03e9a9999999999b93fcdccccbd0000000000000000000010c044535543e9030c000000000078563412000000000000304300002044000000000000000000006ec0000000000000e03f0000000000006cc00000e03f000000001c339045a779e23f0000000000000000920a863fabaaaa3f0000000000401c46",
        },
        tilt_controls_patch_post_init: {
            access: "rx",
            code: "555357565068<option:kernel32_dll_str>e8[th_GetModuleHandleA]68<option:LoadLibraryA_str>50e8[th_GetProcAddress]89042431edbb<codecave:tilt_controls_dlls>8b35<codecave:tilt_controls_dlls>660f1f44000056e8[th_GetModuleHandleA]89c785c0750b56ff54240489c785c0743c8b730439f5741f6690ff34ad<codecave:tilt_controls_import_names>57e8[th_GetProcAddress]85c0742b8904ad<codecave:tilt_controls_imports>4539ee75e38b730883c30885f675b983c4045e5f5b5dc30f1f4000505668<option:dll_load_failed_str>eb0d50ff34ad<codecave:tilt_controls_import_names>68<option:import_failed_str>e8[th_GetLastError]894424086a1068<option:tilt_controls_name_str>e8[log_mboxf]cc",
            "export": true,
        },
        tilt_controls_dlls: {
            access: "r",
            code: "<option:kernel32_dll_str>02000000<option:ws2_32_dll_str>0a000000<option:winmm_dll_str>0b000000<option:zlib-ng_dll_str>0c000000<option:d3dx9_43_dll_str>1400000000000000",
        },
        tilt_controls_import_names: {
            access: "r",
            code: "<option:CreateThread_str><option:VirtualProtect_str><option:WSAStartup_str><option:recvfrom_str><option:bind_str><option:socket_str><option:htons_str><option:inet_pton_str><option:sendto_str><option:WSAGetLastError_str><option:timeGetTime_str><option:crc32_z_str><option:D3DXMatrixPerspectiveFovLH_str><option:D3DXMatrixLookAtLH_str><option:D3DXMatrixTranslation_str><option:D3DXMatrixRotationQuaternion_str><option:D3DXMatrixRotationYawPitchRoll_str><option:D3DXMatrixMultiply_str><option:D3DXQuaternionInverse_str><option:D3DXQuaternionMultiply_str>",
        },
        tilt_controls_imports: {
            access: "rw",
            size: 80,
        },
    },
    binhacks: {
        tilt_controls_hook_jmp: {
            addr: "0x44CBE4",
            code: "E9 ([codecave:tilt_controls.text0]+0xcb0)",
        },
        tilt_controls_flush_sprites: {
            addr: "0x44EF91",
            code: "E8 ([codecave:tilt_controls.text0]+0x820)",
        },
        tilt_controls_move: {
            addr: "0x4543DC",
            code: "8B15(<codecave:tilt_controls.bss2>+0x110) A1((<codecave:tilt_controls.bss2>+0x110)+4) 8954240C EB4A",
        },
    },
}