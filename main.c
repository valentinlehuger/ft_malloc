/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 12:18:13 by vlehuger          #+#    #+#             */
/*   Updated: 2014/04/20 17:15:08 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ft_malloc.h>

void			test()
{
	size_t			i;
	char		*str;

	i = 0;
	str = NULL;
	while (i < 1000)
	{
		str = malloc(i * 10);
		str = realloc(str, i * 20);
		i++;
	}
	show_alloc_mem();
}

int				main(void)
{
	test();
	return (0);
}
