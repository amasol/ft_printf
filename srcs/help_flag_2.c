/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_flag_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:34:23 by amasol            #+#    #+#             */
/*   Updated: 2018/09/04 15:34:24 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
	int		i;
	char	*str;

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

int			ft_flag_ss(va_list lst, char *format, t_flag *flag, t_inf *inf)
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
	int			k;
	uintmax_t	i;
	char		*tmp;

	k = 0;
	i = va_arg(lst, uintmax_t);
	if (format[k] == 'X')
	{
		inf->x = 'X';
		i = (APPLY) ? (cast_uintmax(i, flag, inf)) : (unsigned int)i;
		tmp = ft_itoa_base_uintmax(i, 16, 'X');
		flag->ban = ft_strlen(tmp);
		inf->un_j += ft_strlen(tmp);
		free(tmp);
		if (LY)
			entry_min_uint(inf);
		tmp = ft_itoa_base_uintmax(i, 16, 'X');
		cast_flag_x(inf, i, flag, tmp);
		ft_strdel(&tmp);
	}
	return (1);
}
