section	.text
global	_ft_strcmp

_ft_strcmp:
	mov	rdx, 0					;initialize rdx to 0

comp:
	cmp byte [rdi + rdx], 0		;compare s1[i] to '\0'
	jz	end
	cmp	byte [rsi + rdx], 0
	jz	end
	mov	cl, byte [rdi + rdx]	;put s1[i] in rcx
	sub	cl, byte [rsi + rdx]	;substract s1[i] to s2[i] and put the result in rcx
	cmp	cl, 0					;compare the result to 0
	jnz	end						;if == 0 go to end
	inc	rdx						;else increment rdx (i++);
	jmp	comp;					;loop

end:
	mov	cl, byte [rdi + rdx]
	sub	cl, byte [rsi + rdx]
	cmp	cl, 0
	jz	null
	jg	greater					;jg = jmp if greater
	jmp	smaller

null:
	mov	rax, 0					;return 0 or..
	ret

greater:
	mov	rax, 1					;return 1 or..
	ret

smaller:
	mov	rax, -1					;return -1.... :P
	ret
