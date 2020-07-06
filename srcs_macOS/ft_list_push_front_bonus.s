section	.text
global	_ft_list_push_front
extern	_malloc
;void	ft_list_push_front(t_list **begin, void *data);

_ft_list_push_front:
	cmp	rdi, 0				;check if *begin == NULL
	jz	end					; if NULL
	push rdi				;save rdi...
	push rsi				;and rsi before malloc call
	mov rdi, 16				;malloc of 16, size of t_list
	call _malloc
	cmp rax, 0				;checking if malloc failed
	jz end					;if NULL go to end
	pop rsi					;and rsi back from the stack
	pop rdi					;tacking rdi..
	mov [rax], rsi			;puttind data in new* (rax from malloc)
	mov	rdx, [rdi]			;*begin -> rdx
	mov	[rax + 8], rdx		;new->next = lst
	mov [rdi], rax			;*begin = new;

end:
	ret