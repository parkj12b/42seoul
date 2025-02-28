section .text
global _ft_atoi_base
extern _ft_isspace

_ft_atoi_base:
    ; no need to sub because local subroutine check_isspace doesn't use stack
    mov rbx, rdi        ; save rdi
    mov rbp, rsi        ; save rsi
    call check_isspace  ; rdi = str, rsi = base
    xor rcx, rcx        ; using rcx as +- flag
    
    ret

check_isspace:
    mov r8, rdi
    jmp .isspace_loop

.isspace_loop:
    mov rdi, [r8]
    call _ft_isspace
    jz .done
    inc r8
    jmp .isspace_loop

.done:
    mov rax, r8
    ret