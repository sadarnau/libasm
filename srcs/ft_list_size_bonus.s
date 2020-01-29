section	.text
global	_ft_list_size

_ft_list_size:
	mov	rax, 0				;i = 0
	cmp	rdi, 0				;check *lst == NULL
	jz	end					; if NULL
	mov	rdi, [rdi + 8]		;lst = lst->next
	inc rax					;i++
	jmp	comp

incr:
	inc	rax					;i++

comp:
	cmp	rdi, 0
	jz	end
	mov	rdi, [rdi + 8]
	jmp	incr

end:
	ret