section .text
%ifdef OS_LINUX
    global ft_strcpy
    ft_strcpy:
%else
    global _ft_strcpy
    _ft_strcpy:
%endif
    mov rax, rdi    ; macOS: rdi = dest, rsi = src
    xor rcx, rcx    ; counter
.loop:
    mov dl, [rsi + rcx]
    mov [rdi + rcx], dl
    cmp dl, 0
    je .done
    inc rcx
    jmp .loop
.done:
    ret