/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_coord.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 14:03:04 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/14 16:13:31 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
**	for a string type as "x, y, z".
*/

t_coord			*ft_str_to_coord(char *str)
{
	double		x;
	double		y;
	double		z;
	int			i;

	i = 0;
	while (ft_isdigit(str[i]) == 0 && str[i] != '-')
		i++;
	x = (double)ft_atoi(str + i) / 100;
	while (ft_isdigit(str[i]) == 1 || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]) == 0 && str[i] != '-')
		i++;
	y = (double)ft_atoi(str + i) / 100;
	while (ft_isdigit(str[i]) == 1 || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]) == 0 && str[i] != '-')
		i++;
	z = (double)ft_atoi(str + i) / 100;
	return (get_coord(x, y, z));
}
