/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:08:26 by vlehuger          #+#    #+#             */
/*   Updated: 2013/11/28 15:41:38 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strsub(char const *s, unsigned int i, size_t len)
{
	size_t	j;
	char	*str;

	if (s == NULL)
		return (NULL);
	str = malloc(sizeof(char) * len + 1);
	if (str)
	{
		j = 0;
		while (j < len)
		{
			str[j] = (s + i)[j];
			j++;
		}
		str[j] = '\0';
		return (str);
	}
	return (NULL);
}
