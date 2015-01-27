/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 18:08:58 by vlehuger          #+#    #+#             */
/*   Updated: 2015/01/22 18:08:59 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>

char			is_pointer_in_page(void *page, void *ptr)
{
	int			*int_mem;

	int_mem = (int *)(page + 1);
	if (ptr > page && ptr < (page + (*int_mem)))
		return (1);
	else
		return (0);
}

void		*realloc_less_size(int *ptr, size_t size)
{
	char	*mem;
	int		i;

	// printf("Realloc less size\n");

	mem = (char *)(ptr + 1);
	i = (int)size;
	while (i < *ptr)
		mem[i++] = 0;
	*ptr = (int)size;
	return ((void *)mem);
}

void		*go_elsewhere(void *old_ptr, size_t size, int old_size)
{
	void	*new_ptr;

	new_ptr = ft_malloc(size);
	if (!new_ptr)
		return (NULL);
	new_ptr = ft_memcpy(new_ptr, old_ptr, (size_t)old_size);
	ft_free(old_ptr);
	return new_ptr;
}

void		*realloc_page(void *mem, int page_size, void *ptr, size_t size)
{
	int		i;
	int		*ptr_old_size;
	int		*int_ptr;

	ptr_old_size = (int *)(ptr - 4);
	if ((int)size < *ptr_old_size)
		return realloc_less_size(ptr_old_size, size);

	i = *ptr_old_size;

	// printf("ptr = %p and mem = %p\n", ptr, mem);
	// printf("page_size - (ptr - mem) = %ld\n", page_size - (ptr - mem));
	// printf("i = %d\n", i);

	while (i < ((int)size) && /*FALSE*/ i + 3 < (page_size - (int)(ptr - mem)) /* UNTIL HERE */ )
	{
		int_ptr = (int *)(ptr + i);
		// printf("%d.\tYOO int_ptr = %p\n", i, int_ptr);
		if (*int_ptr != 0)
		{
			// printf("Enter HERE !\n");
			return go_elsewhere(ptr, size, *ptr_old_size);
		}
		i++;
	}
	if (i == (int)size)
	{
		// printf("Enter HERE2 !\n");
		*ptr_old_size = (int)size;
	}
	else
	{
		// printf("Enter HERE3 !\n");
		return go_elsewhere(ptr, size, *ptr_old_size);
	}
	return ptr;
}


void		*ft_realloc(void *ptr, size_t size)
{
	char	*char_ptr;
	char	*mem;
	char	**ptr_mem;
	int		*int_mem;

	(void)size;

	char_ptr = (char *)ptr;
	mem = get_malloc(0);

	while (mem != NULL)
	{
		ptr_mem = (char **)(mem + 5);

		if (is_pointer_in_page(mem, ptr) == 1)
		{
			int_mem = (int *)(mem + 1);
			return realloc_page(mem, *int_mem, ptr, size);
		}

		mem = *ptr_mem;
	}
	return (NULL);
}
