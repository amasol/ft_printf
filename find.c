#include "ft_printf.h"

void		find(char *format)
{
	if (*format != '%')
	{
		format++;
//		printf("----1---%s\n", format);
	}
}

void		pars(char *format)
{
	char *tmp;
	int i;

	i = 0;
	tmp = (char *)malloc(sizeof(char));
	if (*format == '%')
	{
		*format  = *format + 1;
		while (ft_strchr(format, ft_qualifier(*format)))
		{
			tmp = ft_strcpy(tmp, format);
			tmp++;
			format++;
//			i++;
		}
	}
	printf("----2---%s\n", tmp);
//	printf("----3---%d\n", *tmp);
//	printf("%s\n", format);
}
//		почему-то не выводит tmp как нужно....сдвинутый указатель до строки слага
//