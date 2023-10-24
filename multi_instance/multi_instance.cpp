// clang++ -m32 -Os -c multi_instance.cpp -o multi_instance.obj

#define _CRT_NONSTDC_NO_WARNINGS
#include <Windows.h>

extern "C" char g_base;

void iat_hook(void* target_ptr, void* hook) {
	// Get the PE optional header
	auto nt_header = (PIMAGE_NT_HEADERS32)(&g_base + ((PIMAGE_DOS_HEADER)&g_base)->e_lfanew);
	auto optional_header = (PIMAGE_OPTIONAL_HEADER32)(&nt_header->OptionalHeader);

	// Find the dll's import descriptor
	bool found = false;
	auto import_desc = (PIMAGE_IMPORT_DESCRIPTOR)(&g_base + optional_header->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress);
	for (; import_desc->Name; import_desc++) {
		if (!stricmp(&g_base + import_desc->Name, "kernel32.dll")) {
			found = true;
			break;
		}
	}
	if (!found)
		return;

	// Find and replace the target function with the hook
	auto thunk = (PIMAGE_THUNK_DATA)(&g_base + import_desc->FirstThunk);
	for (; thunk->u1.Function != NULL; thunk++) {
		if (thunk->u1.Function == (DWORD)target_ptr) {
            DWORD prot;
            VirtualProtect(&thunk->u1.Function, sizeof(hook), PAGE_READWRITE, &prot);
            thunk->u1.Function = (DWORD)hook;
            VirtualProtect(&thunk->u1.Function, sizeof(hook), prot, &prot);
		}
	}
}

HANDLE __declspec(naked) WINAPI CreateMutexA_hook(LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCSTR) {
    __asm {
        mov     dword ptr [esp+0xC], 0
        jmp     CreateMutexA
    }
}

HANDLE __declspec(naked) WINAPI CreateMutexW_hook(LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCWSTR) {
    __asm {
        mov     dword ptr [esp+0xC], 0
        jmp     CreateMutexW
    }
}

extern "C" void coff2binhack_init() {
    iat_hook((void*)CreateMutexA, (void*)CreateMutexA_hook);
    iat_hook((void*)CreateMutexW, (void*)CreateMutexW_hook);
}
