bits 32

dummy:

start:
    push    ebx
    push    edi
    mov     ebx, edi

loop:
    mov     edi, ebx
    call    dummy
    cmp     dword [ebx + 0x124], 0
    jne     loop

    pop     edi
    pop     ebx
    ret