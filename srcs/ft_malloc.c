/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 18:08:53 by vlehuger          #+#    #+#             */
/*   Updated: 2015/01/22 18:08:54 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		*get_register(int type)
{
	static t_reg		*tiny_reg;
	static t_reg		*small_reg;
	static t_reg		*large_reg;

	
}

void		*malloc(size_t size)
{
	char	*mem;

	mem = (char *)mmap();

	return ((void *)mem);
}