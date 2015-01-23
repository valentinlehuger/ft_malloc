/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 16:36:22 by vlehuger          #+#    #+#             */
/*   Updated: 2014/01/18 20:01:45 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				ft_striteri(char *str, void (*f)(unsigned int, char *))
{
	unsigned int	index;

	if (str && f)
	{
		index = 0;
		while (str[0] != '\0')
		{
			(*f)(index, str);
			str++;
			index++;
		}
	}
}
