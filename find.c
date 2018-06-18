
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
		else if (ft_refinement(format) == 4)
			ft_flag_Xx(lst, format);
		else if (ft_refinement(format) == 5)
			ft_flag_Oo(lst, format);
		else if (ft_refinement(format) == 6)
			ft_flag_Uu(lst, format);
		else if (ft_refinement(format) == 7)
			ft_flag_p(lst, format);
	}
}
int			ft_flag_Ddi(va_list lst, char format)
{
	int		i;
	long	j;

	if (format == 'd' || format == 'i')
	{
		i = va_arg(lst, int);
		ft_putnbr(i);
	}
	else if (format == 'D')
	{
		j = va_arg(lst, long);
		ft_putnbr(j);
	}
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

int			ft_flag_Ss(va_list lst, char format)
{
	char	*str;

	if (format == 's')
	{
		str = va_arg(lst, char *);
		ft_putstr(str);
	}
	return (1);
}

int			ft_flag_Xx(va_list lst, char format)
{
	uintmax_t i;
	char	*str;

	if (format == 'x')
	{
		i = va_arg(lst, uintmax_t);
		str = ft_itoa_base_uintmax(i, 16, 'x');
		ft_putstr(str);
	}
	else if (format == 'X')
	{
		i = va_arg(lst, uintmax_t);
		str = ft_itoa_base_uintmax(i, 16, 'X');
		ft_putstr(str);
	}
	return (1);
}

int 		ft_flag_Uu(va_list lst, char format)
{
	uintmax_t i;
	char	*str;
	// спецификатор (U) стоит в формате uintmax_t...какой должен быть маленькая (U)
	if (format == 'u' || format == 'U')
	{
		i = va_arg(lst, uintmax_t);
		str = ft_itoa_base_uintmax(i, 10, 'u');
		ft_putstr(str);
	}
	return (1);
}

int			ft_flag_Oo(va_list lst, char format)
{
	uintmax_t i;
	char	*str;
	// спецификатор (O) стоит в формате uintmax_t...какой должен быть маленькая (о)
	if (format == 'o' || format == 'O')
	{
		i = va_arg(lst, uintmax_t);
		str = ft_itoa_base_uintmax(i, 8, 'o');
		ft_putstr(str);
	}
	return (1);
}

int 		ft_flag_p(va_list lst, char format)
{
	uintmax_t	i;
	char		*str;

	if (format == 'p')
	{
		i = va_arg(lst, uintmax_t);
		str = ft_itoa_base_uintmax(i, 16, 'x');
		ft_putstr("0x");
		ft_putstr(str);
	}
	return (1);
}
