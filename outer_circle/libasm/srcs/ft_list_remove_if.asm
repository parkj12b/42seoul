section .text
global _ft_list_remove_if
extern _free
_ft_list_remove_if:
; void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
;   void (*free_fc)(void *))
    push    rbp
    mov     rbp, rsp
    sub     rsp, 16
    push    rbx
    push    r12
    push    r13
    push    r14
    push    r15


    mov     [rbp - 8], rdi      ; begin_list
    mov     r13, rsi            ; data_ref
    mov     r14, rdx            ; cmp function
    mov     r15, rcx            ; free function

    mov     rbx, rdi            ; rbx = prev

; first iteration as exception
; compare data
.begin_list:
    ; test cur = NULL
    mov     rdi, [rbx]          ; rax = *begin_list
    test    rdi, rdi
    jz      .done

    ; perform comparison
    mov     rdi, [rdi]          
    mov     rsi, r13
    call    r14
    jnz    .first_loop                ; jump out of begin_list if not eql

    ; free data
    mov     rdi, [rbx]
    mov     rdi, [rdi]
    call    r15

    ; free t_list *
    mov     rdi, [rbx]          ; store first elem
    push    qword [rdi + 8]         ; store next in stack
    call    _free

    ; connect prev and next
    pop     rax
    mov     [rbx], rax
    jmp     .begin_list

.first_loop:
    mov     rbx, [rbx]          ; make first elem prev

.loop:
    mov     rax, [rbx + 8]      ; store cur in rax
    
    ; test if cur is null
    test    rax, rax
    jz      .done

    ; test data equality
    mov     rdi, [rax]
    mov     rsi, r13
    call    r14
    jnz     .move_pointer

    mov     rax, [rbx + 8]      ; set current back in rax
    mov     rdi, [rax]
    call    r15

    mov     rdi, [rbx + 8]      ; store current t_list in rdi
    push    qword [rdi + 8]           ; store next in stack
    call    _free

    ; connect prev and next
    pop     rax
    mov     [rbx + 8], rax
    jmp     .loop

.move_pointer:
    mov     rbx, [rbx + 8]
    jmp     .loop

.done:
    mov     rdi, [rbp - 8]
    pop     r15
    pop     r14
    pop     r13
    pop     r12
    pop     rbx
    leave
    ret