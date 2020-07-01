/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:13:52 by sadarnau          #+#    #+#             */
/*   Updated: 2020/02/21 18:44:06 by sadarnau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <stdlib.h>
# include <stddef.h>

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

extern void				ft_list_push_front(t_list **begin, void *data);
extern int					ft_list_size(t_list *begin_list);
extern size_t				ft_strlen(const char *s);
extern char				*ft_strcpy(char *dst, const char *src);
extern int					ft_strcmp(const char *s1, const char *s2);
extern size_t				ft_write(int fildes, const void *buf, size_t nbyte);
extern size_t				ft_read(int fildes, void *buf, size_t nbyte);
extern char				*ft_strdup(const char *s1);

#endif
