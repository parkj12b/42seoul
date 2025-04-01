section .data
fmt db "section .data%1$cfmt db %2$c%3$s%2$c, 0%1$cfilename db %2$cSully_%%d.s%2$c, 0%1$cmode db %2$cw+%2$c, 0%1$cexename db %2$c./Sully_%%d%2$c, 0%1$ccommand_format db %2$cnasm -f elf64 %%s%2$c, 0%1$cgnu_format db %2$cgcc -z noexecstack -lc Sully_%%1$d.o -o Sully_%%1$d%2$c, 0%1$csection .bss%1$cdata resb 100%1$cfilename_buf resb 100%1$cextern fopen%1$cextern fprintf%1$cextern fclose%1$cextern snprintf%1$cextern system%1$cglobal main%1$csection .text%1$cmain:%1$cpush rbp%1$cmov rbp, rsp%1$csub rsp, 8%1$cpush rbx%1$cpush r12%1$cpush r13%1$cpush r14%1$cpush r15%1$cmov rbx, %4$d%1$ccmp rbx, 0%1$cjle .end%1$cdec rbx%1$cmov rdi, filename_buf%1$cmov rsi, 100%1$cmov rdx, filename%1$cmov rcx, rbx%1$ccall snprintf wrt ..plt%1$ctest rax, rax%1$cjs .end%1$cmov rdi, filename_buf%1$cmov rsi, mode%1$ccall fopen wrt ..plt%1$ctest rax, rax%1$cjs .end%1$cmov r12, rax%1$cmov rdi, rax%1$cmov rsi, fmt%1$cmov rdx, 10%1$cmov rcx, 34%1$cmov r8, fmt%1$cmov r9, rbx%1$ccall fprintf wrt ..plt%1$ctest rax, rax%1$cjs .end%1$cmov rdi, r12%1$ccall fclose wrt ..plt%1$ctest rax, rax%1$cjs .end%1$cmov rdi, data%1$cmov rsi, 100%1$cmov rdx, command_format%1$cmov rcx, filename_buf%1$ccall snprintf wrt ..plt%1$ctest rax, rax%1$cjs .end%1$cmov rdi, data%1$ccall system wrt ..plt%1$cmov rdi, data%1$cmov rsi, 100%1$cmov rdx, gnu_format%1$cmov rcx, rbx%1$ccall snprintf wrt ..plt%1$ctest rax, rax%1$cjs .end%1$cmov rdi, data%1$ccall system wrt ..plt%1$ctest rax, rax%1$cjs .end%1$cmov rdi, data%1$cmov rsi, 100%1$cmov rdx, exename%1$cmov rcx, rbx%1$ccall snprintf wrt ..plt%1$ctest rax, rax%1$cjs .end%1$cmov rdi, data%1$ccall system wrt ..plt%1$c.end:%1$cpop r15%1$cpop r14%1$cpop r13%1$cpop r12%1$cpop rbx%1$cleave%1$cret%1$c", 0
filename db "Sully_%d.s", 0
mode db "w+", 0
exename db "./Sully_%d", 0
command_format db "nasm -f elf64 %s", 0
gnu_format db "gcc -z noexecstack -lc Sully_%1$d.o -o Sully_%1$d", 0
section .bss
data resb 100
filename_buf resb 100
extern fopen
extern fprintf
extern fclose
extern snprintf
extern system
global main
section .text
main:
push rbp
mov rbp, rsp
sub rsp, 8
push rbx
push r12
push r13
push r14
push r15
mov rbx, 5
cmp rbx, 0
jle .end
dec rbx
mov rdi, filename_buf
mov rsi, 100
mov rdx, filename
mov rcx, rbx
call snprintf wrt ..plt
test rax, rax
js .end
mov rdi, filename_buf
mov rsi, mode
call fopen wrt ..plt
test rax, rax
js .end
mov r12, rax
mov rdi, rax
mov rsi, fmt
mov rdx, 10
mov rcx, 34
mov r8, fmt
mov r9, rbx
call fprintf wrt ..plt
test rax, rax
js .end
mov rdi, r12
call fclose wrt ..plt
test rax, rax
js .end
mov rdi, data
mov rsi, 100
mov rdx, command_format
mov rcx, filename_buf
call snprintf wrt ..plt
test rax, rax
js .end
mov rdi, data
call system wrt ..plt
mov rdi, data
mov rsi, 100
mov rdx, gnu_format
mov rcx, rbx
call snprintf wrt ..plt
test rax, rax
js .end
mov rdi, data
call system wrt ..plt
test rax, rax
js .end
mov rdi, data
mov rsi, 100
mov rdx, exename
mov rcx, rbx
call snprintf wrt ..plt
test rax, rax
js .end
mov rdi, data
call system wrt ..plt
.end:
pop r15
pop r14
pop r13
pop r12
pop rbx
leave
ret
