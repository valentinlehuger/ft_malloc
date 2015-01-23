/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 17:46:32 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/16 15:33:35 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_coord		*get_coord(double x, double y, double z)
{
	t_coord	*p;

	p = (t_coord *)malloc(sizeof(t_coord));
	if (p)
	{
		p->x = x;
		p->y = y;
		p->z = z;
		return (p);
	}
	return (NULL);
}
