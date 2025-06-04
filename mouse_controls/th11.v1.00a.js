{
    options: {
        user32_dll_str: {
            type: "s",
            val: "user32.dll",
        },
        ScreenToClient_str: {
            type: "s",
            val: "ScreenToClient",
        },
        GetCursorPos_str: {
            type: "s",
            val: "GetCursorPos",
        },
        IsIconic_str: {
            type: "s",
            val: "IsIconic",
        },
        mouse_controls_name_str: {
            type: "s",
            val: "mouse_controls",
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
        "mouse_controls.text0": {
            access: "rx",
            code: "575683ec0c8b74241856e8[0x430290]ff35<0x4C3D88>ff15(<codecave:mouse_controls_imports>+0x8)85c00f85a40000008b15<0x4C3DC0>c1ea0283e20331c083fa030f94c183fa02740d88c8f30f100485<codecave:mouse_controls_comdat_pool>eb08f30f1005(<codecave:mouse_controls_comdat_pool>+0x8)f30f1104248d7c240457ff15(<codecave:mouse_controls_imports>+0x4)57ff35<0x4C3D88>ff15<codecave:mouse_controls_imports>0f57c0f30f2a442404f30f101424f30f5ec2f30f5805(<codecave:mouse_controls_comdat_pool>+0xc)f30f2a4c2408f30f5eca0f14c10f5805(<codecave:mouse_controls_comdat_pool>+0x10)f20f100d(<codecave:mouse_controls_comdat_pool>+0x20)0f5dc80f5f0d(<codecave:mouse_controls_comdat_pool>+0x30)0f138e7c0800000f590d(<codecave:mouse_controls_comdat_pool>+0x40)f30f5bc10f13868808000031c083c40c5e5fc20400",
        },
        mouse_controls_comdat_pool: {
            access: "r",
            code: "0000803f000000400000c03f000000c2000040c3000080c10000000000000000000038430000d8430000000000000000000038c3000000420000000000000000000000430000004300000000000000004c010d00",
        },
        mouse_controls_patch_post_init: {
            access: "rx",
            code: "555357565068<option:kernel32_dll_str>e8[th_GetModuleHandleA]68<option:LoadLibraryA_str>50e8[th_GetProcAddress]89042431edbb<codecave:mouse_controls_dlls>8b35<codecave:mouse_controls_dlls>660f1f44000056e8[th_GetModuleHandleA]89c785c0750b56ff54240489c785c0743c8b730439f5741f6690ff34ad<codecave:mouse_controls_import_names>57e8[th_GetProcAddress]85c0742b8904ad<codecave:mouse_controls_imports>4539ee75e38b730883c30885f675b983c4045e5f5b5dc30f1f4000505668<option:dll_load_failed_str>eb0d50ff34ad<codecave:mouse_controls_import_names>68<option:import_failed_str>e8[th_GetLastError]894424086a1068<option:mouse_controls_name_str>e8[log_mboxf]cc",
            "export": true,
        },
        mouse_controls_dlls: {
            access: "r",
            code: "<option:user32_dll_str>0300000000000000",
        },
        mouse_controls_import_names: {
            access: "r",
            code: "<option:ScreenToClient_str><option:GetCursorPos_str><option:IsIconic_str>",
        },
        mouse_controls_imports: {
            access: "rw",
            size: 12,
        },
    },
    binhacks: {
        mouse_controls_hook_calc_move: {
            addr: "0x43121B",
            code: "E8 [codecave:mouse_controls.text0]",
        },
    },
}