section	.text
global	ft_strlen

;rax = return value

ft_strlen:
	mov	rax, 0						;put 0 in rax(the return)
	jmp	comp						;jump to comparaison

incr:
	inc rax							;increment rax

comp:
	cmp byte [rdi + rax], 0			;compare str[rax] to '\0'
	jne	incr						;if not equql jump to incr
	ret								;return ret