#include <Windows.h>

// Sorry

extern "C" {
   void _invalid_parameter_noinfo_noreturn() {
        DebugBreak();
        ExitProcess(1337);
    }
    void __cdecl _invoke_watson(
        _In_opt_z_ wchar_t const* _Expression,
        _In_opt_z_ wchar_t const* _FunctionName,
        _In_opt_z_ wchar_t const* _FileName,
        _In_       unsigned int _LineNo,
        _In_       uintptr_t _Reserved) {
        DebugBreak();
        ExitProcess(1337);
    }
}

void* __cdecl operator new(unsigned int size) {
    return malloc(size); // Exceptions are overrated anyway
}

void __cdecl operator delete(void* addr) noexcept {
    free(addr);
}

void __cdecl operator delete(void* addr, unsigned int size) {
    free(addr);
}

namespace stdext {
    class exception;
}

namespace std {
    void __cdecl _Xlength_error(char const *) {
        DebugBreak();
    }
    void (__cdecl* _Raise_handler)(class stdext::exception const &);
}