section .data
	fmt db "%s", 10, 0
	msg db "Hello, Holberton", 0

section .text
	extern printf
	global main

main:
	push rbp
	mov rsi, msg
	mov rdi, fmt
	call printf
	pop rbp

	xor rax, rax    ; Return value 0
	ret
