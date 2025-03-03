section .text
global _ft_atoi_base
extern _ft_isspace

_ft_atoi_base:
    push rbp            ; Save from pointer
    mov rbp, rsp        ; Set up stack frame
    sub rsp, 128        ; Allocate 128 bytes for symbol table (on stack)

    push r14
    push r12
    push r13

    mov r12, rsi        ; save rsi  (base)
    mov r13, rdi        ; save rdi  (str)

    ;Initialize table with -1 (0xFF)
    lea rdi, [rbp - 128]
    mov rcx, 128
    mov al, 0xFF
    rep stosb

    xor r14, r14        ; r14 = index in base

.check_base:
    movzx rax, byte [r12 + r14]     ; Load base char
    test rax, rax                   ; End of base check
    jz .base_done

    cmp rax, '+'                    ; disallow +/-
    je .error
    cmp rax, '-'
    je .error

    mov rdi, rax                    ; mov char into rdi (1st arg)
    push rax
    call _ft_isspace                ; disallow isspace
    cmp rax, 1
    je .error

    pop rax
    lea rdx, [rbp - 128]            ; Table base
    cmp byte [rdx + rax], 0xFF      ; if the base char has occured already
    jne .error

    mov [rdx + rax], r14b           ; table[char] = position (r14 as 8-bit)
    inc r14                         ; Next position
    jmp .check_base

.base_done:
    test r14, r14                   ; Test base empty
    jz .error                        
    cmp r14, 1                      ; Test base length = 1
    je .error
    mov r9, r14                     ; r9 = base length

    ; Parse str
    xor rax, rax                    ; Result = 0
    mov r10, 1                      ; Sign = 1 

    lea rdx, [rbp - 128]            ; rdx = symbol table pointer


.skip_whitespace:           ; rdi = str, rsi = base
    mov rdi, r13            ; restore str
    mov r12, rdi

.isspace_loop:
    movzx rdi, byte [r12]
    test rdi, rdi
    jz .done
    call _ft_isspace
    test rax, rax
    jz .check_signs
    inc r12
    jmp .isspace_loop

.check_signs:
    cmp rdi, '-'
    je .set_negative
    cmp rdi, '+'
    jne .digit_start
    inc r12
    movzx rdi, byte [r12]
    jmp .check_signs
    
.set_negative:
    inc r10
    inc r12
    movzx rdi, byte [r12]
    jmp .check_signs

.digit_start:
.digit_loop:

    test rdi, rdi
    jz .apply_sign

    movzx r13, byte [rdx + rdi] ; r13 = table[char]
    cmp r13, 0xFF               ; Invalid digit, (-1)
    je .done

    cmp r13, r9                 ; exceeds base length?
    jge .done

    imul rax, r9
    add rax, r13
    inc r12
    movzx rdi, byte[r12]
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
    pop r13
    pop r12
    pop r14
    leave
    ret