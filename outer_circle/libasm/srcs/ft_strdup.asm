section .text
extern _ft_strlen
extern _malloc

global _ft_strdup
_ft_strdup:
    test rdi, rdi
    jz .error
    push rbx                    ; Save rbx (callee-saved)
    mov rbx, rdi                ; Save str in rbx
    call _ft_strlen
    mov rdi, rax
    inc rdi
    call _malloc
    mov rdi, rbx                ; Restore str
    pop rbx                     ; Restore rbx

    test rax, rax
    jz .error
    mov r8, rax

.loop:
    mov cl, [rdi]
    mov [r8], cl
    cmp byte [rdi], 0
    je .done
    inc rdi
    inc r8
    jmp .loop

.error:
    xor rax, rax
    ret

.done:
    ret