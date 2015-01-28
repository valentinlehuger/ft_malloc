/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 18:08:53 by vlehuger          #+#    #+#             */
/*   Updated: 2015/01/22 18:08:54 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>

void		*malloc(size_t size)
{
	char	*mem;

	mem = book_it(size);
	return ((void *)mem);
}
