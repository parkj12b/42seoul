section .text
global _ft_list_sort
extern _ft_list_size

; void ft_list_sort(t_list **begin_list, int (*cmp)())
_ft_list_sort:
    push    rbp
    mov     rbp, rsp
    sub     rsp, 16                 ; Space for local variables
    push    rbx
    push    r12
    push    r13
    push    r14
    push    r15

    ; Save arguments
    mov     r12, rdi                ; r12 = begin_list (t_list **)
    mov     r13, rsi                ; r13 = cmp function pointer

    ; Check if list is empty or has one node
    mov     rdi, [r12]              ; rdi = *begin_list
    test    rdi, rdi                ; If list is empty, exit
    jz      .done
    call    _ft_list_size           ; rax = list size
    cmp     rax, 1                  ; If size <= 1, no sorting needed
    jle     .done

    ; Outer loop: number of passes = size - 1
    dec     rax                     ; rax = size - 1
    mov     [rbp - 8], rax          ; Store passes in [rbp - 8]
    xor     rax, rax
    mov     [rbp - 16], rax

.outer_loop:
    cmp     qword [rbp - 8], 0      ; If passes <= 0, sorting is done
    jle     .done

    ; Initialize pointers for inner loop
    mov     r14, r12                ; r14 = prev = &begin_list
    mov     r15, [r12]              ; r15 = cur = *begin_list
    mov     rbx, [r15 + 8]          ; rbx = next = cur->next

    ; Inner loop: traverse and swap adjacent nodes
.inner_loop:
    test    rbx, rbx                ; If next is null, end inner loop
    jz      .inner_done

    ; Compare cur->data and next->data
    mov     rdi, [r15]              ; rdi = cur->data
    mov     rsi, [rbx]              ; rsi = next->data
    call    r13                     ; Call cmp function
    test    eax, eax                ; If cmp <= 0, no swap needed
    jle     .no_swap

    ; Swap nodes: check if cur is the head
    cmp     r15, [r12]              ; Is cur the head?
    je      .swap_head

    ; Normal swap (not head)
    mov     rax, [rbx + 8]          ; rax = next->next
    mov     [r15 + 8], rax          ; cur->next = next->next
    mov     [r14 + 8], rbx          ; prev->next = next
    mov     [rbx + 8], r15          ; next->next = cur

    ; Update pointers after swap
    mov     r14, rbx                ; prev = next
    mov     r15, rbx                ; cur = next
    mov     rbx, [r15 + 8]          ; next = cur->next
    jmp     .inner_loop

.swap_head:
    mov     rax, [rbx + 8]          ; rax = next->next
    mov     [r15 + 8], rax          ; cur->next = next->next
    mov     [r12], rbx              ; *begin_list = next
    mov     [rbx + 8], r15          ; next->next = cur

    ; Update pointers after head swap
    mov     r14, rbx                ; prev = next (head)
    mov     rbx, [r15 + 8]          ; next = cur->next
    jmp     .inner_loop

.no_swap:
    ; Advance pointers without swapping
    mov     r14, r15                ; prev = cur
    mov     r15, rbx                ; cur = next
    mov     rbx, [r15 + 8]          ; next = next->next
    jmp     .inner_loop

.inner_done:
    dec     qword [rbp - 8]         ; Decrement passes
    jmp     .outer_loop

.done:
    pop     r15
    pop     r14
    pop    r13
    pop     r12
    pop     rbx
    leave
    ret