/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 16:36:22 by vlehuger          #+#    #+#             */
/*   Updated: 2014/01/18 20:01:45 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void			ft_striter(char *str, void (*f)(char *))
{
	size_t		index;

	if (str && f)
	{
		index = 0;
		while (str[index] != '\0')
		{
			(*f)(str + index);
			index++;
		}
	}
}
