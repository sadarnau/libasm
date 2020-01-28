section	.text
global	_ft_write

; rdi first arg (fd), rsi second arg (*buf) and rdx third arg (nbytes)

_ft_write:
	cmp	byte [rsi], 0
	jz	error
	mov	rax, 0x2000004
	syscall
	cmp	rax, 9
	jz	error
	ret

error:
	mov rax, -1
	ret