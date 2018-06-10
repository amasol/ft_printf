#include "ft_printf.h"

int		main(void)
{
	char str[] = "text";
	int j = 4;

	 ft_printf("(my)--> %i", j);
	 ft_printf("(my)--> %d", j);
	 ft_printf("(my)--> %c", 'a');
	 ft_printf("(my)--> %i%c%d%i%s", j, 's', 1, 2, "a");
	 ft_printf("(my)--> %s", "text    text\n      text");
	 printf("(org)--> %d\n", 5);
	return (0);
}
