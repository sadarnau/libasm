section	.text
global	_ft_write

; rdi first arg (fd), rsi second arg (*buf) and rdx third arg (nbytes)

_ft_write:
	mov	rax, 0x2000004
	syscall
	jc error
	ret

error:
	mov rax, -1
	ret