section	.text
global	_ft_strcmp

_ft_strcmp:
	mov	rdx, 0					;initialize rdx to 0
	mov	rcx, 0
	mov	r8, 0

comp:
	cmp byte [rdi + rdx], 0		;compare s1[i] to '\0'
	jz	end
	cmp	byte [rsi + rdx], 0
	jz	end
	mov	cl,	byte [rdi + rdx]	;put s1[i] in rcx low
	mov	r8b, byte [rsi + rdx]	;put s2[i] in r8 low
	cmp	rcx, r8					;compare rcx and r8
	jnz	end						;if == 0 go to end
	inc	rdx						;else increment rdx (i++);
	jmp	comp;					;loop

end:
	mov	cl,	byte [rdi + rdx]	;put s1[i] in rcx
	mov	r8b, byte [rsi + rdx]	;put s2[i] in r8
	sub	rcx, r8					;substract s1[i] to s2[i] and put the result in rcx
	cmp	rcx, 0
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
