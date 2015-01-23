/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 11:52:42 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/12 11:54:08 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void				*ft_memchr(const void *src, int value, size_t len)
{
	unsigned char	*p_src;
	size_t			k;
	char			end;

	p_src = (unsigned char*)src;
	k = 0;
	end = '0';
	while (k < len && end == '0')
	{
		if (p_src[k++] == (unsigned char)value)
			end = '1';
	}
	if (end == '0')
		return (NULL);
	return (p_src + k - 1);
}
