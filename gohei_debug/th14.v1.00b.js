{
    options: {
        gohei_debug_const_0: {
            type: "s",
            val: "Shoot timer: %d",
        },
        gohei_debug_const_1: {
            type: "s",
            val: "Gohei active: %u",
        },
        gohei_debug_const_2: {
            type: "s",
            val: "Initial target: 0x%p",
        },
        gohei_debug_const_3: {
            type: "s",
            val: "Free list: ",
        },
        gohei_debug_const_4: {
            type: "s",
            val: "%03u",
        },
        gohei_debug_const_5: {
            type: "s",
            val: "[%03d] State: %d, Despawn: %d, Offscreen: %.0f",
        },
        gohei_debug_const_6: {
            type: "s",
            val: "[%03d] State: %d, Despawned :(",
        },
        gohei_debug_const_7: {
            type: "s",
            val: "[%03d] State: %d, Target: 0x%p, Unfocus: %d, Speed: %f",
        },
        d3dx9_43_dll_str: {
            type: "s",
            val: "d3dx9_43.dll",
        },
        D3DXCreateLine_str: {
            type: "s",
            val: "D3DXCreateLine",
        },
        gohei_debug_name_str: {
            type: "s",
            val: "gohei_debug",
        },
        kernel32_dll_str: {
            type: "s",
            val: "kernel32.dll",
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
        "gohei_debug.text0": {
            access: "rx",
            code: "5553575683ec588b7424788b7c24748b5c24708b4c246c89e050e8[0x479560]0f100424f20f100d(<0x4F5A18>+0x2058)0f5bc90f16c90f1644240c0f5cc10f2815<codecave:gohei_debug_comdat_pool>0f58c2f30f101d(<0x4F5A18>+0x2054)0fc6db000f59c3f20f106424240f166424180f114424300f5ce10f58e20f59e30f116424400f13442450a1<codecave:gohei_debug.bss2>8b086a0050ff5134a1<codecave:gohei_debug.bss2>8b08680000804050ff512ca1<codecave:gohei_debug.bss2>8b088d6c243068000000ff6a055550ff5114a1<codecave:gohei_debug.bss2>8b08680000004050ff512ca1<codecave:gohei_debug.bss2>8b08536a055550ff511485ff740ff30f1044240cf30f5c0424f30f110785f67410f30f1044241cf30f5c442404f30f110683c4585e5f5b5dc3660f1f84000000000053575681ec340400008bb4244c0400008bbc244404000031db0f1f80000000000f57c0f30f2ac3f30f100ff30f114c2414f30f5905(<codecave:gohei_debug_comdat_pool>+0x10)f30f5905(<codecave:gohei_debug_comdat_pool>+0x14)f30f5ac0f20f1144240c83ec08f20f110424e8[th_cos]83c408d95c2408f30f104c2408f30f10842448040000f30f59c8f30f584c2414f30f580d(<codecave:gohei_debug_comdat_pool>+0x18)0f114c2424f30f104704f30f110424f30f1005(<0x4F5A18>+0x2054)0f1144241483ec08f20f10442414f20f110424e8[th_sin]83c408d95c2404f30f10442404f30f59842448040000f30f5804240f104c24240f14c80f580d(<codecave:gohei_debug_comdat_pool>+0x20)f30f1005(<0x4F5A18>+0x2054)0f105424140f14d00f59d10f1354dc344383fb7f0f8525ffffff8b4424348b4c2438898c24300400008984242c040000a1<codecave:gohei_debug.bss2>8b086a0150ff5134a1<codecave:gohei_debug.bss2>8b08680000804050ff512ca1<codecave:gohei_debug.bss2>8b088d7c243468000000ff68800000005750ff5114a1<codecave:gohei_debug.bss2>8b08680000004050ff512ca1<codecave:gohei_debug.bss2>8b085668800000005750ff511481c4340400005e5f5bc36666662e0f1f8400000000005553575683ec200f57c0f20f110424c744240800000000833d<0x4DB520>000f8409050000833d<0x4DB67C>000f84fc040000833d<0x4DB544>000f84ef0400008b0d<0x4F56CC>e8[0x475EB0]8b3d<0x4DB67C>8d87e0050000f30f1015(<codecave:gohei_debug_comdat_pool>+0x30)50e8[0x42C310]89c28d87c806000089442418b8540800008954240ceb12660f1f44000005a00100003d54d80000742b83bc070cffffff01750d8b8c0730ffffff807921027410837c07dc0175d68b0c078079210275cdb301eb0231db8b873c83010069c8abaaaaaa81c1aaaaaa2a31ed81f955555555b90000000083d1ff81c900ff00ff8b15<0x4DB520>898ab091010089e65068<option:gohei_debug_const_0>5652e8[0x40BDC0]83c410f30f10442404f30f5805(<codecave:gohei_debug_comdat_pool>+0x34)f30f1144240483bf4c830100000f95c0f6d308c30fb6c383e001f7d80d00ff00ff8b0d<0x4DB520>8981b0910100ffb74c83010068<option:gohei_debug_const_1>5651e8[0x40BDC0]83c410f30f10442404f30f5805(<codecave:gohei_debug_comdat_pool>+0x34)8b4c240c89c8f7d819edf30f1144240481cd00ff00ffa1<0x4DB520>89a8b09101005168<option:gohei_debug_const_2>5650e8[0x40BDC0]83c410f30f10442404f30f5805(<codecave:gohei_debug_comdat_pool>+0x34)f30f11442404a1<0x4DB520>c780b0910100ffffffff68<option:gohei_debug_const_3>5650e8[0x40BDC0]83c40cc70424000090428bafccd60000be10000000bb4fecc44e660f1f84000000000089e82b442418f7e3c1ea065268<option:gohei_debug_const_4>8d44240850ff35<0x4DB520>e8[0x40BDC0]83c4108b6d0485ed7415f30f100424f30f5805(<codecave:gohei_debug_comdat_pool>+0x38)f30f1104244e75c0c7042400000000f30f10442404f30f5805(<codecave:gohei_debug_comdat_pool>+0x34)f30f114424048b44240c85c074278b0d<0x4F56CC>ffb014130000e8[0x47F0A0]85c074126a006a00680000ffff50e8[codecave:gohei_debug.text0]83c410c7442404000020428daf8407000031dbe9820000008b0d<0x4DB520>c781b0910100fffffffff30f1045b0f30f5ac0ba0c0000002b9574ffffff8b75e083ec24f20f1144241c895424188974241489442410895c240c8d44242489442404890c24c7442408<option:gohei_debug_const_7>e8[0x40BDC0]83c424f30f10442404f30f5805(<codecave:gohei_debug_comdat_pool>+0x34)f30f114424044381c5d000000081fb000100000f841d020000837ddc0074e78b45008078210275de8b0d<0x4F56CC>ffb558ffffffe8[0x47F0A0]89c6c744241400000000c7442410000000008b45dc85f60f843f01000031c983f8020f95c1f7d981c9ffffff808d442410508d442418505156e8[codecave:gohei_debug.text0]83c4108b45dc83f8020f8511fffffff20f1045ccf30f104c2410f30f105424140f14d10f28da0f5915(<codecave:gohei_debug_comdat_pool>+0x50)f30f100d(<codecave:gohei_debug_comdat_pool>+0x60)0f5cca0f5915(<codecave:gohei_debug_comdat_pool>+0x70)0fc6d1010fc6d1e20f57c90fc2c8010f591d(<codecave:gohei_debug_comdat_pool>+0x40)0f581d(<codecave:gohei_debug_comdat_pool>+0x80)0f54d90f55ca0f56cbf20f1055980f5cca0f5ec80f580d(<codecave:gohei_debug_comdat_pool>+0x90)0f28c10fc6c155f30f5dc80f28c10f5405(<codecave:gohei_debug_comdat_pool>+0xa0)f30f1015(<codecave:gohei_debug_comdat_pool>+0xb0)0f2ec20f84b400000083ec080f57c0f30f5ac1f20f110424e8[th_ceil]83c408d95c241cb80a0000002b8560fffffff30f1044241c0f57c9f30f2ac8f30f5fc1b80b0000002b864c050000f30f2cc8ba0000ffff39c80f8c860000008b973c83010083faff747601ca69caabaaaaaa81c1aaaaaa2a81f955555555ba00ffffffb900ff00ff0f42d1eb5883f8020f85f9fdffffa1<0x4DB520>c780b09101000000ffff6a025368<option:gohei_debug_const_6>8d4c240c5150e8[0x40BDC0]83c414e92afeffff0f28c28b0d<0x4DB520>c781b09101000000ffffb80b0000002b864c050000eb11ba00ffffff8b0d<0x4DB520>8991b0910100f30f5ac083ec20f20f1144241889442414895c240c8d44242089442404890c24c744241002000000c7442408<option:gohei_debug_const_5>e8[0x40BDC0]83c420e9bcfdffffa1<0x4DB520>c780b0910100ffffffffb80100000083c4205e5f5b5dc3660f1f44000068(<codecave:gohei_debug.text0>+0x280)e8[0x401570]804804026a4250e8[0x4011D0]68<codecave:gohei_debug.bss2>ff35<0x4D8F68>ff15<codecave:gohei_debug_imports>85c0780331c0c3cc31c0c3",
        },
        "gohei_debug.bss2": {
            access: "rw",
            size: 4,
        },
        gohei_debug_comdat_pool: {
            access: "r",
            code: "000000420000804100000042000080410000003cdb0fc94000004043000000000000004200008041000000000000000000002043000000410000c041000000000000003f0000003f00000000000000000000003f0000803f0000000000000000000040c300000000000000000000000000000000000000bf0000000000000000000040430000e04300000000000000000000803f0000803f0000000000000000ffffff7fffffff7fffffff7fffffff7f0000807f",
        },
        gohei_debug_patch_post_init: {
            access: "rx",
            code: "555357565068<option:kernel32_dll_str>e8[th_GetModuleHandleA]68<option:LoadLibraryA_str>50e8[th_GetProcAddress]89042431edbb<codecave:gohei_debug_dlls>8b35<codecave:gohei_debug_dlls>660f1f44000056e8[th_GetModuleHandleA]89c785c0750b56ff54240489c785c0743c8b730439f5741f6690ff34ad<codecave:gohei_debug_import_names>57e8[th_GetProcAddress]85c0742b8904ad<codecave:gohei_debug_imports>4539ee75e38b730883c30885f675b983c4045e5f5b5dc30f1f4000505668<option:dll_load_failed_str>eb0d50ff34ad<codecave:gohei_debug_import_names>68<option:import_failed_str>e8[th_GetLastError]894424086a1068<option:gohei_debug_name_str>e8[log_mboxf]cc",
            "export": true,
        },
        gohei_debug_dlls: {
            access: "r",
            code: "<option:d3dx9_43_dll_str>0100000000000000",
        },
        gohei_debug_import_names: {
            access: "r",
            code: "<option:D3DXCreateLine_str>",
        },
        gohei_debug_imports: {
            access: "rw",
            size: 4,
        },
    },
    binhacks: {
        gohei_debug_hook_jmp: {
            addr: "0x444FF4",
            code: "E9 ([codecave:gohei_debug.text0]+0x7c0)",
        },
    },
}