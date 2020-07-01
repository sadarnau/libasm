section	.text
global	ft_read

;rdi first arg (fd), rsi second arg (*buf) and rdx third arg (nbytes)

ft_read:
	mov rax, 0			;read = 3 and MacOX = 0x2000000 ?
	syscall
	jc	error
	ret

error:
	mov	rax, -1
	ret