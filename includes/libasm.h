/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadarnau <sadarnau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:13:52 by sadarnau          #+#    #+#             */
/*   Updated: 2020/01/29 15:14:30 by sadarnau         ###   ########.fr       */
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

int					ft_list_size(t_list *begin_list);
size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *dst, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_write(int fildes, const void *buf, size_t nbyte);
size_t				ft_read(int fildes, void *buf, size_t nbyte);
char				*ft_strdup(const char *s1);

#endif
