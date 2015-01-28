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

# include <stdio.h>
# include <stdlib.h>
# include <sys/mman.h>

# define TINYSIZE 40
# define SMALLSIZE 409
# define TINYMAX 4096
# define SMALLMAX 40960

enum Type
{
	TINY = 1,
	SMALL,
	LARGE
};

void		free(void *ptr);
void		*malloc(size_t size);
void		*realloc(void *ptr, size_t size);
void		*book_it(size_t size);
int			get_max_type_size(size_t size);
int			get_size(size_t size);
char		get_type(size_t size);
void		*get_page(size_t size, int init);
void		*get_malloc(char init);

void		show_alloc_mem(void);

void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t len);
void		*ft_memset(void *b, int c, size_t len);
void		ft_putaddress(void *ptr);
int			ft_putchar(char c);
void		ft_putstr(char const *str);
void		ft_putnbr(int nb);

/*
  0   1   2   3   4   5   6   7   8   9   10  11  12 
| A | B | B | B | B | C | C | C | C | C | C | C | C |

A = type
B = size
C = pointer on next
*/

#endif
