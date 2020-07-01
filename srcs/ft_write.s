section	.text
global	ft_write

;rdi first arg (fd), rsi second arg (*buf) and rdx third arg (nbytes)

ft_write:
	mov	rax, 1		;write= 4 and MacOX = 0x2000000 ?
	syscall					;system call
	jc error				;if CF (carry flag), then error
	ret

error:
	mov rax, -1
	ret