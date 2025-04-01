%macro one 0
extern fopen
extern fprintf
extern fclose
global main
%endmacro
%macro two 0
section .data
fmt db "%3$cmacro one 0%1$cextern fopen%1$cextern fprintf%1$cextern fclose%1$cglobal main%1$c%3$cendmacro%1$c%3$cmacro two 0%1$csection .data%1$cfmt db %2$c%4$s%2$c, 0%1$cfilename db %2$cGrace_kid.s%2$c, 0%1$cmode db %2$cw+%2$c, 0%1$c%3$cendmacro%1$c%3$cmacro three 0%1$cone%1$ctwo%1$csection .text%1$cmain:%1$cpush rbx%1$cmov rdi, filename%1$cmov rsi, mode%1$ccall fopen wrt ..plt%1$cmov rbx, rax%1$cmov rdi, rax%1$cmov rsi, fmt%1$cmov rdx, 10%1$cmov rcx, 34%1$cmov r8, 37%1$cmov r9, fmt%1$ccall fprintf wrt ..plt%1$cmov rdi, rbx%1$ccall fclose wrt ..plt%1$cpop rbx%1$cxor rax, rax%1$cret%1$c%3$cendmacro%1$cthree", 0
filename db "Grace_kid.s", 0
mode db "w+", 0
%endmacro
%macro three 0
one
two
section .text
main:
push rbx
mov rdi, filename
mov rsi, mode
call fopen wrt ..plt
mov rbx, rax
mov rdi, rax
mov rsi, fmt
mov rdx, 10
mov rcx, 34
mov r8, 37
mov r9, fmt
call fprintf wrt ..plt
mov rdi, rbx
call fclose wrt ..plt
pop rbx
xor rax, rax
ret
%endmacro
three