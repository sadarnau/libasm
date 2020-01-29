section	.text
global	_ft_read

;rdi first arg (fd), rsi second arg (*buf) and rdx third arg (nbytes)

_ft_read:
	mov rax, 0x2000003			;read = 3 and MacOX = 0x2000000 ?
	syscall
	jc	error
	ret

error:
	mov	rax, -1
	ret