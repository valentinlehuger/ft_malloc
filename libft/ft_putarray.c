/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 13:44:36 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/06 13:46:27 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void			ft_putarray(char **array)
{
	int			i;

	i = 0;
	while (array[i])
	{
		if (array[i])
		{
			write(1, array[i], ft_strlen(array[i]));
			write(1, "\n", 1);
		}
		i++;
	}
}
