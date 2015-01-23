/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 16:36:22 by vlehuger          #+#    #+#             */
/*   Updated: 2014/01/18 20:01:45 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char			*ft_strmap(char const *s, char (*f)(char))
{
	int			i;
	char		*tmp;

	tmp = NULL;
	if (s != NULL)
	{
		tmp = ft_strdup(s);
		i = -1;
		while (tmp[++i] != '\0')
			tmp[i] = f(s[i]);
	}
	return (tmp);
}
