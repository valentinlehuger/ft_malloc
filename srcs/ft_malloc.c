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

#include <ft_malloc.h>

void		*get_malloc(void)
{
	static void			*pages = NULL;

	if (!pages)
		pages = ft_bzero(get_page(TINYSIZE));
	return pages;
}

void		*get_page(size_t size)
{
	char	*mem;
	int		*mem2;
	char	**mem3;

	mem = (char *)ft_bzero(mmap(0, get_size(size),  PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0));

	mem[0] = get_type(size);
	mem2 = (int *)(mem + 1);
	mem2[0] = get_size(size);
	mem3 = (char **)(mem + 5);
	mem3[0] = NULL;

	return mem;
}

char		get_type(size_t size)
{
	if (size <= TINYSIZE)
		return TINY;
	else if (size <= SMALLSIZE)
		return SMALL;
	else
		return LARGE;
}

int			get_size(size_t size)
{
	if (size <= TINYSIZE)
		return TINYSIZE;
	else if (size <= SMALLSIZE)
		return SMALLSIZE;
	else
		return size;
}

int			get_max_type_size(size_t size)
{
	if (size <= TINYSIZE)
		return TINYMAX;
	else if (size <= SMALLSIZE)
		return SMALLMAX;
	else
		return size;

}


void		*book_it(size_t size)
{
	char	*mem;
	void	*ret;

	if (size <= SMALLSIZE)
	{
		mem = (char *)get_malloc();
		while (mem != NULL)
		{
			if (get_type(size) == (char)(*mem))
			{
				ret = book_into_page(mem);
				if (ret != NULL)
					return ret;
			}
			mem += (int)mem[1];
		}
	}

	// CASE OF LARGE
	else
	{
	}
}

void		*book_into_page(char *mem)
{
	int		i;
	int 	*int_mem;

	i = 0;
	while (i < (get_max_type_size(size) - size))
	{
		if (i == 0)
		{
			int_mem = (int *)mem;
			int_mem[i/4] = (int)size;
			return mem + i + 4;
		}
		i += (int)(*(mem + i));
	}
	return (NULL);
}

void		*ft_malloc(size_t size)
{
	char	*mem;

	mem = book_it(size);

	return ((void *)mem);
}