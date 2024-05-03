#include <Windows.h>
#include <Commctrl.h>
#include <winternl.h>
#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class FakeCrash : public Effect {
public:
    virtual bool Update() {
        // Make sure we're running in the comctl32 6.0 activation context
        ULONG_PTR cookie = 0;
        ActivateActCtx(StupidWindowsStuff::ActivationContext, &cookie);

        // GetModuleHandle returns comctl32 5.x, time to walk the PEB...
        HRESULT (WINAPI* TaskDialogIndirectPtr)(const TASKDIALOGCONFIG*, int*, int*, BOOL*) = nullptr;
        struct COOLER_PEB_LDR_DATA {
            char pad0[0xC];
            LIST_ENTRY InLoadOrderModuleList;
            LIST_ENTRY InMemoryOrderModuleList;
            LIST_ENTRY InInitializationOrderModuleList;
        };
        struct COOLER_LDR_DATA_TABLE_ENTRY {
            LIST_ENTRY InLoadOrderLinks;
            LIST_ENTRY InMemoryOrderLinks;
            LIST_ENTRY InInitializationOrderLinks;
            VOID* DllBase;
            char pad1C[0x10];
            UNICODE_STRING BaseDllName;
        };

        auto teb = (PTEB)__readfsdword(offsetof(NT_TIB, Self));
        auto ldr = (COOLER_PEB_LDR_DATA*)teb->ProcessEnvironmentBlock->Ldr;

        auto cur_entry = ldr->InLoadOrderModuleList.Flink;
        COOLER_LDR_DATA_TABLE_ENTRY* cur = nullptr;

        while (cur_entry != &ldr->InLoadOrderModuleList && cur_entry != nullptr) {
            cur = CONTAINING_RECORD(cur_entry, COOLER_LDR_DATA_TABLE_ENTRY, InLoadOrderLinks);
            if (!_wcsicmp(cur->BaseDllName.Buffer, L"comctl32.dll")) {
                *(FARPROC*)&TaskDialogIndirectPtr = GetProcAddress((HMODULE)cur->DllBase, "TaskDialogIndirect");
                if (TaskDialogIndirectPtr)
                    break;
            }
            cur_entry = cur_entry->Flink;
        }
        if (!TaskDialogIndirectPtr)
            return false;

        // Make it more convincing for people with VS installed
        HKEY key = NULL;
        bool has_debugger = RegOpenKey(HKEY_LOCAL_MACHINE, TEXT("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\AeDebug"), &key) == ERROR_SUCCESS;
        if (key)
            RegCloseKey(key);

        // Freeze for a bit
        LONG vol = 0;
        SoundManager::StopAllSounds();
        SoundManager::Instance.SendMsg(6, 0, "Pause");
        while (SoundManager::Instance.HandleMsg())
            ;
        SetCursor(LoadCursorA(NULL, IDC_APPSTARTING));
        Sleep(500);
        SetCursor(LoadCursorA(NULL, IDC_ARROW));

        TASKDIALOG_BUTTON tdb[2] = {
            {
                .nButtonID = 2,
                .pszButtonText = L"Close the program"
            },
            {
                .nButtonID = 3,
                .pszButtonText = L"Debug the program"
            },
        };

        TASKDIALOGCONFIG tdc = {};
        tdc.cbSize = sizeof(tdc);
        tdc.hwndParent = Main::Window;
        tdc.hInstance = (HINSTANCE)0x400000;
        tdc.dwFlags = TDF_USE_COMMAND_LINKS;
        tdc.pszMainInstruction = L"th18.exe has stopped working";
        tdc.pszContent = L"A problem caused the program to stop working correctly. Please close the program.";
        tdc.cButtons = has_debugger ? 2 : 1;
        tdc.pszWindowTitle = L"th18.exe";
        tdc.pButtons = tdb;
        tdc.pszMainIcon = L"IDI_ICON3";
        TaskDialogIndirectPtr(&tdc, 0, 0, 0);

        // Turn the audio back on
        SoundManager::Instance.SendMsg(7, 0, "UnPause");

        if (Window::IsFullscreen())
            SetCursor(LoadCursorA(NULL, NULL));

        DeactivateActCtx(0, cookie);
        return false;
    }
};
REGISTER_EFFECT(FakeCrash);
