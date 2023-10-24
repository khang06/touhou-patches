{
    options: {
        multi_instance_const_0: {
            type: "s",
            val: "kernel32.dll",
        },
        kernel32_dll_str: {
            type: "s",
            val: "kernel32.dll",
        },
        VirtualProtect_str: {
            type: "s",
            val: "VirtualProtect",
        },
        CreateMutexA_str: {
            type: "s",
            val: "CreateMutexA",
        },
        CreateMutexW_str: {
            type: "s",
            val: "CreateMutexW",
        },
        multi_instance_name_str: {
            type: "s",
            val: "multi_instance",
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
        "multi_instance.text": {
            prot: "rx",
            code: "5553575650a1(<Rx0>+0x3c)8b88(<Rx0>+0x80)8b81(<Rx0>+0xc)85c0746e8db1(<Rx0>+0x20)8d80<Rx0>68<option:multi_instance_const_0>50e8[th_stricmp]83c40885c0740b8b0683c61485c075dfeb458b4ef08b81<Rx0>85c074388d99<Rx0>89e5be040000008b3d<codecave:multi_instance_imports>3b442418751555565653ffd78b44241c890355ff7424045653ffd78b430483c30485c075db83c4045e5f5b5dc3a1(<codecave:multi_instance_imports>+0x4)c744240c00000000ff20a1(<codecave:multi_instance_imports>+0x8)c744240c00000000ff20a1(<codecave:multi_instance_imports>+0x4)68(<codecave:multi_instance.text>+0x90)50e8[codecave:multi_instance.text]83c408a1(<codecave:multi_instance_imports>+0x8)68(<codecave:multi_instance.text>+0x9f)50e8[codecave:multi_instance.text]83c408c3",
        },
        multi_instance_patch_init: {
            prot: "rx",
            code: "555357565068<option:kernel32_dll_str>e8[th_GetModuleHandleA]68<option:LoadLibraryA_str>50e8[th_GetProcAddress]89042431edbb<codecave:multi_instance_dlls>8b35<codecave:multi_instance_dlls>660f1f44000056e8[th_GetModuleHandleA]89c785c0750b56ff54240489c785c0743c8b730439f5741f6690ff34ad<codecave:multi_instance_import_names>57e8[th_GetProcAddress]85c0742b8904ad<codecave:multi_instance_imports>4539ee75e38b730883c30885f675b983c4045e5f5b5de92c000000505668<option:dll_load_failed_str>eb0d50ff34ad<codecave:multi_instance_import_names>68<option:import_failed_str>e8[th_GetLastError]894424086a1068<option:multi_instance_name_str>e8[log_mboxf]cce8([codecave:multi_instance.text]+0xae)c3",
            "export": true,
        },
        multi_instance_dlls: {
            prot: "r",
            code: "<option:kernel32_dll_str>0300000000000000",
        },
        multi_instance_import_names: {
            prot: "r",
            code: "<option:VirtualProtect_str><option:CreateMutexA_str><option:CreateMutexW_str>",
        },
        multi_instance_imports: {
            prot: "rw",
            size: 12,
        },
    },
    binhacks: {},
}