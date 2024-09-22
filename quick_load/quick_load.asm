bits 32

dummy:

start:
    push    ebx
    mov     ebx, dword [esp + 8]

loop:
    push    ebx
    call    dummy
    cmp     dword [ebx + 0x128], 0
    jne     loop

    pop     ebx
    ret     4