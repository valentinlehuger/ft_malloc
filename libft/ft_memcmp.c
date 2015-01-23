/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:11:01 by vlehuger          #+#    #+#             */
/*   Updated: 2014/01/25 11:43:03 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int					ft_memcmp(const void *s1, const void *s2, size_t len)
{
	unsigned char	*ps1;
	unsigned char	*ps2;
	size_t			k;

	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	k = 0;
	while (k < len)
	{
		if (ps1[k] != ps2[k])
			return (ps1[k] - ps2[k]);
		k++;
	}
	return (0);
}
