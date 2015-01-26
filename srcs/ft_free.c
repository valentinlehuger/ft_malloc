/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 18:08:47 by vlehuger          #+#    #+#             */
/*   Updated: 2015/01/22 18:08:48 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>

void		remap(int *int_mem)
{
	int		tmp;
	int		*next_int_mem;
	char 	*mem;
	char	*next_mem;
	int		i;

	mem = (char *)(int_mem + 1);
	next_int_mem = (int *)(mem + *int_mem);
	next_mem = (char *)(next_int_mem + 1);

	while (next_int_mem > 0)
	{
		tmp = *int_mem;
		*int_mem = *next_int_mem;
		i = -1;
		while (i++ < *int_mem)
		{
			*(mem + i) = *(next_mem + i);
			*(next_mem + i) = 0;
		}
		next_int_mem = (int *)(mem + tmp + 4 + *int_mem);
		next_mem = (char *)(next_int_mem + 1);
		int_mem = (int *)(mem + i);
		mem = (char *)(int_mem + 1);
	}
}

void		free_and_remap(char *mem)
{
	int		*int_mem;
	int 	*next_block;

	int_mem = (int *)mem;
	mem += 4;
	next_block = (int*)(mem + *int_mem);

	if (*next_block > 0)
	{
		ft_bzero(mem, *int_mem);
		remap(int_mem);
	}
}

void		free_page(void *mem, int page_size)
{
	int		i;
	int		*int_mem;

	i = 13;
	while (i < page_size)
	{
		int_mem = (int *)(mem + i + 4);

		free_and_remap(mem + i);

		i += *int_mem;
		i += 4;
	}

}

void		ft_free(void *ptr)
{
	char	*char_ptr;
	char	*mem;
	char	**ptr_mem;
	int		*int_mem;

	char_ptr = (char *)ptr;
	mem = get_malloc();

	while (mem != NULL)
	{
		ptr_mem = (char **)(mem + 5);
		int_mem = (int *)(mem + 1);

		free_page(mem, *int_mem);

		mem = *ptr_mem;
	}

}