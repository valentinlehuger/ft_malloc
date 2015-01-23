/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/27 18:17:31 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/09 16:22:36 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_coord				*ft_add_vectors(t_coord *v1, t_coord *v2)
{
	return (get_coord(v1->x + v2->x, v1->y + v2->y, v1->z + v2->z));
}

t_coord				*ft_sub_vectors(t_coord *v1, t_coord *v2)
{
	return (get_coord(v1->x - v2->x, v1->y - v2->y, v1->z - v2->z));
}

t_coord				*ft_mult_vector(t_coord *v, double k)
{
	return (get_coord(v->x * k, v->y * k, v->z * k));
}

t_coord				*ft_div_vector(t_coord *v, double k)
{
	return (get_coord(v->x / k, v->y / k, v->z / k));
}
