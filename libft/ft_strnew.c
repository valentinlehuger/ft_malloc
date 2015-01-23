/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 16:25:38 by vlehuger          #+#    #+#             */
/*   Updated: 2014/01/22 16:25:39 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char			*ft_strnew(size_t size)
{
	char		*str;
	size_t		index;

	index = 0;
	str = (char *)malloc(sizeof(*str) * (size + 1));
	if (str != NULL)
	{
		while (index < size)
		{
			str[index] = '\0';
			index++;
		}
		str[index] = '\0';
	}
	return (str);
}
