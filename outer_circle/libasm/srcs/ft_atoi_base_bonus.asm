section .text
global _ft_atoi_base
extern _ft_isspace

_ft_atoi_base:
    push rbp            ; Save from pointer
    mov rbp, rsp        ; Set up stack frame
    sub rsp, 128        ; Allocate 128 bytes for symbol table (on stack)

    mov r8, rsi         ; save rsi
    mov r11, rdi        ; save rdi

    ;Initialize table with -1 (0xFF)
    lea rdi, [rbp - 128]
    mov rcx, 128
    mov al, 0xFF
    rep stosb

    xor rcx, rcx        ; rcx = index in base

.check_base:
    movzx rax, byte [r8 + rcx]      ; Load base char
    test rax, rax                   ; End of base check
    jz .base_done
    cmp rax, '+'                    ; disallow +/-
    je .error
    cmp rax, '-'
    je .error
    mov rdi, rax
    push rax
    call _ft_isspace                ; disallow isspace
    cmp rax, 1
    je .error
    pop rax
    lea rdx, [rbp - 128]            ; Table base
    cmp byte [rdx + rax], 0xFF
    jne .error
    mov [rdx + rax], cl             ; table[char] = position (rcx as 8-bit)
    inc rcx                         ; Next position
    jmp .check_base

.base_done:
    test rcx, rcx                   ; Test base empty
    jz .error                        
    cmp rcx, 1                      ; Test base length = 1
    je .error
    mov r9, rcx                     ; r9 = base length

    ; Parse str
    xor rax, rax                    ; Result = 0
    mov r10, 1                      ; Sign = 1 
    lea rdx, [rbp - 128]            ; rdx = symbol table pointer

.skip_whitespace:           ; rdi = str, rsi = base
    mov rdi, r11            ; restore str
    mov r8, rdi

.isspace_loop:
    ; int3
    movzx rdi, byte [r8]
    test rdi, rdi
    jz .done
    call _ft_isspace
    test rax, rax
    jz .check_signs
    inc r8
    jmp .isspace_loop

.check_signs:
    cmp rdi, '-'
    je .set_negative
    cmp rdi, '+'
    jne .digit_start
    inc r8
    movzx rdi, byte [r8]
    jmp .check_signs
    
.set_negative:
    inc r10
    inc r8
    movzx rdi, byte [r8]
    jmp .check_signs

.digit_start:
.digit_loop:
    test rdi, rdi
    jz .apply_sign
    movzx r11, byte [rdx + rdi] ; r11 = table[char]
    cmp r11, 0xFF               ; Invalid digit, (-1)
    je .done
    cmp r11, r9                 ; exceeds base length?
    jge .done
    imul rax, r9
    add rax, r11
    inc r8
    movzx rdi, byte[r8]
    jmp .digit_loop

.error:
    mov rax, 0
    leave
    ret

.apply_sign:
    test r10, 1
    je .negate
    jmp .done
.negate:
    neg rax

.done:
    leave
    ret