
#include "ft_printf.h"

void		pars(char format, va_list lst)
{
	if (ft_qualifier(format))
	{
		if (ft_refinement(format) == 1)
			ft_flag_Ddi(lst, format);
		else if (ft_refinement(format) == 2)
			ft_flag_Cc(lst, format);
		else if (ft_refinement(format) == 3)
			ft_flag_Ss(lst, format);
	/*	else if (ft_refinement(format) == 4)
			ft_flag_Xx();
		else if (ft_refinement(format) == 5)
			ft_flag_Oo();
		else if (ft_refinement(format) == 6)
			ft_flag_Uu();
		else if (ft_refinement(format) == 7)
			ft_flag_p();*/
	}
}
int			ft_flag_Ddi(va_list lst, char format)
{
	int	i;

	i = va_arg(lst, int);
	if (format == 'd' || format == 'i')
		ft_putnbr(i);
	 return (1);
}

//(С) рассматриваеться как (с) с подификатором (l)
int			ft_flag_Cc(va_list lst, char format)
{
	int	j;

	if (format == 'c')
	{
		j = va_arg(lst, int);
		ft_putchar(j);
	}
	return (1);
}

// Если указан модификатор l, то строка интерпитируется как wchar_t*.
// Для функции wprintf строка по умолчанию обрабатывается как wchar_t*.
//
int			ft_flag_Ss(va_list lst, char format)
{
	char *str;

	if (format == 's')
	{
		str = va_arg(lst, char *);
		ft_putstr(str);
	}
	return (1);
}

