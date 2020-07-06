section	.text
global	ft_strdup
extern	malloc
extern	ft_strlen
extern	ft_strcpy

ft_strdup:					;rdi = str
	cmp		rdi, 0			;check if == NULL
	jz		error			;go to error
	call	ft_strlen		;rax = len(str)
	push	rdi				;save rdi
	inc		rax				;rax = len + 1 for '\0'
	mov		rdi, rax		;put rax in rdi to call malloc
	call malloc wrt ..plt	;malloc(rax)
	cmp		rax, 0			;check the malloc
	jz		error
	pop		rdi				;take back rdi from stack
	mov		rsi, rdi		;put rdi in rsi (src)
	mov		rdi, rax		;put the allocate memory create by malloc in rdi (dst)
	call	ft_strcpy		;call strcpy
	cmp		rax, 0			;check if strcpy went wrong
	jz		error
	ret

error:
	mov	rax, 0
	ret