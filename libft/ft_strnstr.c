/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:11:01 by vlehuger          #+#    #+#             */
/*   Updated: 2014/01/25 11:43:03 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t			i;
	size_t			j;
	size_t			i_tmp;

	if (!s2 || ft_strlen(s2) == 0)
		return ((char*)s1);
	i = 0;
	j = 0;
	while (s1[i] != '\0' && i < len)
	{
		i_tmp = i;
		while (s1[i] == s2[j] && s1[i] != '\0' && s2[j] != '\0' && i < len)
		{
			i++;
			j++;
		}
		if (s2[j] == '\0')
			return ((char *)&s1[i_tmp]);
		i = i_tmp + 1;
		j = 0;
	}
	return (NULL);
}
