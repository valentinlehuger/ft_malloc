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

void		*get_malloc(char init)
{
	static void			*pages = NULL;

	if (init == 1)
		pages = NULL;
	if (!pages && init != 1)
		pages = get_page(TINYSIZE, 1);
	// printf("return ptr pages at : %p\n", pages);
	return pages;
}

char		test_rlimit(size_t size)
{
	char		*mem;
	char		**ptr_mem;
	int			total;
	int			*int_mem;
	struct rlimit			rlp;

	total = 0;
	getrlimit(RLIMIT_STACK, &rlp);
	mem = get_malloc(0);
	while (mem != NULL)
	{
		ptr_mem = (char **)(mem + 5);
		int_mem = (int *)(mem + 1);
		total += *int_mem;
		mem = *ptr_mem;
	}

	printf("total = %d\n", total);
	printf("limit = %d\n", (int)rlp.rlim_cur);

	if (total + get_max_type_size(size) <= (int)rlp.rlim_cur)
		return (0);
	return (1);
}

void		*get_page(size_t size, int init)
{
	char					*mem;
	int						*mem2;
	char					**mem3;

	printf("Call to get page for %d bytes.\n", get_max_type_size(size));

	if (init == 0 && test_rlimit(size) == 1)
		return (NULL);

	mem = (char *)mmap(0, get_max_type_size(size),  PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

	ft_bzero(mem, get_max_type_size(size));

	mem[0] = get_type(size);
	mem2 = (int *)(mem + 1);
	mem2[0] = get_max_type_size(size);
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
		return size + 17;

}


void		*book_it(size_t size)
{
	char	*mem;
	char	**ptr_mem;
	void	*ret;

	mem = (char *)get_malloc(0);
		// printf("Enter in book it. Size : %zu\n", size);
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
			// printf("ptr_mem[0](%p) = %p\n", (&(ptr_mem[0])), ptr_mem[0]);
			ptr_mem[0] = get_page(size, 0);
			// printf("ptr_mem[0](%p) from %p to %p\n", (&(ptr_mem[0])), ptr_mem[0], ptr_mem[0] + get_max_type_size(size));
		}

		// printf("ptr_mem(%p) = %p\n", ptr_mem, *ptr_mem);

		// for (int j = 0; j < 40; j++)
		// 	printf("%d : %p => %d\n", j, (mem + j), *(mem + j));

		mem = *ptr_mem;

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

void		*malloc(size_t size)
{
	char	*mem;

	mem = book_it(size);

	return ((void *)mem);
}