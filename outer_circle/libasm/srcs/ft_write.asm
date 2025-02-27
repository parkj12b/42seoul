section .text
extern __errno_location
%ifdef OS_LINUX
    global ft_write
    ft_write:
        mov rax, 1
%else
    global _ft_write
    _ft_write:
        mov rax, 0x2000004  ; rdi = fd, rsi = buf, rdx = count
%endif
    syscall

    cmp rax, 0
    jl .error
    jmp .done

.error:
    neg rax
    mov r8, rax
    call __errno_location
    mov [rax], r8

    mov rax, -1 ; return -1 on error

.done:
    ret
