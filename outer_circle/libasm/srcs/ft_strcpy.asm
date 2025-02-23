section .text
	global ft_strcpy

ft_strcpy:
	; arguments:
	; rdi = dest
	; rsi = src

	mov rax, rdi

.loop:
	mov al, byte [rsi]	;
	mov byte [rdi], al	;
	inc rsi
	inc rdi
	test al, al
	jnz .loop

	ret