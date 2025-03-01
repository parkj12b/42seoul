section .text
extern _malloc

global _ft_create_elem

_ft_create_elem:
    mov r12, rdi        ; rdi = void *data
    mov rdi, 16         ; sizeof(t_list)
    call _malloc

    ;check malloc fail
    test rax, rax
    jz  .done

    mov [rax], r12
    mov qword [rax + 8], 0

.done:
    ret