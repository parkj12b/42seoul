section .text

%ifdef WIN64
    global ft_strlen
    ft_strlen:
        mov rax, rcx        ; Windows: string pointer in rcx
%else
    global _ft_strlen
    _ft_strlen:
        mov rax, rdi        ; macOS: string pointer in rdi
%endif

    ; Save original pointer for length calculation
    mov r8, rax
    pxor xmm0, xmm0         ; xmm0 = all zeros (to detect nulls)

.loop:
    movdqu xmm1, [rax]      ; Load 16 bytes from string (unaligned)
    pcmpeqb xmm1, xmm0      ; Compare each byte with 0 (0xFF if null)
    pmovmskb ecx, xmm1      ; Extract 16-bit mask (1 bit per byte)
    test ecx, ecx           ; Any nulls in this chunk?
    jnz .found_null         ; If yes, calculate position
    add rax, 16             ; Move to next 16-byte chunk
    jmp .loop

.found_null:
    bsf ecx, ecx            ; Find index of first 1 in mask (null position)
    sub rax, r8             ; Current position - start = base length
    add rax, rcx            ; Add offset of null within chunk
    ret