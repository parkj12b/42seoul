section .text
global _ft_list_size
_ft_list_size:
    xor rax, rax            ; rdi = t_list *begin_list
.loop:
    test rdi, rdi
    jz  .done
    inc rax                 ; increase counter
    mov rdi, [rdi + 8]      ; begin_list = begin_list->next;
    jmp .loop

.done:
    ret