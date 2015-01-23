/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:04:46 by vlehuger          #+#    #+#             */
/*   Updated: 2015/01/21 15:49:30 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	char	*p_dst;
	char	*p_src;
	size_t	k;

	p_dst = (char*)dst;
	p_src = (char*)src;
	k = 0;
	while (k < len)
	{
		if ((*p_dst++ = *p_src++) == c)
			return (p_dst);
		k++;
	}
	return (NULL);
}
