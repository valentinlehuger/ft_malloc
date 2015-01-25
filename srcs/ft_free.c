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

void		ft_free(void *ptr)
{
	char	*char_ptr;
	char	*mem;
	char	**ptr_mem;
	int		*int_mem;
	int 	*int_mem2;
	int		i;

	char_ptr = (char *)ptr;
	mem = get_malloc();

	printf("Pointer to find : %p\n", char_ptr);
	for (int k = 0; k < 60; k++)
	{
		printf("k => %p => %d\n", mem + k, (int)(*(mem + k)));
	}

	while (mem != NULL)
	{
		printf("next page.\n");
		ptr_mem = (char **)(mem + 5);
		int_mem = (int *)(mem + 1);
		i = 13;
		printf("%d\n", *int_mem);
		while (i < *int_mem)
		{
			printf("next memory block.\n");
			int_mem2 = (int *)(mem + i);
			if (mem == char_ptr)
			{
				printf("Detect the pointer\n");
				ft_bzero(ptr, *int_mem);
				*int_mem2 = 0;
				// Use unmap HERE if All the zone is free.
				return ;
			}
			i += *int_mem2;
			i += 4;
		}
		mem = *ptr_mem;
	}

}