/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 11:48:45 by vlehuger          #+#    #+#             */
/*   Updated: 2015/01/28 11:49:03 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>

char		get_type(size_t size)
{
	if (size <= TINYSIZE)
		return (TINY);
	else if (size <= SMALLSIZE)
		return (SMALL);
	else
		return (LARGE);
}

int			get_size(size_t size)
{
	if (size <= TINYSIZE)
		return (TINYSIZE);
	else if (size <= SMALLSIZE)
		return (SMALLSIZE);
	else
		return (size);
}

int			get_max_type_size(size_t size)
{
	if (size <= TINYSIZE)
		return (TINYMAX);
	else if (size <= SMALLSIZE)
		return (SMALLMAX);
	else
		return (size + 17);
}
