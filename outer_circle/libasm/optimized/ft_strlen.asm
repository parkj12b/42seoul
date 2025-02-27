%ifdef OS_LINUX
    global ft_strlen
    ft_strlen:
%else
    global _ft_strlen
    _ft_strlen:
%endif
    mov rax, rdi            ; String pointer to rax
    vpxor ymm0, ymm0, ymm0  ; Zero ymm0 for null comparison
    mov r8, rax             ; Save start for length calc

    ; Compute previous 32-byte aligned address
    mov r9, rax             ; Copy original pointer
    and r9, ~0x1F           ; Align down to 32-byte boundary (e.g., 0xFFFFFFE0)
    sub rax, r9             ; Offset from aligned start (0-31)

    ; Initial load from aligned address
    vmovdqu ymm1, [r9]      ; Load 32 bytes from aligned address
    vpcmpeqb ymm1, ymm1, ymm0 ; Compare with zero
    vpmovmskb ecx, ymm1     ; Get 32-bit mask

    ; Mask off bytes before the string start
    mov edx, 0xFFFFFFFF     ; Full 32-bit mask
    mov cl, al              ; Offset into cl for shift
    shl edx, cl             ; Shift left by offset (ignore bytes before start)
    and ecx, edx            ; Mask out bytes before string start
    mov rax, r9             ; for the initial address setup
    test ecx, ecx           ; Null in valid part?
    jnz .found_null         ; If yes, compute length

    ; Move to next 32-byte chunk
    add r9, 32              ; Next aligned chunk
    mov rax, r9             ; Update rax for loop

.loop:
    vmovdqu ymm1, [rax]     ; Load 32 bytes (aligned)
    vpcmpeqb ymm1, ymm1, ymm0 ; Compare with zero
    vpmovmskb ecx, ymm1     ; Get mask
    test ecx, ecx           ; Null found?
    jnz .found_null         ; If yes, compute length
    add rax, 32             ; Next aligned chunk
    jmp .loop

.found_null:
    bsf ecx, ecx            ; Index of first null in mask
    sub rax, r8             ; Current pos - start
    add rax, rcx            ; Add null offset
    vzeroupper              ; Clean up AVX state
    ret