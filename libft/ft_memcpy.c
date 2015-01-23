/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:04:46 by vlehuger          #+#    #+#             */
/*   Updated: 2014/01/22 16:23:02 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				*ft_memcpy(void *dst, const void *src, size_t len)
{
	char			*p_dst;
	char			*p_src;
	size_t			k;

	if (!dst || !src || !len)
		return (dst);
	p_dst = (char*)dst;
	p_src = (char*)src;
	k = 0;
	while (k < len)
	{
		p_dst[k] = p_src[k];
		k++;
	}
	return (dst);
}
