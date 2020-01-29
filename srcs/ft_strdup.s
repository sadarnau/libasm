section	.text
global	_ft_strdup
extern	_malloc
extern	_ft_strlen
extern	_ft_strcpy

_ft_strdup:
	cmp		rdi, 0
	jz		error
	call	_ft_strlen
	push	rdi
	inc		rax
	mov		rdi, rax
	call	_malloc
	cmp		rax, 0
	jz		error
	pop		rdi
	mov		rsi, rdi
	mov		rdi, rax
	call	_ft_strcpy
	cmp		rax, 0
	jz		error
	ret

error:
	mov	rax, 0
	ret