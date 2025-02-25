section .text
%ifdef WIN64
    global ft_strlen
    ft_strlen:
        mov rax, rcx    ; Windows: rcx = string pointer
        xor rdx, rdx    ; counter
    .loop:
        cmp byte [rax + rdx], 0
        je .done
        inc rdx
        jmp .loop
    .done:
        mov rax, rdx    ; return length
        ret
%else
    global _ft_strlen
    _ft_strlen:
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
%endif