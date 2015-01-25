#include <ft_malloc.h>

int			main(void)
{
	char	*str;
	char	*str2;
	int		i;

	str = (char *)ft_malloc(sizeof(char) * 10);
	printf("%i\n", (int)*(str - 4));
	if (str)
	{
		i = 0;
		while (i < 9)
		{
			str[i] = 'a' + i;
			i++;
		}
		str[i] = '\0';

		i = 0;
		while (i < 4080)
		{
			printf("%i : %d\n", i, (str[i]));
			i++;
		}

	}
	else
	{
		printf("Erreur malloc str\n");
	}

	printf("\n");
	str2 = (char *)ft_malloc(sizeof(char) * 10);
	if (str2)
	{
		i = 0;
		while (i < 9)
		{
			str2[i] = 'a' + i;
			i++;
		}
		str2[i] = '\0';
		printf("%s\n", str2);
	}
	else
	{
		printf("Erreur malloc str2\n");
	}


	return (0);
}
