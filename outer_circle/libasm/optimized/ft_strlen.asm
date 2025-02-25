%ifdef WIN64
    global ft_strlen
    ft_strlen:
        mov rax, rcx        ; Windows: string pointer in rcx
%else
    global _ft_strlen
    _ft_strlen:
        mov rax, rdi        ; macOS: string pointer in rdi
%endif
    vpxor ymm0, ymm0, ymm0  ; Zero out ymm0 for null comparison (AVX)
    mov r8, rax             ; Save original pointer

    ; Check alignment (32-byte boundary for YMM)
    test rax, 0x1F          ; Check if aligned to 32 bytes
    jz .aligned_start       ; If aligned, jump to aligned part

    ; Handle unaligned first part (up to 31 bytes)
    mov r9, rax             ; Save original start address
    vmovdqu ymm1, [rax]     ; Load 32 bytes from original start (unaligned)
    vpcmpeqb ymm1, ymm1, ymm0 ; Compare with 0 (AVX2)
    vpmovmskb ecx, ymm1     ; Get 32-bit mask
    test ecx, ecx           ; Any nulls?
    jnz .found_null         ; If yes, calculate length
    and rax, 0xFFFFFFE0     ; Align to 32-byte boundary
    add rax, 32             ; Move to next chunk
    jmp .aligned_loop

.aligned_start:
    ; If already aligned, no need to realign (test rax, 0x1F ensures this)
    ; and rax, 0xFFFFFFE0    ; (Commented out - unnecessary)

.aligned_loop:
.loop:
    vmovdqu ymm1, [rax]     ; Load 32 bytes (unaligned OK with vmovdqu)
    vpcmpeqb ymm1, ymm1, ymm0 ; Compare each byte with 0 (AVX2)
    vpmovmskb ecx, ymm1     ; Extract 32-bit mask
    test ecx, ecx           ; Any nulls?
    jnz .found_null         ; If yes, calculate position
    add rax, 32             ; Move to next 32-byte chunk
    jmp .loop

.found_null:
    bsf ecx, ecx            ; Find index of first null in mask (0-31)
    sub rax, r8             ; Current position - start
    add rax, rcx            ; Add offset of null within chunk
    vzeroupper              ; Clean up YMM state (good practice)
    ret