section	.text
global	ft_write
extern	__errno_location

;rdi first arg (fd), rsi second arg (*buf) and rdx third arg (nbytes)

ft_write:
	mov	rax, 1				;write= 4 and MacOX = 0x2000000 ?
	syscall					;system call
	cmp	rax, 0
	jl erreur				;if CF (carry flag), then error
	ret

erreur:
	neg	rax
	mov	rdi, rax
	call __errno_location wrt ..plt
	mov [rax], rdi
	mov rax, -1
	ret