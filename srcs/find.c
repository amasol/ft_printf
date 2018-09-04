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
			{
				if (format[i] == 'd' || format[i] == 'i')
					ft_flag_di(lst, &format[i], flag, inf);
				else
					ft_flag_dd(lst, &format[i], flag, inf);
			}
			else if (ft_refinement(format[i]) == 2)
			{
				if (format[i] == 'c' || (*format == 'c' && flag->l == 1))
					ft_flag_c(lst, &format[i], flag, inf);
				else
				ft_flag_cc(lst, &format[i], flag, inf);
			}
			else if (ft_refinement(format[i]) == 3)
			{
				if (format[i] == 's' || (*format == 's' && flag->l == 1))
					ft_flag_s(lst, &format[i], flag, inf);
				else
					ft_flag_ss(lst, &format[i], flag, inf);
			}
			else if (ft_refinement(format[i]) == 4)
			{
				if (format[i] == 'x')
					ft_flag_x(lst, &format[i], flag, inf);
				else
					ft_flag_xx(lst, &format[i], flag, inf);
			}
			else if (ft_refinement(format[i]) == 5)
			{
				if (format[i] == 'o')
					ft_flag_o(lst, &format[i], flag, inf);
				else
					ft_flag_oo(lst, &format[i], flag, inf);
			}
			else if (ft_refinement(format[i]) == 6)
				ft_flag_u(lst, &format[i], flag, inf);
			else if (ft_refinement(format[i]) == 7)
				ft_flag_p(lst, &format[i], flag, inf);
			else if (format[i] == '%')
				pars_no_spec(&format[i], lst, flag, inf);
		}
//		i++;
	}
}


int			ft_flag_dd(va_list lst, char *format, t_flag *flag, t_inf *inf)
{
	int 			k;
	intmax_t 		j;

	k = 0;
	j = 0;
	if (format[k] == 'D')
	{
		if (flag->hh)
			j = (unsigned short)va_arg(lst, int);
		else
			j = va_arg(lst, long);
		min_v_di(j, flag, inf);
		cancellation_flags_di(flag, inf);
		if (LY)
			entry_min_intm(j, inf, flag);
		cast_flag_di(inf, j, flag, format);
	}
	return (1);
}

int			ft_flag_di(va_list lst, char *format, t_flag *flag, t_inf *inf)
{
	int 			k;
	intmax_t		i;

	k = 0;
	i = 0;
	if (format[k] == 'd' || format[k] == 'i')
	{
		i = va_arg(lst, intmax_t);
		i = (APPLY) ? (cast_intmax(i, flag, inf)) : (int)i;
		i = min_v_di(i, flag, inf);
		cancellation_flags_di(flag, inf);
		if (LY)
			entry_min_intm(i, inf, flag);
		cast_flag_di(inf, i, flag, format);
	}
	 return (1);
}

int			ft_flag_c(va_list lst, char *format, t_flag *flag, t_inf *inf)
{
	unsigned char	str;

	if (*format == 'c' || (*format == 'C' && MB_LEN_MAX == 1))
	{
		if (flag->l == 1)
		{
			ft_flag_cc(lst, format, flag, inf);
			return (1);
		}
		else if (*format == 'C' && MB_LEN_MAX == 1)
			str = va_arg(lst, unsigned int);
		else
			str = va_arg(lst, unsigned int);
		flag->ban = 1;
		inf->un_j += 1;
		cast_flag_c(inf, flag, str);
	}
	return (1);
}

 int			ft_flag_cc(va_list lst, char *format, t_flag *flag, t_inf *inf)
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
		 cast_flag_cc(inf, flag, c);
	 }
	 return (1);
 }

int			ft_flag_s(va_list lst, char *format, t_flag *flag, t_inf *inf)
{
	int i;
	char *str;

	i = 0;
	if (format[i] == 's' || (*format == 'S' && MB_LEN_MAX == 1))
	{
		if (flag->l == 1)
		{
			ft_flag_ss(lst, format, flag, inf);
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
		inf->un_j += ft_strlen(str);
		cast_flag_s(inf, flag, str);
	}
	return (1);
}

int		ft_flag_ss(va_list lst, char *format, t_flag *flag, t_inf *inf)
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
			cast_flag_ss(inf, flag, sstr);
			return (1);
		}
		cast_flag_ss(inf, flag, sstr);
	}
	return (1);
}

int			ft_flag_xx(va_list lst, char *format, t_flag *flag, t_inf *inf)
{
	int 		k;
	uintmax_t	i;
	char 		*tmp;

	k = 0;
	i = va_arg(lst, uintmax_t);
	if (format[k] == 'X')
	{
		inf->x = 'X';
		i = (APPLY) ? (cast_uintmax(i, flag, inf)) : (unsigned int)i;
		flag->ban = ft_strlen(tmp = ft_itoa_base_uintmax(i, 16, 'X'));
		free(tmp);
		inf->un_j += ft_strlen(tmp = ft_itoa_base_uintmax(i, 16, 'X'));
		free(tmp);
		if (LY)
			entry_min_uint(inf);
		tmp = ft_itoa_base_uintmax(i, 16, 'X');
		cast_flag_x(inf, i, flag, tmp);
		ft_strdel(&tmp);
	}
	return (1);
}


int			ft_flag_x(va_list lst, char *format, t_flag *flag, t_inf *inf)
{
	int 		k;
	uintmax_t	i;
	char 		*tmp;

	k = 0;
	i = va_arg(lst, uintmax_t);
	if (format[k] == 'x')
	{
		inf->x = 'x';
		i = (APPLY) ? (cast_uintmax(i, flag, inf)) : (unsigned int)i;
		flag->ban = ft_strlen((tmp = ft_itoa_base_uintmax(i, 16, 'x')));
		free(tmp);
		inf->un_j += ft_strlen(tmp =ft_itoa_base_uintmax(i, 16, 'x'));
		free(tmp);
		if (LY)
			entry_min_uint(inf);
		tmp = ft_itoa_base_uintmax(i, 16, 'x');
		cast_flag_x(inf, i, flag, tmp);
		ft_strdel(&tmp);
	}
	return (1);
}

int 		ft_flag_u(va_list lst, char *format, t_flag *flag, t_inf *inf)
{
	int			k;
	uintmax_t	i;

	k = 0;
	i = va_arg(lst, uintmax_t);
	if (format[k] == 'u')
	{
		i = (APPLY) ? (cast_uintmax(i, flag, inf)) : (unsigned int)i;
		flag->ban = ft_cou_uint(i);
		inf->un_j = ft_cou_uint(i);
		if (LY)
			entry_min_uint(inf);
		cast_flag_u(inf, i, flag);
	}
	else if (format[k] == 'U')
	{
		i = (unsigned long)i;
		inf->un_j = ft_cou_uint(i);
		if (LY)
			entry_min_uint(inf);
		cast_flag_u(inf, i, flag);
	}
	return (1);
}

int			ft_flag_oo(va_list lst, char *format, t_flag *flag, t_inf *inf)
{
	int			k;
	uintmax_t	i;
	char		*str;

	k = 0;
	i = va_arg(lst, uintmax_t);
	if (format[k] == 'O')
	{
		i = (unsigned long)i;
		flag->ban = ft_strlen(str = ft_itoa_base_uintmax(i, 8, 'X'));
		free(str);
		inf->un_j += ft_strlen(str = ft_itoa_base_uintmax(i, 8, 'X'));
		free(str);
		if (LY)
			entry_min_uint(inf);
		str = ft_itoa_base_uintmax(i, 8, 'X');
		cast_flag_x(inf, i, flag, str);
		ft_strdel(&str);
	}
	return (1);
}

int			ft_flag_o(va_list lst, char *format, t_flag *flag, t_inf *inf)
{
	int			k;
	uintmax_t	i;
	char		*str;

	k = 0;
	i = va_arg(lst, uintmax_t);
	if (format[k] == 'o')
	{
		i = (APPLY) ? (cast_uintmax(i, flag, inf)) : (unsigned int)i;
		flag->ban = ft_strlen(str = ft_itoa_base_uintmax(i, 8, 'x'));
		free(str);
		inf->un_j += ft_strlen(str = ft_itoa_base_uintmax(i, 8, 'x'));
		free(str);
		if (LY)
			entry_min_uint(inf);
		str = ft_itoa_base_uintmax(i, 8, 'x');
		cast_flag_o(inf, i, flag, str);
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
		inf->un_j += ft_strlen(str = ft_itoa_base_uintmax(i, 16, 'x'));
		free(str);
		if (LY)
			entry_min_uint(inf);
		str = ft_itoa_base_uintmax(i, 16, 'x');
		cast_flag_p(inf, i, flag, str);
		free(str);
	}
	return (1);
}

