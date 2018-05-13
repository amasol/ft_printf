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
	char *str = "111";
	printf("%hhd\n", 129);
	return (0);
}
