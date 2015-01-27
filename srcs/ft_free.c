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

void		*unmap_it(char *mem, int page_size)
{
	int		i;
	void	**ptr;
	void	*next;

	// printf("HERE 3\n");
	ptr = (void **)(mem + 5);
	next = *ptr;

	i = 12;
	while (++i < page_size)
	{
		if (mem[i] != 0)
			return (mem);
	}

	if ((void *)mem == get_malloc(0) && next == NULL)
	{
		printf("Vous ne passerez... PAS !\n");
		get_malloc(1);
	}
	else if ((void *)mem == get_malloc(0))
		return next;
	munmap((void *)mem, page_size);
	return (next);
}

void		*free_page(void *mem, int page_size, void *ptr)
{
	int		i;
	int		*int_mem;

	// printf("HERE 2\n");
	i = 17;
	while (i < page_size)
	{
		if (mem + i == ptr)
		{
			int_mem = (int *)(mem + i - 4);
			// printf("int_mem (%p) = %d\n", int_mem, *int_mem);
			ft_bzero(ptr, *int_mem);
			*int_mem = 0;
			return unmap_it((char *)mem, page_size);
		}
		i++;
	}
	return mem;
}

void		ft_free(void *ptr)
{
	char	*char_ptr;
	char	*mem;
	char	*tmp;
	char	**ptr_mem;
	int		*int_mem;

	// printf("HERE 1\n");
	char_ptr = (char *)ptr;
	mem = get_malloc(0);
	tmp = NULL;
	// printf("HERE 1.1\n");
	while (mem != NULL)
	{
		// printf("HERE 1.2\n");
		int_mem = (int *)(mem + 1);
		// printf("HERE 1.3\n");
		if (tmp != NULL)
		{
			// printf("HERE 1.4\n");
			ptr_mem = (char **)(tmp + 5);
			*ptr_mem = (char *)free_page(mem, *int_mem, ptr);
			ptr_mem = (char **)(mem + 5);
			mem = *ptr_mem;
		}
		else
		{
			// printf("HERE 1.5 => *int_mem = %d\n", *int_mem);
			mem = free_page(mem, *int_mem, ptr);
		}
		tmp = mem;
		mem = NULL;
	}
}