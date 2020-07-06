section	.text
global	_ft_strdup
extern	_malloc
extern	_ft_strlen
extern	_ft_strcpy

_ft_strdup:					;rdi = str
	cmp		rdi, 0			;check if == NULL
	jz		error			;go to error
	call	_ft_strlen		;rax = len(str)
	push	rdi				;save rdi
	inc		rax				;rax = len + 1 for '\0'
	mov		rdi, rax		;put rax in rdi to call malloc
	call 	_malloc			;malloc(rax)
	cmp		rax, 0			;check the malloc
	jz		error
	pop		rdi				;take back rdi from stack
	mov		rsi, rdi		;put rdi in rsi (src)
	mov		rdi, rax		;put the allocate memory create by malloc in rdi (dst)
	call	_ft_strcpy		;call strcpy
	cmp		rax, 0			;check if strcpy went wrong
	jz		error
	ret

error:
	mov	rax, 0
	ret