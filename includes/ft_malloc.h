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
# include <stdio.h>
# include <stdlib.h>
# include <sys/mman.h>

# define TINYSIZE 40
# define SMALLSIZE 409
# define TINYMAX 4096
# define SMALLMAX 40960

enum Type
{
	TINY = 0,
	SMALL,
	LARGE
};

void		ft_free(void *ptr);
void		*ft_malloc(size_t size);
void		*realloc(void *ptr, size_t size);
void		*book_into_page(char *mem, size_t size);
void		*book_it(size_t size);
int			get_max_type_size(size_t size);
int			get_size(size_t size);
char		get_type(size_t size);
void		*get_page(size_t size, int init);
void		*get_malloc(void);

void		show_alloc_mem(void);

#endif
