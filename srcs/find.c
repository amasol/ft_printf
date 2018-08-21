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

#include "../includes/ft_printf.h"

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
				ft_flag_Ss(lst, &format[i], flag, inf);
			else if (ft_refinement(format[i]) == 4)
				ft_flag_Xx(lst, &format[i], flag, inf);
			else if (ft_refinement(format[i]) == 5)
				ft_flag_Oo(lst, &format[i], flag, inf);
			else if (ft_refinement(format[i]) == 6)
				ft_flag_Uu(lst, &format[i], flag, inf);
			else if (ft_refinement(format[i]) == 7)
				ft_flag_p(lst, &format[i], flag, inf);
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
			entry_minus_intm(i, inf, flag);
		cast_flag_Ddi(inf, i, flag, format);
	}
	if (format[k] == 'D')
	{
//		j = va_arg(lst, long);
		i = (APPLY) ? (cast_intmax(i, flag)) : (long)i;
		minus_value_Ddi(i, flag, inf);
		cancellation_flags_Ddi(flag, inf);
		if (LY)
			entry_minus_intm(i, inf, flag);
		cast_flag_Ddi(inf, i, flag, format);
	}
//	flag->ban = 1;
	 return (1);
}

//(С) рассматриваеться как (с) с подификатором (l)
int			ft_flag_Cc(va_list lst, char *format, t_flag *flag, t_inf *inf)
{
	unsigned char	str;

	if (*format == 'c')
	{
		str = va_arg(lst, unsigned int);
		flag->ban = 1;
		inf->uint_j += 1;
		cast_flag_Cc(inf, flag, str);
	}
//	if (format[k] == 'C')
	return (1);
}

// Если указан модификатор l, то строка интерпитируется как wchar_t*.
// Для функции wprintf строка по умолчанию обрабатывается как wchar_t*.

int			ft_flag_Ss(va_list lst, char *format, t_flag *flag, t_inf *inf)
{
	int 	i;
	char	*str;
//	wchar_t	*sstr;

	i = 0;
	if (format[i] == 's')
	{
		str = va_arg(lst, char *);
		flag->ban = ft_strlen(str);
		inf->uint_j += ft_strlen(str);
		cast_flag_Ss(inf, flag, str);
	}
//	else if (format[i] == 'S')
//	{
	//	посмотреть приминение ft_putstr c wchar_t!!!!!


//		sstr = va_arg(lst, wchar_t *);
//		flag->ban = ft_strlen(sstr);
//		inf->uint_j += ft_strlen(sstr);
//		if (LY)
//			entry_minus_uint(inf, flag);
//		cast_flag_Ss(inf, flag, sstr);
//	}
	return (1);
}

int			ft_flag_Xx(va_list lst, char *format, t_flag *flag, t_inf *inf)
{
	int 		k;
	uintmax_t	i;
	char		*str;

	k = 0;
//	i = 0;
	i = va_arg(lst, uintmax_t);
	if (format[k] == 'x')
	{
		inf->x = 'x';
		i = (APPLY) ? (cast_uintmax(i, flag)) : (unsigned int)i;
		flag->ban = ft_strlen(ft_itoa_base_uintmax(i, 16, 'x'));
//		cancellation_flags_Uu(flag, inf);
		inf->uint_j += ft_strlen(ft_itoa_base_uintmax(i, 16, 'x'));
		if (LY)
			entry_minus_uint(inf);
		str = ft_itoa_base_uintmax(i, 16, 'x');
		cast_flag_Xx(inf, i, flag, str);
	}
	else if (format[k] == 'X')
	{
		i = (unsigned int)i;
		flag->ban = ft_strlen(ft_itoa_base_uintmax(i, 16, 'X'));
//		cancellation_flags_Uu(flag, inf);
		inf->uint_j += ft_strlen(ft_itoa_base_uintmax(i, 16, 'X'));
		if (LY)
			entry_minus_uint(inf);
		str = ft_itoa_base_uintmax(i, 16, 'X');
		cast_flag_Xx(inf, i, flag, str);
	}
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
		inf->uint_j = ft_count(i);
		cancellation_flags_Uu(flag, inf);
		if (LY)
			entry_minus_uint(inf);
		cast_flag_Uu(inf, i, flag, format);
	}
	else if (format[k] == 'U')
	{
		i = (unsigned long)i;
		inf->uint_j = ft_count(i);
		cancellation_flags_Uu(flag, inf);
		if (LY)
			entry_minus_uint(inf);
		cast_flag_Uu(inf, i, flag, format);
	}
	return (1);
}




int			ft_flag_Oo(va_list lst, char *format, t_flag *flag, t_inf *inf)
{
	int			k;
	uintmax_t	i;
	char		*str;

	k = 0;
	i = va_arg(lst, uintmax_t);
	if (format[k] == 'o')
	{
		i = (APPLY) ? (cast_uintmax(i, flag)) : (unsigned int)i;
		flag->ban = ft_strlen(ft_itoa_base_uintmax(i, 8, 'x'));
//		cancellation_flags_Oo(flag, inf);
		inf->uint_j += ft_strlen(ft_itoa_base_uintmax(i, 8, 'x'));
		if (LY)
			entry_minus_uint(inf);
		str = ft_itoa_base_uintmax(i, 8, 'x');
		cast_flag_Oo(inf, flag, str);
	}
	else if (format[k] == 'O')
	{
		i = (unsigned long)i;
		flag->ban = ft_strlen(ft_itoa_base_uintmax(i, 8, 'X'));
//		cancellation_flags_Oo(flag, inf);
		inf->uint_j += ft_strlen(ft_itoa_base_uintmax(i, 8, 'X'));
		if (LY)
			entry_minus_uint(inf);
		str = ft_itoa_base_uintmax(i, 8, 'X');
		cast_flag_Xx(inf, i, flag, str);
	}
	return (1);
}

int 		ft_flag_p(va_list lst, char *format, t_flag *flag, t_inf *inf)
{
	int 		k;
	uintmax_t	i;
	char		*str;

	k = 0;
	i = va_arg(lst, uintmax_t);
	if (format[k] == 'p')
	{
		flag->ban = ft_strlen(ft_itoa_base_uintmax(i, 16, 'x'));
		inf->uint_j += ft_strlen(ft_itoa_base_uintmax(i, 16, 'x'));
//		inf->uint_j += 2;
//		flag->ban += 2;
		if (LY)
			entry_minus_uint(inf);
		str = ft_itoa_base_uintmax(i, 16, 'x');
		cast_flag_p(inf, flag, str);
	}
	return (1);
}

