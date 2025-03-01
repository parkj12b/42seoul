section .text
extern _ft_create_elem

global _ft_list_push_front
_ft_list_push_front:
    push    rdi             ; Save rdi (t_list **begin_list)
    mov     rdi, rsi        ; Pass rsi (void *data)
    sub     rsp, 8          ; Align stack
    call    _ft_create_elem

    add     rsp, 8
    test    rax, rax
    jz      .error
    pop     rsi             ; Restore t_list **begin_list into rsi

    mov     rdi, [rsi]      ; Get current head
    mov     [rax + 8], rdi
    mov     [rsi], rax      ; Update head

    ret

.error:
    add     rsp, 8          ; Balance stack
    ret