/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 11:41:08 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/25 12:01:32 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int				ft_ten_pow(int ten, int p)
{
	if (p <= 0)
		return (1);
	else
		return (ft_ten_pow(ten, p - 1) * 10);
}

double			ft_atod(const char *s)
{
	int			i;
	double		integer;
	double		float_;

	float_ = 0.0;
	i = 0;
	while (s[i] && s[i] != '.')
		i++;
	if (s[i] == '\0')
		return ((double)(ft_atoi(s)));
	else if (s[i] == '.')
	{
		integer = (double)ft_atoi(ft_strsub(s, 0, i));
		float_ = (double)ft_atoi(ft_strsub(s, i + 1, ft_strlen(s) - i - 1));
		float_ = float_ / ft_ten_pow(1, ft_strlen(s) - i - 1);
		float_ = float_ + integer;
	}
	return (float_);
}
