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

//   0   1   2   3   4   5   6   7   8   9   10  11  12 
// | A | B | B | B | B | C | C | C | C | C | C | C | C |

// A = type
// B = size
// C = pointer on next

void		*get_malloc(void)
{
	static void			*pages = NULL;

	if (!pages)
	{
		pages = get_page(TINYSIZE);
		ft_bzero(pages, TINYSIZE);
	}
	return pages;
}

void		*get_page(size_t size)
{
	char	*mem;
	int		*mem2;
	char	**mem3;

	mem = (char *)mmap(0, get_size(size),  PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

	ft_bzero(mem, get_size(size));

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
		printf("Enter in book it. Size : %zu\n", size);
		mem = (char *)get_malloc();
		while (mem != NULL)
		{
			if (get_type(size) == (char)(*mem))
			{
				ret = book_into_page(mem, size);
				if (ret != NULL)
					return ret;
			}
			mem = NULL;
		}
	}

	// CASE OF LARGE
	else
	{
	}
	return (NULL);
}

void		*book_into_page(char *mem, size_t size)
{
	int		i;
	int 	*int_mem;

	printf("Enter in book into page. Size : %zu   Mem : %x\n", size, (int)mem);
	i = 0;
	while (i < (get_max_type_size(size) - (int)size))
	{
		if (i == 0)
		{
			int_mem = (int *)mem;
			int_mem[i/4] = (int)size;
			return mem + i + 4;
		}
		i += (int)(*(mem + i)) + 1;
	}
	return (NULL);
}

void		*ft_malloc(size_t size)
{
	char	*mem;

	mem = book_it(size);

	return ((void *)mem);
}