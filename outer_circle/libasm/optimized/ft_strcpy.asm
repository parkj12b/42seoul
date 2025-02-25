section .text
%ifdef WIN64
    global ft_strcpy
    ft_strcpy:
        mov rax, rcx    ; Windows: rcx = dest, rdx = src
        xor r8, r8      ; counter
    .loop:
        mov r9b, [rdx + r8]
        mov [rcx + r8], r9b
        cmp r9b, 0
        je .done
        inc r8
        jmp .loop
    .done:
        ret
%else
    global _ft_strcpy
    _ft_strcpy:
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
%endif