section .text
%ifdef OS_LINUX
    global ft_strlen
    ft_strlen:
%else
    global _ft_strlen
    _ft_strlen:
%endif
    mov rax, rdi    ; macOS: rdi = string pointer
    xor rcx, rcx    ; counter
.loop:
    cmp byte [rax + rcx], 0
    je .done
    inc rcx
    jmp .loop
.done:
    mov rax, rcx    ; return length
    ret