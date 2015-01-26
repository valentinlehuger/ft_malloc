
#include <ft_malloc.h>

void		print_address(void *address)
{
	int		*int_mem;

	int_mem = (int *)address;
	address = address + 4;

	ft_putaddress(address);
	ft_putstring(" - ");
	ft_putaddress(address + (*int_mem));
	ft_putstring(" : ");
	ft_putnbr((*int_mem));
	ft_pustring(" octets");
}

void		put_type(char *mem, char type)
{
	int		i;
	char	**ptr_mem;
	int		*int_mem;

	while (mem)
	{
		ptr_mem = (char **)(mem + 5);
		if (*mem == type)
		{
			i = 13;
			while (i < (get_max_type_size(size) - (int)size))
			{
				int_mem = (int *)(mem + i);

				if (*int_mem != 0)
					ft_putaddress((void *)(mem + i + 4));
				i += *int_mem;
			}
		}
		mem = *ptr_mem;
	}
}

void		show_alloc_mem(void)
{
	void	*mem;
	void	*tmp;

	mem = get_malloc();
	tmp = mem;

}