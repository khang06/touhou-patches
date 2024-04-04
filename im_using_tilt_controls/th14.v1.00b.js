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
        tilt_controls_const_5: {
            type: "s",
            val: " ",
        },
        tilt_controls_const_6: {
            type: "s",
            val: "",
        },
        tilt_controls_const_7: {
            type: "s",
            val: "true",
        },
        tilt_controls_const_8: {
            type: "s",
            val: "false",
        },
        tilt_controls_const_9: {
            type: "s",
            val: "Controller connected: %s\nTilt X: %s%f\nTilt Y: %s%f\nTilt Z: %s%f",
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
        "tilt_controls.text": {
            access: "rx",
            code: "5683ec1489e05068<option:tilt_controls_const_0>6a02ff15(<codecave:tilt_controls_imports>+0x1c)8b35(<codecave:tilt_controls_imports>+0x18)6855a40000ffd666c744240402006855a40000ffd666894424068b042489442408c744241000000000c744240c000000006888680000ffd68b0c2466c705(<codecave:tilt_controls.bss>+0x11c)020066a3(<codecave:tilt_controls.bss>+0x11e)890d(<codecave:tilt_controls.bss>+0x120)c705(<codecave:tilt_controls.bss>+0x128)00000000c705(<codecave:tilt_controls.bss>+0x124)000000006a116a026a02ff15(<codecave:tilt_controls_imports>+0x14)a3<codecave:tilt_controls.bss>8d4c24046a105150ff15(<codecave:tilt_controls_imports>+0x10)85c0791bff15(<codecave:tilt_controls_imports>+0x24)5068<option:tilt_controls_const_1>6a1068<option:tilt_controls_const_2>e8[log_mboxf]83c41083c4145ec36666666666662e0f1f8400000000005589e583e4f081ecd0000000f30f102d(<codecave:tilt_controls.data>+0x4)f30f1035(<codecave:tilt_controls.bss>+0x4)0f28e50f14e60f5725<codecave:tilt_controls_comdat_pool>f30f1015(<codecave:tilt_controls.bss>+0x8)f30f101d<codecave:tilt_controls.data>0f296c24200f16ec0f297424100fc6f4d40fc6ee28f20f1075100f16f60f59f50f28ca0fc6ccd40f16e30f28fb0fc6fc80f30f106510f30f1045140f14c4f30f106d0c0f28e00fc6e5040f59e70f58e60f295424300f5715<codecave:tilt_controls_comdat_pool>0fc6ca020fc6e8400f59e90f58ec0f592d(<codecave:tilt_controls_comdat_pool>+0x10)f30f1075180f57e40f2ef4f30f105520f30f107d1cf30f104d0875277a250f2efc75207a1e0f57c00f2ed075167a140f284424100f287424300f28542420e9b40200000f28c7f30f59c70f28cef30f59cef30f58c80f28c2f30f59c2f30f58c1f30f5ac00f57c9660f2ec10f296c24607206f20f51c0eb19f20f110424e8[0x4A9404]f30f107d1cdd5c2458f20f10442458f20f5ac0f30f1015(<codecave:tilt_controls_comdat_pool>+0x20)f30f5ed00f29542430f30f1045200f14f80f28c20fc6c2000f16ff0f59f80f29bc24b0000000f30f100d(<codecave:tilt_controls.bss>+0x4)f30f101d(<codecave:tilt_controls.data>+0x4)0f28c10f14c30f59c00f294424200f28c30f14c10fc6c0140f5905(<codecave:tilt_controls_comdat_pool>+0x30)0f28f00f29842490000000f30f1015<codecave:tilt_controls.data>0f299424a0000000f30f59d2f30f103d(<codecave:tilt_controls.bss>+0x8)0f28e70f297c2470f30f59e7f30f5915(<codecave:tilt_controls_comdat_pool>+0x50)0f12c00f29442410f30f10c20f286c24200f14e90f14cc0f59c80f14e30f288424a00000000f16d80f299c2480000000f30f105d18f30f595c24300f14c70f5905(<codecave:tilt_controls_comdat_pool>+0x40)0f28fb0f14fb0f59f80f58cf0f28b424900000000fc6d6d40fc6d6520f59e20f58e10f28c80f283d<codecave:tilt_controls_comdat_pool>0f57cf0fc6c0550f14c10f284c2430f30f10551cf30f59ca0f14c90f59c80f58cc0f28d10f286424700f28c40f284c24200fc6c1100fc6c1480f16e10fc6e1180fc6c955f30f590d(<codecave:tilt_controls_comdat_pool>+0x50)0f14da0f28d30f16d30f59d60f5cde0fc6d3d80fc6ac2480000000240f592d(<codecave:tilt_controls_comdat_pool>+0x60)0f59e5f30f10e90f59c50fc6d2d80f58c20f58e00f285424100f57d70fc6d6d40fc6d6c80f599424b00000000f58d40f28c20f59c20fc6c0ff0f28ca660f15caf30f59c9f30f58c80f28c20fc6c255f30f59c0f30f58c10f295424100f28caf30f59caf30f58c80f57c0f30f5ac1660f2e05(<codecave:tilt_controls_comdat_pool>+0x70)7206f20f51c0eb14f20f110424e8[0x4A9404]dd5c2450f20f104424500f286c2460f30f104d08f20f5ac0f30f1015(<codecave:tilt_controls_comdat_pool>+0x20)f30f5ed00fc6d2000f285c24100f59daf30f1005(<codecave:tilt_controls.data>+0x8)0fc6c0000f59c30f5ce8f30f101d<codecave:tilt_controls.data>f30f1015(<codecave:tilt_controls.data>+0x4)f30f1005(<codecave:tilt_controls.bss>+0x4)f30f1035(<codecave:tilt_controls.bss>+0x8)0f28e5660f15e5f30f59e1f30f58e3f30f1125<codecave:tilt_controls.data>0f28dd0fc6ddfff30f59d9f30f58daf30f111d(<codecave:tilt_controls.data>+0x4)0f28d50fc6d555f30f59d1f30f58d0f30f1115(<codecave:tilt_controls.bss>+0x4)f30f59e9f30f58eef30f112d(<codecave:tilt_controls.bss>+0x8)f30f59dbf30f59e4f30f58e3f30f59d2f30f58d4f30f59edf30f58ea0f57c0f30f5ac50f57c9660f2ec17206f20f51c0eb14f20f110424e8[0x4A9404]dd5c2448f20f104424480f57c9f20f5ac8f30f1005(<codecave:tilt_controls_comdat_pool>+0x20)f30f5ec1f30f100d<codecave:tilt_controls.data>f30f59c8f30f110d<codecave:tilt_controls.data>f30f100d(<codecave:tilt_controls.data>+0x4)f30f59c8f30f110d(<codecave:tilt_controls.data>+0x4)f30f100d(<codecave:tilt_controls.bss>+0x4)f30f59c8f30f110d(<codecave:tilt_controls.bss>+0x4)f30f5905(<codecave:tilt_controls.bss>+0x8)f30f1105(<codecave:tilt_controls.bss>+0x8)89ec5dc3905589e553575683e4f881ec40040000c744241c100000008d74243c68000400006a0056e8[th_memset]83c40cc7442410000000008d5c242c8b3d(<codecave:tilt_controls_imports>+0xc)c74424040000000066662e0f1f8400000000008d44241c50536a00680004000056ff35<codecave:tilt_controls.bss>ffd783f864740a83f8ff75e0e9ba020000817c243c4453555375d10fb74424403de903000075c566837c24425475bd817c244c0200100075b3837c245c0074ac8b4424448944240cc7442444000000006a64566a00ff15(<codecave:tilt_controls_imports>+0x2c)83c40c3944240c7588807c2451020f9405(<codecave:tilt_controls.bss>+0x10)f20f10464cf20f1105(<codecave:tilt_controls.bss>+0x24)8b4654a3(<codecave:tilt_controls.bss>+0x2c)0f5a842494000000660f5905(<codecave:tilt_controls_comdat_pool>+0x80)660f5ac0f30f108c249c000000f30f5ac9f20f590d(<codecave:tilt_controls_comdat_pool>+0x90)f20f5ac9660f1305(<codecave:tilt_controls.bss>+0x30)f30f110d(<codecave:tilt_controls.bss>+0x38)8b4c241089c88b54240409d00f84dc0100008b842484000000895424048b9424800000008954240c31ca89c13344240409d00f84b6010000803d(<codecave:tilt_controls.bss>+0xc)007439c705<codecave:tilt_controls.data>f304353fc705(<codecave:tilt_controls.data>+0x4)f304353fc705(<codecave:tilt_controls.bss>+0x4)00000000c705(<codecave:tilt_controls.bss>+0x8)00000000c705(<codecave:tilt_controls.data>+0x8)00002041c605(<codecave:tilt_controls.bss>+0xc)008b44240c2b442410660f6ed01b4c2404660f6ed9660f62d3660fd6542420df6c2420d97c240a0fb744240a0d000300006689442416d96c2416c1e91fd8048d(<codecave:tilt_controls_comdat_pool>+0x98)d96c240ad95c2418f30f10542418f30f5ad2f20f5915(<codecave:tilt_controls_comdat_pool>+0xa0)f20f5af2f30f1015(<codecave:tilt_controls.bss>+0x2c)0f2825<codecave:tilt_controls_comdat_pool>0f57d4f30f101d(<codecave:tilt_controls.bss>+0x28)0f57dcf30f1025(<codecave:tilt_controls.bss>+0x24)660f28e80fc6e85583ec1cf30f11542418f30f115c2414f30f11642410f30f114c240cf30f116c2408f30f11442404f30f11742420f30f113424e8([codecave:tilt_controls.text]+0xd0)83c41cf30f1005<codecave:tilt_controls.data>0f2825<codecave:tilt_controls_comdat_pool>0f57c4f30f100d(<codecave:tilt_controls.data>+0x4)f30f1015(<codecave:tilt_controls.bss>+0x4)f30f101d(<codecave:tilt_controls.bss>+0x8)0f57dcf30f1105(<codecave:tilt_controls.bss>+0x14)f30f110d(<codecave:tilt_controls.bss>+0x18)f30f1115(<codecave:tilt_controls.bss>+0x1c)f30f111d(<codecave:tilt_controls.bss>+0x20)f30f100d(<codecave:tilt_controls.data>+0x8)0f57c0f30f5ac1660f2e05(<codecave:tilt_controls_comdat_pool>+0xa8)7646f30f580d(<codecave:tilt_controls_comdat_pool>+0xb0)f30f594c2404f30f5ac9f20f590d(<codecave:tilt_controls_comdat_pool>+0xb8)f20f58c1f20f5ac0f30f1105(<codecave:tilt_controls.data>+0x8)f30f5ac0f20f100d(<codecave:tilt_controls_comdat_pool>+0xa8)660f2ec8760ac705(<codecave:tilt_controls.data>+0x8)cdcccc3d8b842480000000894424108b84248400000089442404e921fdffffff15(<codecave:tilt_controls_imports>+0x24)5068<option:tilt_controls_const_3>6a1068<option:tilt_controls_const_2>e8[log_mboxf]83c410b8010000008d65f45e5f5b5dc204000f1f80000000005553575681ec500100008b81f081bc0085c00f847402000089ce8d0c008d0c4985c90f849c0000008b0d(<codecave:tilt_controls.bss>+0x3c)85c9742f51e8[th_free]83c4048b86f081bc008d0c008d3c49c1e0048d04c050e8[th_malloc]83c404a3(<codecave:tilt_controls.bss>+0x3c)85ff7516eb63c1e0048d04c050e8[th_malloc]83c404a3(<codecave:tilt_controls.bss>+0x3c)31c08b0d(<codecave:tilt_controls.bss>+0x3c)31d2908bbef881f4008b5c0708895908f20f100407f20f11018bbef881f4008b5c0718895914f20f10440710f20f11410c428bbef081bc0001ff8d3c7f83c01c83c11839fa72bc89e368(<codecave:tilt_controls.bss>+0x14)53ff15(<codecave:tilt_controls_imports>+0x48)8dbc24100100005357ff15(<codecave:tilt_controls_imports>+0x3c)a1<0x4D8F68>8b088d54241052680001000050ff91b4000000a1<0x4D8F68>8b0868(<codecave:tilt_controls.bss>+0x40)680001000050ff91b0000000a1<0x4D8F68>8b088d9c24d0000000536a0250ff91b4000000a1<0x4D8F68>8b08576a0250ff91b0000000a1<0x4D8F68>8b088dac2490000000556a0350ff91b4000000a1<0x4D8F68>8b0868(<codecave:tilt_controls.bss>+0x80)6a0350ff91b0000000a1<0x4D8F68>8b088d7c2450576a1050ff91b4000000a1<0x4D8F68>8b0868(<codecave:tilt_controls.bss>+0xc0)6a1050ff91b000000080be9381bc0001742fa1<0x4D8F68>8b086a046a046a0050ff910c010000a1<0x4D8F68>8b086a046a016a0050ff910c010000c6869381bc0001a1<0x4D8F68>8b086a006a066a0050ff910c010000a1<0x4D8F68>8b086a006a036a0050ff910c010000a1<0x4D8F68>8b08684201000050ff9164010000a1<0x4D8F68>8b8ef081bc0001c98b106a18ff35(<codecave:tilt_controls.bss>+0x3c)516a0450ff924c010000ff86cc0000008b86f881f4008986f481f400c786f081bc0000000000a1<0x4D8F68>8b088d54241052680001000050ff91b0000000a1<0x4D8F68>8b08536a0250ff91b0000000a1<0x4D8F68>8b08556a0350ff91b0000000a1<0x4D8F68>8b08576a1050ff91b0000000b80100000081c4500100005e5f5b5dc30f1f400053575681ec50010000ff15(<codecave:tilt_controls_imports>+0x28)b9e8030000030d(<codecave:tilt_controls.bss>+0x118)39c8766c66c744245a0000c7442456000000000f2805(<codecave:tilt_controls_comdat_pool>+0xc0)0f11442440c74424500200100066c744245401008d7424406a1c566a00ff15(<codecave:tilt_controls_imports>+0x2c)83c40c894424486a1068(<codecave:tilt_controls.bss>+0x11c)6a006a1c56ff35<codecave:tilt_controls.bss>ff15(<codecave:tilt_controls_imports>+0x20)83f8ff0f8453010000ff15(<codecave:tilt_controls_imports>+0x28)a3(<codecave:tilt_controls.bss>+0x118)8d74244068100100006a0056e8[th_memset]83c40ca1<0x4D8F84>85c0742d8b0850ff516485c07823a1<0x4D8F84>8b0856681001000050ff512485c0780e807c2474007907c605(<codecave:tilt_controls.bss>+0xc)010f1005<codecave:tilt_controls.rdata>0f1104240f1005(<codecave:tilt_controls.rdata>+0x10)0f114424200f1005(<codecave:tilt_controls.rdata>+0x20)0f114424108d7c243068(<codecave:tilt_controls.bss>+0x14)57ff15(<codecave:tilt_controls_imports>+0x48)89e38b35(<codecave:tilt_controls_imports>+0x4c)535753ffd668(<codecave:tilt_controls.bss>+0x14)5053ffd68d5c2420535753ffd668(<codecave:tilt_controls.bss>+0x14)5053ffd68d5c2410535753ffd668(<codecave:tilt_controls.bss>+0x14)5053ffd6f30f104c2408f30f110d(<codecave:tilt_controls.bss>+0x100)f30f1014240f2805<codecave:tilt_controls_comdat_pool>0f57d0f605<0x4D6878>08b8dc050000b9ee0200000f44c8f30f1115(<codecave:tilt_controls.bss>+0x104)f30f2ad9f30f10642404f30f1125(<codecave:tilt_controls.bss>+0x108)f30f10642420f30f106c24180f14ec0f57e40fc2e5010f14ca0fc6db000f59d90f57c30f54c40f55e30f56e0f30f5bc40f1305(<codecave:tilt_controls.bss>+0x110)b80100000081c4500100005e5f5bc3ff15(<codecave:tilt_controls_imports>+0x24)5068<option:tilt_controls_const_4>6a1068<option:tilt_controls_const_2>e8[log_mboxf]83c410ebd49053575683ec40c744243800000000c744243400000000c744243c00000000a1<0x4DB520>85c00f849b000000f30f100d(<codecave:tilt_controls.bss>+0x108)f30f5ac10f57d20f2ecabf<option:tilt_controls_const_5>ba<option:tilt_controls_const_6>0f43d7b9<option:tilt_controls_const_6>f30f100d(<codecave:tilt_controls.bss>+0x104)0f2ecaf30f5ac9be<option:tilt_controls_const_6>0f43f7f30f101d(<codecave:tilt_controls.bss>+0x100)f30f5ae30f2eda0f43cf803d(<codecave:tilt_controls.bss>+0x10)00bf<option:tilt_controls_const_8>bb<option:tilt_controls_const_7>0f44dff20f1144242c89542428f20f114c24208974241cf20f11642414894c2410895c240c8d4c2434894c2404890424c7442408<option:tilt_controls_const_9>e8[0x40BDC0]b80100000083c4405e5f5bc366666666662e0f1f8400000000005553575681ecf40200008d842464010000506802020000ff15(<codecave:tilt_controls_imports>+0x8)e8[codecave:tilt_controls.text]6a006a006a0068(<codecave:tilt_controls.text>+0x570)6a006a00ff15<codecave:tilt_controls_imports>68(<codecave:tilt_controls.text>+0xb70)e8[0x401570]804804026a0150e8[0x401120]68(<codecave:tilt_controls.text>+0xd60)e8[0x401570]804804026a4250e8[0x4011D0]f30f1005<0x4D9054>f20f100d(<codecave:tilt_controls_comdat_pool>+0xd0)660f56c1f20f5cc1f20f5ac0f30f5e05(<codecave:tilt_controls_comdat_pool>+0xd8)f30f5ac0f20f100d(<codecave:tilt_controls_comdat_pool>+0xe0)f20f59c8f20f1015(<codecave:tilt_controls_comdat_pool>+0xe8)f20f58caf20f5ac9f20f5905(<codecave:tilt_controls_comdat_pool>+0xf0)f20f58c2f20f5ac083ec108d9c2434010000891c24f30f114c2408f30f11442404c744240c00000000ff15(<codecave:tilt_controls_imports>+0x38)8dbc24e40000006a0068db0fc93f68db0fc93f57ff15(<codecave:tilt_controls_imports>+0x40)8b35(<codecave:tilt_controls_imports>+0x44)575368(<codecave:tilt_controls.bss>+0x40)ffd6f30f1005(<0x4D9054>+0x4)f20f100d(<codecave:tilt_controls_comdat_pool>+0xd0)660f56c1f20f5cc1f20f5ac0f30f5e05(<codecave:tilt_controls_comdat_pool>+0xf8)f30f5ac0f20f5e05(<codecave:tilt_controls_comdat_pool>+0x100)f20f5ac0f30f114424180f57c00f1344241cc744241000000000c744240c00000000c744241400000000c744240800000000c74424040000803fc704240000000089e08d4c240c8d5424188d9c24a400000050515253ff15(<codecave:tilt_controls_imports>+0x34)83ec140f2805(<codecave:tilt_controls_comdat_pool>+0x110)0f114424048d7c2478893c24ff15(<codecave:tilt_controls_imports>+0x30)8d6c24246a006a00689a9999be55ff15(<codecave:tilt_controls_imports>+0x38)575368(<codecave:tilt_controls.bss>+0x80)ffd65568(<codecave:tilt_controls.bss>+0x80)68(<codecave:tilt_controls.bss>+0x80)ffd60f57c00f1105(<codecave:tilt_controls.bss>+0xc4)0f1105(<codecave:tilt_controls.bss>+0xd8)0f1105(<codecave:tilt_controls.bss>+0xec)c705(<codecave:tilt_controls.bss>+0xfc)0000803fc705(<codecave:tilt_controls.bss>+0xe8)0000803fc705(<codecave:tilt_controls.bss>+0xd4)0000803fc705(<codecave:tilt_controls.bss>+0xc0)0000803f31c081c4f40200005e5f5b5dc3",
        },
        "tilt_controls.data": {
            access: "rw",
            code: "f304353ff304353f00002041",
        },
        "tilt_controls.bss": {
            access: "rw",
            size: 300,
        },
        "tilt_controls.rdata": {
            access: "r",
            code: "0000803f000000000000000000000000000000000000803f000000000000000000000000000000000000803f00000000000000000000803f00000000",
        },
        tilt_controls_comdat_pool: {
            access: "r",
            code: "000000800000008000000080000000800000003f0000003f0000003f0000003f0000803f000000000000000000000000000000c000008040000000400000804000000040000000c00000000000000000000080400000000000000000000000000000804000000041000080400000004100000000000000000000000000000000399d52a246df913f399d52a246df913f399d52a246df913f000000000000805f8dedb5a0f7c6b03e9a9999999999b93fcdccccbd0000000000000000000010c044535543e9030c000000000078563412000000000000304300002044000000000000000000006ec0000000000000e03f0000000000006cc00000e03f000000001c339045a779e23f0000000000000000920a863fabaaaa3f0000000000401c46",
        },
        tilt_controls_patch_init: {
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
            addr: "0x444FF4",
            code: "E9 [codecave:tilt_controls.text+0xe40]",
        },
        tilt_controls_flush_sprites: {
            addr: "0x447291",
            code: "E8 [codecave:tilt_controls.text+0x8d0]",
        },
        tilt_controls_move: {
            addr: "0x44D621",
            code: "8B1D <codecave:tilt_controls.bss+0x110> A1 (<codecave:tilt_controls.bss+0x110>+4) EB48",
        },
    },
}