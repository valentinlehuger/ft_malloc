/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 11:52:42 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/12 11:54:08 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				*ft_memalloc(size_t size)
{
	char			*mem;
	size_t			i;

	mem = (char *)malloc(sizeof(char) * size);
	if (mem != NULL)
	{
		i = -1;
		while (++i < size)
			mem[i] = 0;
	}
	return (void*)mem;
}
