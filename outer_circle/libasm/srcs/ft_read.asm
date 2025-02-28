section .text
%ifdef OS_LINUX
    extern __errno_location
    global ft_read
    ft_read:
        mov rax, 0
    syscall
    cmp rax, 0
    jl .error
    jmp .done
%else
    extern ___error
    global _ft_read
    _ft_read:
        mov rax, 0x2000003  ; rdi = fd, rsi = buf, rdx = count
    syscall
    jc .error
    jmp .done
%endif

.error:
    sub rsp, 8
    mov r8, rax
    %ifdef OS_LINUX
        neg r8
        call __errno_location wrt ..plt
    %else
        call ___error
    %endif
    mov [rax], r8d
    add rsp, 8
    mov rax, -1 ; return -1 on error

.done:
    ret