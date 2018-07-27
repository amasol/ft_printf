/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 17:49:03 by amasol            #+#    #+#             */
/*   Updated: 2018/07/16 17:49:09 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
				ft_flag_Cc(lst, &format[i], flag, inf);
			else if (ft_refinement(format[i]) == 3)
				ft_flag_Ss(lst, &format[i], inf);
			else if (ft_refinement(format[i]) == 4)
				ft_flag_Xx(lst, &format[i], flag, inf);
			else if (ft_refinement(format[i]) == 5)
				ft_flag_Oo(lst, &format[i], flag, inf);
			else if (ft_refinement(format[i]) == 6)
				ft_flag_Uu(lst, &format[i], flag, inf);
			else if (ft_refinement(format[i]) == 7)
				ft_flag_p(lst, &format[i], inf);
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
//	int 		j;
	intmax_t	i;

//	j = 0;
	k = 0;
	i = 0;
	i = va_arg(lst, intmax_t);
	if (format[k] == 'd' || format[k] == 'i')
	{
		i = (APPLY) ? (cast_intmax(i, flag)) : (int)i;
		i = minus_value_Ddi(i, flag, inf);
		cancellation_flags_Ddi(flag, inf);
		if (LY)
			entry_minus(i, inf, flag);
		cast_flag_Ddi(inf, i, flag, format);
	}
	if (format[k] == 'D')
	{
//		j = va_arg(lst, long);
		i = (APPLY) ? (cast_intmax(i, flag)) : (long)i;
		minus_value_Ddi(i, flag, inf);
		cancellation_flags_Ddi(flag, inf);
		if (LY)
			entry_minus(i, inf, flag);
		cast_flag_Ddi(inf, i, flag, format);
	}
//	flag->ban = 1;
	 return (1);
}

//(С) рассматриваеться как (с) с подификатором (l)
int			ft_flag_Cc(va_list lst, char *format, t_flag *flag, t_inf *inf)
{
	int 		k;
	uintmax_t	j;

	k = 0;
	j = 0;
	j = va_arg(lst, uintmax_t);
	if (format[k] == 'c')
	{
		j = (APPLY) ? (cast_uintmax(j, flag)) : (unsigned char)j;
//		cancellation_flags_Cc(flag, inf);
		if (LY)
			entry_minus(j, inf, flag);
//		cast_flag_Cc(inf, flag, format);

//		ft_putchar(j);
	}
//	if (format[k] == 'C')
//	{
//	}
	return (1);
}

// Если указан модификатор l, то строка интерпитируется как wchar_t*.
// Для функции wprintf строка по умолчанию обрабатывается как wchar_t*.

int			ft_flag_Ss(va_list lst, char *format, t_inf *inf)
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

int			ft_flag_Xx(va_list lst, char *format, t_flag *flag, t_inf *inf)
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
//		flag->ban = ft_count(i);
		cancellation_flags_Uu(flag, inf);
		inf->cast_j += ft_strlen(ft_itoa_base_uintmax(i, 16, 'x'));
		if (LY)
			entry_minus(inf->cast_j, inf, flag);
		str = ft_itoa_base_uintmax(i, 16, 'x');
		cast_flag_Xx(inf, i, flag, str);
//		ft_putstr(str);
	}
//	else if (format[k] == 'X')
//	{
//		i = (APPLY) ? (cast_uintmax(i, flag)) : (unsigned int)i;
//		str = ft_itoa_base_uintmax(i, 16, 'X');
//		cast_flag_Ddi(inf, i, flag, format);
//		ft_putstr(str);
//	}
	return (1);
}


int 		ft_flag_Uu(va_list lst, char *format, t_flag *flag, t_inf *inf)
{
	int			k;
	uintmax_t	i;
	k = 0;
	i = va_arg(lst, uintmax_t);
	if (format[k] == 'u')
	{
		i = (APPLY) ? (cast_uintmax(i, flag)) : (unsigned int)i;
		flag->ban = ft_count(i);
		cancellation_flags_Uu(flag, inf);
		if (LY)
			entry_minus(i, inf, flag);
		cast_flag_Uu(inf, i, flag, format);
	}
	else if (format[k] == 'U')
	{
		i = (unsigned long)i;
//		i = minus_value_Uu(i, flag, inf);
		cancellation_flags_Uu(flag, inf);
		if (LY)
			entry_minus(i, inf, flag);
		cast_flag_Uu(inf, i, flag, format);
	}
	return (1);
}















int			ft_flag_Oo(va_list lst, char *format, t_flag *flag, t_inf *inf)
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
		cast_flag_Ddi(inf, i, flag, format);
		ft_putstr(str);
	}
	return (1);
}

int 		ft_flag_p(va_list lst, char *format, t_inf *inf)
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

