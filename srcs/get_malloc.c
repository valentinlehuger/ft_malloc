/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_malloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 11:50:55 by vlehuger          #+#    #+#             */
/*   Updated: 2015/01/28 11:50:57 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>

#define FLAGS PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE

void				*get_malloc(char init)
{
	static void		*pages = NULL;

	if (init == 1)
		pages = NULL;
	if (!pages && init != 1)
		pages = get_page(TINYSIZE, 1);
	return (pages);
}

char				test_rlimit(size_t size)
{
	char			*mem;
	char			**ptr_mem;
	int				total;
	int				*int_mem;
	struct rlimit	rlp;

	total = 0;
	getrlimit(RLIMIT_STACK, &rlp);
	mem = get_malloc(0);
	while (mem != NULL)
	{
		ptr_mem = (char **)(mem + 5);
		int_mem = (int *)(mem + 1);
		total += *int_mem;
		mem = *ptr_mem;
	}
	if (total + get_max_type_size(size) <= (int)rlp.rlim_cur)
		return (0);
	return (1);
}

void				*get_page(size_t size, int init)
{
	char			*mem;
	int				*mem2;
	char			**mem3;

	if (init == 0 && test_rlimit(size) == 1)
		return (NULL);
	mem = (char *)mmap(0, get_max_type_size(size), FLAGS, -1, 0);
	ft_bzero(mem, get_max_type_size(size));
	mem[0] = get_type(size);
	mem2 = (int *)(mem + 1);
	mem2[0] = get_max_type_size(size);
	mem3 = (char **)(mem + 5);
	mem3[0] = NULL;
	return (mem);
}

void				*book_into_page(char *mem, size_t size)
{
	int				i;
	int				*int_mem;

	i = 13;
	while (i < (get_max_type_size(size) - (int)size))
	{
		int_mem = (int *)(mem + i);
		if (*int_mem == 0)
		{
			int_mem[0] = (int)size;
			return (mem + i + 4);
		}
		i += *int_mem;
		i += 4;
	}
	return (NULL);
}

void				*book_it(size_t size)
{
	char			*mem;
	char			**ptr_mem;
	void			*ret;

	mem = (char *)get_malloc(0);
	while (mem != NULL)
	{
		if (get_type(size) == *mem)
		{
			ret = book_into_page(mem, size);
			if (ret != NULL)
				return (ret);
		}
		ptr_mem = (char **)(mem + 5);
		if (!*ptr_mem)
			ptr_mem[0] = get_page(size, 0);
		mem = *ptr_mem;
	}
	return (NULL);
}
