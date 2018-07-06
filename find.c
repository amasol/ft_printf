
#include "ft_printf.h"

void		pars_spec(char *format, va_list lst, t_flag *flag, t_inf *inf)
{
	int i;

	i = 0;
	if (format[i])
	{
		if (ft_qualifier(format[i]))
		{
			if (ft_refinement(format[i]) == 1)
				ft_flag_Ddi(lst, &format[i], flag, inf);
			else if (ft_refinement(format[i]) == 2)
				ft_flag_Cc(lst, &format[i], flag);
			else if (ft_refinement(format[i]) == 3)
				ft_flag_Ss(lst, &format[i]);
			else if (ft_refinement(format[i]) == 4)
				ft_flag_Xx(lst, &format[i], flag);
			else if (ft_refinement(format[i]) == 5)
				ft_flag_Oo(lst, &format[i], flag);
			else if (ft_refinement(format[i]) == 6)
				ft_flag_Uu(lst, &format[i], flag);
			else if (ft_refinement(format[i]) == 7)
				ft_flag_p(lst, &format[i]);
		}
		i++;
	}
}

//if (flag->h == 1)
//{
//	i = (unsigned char)va_arg(lst, int);
//	ft_putnbr(i);
//}

//if (c == 'd' || c == 'i')
//{
	//i = (CAST) ? (ft_cast_to_signed(i, f)) : (int)i;
	//return (ft_collect_for_decimal(i, f));
//}

int			ft_flag_Ddi(va_list lst, char *format, t_flag *flag, t_inf *inf)
{
	int 		k;
	int 		j;
	intmax_t	i;

	j = 0;
	k = 0;
	i = 0;
	i = va_arg(lst, intmax_t);
	if (format[k] == 'd' || format[k] == 'i')
	{
		i = (APPLY) ? (cast_intmax(i, flag)) : (int)i;
		if (LY)
			entry_minus(i, inf);
		cast_flag(inf, i, flag);
	}
	if (format[k] == 'D')
	{
//		j = va_arg(lst, long);
		i = (APPLY) ? (cast_intmax(i, flag)) : (long)i;
		if (LY)
			entry_minus(i, inf);
		cast_flag(inf, i, flag);
//		ft_putnbr_intmax(i);
	}
	flag->ban = 1;
	 return (1);
}

//(С) рассматриваеться как (с) с подификатором (l)
int			ft_flag_Cc(va_list lst, char *format, t_flag *flag)
{
	int 		k;
	uintmax_t	j;

	k = 0;
	j = 0;
	j = va_arg(lst, uintmax_t);
	if (format[k] == 'c')
	{
		j = (APPLY) ? (cast_uintmax(j, flag)) : (unsigned char)j;
		ft_putchar(j);
	}
//	if (format[k] == 'C')
//	{
//	}
	return (1);
}

// Если указан модификатор l, то строка интерпитируется как wchar_t*.
// Для функции wprintf строка по умолчанию обрабатывается как wchar_t*.

int			ft_flag_Ss(va_list lst, char *format)
{
	int 	i;
	char	*str;
//	wchar_t	*str;

	i = 0;
//	str = va_arg(lst, wchar_t *);
	str = va_arg(lst, char *);
	if (format[i] == 's')
		ft_putstr(str);
	return (1);
//	посмотреть приминение ft_putstr c wchar_t!!!!!
}

int			ft_flag_Xx(va_list lst, char *format, t_flag *flag)
{
//	флаг j -требует что бы мы вытягивали intmax_t..
	int 		k;
	uintmax_t	i;
	char		*str;

	k = 0;
//	i = 0;
	i = va_arg(lst, uintmax_t);
	if (format[k] == 'x')
	{
		i = (APPLY) ? (cast_uintmax(i, flag)) : (unsigned int)i;
		str = ft_itoa_base_uintmax(i, 16, 'x');
		ft_putstr(str);
	}
	else if (format[k] == 'X')
	{
		i = (APPLY) ? (cast_uintmax(i, flag)) : (unsigned int)i;
		str = ft_itoa_base_uintmax(i, 16, 'X');
		ft_putstr(str);
	}
	return (1);
}

int 		ft_flag_Uu(va_list lst, char *format, t_flag *flag)
{
//	флаг j -требует что бы мы вытягивали intmax_t..
	int			k;
	uintmax_t	i;
	char		*str;
	// спецификатор (U) стоит в формате uintmax_t...какой должен быть маленькая (U)
	k = 0;
	i = va_arg(lst, uintmax_t);
	if (format[k] == 'u' || format[k] == 'U')
	{
		i = (APPLY) ? (cast_uintmax(i, flag)) : (unsigned int)i;
		str = ft_itoa_base_uintmax(i, 10, 'u');
		ft_putstr(str);
	}
	return (1);
}

int			ft_flag_Oo(va_list lst, char *format, t_flag *flag)
{
	int			k;
	uintmax_t	i;
	char		*str;
	// спецификатор (O) стоит в формате uintmax_t...какой должен быть маленькая (о)
	k = 0;
	i = va_arg(lst, uintmax_t);
	if (format[k] == 'o' || format[k] == 'O')
	{
		i = (APPLY) ? (cast_uintmax(i, flag)) : (unsigned int)i;
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
	i = va_arg(lst, uintmax_t);
	if (format[k] == 'p')
	{
		str = ft_itoa_base_uintmax(i, 16, 'x');
		ft_putstr("0x");
		ft_putstr(str);
	}
	return (1);
}

void		cast_flag(t_inf *inf, intmax_t i, t_flag *flag)
{
	if (inf->count > 0 && flag->minus == 1)
	{
		ft_putnbr_intmax(i);
		while (inf->count > 0 && (!(inf->width == 1 && i == 1)))
		{
			write(1, " ", 1);
			inf->count--;
		}
	}
	else if (inf->count > 0 && flag->zero == 1)
	{
		while (inf->count > 0)
		{
			write(1, "0", 1);
			inf->count--;
		}
		ft_putnbr_intmax(i);
	}
	else if (inf->count > 0 && flag->width == 1)
	{
		while (inf->count > 0)
		{
			write(1, " ", 1);
			inf->count--;
		}
		ft_putnbr_intmax(i);
	}
	else if (flag->zero == 0 || flag->minus == 0)
		ft_putnbr_intmax(i);
}