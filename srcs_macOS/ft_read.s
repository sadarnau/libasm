section	.text
global	_ft_read
extern	___error

;rdi first arg (fd), rsi second arg (*buf) and rdx third arg (nbytes)

_ft_read:
	mov rax, 0x2000003			;read = 3 and MacOX = 0x2000000 ?
	syscall
	jc erreur
	ret

erreur:
	mov	rdi, rax
	call ___error
	mov [rax], rdi
	mov	rax, -1
	ret