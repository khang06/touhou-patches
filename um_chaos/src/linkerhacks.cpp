#include <Windows.h>

// Sorry

void* __cdecl operator new(unsigned int size) {
    return malloc(size); // Exceptions are overrated anyway
}

void __cdecl operator delete(void* addr) noexcept {
    free(addr);
}

void __cdecl operator delete(void* addr, unsigned int size) {
    free(addr);
}

int __cdecl atexit(void(*)()) {
    return 0;
}

namespace stdext {
    class exception;
}

namespace std {
    void (__cdecl* _Raise_handler)(class stdext::exception const &) = nullptr;
}

extern "C" {
    __declspec(dllimport) void __stdcall DnsFree_dll(PVOID, DWORD);
    void __stdcall DnsFree(PVOID pData, DWORD FreeType) {
        return DnsFree_dll(pData, FreeType);
    }

    __declspec(dllimport) PCWSTR FAR PASCAL InetNtopW_dll(INT, const VOID *, PWSTR, size_t);
    PCWSTR FAR PASCAL InetNtopW(INT Family, const VOID * pAddr, PWSTR pStringBuf, size_t StringBufSize) {
        return InetNtopW_dll(Family, pAddr, pStringBuf, StringBufSize);
    }

    __declspec(dllimport) DWORD __stdcall DnsQuery_W_dll(PCWSTR, WORD, DWORD, PVOID, PVOID*, PVOID*);
    DWORD __stdcall DnsQuery_W(PCWSTR pszName, WORD wType, DWORD Options, PVOID pExtra, PVOID* ppQueryResults, PVOID* pReserved) {
        return DnsQuery_W_dll(pszName, wType, Options, pExtra, ppQueryResults, pReserved);
    }
}
