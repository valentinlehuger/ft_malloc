/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:11:01 by vlehuger          #+#    #+#             */
/*   Updated: 2014/01/25 11:43:03 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strrchr(const char *src, int value)
{
	size_t			index;
	char			*res;

	index = 0;
	res = NULL;
	while (src[index] != '\0')
	{
		if (src[index] == (char)value)
			res = (char*)&src[index];
		index++;
	}
	if ((char)value == '\0')
		return ((char*)&src[index]);
	return (res);
}
