section	.text
global	ft_strcpy

;rdi first arg (dest) and rsi second arg (src)

ft_strcpy:
	mov	rdx, 0					;i = 0;
	mov	rcx, 0					;tmp buffer
	cmp	rsi, 0					;check src[0] == 0 ?
	jnz	copy					;if not 0, copy
	jmp	end						;else end

incr:
	inc	rdx						;increment i

copy:
	mov	cl, byte [rsi + rdx]	;put src[i] in rcx (tmp)
	mov	byte [rdi + rdx], cl	;put rcx (cl) in dest[i]
	cmp	cl, 0					;check id rcx == \0
	jz	end						;if yes, end
	jmp	incr					;if no, increment

end:
	mov rax, rdi				;put rdi (dest) in ret
	ret							;return