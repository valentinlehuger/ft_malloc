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

// Return a bool 0 if false | 1 if true
char		stay_here()
{
	return (0);
}

// void		realloc_page(void *mem, int page_size, void *ptr, size_t size)
// {
// 	int		i;

// 	i = 13;
// 	while ()
// 	{
// 		// IF pointer is found
// 		{
// 			// Test to stay here

// 			// Else
// 				// malloc(size)
// 				// fill new mem block
// 				// free old pointer
// 			i++;
// 		}
// 	}
// }


void		*ft_realloc(void *ptr, size_t size)
{
	char	*char_ptr;
	char	*mem;
	char	**ptr_mem;
	// int		*int_mem;

	(void)size;

	char_ptr = (char *)ptr;
	mem = get_malloc(0);

	while (mem != NULL)
	{
		ptr_mem = (char **)(mem + 5);
		// int_mem = (int *)(mem + 1);
		// realloc_page(mem, *int_mem, ptr, size);

		printf("%d\n", is_pointer_in_page(mem, ptr));

		mem = *ptr_mem;
	}
	return (NULL);
}
