section .text
global _ft_isspace
_ft_isspace:
    cmp dil, 0x20
    je .is_whitespace

    cmp dil, 0x09
    jl .not_whitespace
    cmp dil, 0x0D
    jg .not_whitespace
    jmp .is_whitespace

.not_whitespace:
    xor rax, rax
    ret

.is_whitespace:
    mov rax, 1
    ret
