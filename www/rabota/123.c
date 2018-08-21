#include <unistd.h>
#include <stdio.h>
/*
int			ft_length(char *tmp)
{
	int i;

	i = 0;
	if (tmp[i] == 'h' && tmp[i + 1] == 'h')
		return (1);
	else
		return (0);
}

int		main(void)
{
	char str[] = "h";
	printf("%d\n", ft_length(str));
	return (0);
}
*/

int		main()
{
	int i;
	i = 0;

	char str[] = "1asd";
	printf("%C\n", *str);
	return (0);
}
