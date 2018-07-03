#include "ft_printf.h"

int		main(void)
{
	char str[] = "text123";

	int j = 12;
//	intmax_t j = 9223372036854775807;
	int 	*a;
	int 	i = 1;

	a = &i;


//	ft_printf("(my)--> %i", j);
//	ft_printf("(my)--> %d", j);
//	ft_printf("(my)-->D %D", j);
//	ft_printf("(my)--> %c", 'a');
//	ft_printf("(my)--> %i%c%-10d%i%s", j, 's', 1, 2, "a");
//	ft_printf("(my)--> %s", "text");
//	ft_printf("(my)--> (16-X)->%X", 151231241);
//	printf("(org)--> (16-X)->%X\n", 151231241);
//	ft_printf("(my)--> (10-u)->%hu", 1512321312);
//	ft_printf("(my)--> (10-U)->%hU", 1512321312);
//	printf("(org)--> (10-u)->%hu\n", 1512321312);
//	printf("(org)--> (10-U)->%u\n", 1512321312);
//	ft_printf("(my)--> (8-o)->%o", -1512321312);
//	ft_printf("(my)--> (8-O)->%O", -1512321312);
//	printf("(org)--> (8-o)->%o\n", -1512321312);
//	printf("(org)--> (8-O)->%o\n", -1512321312);
//	ft_printf("(my)-->x (16)->%x", j);
//	printf("(org)-->x (16)-> %x", j);
//	ft_printf("(my)-->p (16)->%p", a);
//	printf("(org)-->p (16)->%p\n", a);

//	ft_printf("(my)-->%d%c%d%i%s", j, 's', 1, 2, "a");
//	printf("(org)-->%text%c%d%i%s", j, 's', 1, 2, "a");
//	ft_printf("(my)-->d % d", j);
//	printf("(org)--> (D)->%# hd\n", j);

//	ft_printf("%s\n", str);
//	printf("%s\n", str);


//	ft_printf("(my)-->[d] %hhd", j);
//	printf("(org)-->[d] %hd", j);


//	printf("1[%-6d]\n", 123);
//	printf("2[%10d]\n", 123);


//	ft_printf("[%-5d]\n", 123);
//	ft_printf("%-5d\n", 567);
//	ft_printf("(may)[%-15d]\n", 567);




//появилась сега !
//		ft_printf("(my)-->%i%c%-30d%i%s", j, 's', 1, 2, "a");

//	printf("(org)[%04d]\n", 123);
	printf("(org)[%-66d text]\n", 123);
	ft_printf("(my)[%--66d text]", 123);

//	printf("(org)[%d->test]\n", 567);
//	ft_printf("(my)[%d->test]", 567);

	return (0);
}
