section .text
extern _ft_create_elem

global _ft_list_push_front
_ft_list_push_front:
    push    rbp             ; Save rbp (callee-saved)
    mov     rbp, rsp        ; Set up stack frame
    push    rbx             ; Save rbx (callee-saved)

    mov     rbx, rdi        ; Save t_list **begin_list (rdi) in rbx
    mov     rdi, rsi        ; Pass void *data (rsi) to _ft_create_elem

    push    rdi
    push    rsi

    sub     rsp, 8          ; Align stack (16-byte boundary with return address)
    call    _ft_create_elem ; Create new node, returns in rax
    add     rsp, 8          ; Restore stack

    pop rsi
    pop rdi
    test    rax, rax        ; Check if creation failed
    jz      .done

    mov     rsi, [rbx]      ; Get current head (*begin_list)
    mov     [rax + 8], rsi  ; new_node->next = current head
    mov     [rbx], rax      ; *begin_list = new_node

.done:
    pop     rbx             ; Restore rbx
    mov     rsp, rbp        ; Restore stack pointer
    pop     rbp             ; Restore rbp
    ret