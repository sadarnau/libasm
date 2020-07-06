section	.text
global	_ft_write
extern	___error

;rdi first arg (fd), rsi second arg (*buf) and rdx third arg (nbytes)

_ft_write:
	mov	rax, 0x2000004				;write= 4 and MacOX = 0x2000000 ?
	syscall					;system call
	jc erreur				;if CF (carry flag), then error
	ret

erreur:
	mov	rdi, rax
	call ___error
	mov [rax], rdi
	mov rax, -1
	ret