/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:22:46 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/16 15:31:02 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int		ft_nb_int(char *line)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]) == 1 && ft_isdigit(line[i + 1]) != 1)
			nb++;
		i++;
	}
	return (nb);
}
