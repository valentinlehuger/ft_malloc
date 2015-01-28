#include <ft_malloc.h>

int			main(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 8);

	free(str);

	return (0);
}
