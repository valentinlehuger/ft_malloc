#include <ft_malloc.h>

int			main(void)
{
	char	*str;

	for (int i = 0; i < 500; i++)
	{
		str = (char *)ft_malloc(sizeof(char) * 409);
		printf("nb = %d\n", i);
	}
}
