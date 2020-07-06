section	.text
global	ft_read
extern	__errno_location

;rdi first arg (fd), rsi second arg (*buf) and rdx third arg (nbytes)

ft_read:
	mov rax, 0			;read = 3 and MacOX = 0x2000000 ?
	syscall
	cmp	rax, 0
	jl erreur
	ret

erreur:
	neg	rax
	mov	rdi, rax
	call __errno_location wrt ..plt
	mov [rax], rdi
	mov	rax, -1
	ret