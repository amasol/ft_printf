#include "ft_printf.h"

int		main(void)
{
	char str[] = "123";
	int j = 4123;

	int 	*a;
	int 	i = 1;
	a = &i;


//	ft_printf("(my)--> %i", j);
//	ft_printf("(my)--> %d", j);
//	ft_printf("(my)-->D %D", j);
//	ft_printf("(my)--> %c", 'a');
//	ft_printf("(my)--> %i%c%d%i%s", j, 's', 1, 2, "a");
//	ft_printf("(my)--> %s", "text");
//	ft_printf("(my)--> (16)->%X", 151231241);
//	printf("(org)--> (16)->%X\n", 151231241);
//	ft_printf("(my)--> (10)->%u", 1512321312);
//	ft_printf("(my)--> (10)->%U", 1512321312);
//	printf("(org)--> (10)->%u\n", 1512321312);
//	ft_printf("(my)--> (8)->%o", -1512321312);
//	ft_printf("(my)--> (8)->%O", -1512321312);
//	printf("(org)--> (8)->%o\n", -1512321312);
//	ft_printf("(my)-->x (16)->%x", a);
//	ft_printf("(my)-->p (16)->%p", a);
//	printf("(org)--> (16)->%p\n", a);

//	ft_printf("(my)--> %i%c%d%i%s", j, 's', 1, 2, "a");
	ft_printf("(my)-->[d] |%#lhd", j);
//	ft_printf("(my)-->d % d", j);
//	printf("(org)--> (D)->%# hd\n", j);

//	ft_printf("%stest\n", str);
//	printf("%123s\n", str);

//	ft_printf("%d", 123);

	return (0);
}
