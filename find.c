
#include "ft_printf.h"

void		pars_spec(char *format, va_list lst)
{
	int i;

	i = 0;
	while (format[i])
	{
		if (ft_qualifier(format[i]))
		{
			if (ft_refinement(format[i]) == 1)
				ft_flag_Ddi(lst, &format[i]);
			else if (ft_refinement(format[i]) == 2)
				ft_flag_Cc(lst, &format[i]);
			else if (ft_refinement(format[i]) == 3)
				ft_flag_Ss(lst, &format[i]);
			else if (ft_refinement(format[i]) == 4)
				ft_flag_Xx(lst, &format[i]);
			else if (ft_refinement(format[i]) == 5)
				ft_flag_Oo(lst, &format[i]);
			else if (ft_refinement(format[i]) == 6)
				ft_flag_Uu(lst, &format[i]);
			else if (ft_refinement(format[i]) == 7)
				ft_flag_p(lst, &format[i]);
		}
		i++;
	}
}
int			ft_flag_Ddi(va_list lst, char *format)
{
	int 	k;
	int		i;
	long	j;

	k = 0;
	j = 0;
	if (format[k] == 'd' || format[k] == 'i')
	{
		i = va_arg(lst, int);
		ft_putnbr(i);
	}
	if (format[k] == 'D')
	{
		j = va_arg(lst, long);
		ft_putnbr_long(j);
	}
	 return (1);
}

//(С) рассматриваеться как (с) с подификатором (l)
int			ft_flag_Cc(va_list lst, char *format)
{
	int i;
	int	j;

	i = 0;
	if (format[i] == 'c')
	{
		j = va_arg(lst, int);
		ft_putchar(j);
	}
	return (1);
}

// Если указан модификатор l, то строка интерпитируется как wchar_t*.
// Для функции wprintf строка по умолчанию обрабатывается как wchar_t*.

int			ft_flag_Ss(va_list lst, char *format)
{
	int i;
	char	*str;

	i = 0;
	if (format[i] == 's')
	{
		str = va_arg(lst, char *);
		ft_putstr(str);
	}
	return (1);
}

int			ft_flag_Xx(va_list lst, char *format)
{
	int 		k;
	uintmax_t	i;
	char		*str;

	k = 0;
	if (format[k] == 'x')
	{
		i = va_arg(lst, uintmax_t);
		str = ft_itoa_base_uintmax(i, 16, 'x');
		ft_putstr(str);
	}
	else if (format[k] == 'X')
	{
		i = va_arg(lst, uintmax_t);
		str = ft_itoa_base_uintmax(i, 16, 'X');
		ft_putstr(str);
	}
	return (1);
}

int 		ft_flag_Uu(va_list lst, char *format)
{
	int			k;
	uintmax_t	i;
	char		*str;
	// спецификатор (U) стоит в формате uintmax_t...какой должен быть маленькая (U)
	k = 0;
	if (format[k] == 'u' || format[k] == 'U')
	{
		i = va_arg(lst, uintmax_t);
		str = ft_itoa_base_uintmax(i, 10, 'u');
		ft_putstr(str);
	}
	return (1);
}

int			ft_flag_Oo(va_list lst, char *format)
{
	int			k;
	uintmax_t	i;
	char		*str;
	// спецификатор (O) стоит в формате uintmax_t...какой должен быть маленькая (о)
	k = 0;
	if (format[k] == 'o' || format[k] == 'O')
	{
		i = va_arg(lst, uintmax_t);
		str = ft_itoa_base_uintmax(i, 8, 'o');
		ft_putstr(str);
	}
	return (1);
}

int 		ft_flag_p(va_list lst, char *format)
{
	int 		k;
	uintmax_t	i;
	char		*str;

	k = 0;
	if (format[k] == 'p')
	{
		i = va_arg(lst, uintmax_t);
		str = ft_itoa_base_uintmax(i, 16, 'x');
		ft_putstr("0x");
		ft_putstr(str);
	}
	return (1);
}
