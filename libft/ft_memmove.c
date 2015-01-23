/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:04:46 by vlehuger          #+#    #+#             */
/*   Updated: 2014/01/22 16:23:02 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void					*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*p_dst;
	unsigned char		*p_src;
	unsigned char		*tmp;
	size_t				k;

	p_dst = (unsigned char*)dst;
	p_src = (unsigned char*)src;
	tmp = ft_memalloc(len * sizeof(*tmp));
	k = 0;
	while (k < len)
	{
		tmp[k] = p_src[k];
		k++;
	}
	k = 0;
	while (k < len)
	{
		p_dst[k] = tmp[k];
		k++;
	}
	free(tmp);
	return (dst);
}
