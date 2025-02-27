section .text
%ifdef OS_LINUX
    global ft_strcmp
    ft_strcmp:
%else
    global _ft_strcmp
    _ft_strcmp:
%endif
    xor rcx, rcx    ; rdi = s1, rsi = s2, rcx as counter for current pos
.loop:
    movzx r8, byte [rdi + rcx]    ; take a byte and move it to r8
    movzx r9, byte [rsi + rcx]    ; do the same for r9
    cmp r8b, r9b
    jnz .done
    cmp r8b, 0
    je .done
    inc rcx
    jmp .loop
.done:
    movzx rax, r8b
    movzx rcx, r9b
    sub rax, rcx
    ret
