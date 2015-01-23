/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:11:00 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/16 15:47:45 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char			*ft_strmalloc(const char *s, char c)
{
	char		*str;
	int			i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
	}
	str = malloc(sizeof(char) * i + 1);
	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int			ft_strlen_c(const char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static int			ft_nb_str(const char *s, char c)
{
	int			i;
	int			nb;

	i = 0;
	nb = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			nb++;
		i++;
	}
	return (nb);
}

char				**ft_strsplit(char const *s, char c)
{
	int		i;
	int		k;
	char	**array;

	if (s == NULL)
		return (NULL);
	array = malloc(sizeof(int) * (ft_nb_str(s, c) + 1));
	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			array[k] = malloc(sizeof(char) * (ft_strlen_c(s + i, c) + 1));
			array[k] = ft_strmalloc(s + i, c);
			k++;
		}
		i++;
	}
	array[k] = NULL;
	return (array);
}
