/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel_to_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 18:48:43 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/16 15:47:19 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void			pixel_to_img(unsigned long img_color, t_env *e, int x, int y)
{
	unsigned char	color1;
	unsigned char	color2;
	unsigned char	color3;

	color1 = (img_color & 0xFF0000) >> 16;
	color2 = (img_color & 0xFF00) >> 8;
	color3 = (img_color & 0xFF) >> 0;
	e->data[y * e->size_line + x * e->bpp / 8] = color1;
	e->data[y * e->size_line + x * e->bpp / 8 + 1] = color2;
	e->data[y * e->size_line + x * e->bpp / 8 + 2] = color3;
}
