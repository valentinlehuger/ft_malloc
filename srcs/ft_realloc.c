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


void		*ft_realloc(void *ptr, size_t size)
{
	char	*char_ptr;
	char	*mem;
	char	**ptr_mem;
	int		*int_mem;

	char_ptr = (char *)ptr;
	mem = get_malloc(0);

	while (mem != NULL)
	{
		ptr_mem = (char **)(mem + 5);
		int_mem = (int *)(mem + 1);

		realloc_page(mem, *int_mem, ptr);

		mem = *ptr_mem;
	}

}