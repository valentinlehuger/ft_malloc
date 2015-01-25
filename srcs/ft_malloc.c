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
		pages = get_page(TINYSIZE);
	// printf("return ptr pages at : %p\n", pages);
	return pages;
}

void		*get_page(size_t size)
{
	char	*mem;
	int		*mem2;
	char	**mem3;

	printf("Call to get page for %d bytes.\n", get_max_type_size(size));

	mem = (char *)mmap(0, get_max_type_size(size),  PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

	ft_bzero(mem, get_size(size));

	mem[0] = get_type(size);
	mem2 = (int *)(mem + 1);
	mem2[0] = get_size(size);
	mem3 = (char **)(mem + 5);
	mem3[0] = NULL;

	// for (int j = 0; j < 40; j++)
	// 	printf("%d : %p => %d\n", j, (mem + j), *(mem + j));


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
	char	**ptr_mem;
	void	*ret;

	if (size <= SMALLSIZE)
	{
		// printf("Enter in book it. Size : %zu\n", size);
		mem = (char *)get_malloc();
		while (mem != NULL)
		{
			// printf("Test (char)(*mem): %i\n", (char)(*mem));
			if (get_type(size) == *mem)
			{
				ret = book_into_page(mem, size);
				if (ret != NULL)
					return ret;
			}
			ptr_mem = (char **)(mem + 5);
			// printf("ptr_mem[0](%p) = %p\n", (&(ptr_mem[0])), ptr_mem[0]);
			if (!*ptr_mem)
			{
				printf("ptr_mem[0](%p) = %p\n", (&(ptr_mem[0])), ptr_mem[0]);
				ptr_mem[0] = get_page(size);
				printf("ptr_mem[0](%p) from %p to %p\n", (&(ptr_mem[0])), ptr_mem[0], ptr_mem[0] + get_max_type_size(size));
			}

			// printf("ptr_mem(%p) = %p\n", ptr_mem, *ptr_mem);

			// for (int j = 0; j < 40; j++)
			// 	printf("%d : %p => %d\n", j, (mem + j), *(mem + j));

			mem = *ptr_mem;

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

	// printf("Enter in book into page. Size : %zu   Mem : %p\n", size, mem);
	i = 13;

	// for (int j = 0; j < 40; j++)
	// 	printf("%d : %p => %d\n", j, (mem + j), *(mem + j));

	while (i < (get_max_type_size(size) - (int)size))
	{
		// printf("i = %d ->%p\n", i, mem + i);
		// printf("size = %d\n", (int)(*(mem + i)));
		int_mem = (int *)(mem + i);
		// printf("Here 2 -> *int_mem = %d \n", *int_mem);
		if (*int_mem == 0)
		{
			// printf("Here 3\n");
			int_mem[0] = (int)size;
			return mem + i + 4;
		}
		i += *int_mem;
		i+= 4;
	}
	return (NULL);
}

void		*ft_malloc(size_t size)
{
	char	*mem;

	mem = book_it(size);

	return ((void *)mem);
}