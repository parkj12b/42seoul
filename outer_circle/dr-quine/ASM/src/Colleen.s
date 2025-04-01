section .data
    fmt db "section .data%1$c    fmt db %2$c%3$s%2$c, 0%1$c%1$csection .text%1$cglobal main%1$cextern printf%1$c; comment outside main%1$cmain:%1$c    mov rdi, fmt ;comment in main%1$c    mov rsi, 10%1$c    mov rdx, 34%1$c    mov rcx, fmt%1$c    xor rax, rax%1$c    call printf wrt ..plt%1$c    xor rax, rax%1$c    ret", 0

section .text
global main
extern printf
; comment outside main
main:
    mov rdi, fmt ;comment in main
    mov rsi, 10
    mov rdx, 34
    mov rcx, fmt
    xor rax, rax
    call printf wrt ..plt
    xor rax, rax
    ret