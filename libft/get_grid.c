/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 17:28:54 by vlehuger          #+#    #+#             */
/*   Updated: 2014/01/11 16:20:47 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list		*get_file(char *path, int *line_nb)
{
	char	*line;
	int		fd;
	t_list	*list;
	t_list	*tmp;
	t_list	*beg;

	beg = NULL;
	list = NULL;
	if ((fd = open(path, O_RDONLY)) > -1)
	{
		*line_nb = 1;
		if (get_next_line(fd, &line) == 1)
			list = ft_lstnew((char *)line, 0);
		beg = list;
		while (get_next_line(fd, &line) == 1)
		{
			tmp = list;
			list = ft_lstnew((char *)line, 0);
			tmp->next = list;
			*line_nb = *line_nb + 1;
		}
	}
	return (beg);
}

int			*ft_get_int_line(char *line, int nb)
{
	int		*int_line;
	int		i;
	int		j;

	int_line = (int *)malloc(sizeof(int) * (nb + 1));
	i = 0;
	j = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]) == 1)
		{
			int_line[j] = ft_atoi(&line[i]);
			j++;
		}
		i++;
	}
	int_line[j] = 11;
	return (int_line);
}

int			**inverse_grid(int **grid, int line_nb, int col_nb)
{
	int		**new_grid;
	int		i;
	int		j;

	new_grid = (int **)malloc(sizeof(int *) * (col_nb + 1));
	i = 0;
	while (i < col_nb)
	{
		new_grid[i] = (int *)malloc(sizeof(int) * (line_nb + 1));
		j = 0;
		while (j < line_nb)
		{
			new_grid[i][j] = grid[j][i];
			j++;
		}
		new_grid[i][j] = 11;
		i++;
	}
	new_grid[i] = NULL;
	return (new_grid);
}

int			**get_int_grid(t_list *list, int line_nb)
{
	int		**grid;
	int		i;
	int		col_nb;

	col_nb = ft_nb_int(list->content);
	i = 0;
	grid = (int **)malloc(sizeof(int *) * (line_nb + 1));
	while (list)
	{
		grid[i] = (int *)malloc(sizeof(int) * (ft_nb_int(list->content) + 1));
		grid[i] = ft_get_int_line(list->content, ft_nb_int(list->content));
		list = list->next;
		i++;
	}
	grid[i] = NULL;
	return (inverse_grid(grid, line_nb, col_nb));
}

int			**get_grid(char **av)
{
	int		line_nb;
	t_list	*list;

	list = get_file(av[1], &line_nb);
	return (get_int_grid(list, line_nb));
}
