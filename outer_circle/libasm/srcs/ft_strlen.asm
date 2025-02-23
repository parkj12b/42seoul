section .text			; start of text section (or code section)
	global ft_strlen	; declare label ft_strlen global so it can be accessed from anywhere

ft_strlen:				; start of ft_strlen function
	xor rax, rax 		; Clear RAX, use for counting length
.loop:					; loop start
	cmp byte [rdi + rax], 0	; compare byte at [rdi + rax] == *(str + i)
	je .done				; jump if current equals null
	inc rax					; increase value in rax
	jmp .loop				; jump to start of loop
.done:
	ret
