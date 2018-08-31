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
			{
				if (format[i] == 'c' || (*format == 'c' && flag->l == 1))
					ft_flag_c(lst, &format[i], flag, inf);
				else
				ft_flag_C(lst, &format[i], flag, inf);
			}
			else if (ft_refinement(format[i]) == 3)
			{
				if (format[i] == 's' || (*format == 's' && flag->l == 1))
					ft_flag_s(lst, &format[i], flag, inf);
				else
					ft_flag_S(lst, &format[i], flag, inf);
			}
			else if (ft_refinement(format[i]) == 4)
				ft_flag_Xx(lst, &format[i], flag, inf);
			else if (ft_refinement(format[i]) == 5)
				ft_flag_Oo(lst, &format[i], flag, inf);
			else if (ft_refinement(format[i]) == 6)
				ft_flag_Uu(lst, &format[i], flag, inf);
			else if (ft_refinement(format[i]) == 7)
				ft_flag_p(lst, &format[i], flag, inf);
			else if (format[i] == '%')
				pars_no_spec(&format[i], lst, flag, inf);
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
	int 			k;
	intmax_t 	j;
//	unsigned short 	j;
	intmax_t		i;

	j = 0;
	k = 0;
	i = 0;
	if (format[k] == 'd' || format[k] == 'i')
	{
		i = va_arg(lst, intmax_t);
		i = (APPLY) ? (cast_intmax(i, flag, inf)) : (int)i;
		i = minus_value_Ddi(i, flag, inf);
		cancellation_flags_Ddi(flag, inf);
		if (LY)
			entry_minus_intm(i, inf, flag);
		cast_flag_Ddi(inf, i, flag, format);
	}
	if (format[k] == 'D')
	{
		if (flag->hh)
			j = (unsigned short)va_arg(lst, int);
		else
		{
//			j = (intmax_t)va_arg(lst, long);
			j = va_arg(lst, long);
//			j = (APPLY) ? (cast_uintmax(j, flag)) : (long)j;
		}
		minus_value_Ddi(j, flag, inf);
		cancellation_flags_Ddi(flag, inf);
		if (LY)
			entry_minus_intm(j, inf, flag);
		cast_flag_Ddi(inf, j, flag, format);
	}
//	flag->ban = 1;
	 return (1);
}

//(С) рассматриваеться как (с) с подификатором (l)
int			ft_flag_c(va_list lst, char *format, t_flag *flag, t_inf *inf)
{
	unsigned char	str;
//	wchar_t			c;

	if (*format == 'c' || (*format == 'C' && MB_LEN_MAX == 1))
	{
		if (flag->l == 1)
		{
			ft_flag_C(lst, format, flag, inf);
			return (1);
		}
		else if (*format == 'C' && MB_LEN_MAX == 1)
			str = va_arg(lst, unsigned int);
//			c = va_arg(lst, wchar_t);
		else
			str = va_arg(lst, unsigned int);
		flag->ban = 1;
		inf->uint_j += 1;
		cast_flag_c(inf, flag, str);
	}
	return (1);
}

//	придумать как сделать если нету локали но есть юникод, вызвать снова (с)!
//	if (*format == 'C' && MB_LEN_MAX == 1)
//		;

//ft_flag_c(lst, &format[i], flag, inf);
 int			ft_flag_C(va_list lst, char *format, t_flag *flag, t_inf *inf)
 {
	 wchar_t c;

	 if (*format == 'C' && MB_LEN_MAX == 1)
	 {
		 ft_flag_c(lst, format, flag, inf);
		 return (1);
	 }
	 else if (*format == 'C' || (*format == 'c' && flag->l == 1))
	 {
		 c = va_arg(lst, wchar_t);
		 cast_flag_C(inf, flag, c);
	 }
	 return (1);
 }

int			ft_flag_s(va_list lst, char *format, t_flag *flag, t_inf *inf)
{
	int i;
	char *str;
//	wchar_t	*sstr;

	i = 0;
	if (format[i] == 's' || (*format == 'S' && MB_LEN_MAX == 1))
	{
		if (flag->l == 1)
		{
			ft_flag_S(lst, format, flag, inf);
			return (1);
		}
		else if (*format == 'S' && MB_LEN_MAX == 1)
			str = va_arg(lst, char *);
		else
			str = va_arg(lst, char *);
		if (str == NULL)
		{
			cast_flag_s(inf, flag, str);
			return (1);
		}
		flag->ban = ft_strlen(str);
		inf->uint_j += ft_strlen(str);
		cast_flag_s(inf, flag, str);
	}
	return (1);
}

int		ft_flag_S(va_list lst, char *format, t_flag *flag, t_inf *inf)
	{
		wchar_t		*sstr;

		if (*format == 'S' && MB_LEN_MAX == 1)
		{
			ft_flag_s(lst, format, flag, inf);
			return (1);
		}
		else if (*format == 'S' || (*format == 's' && flag->l == 1))
		{
			sstr = va_arg(lst, wchar_t *);
			if (sstr == NULL)
			{
				cast_flag_S(inf, flag, sstr);
				return (1);
			}
//			flag->ban = ft_strlen((char *)sstr);
//			inf->uint_j += ft_strlen((char *)sstr);
			cast_flag_S(inf, flag, sstr);
		}
		return (1);
	}

int			ft_flag_Xx(va_list lst, char *format, t_flag *flag, t_inf *inf)
{
	int 		k;
	uintmax_t	i;
//	char		*str;
	char 		*tmp;

	k = 0;
//	i = 0;
	i = va_arg(lst, uintmax_t);
	if (format[k] == 'x')
	{
		inf->x = 'x';
		i = (APPLY) ? (cast_uintmax(i, flag, inf)) : (unsigned int)i;
		flag->ban = ft_strlen((tmp = ft_itoa_base_uintmax(i, 16, 'x')));
		free(tmp);
		inf->uint_j += ft_strlen(tmp =ft_itoa_base_uintmax(i, 16, 'x'));
		free(tmp);
		if (LY)
			entry_minus_uint(inf);
		tmp = ft_itoa_base_uintmax(i, 16, 'x');
		cast_flag_Xx(inf, i, flag, tmp);
		ft_strdel(&tmp);
//		system("leaks a.out");
//		system("leaks a.out");
//		exit (1);
	}
	else if (format[k] == 'X')
	{
		inf->x = 'X';
		i = (APPLY) ? (cast_uintmax(i, flag, inf)) : (unsigned int)i;
		flag->ban = ft_strlen(tmp = ft_itoa_base_uintmax(i, 16, 'X'));
		free(tmp);
		inf->uint_j += ft_strlen(tmp = ft_itoa_base_uintmax(i, 16, 'X'));
		free(tmp);
		if (LY)
			entry_minus_uint(inf);
		tmp = ft_itoa_base_uintmax(i, 16, 'X');
		cast_flag_Xx(inf, i, flag, tmp);
		ft_strdel(&tmp);
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
		i = (APPLY) ? (cast_uintmax(i, flag, inf)) : (unsigned int)i;
		flag->ban = ft_count_uint(i);
		inf->uint_j = ft_count_uint(i);
		cancellation_flags_Uu(flag, inf);
		if (LY)
			entry_minus_uint(inf);
		cast_flag_Uu(inf, i, flag, format);
	}
	else if (format[k] == 'U')
	{
		i = (unsigned long)i;
		inf->uint_j = ft_count_uint(i);
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
//	char 		*tmp;

	k = 0;
	i = va_arg(lst, uintmax_t);
	if (format[k] == 'o')
	{
		i = (APPLY) ? (cast_uintmax(i, flag, inf)) : (unsigned int)i;
		flag->ban = ft_strlen(str = ft_itoa_base_uintmax(i, 8, 'x'));
		free(str);
//		cancellation_flags_Oo(flag, inf);
		inf->uint_j += ft_strlen(str = ft_itoa_base_uintmax(i, 8, 'x'));
		free(str);
		if (LY)
			entry_minus_uint(inf);
		str = ft_itoa_base_uintmax(i, 8, 'x');
		cast_flag_Oo(inf, i, flag, str);
		ft_strdel(&str);
	}
	else if (format[k] == 'O')
	{
		i = (unsigned long)i;
		flag->ban = ft_strlen(str = ft_itoa_base_uintmax(i, 8, 'X'));
		free(str);
//		cancellation_flags_Oo(flag, inf);
		inf->uint_j += ft_strlen(str = ft_itoa_base_uintmax(i, 8, 'X'));
		free(str);
		if (LY)
			entry_minus_uint(inf);
		str = ft_itoa_base_uintmax(i, 8, 'X');
		cast_flag_Xx(inf, i, flag, str);
		ft_strdel(&str);
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
		flag->ban = ft_strlen(str = ft_itoa_base_uintmax(i, 16, 'x'));
		free(str);
		inf->uint_j += ft_strlen(str = ft_itoa_base_uintmax(i, 16, 'x'));
		free(str);
//		inf->uint_j += 2;
//		flag->ban += 2;
		if (LY)
			entry_minus_uint(inf);
		str = ft_itoa_base_uintmax(i, 16, 'x');
		cast_flag_p(inf, i, flag, str);
		free(str);
	}
	return (1);
}

