#include "ft_printf.h"

int		main(void)
{
	char str[] = "text";
	ft_printf("(my)--> %s", str);
//	ft_printf("(my)--> %s", str);
	printf("(org)--> %s", str);
//	ft_printf("TEXT TEXT -> %%d", 1);
	return 0;
}
