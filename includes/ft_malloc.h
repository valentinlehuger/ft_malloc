/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 18:08:28 by vlehuger          #+#    #+#             */
/*   Updated: 2015/01/22 18:08:31 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <libft.h>

typedef struct		s_reg
{
	t_list			*addr;
	struct s_reg	*next;
}					t_reg;

# define TINY 40
# define SMALL 409
# define LARGE 410

void		free(void *ptr);
void		*malloc(size_t size);
void		*realloc(void *ptr, size_t size);

void		show_alloc_mem(void);

#endif
