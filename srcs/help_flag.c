/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:07:05 by amasol            #+#    #+#             */
/*   Updated: 2018/09/04 15:07:06 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_flag_x(va_list lst, char *format, t_flag *flag, t_inf *inf)
{
	int			k;
	uintmax_t	i;
	char		*tmp;

	k = 0;
	i = va_arg(lst, uintmax_t);
	if (format[k] == 'x')
	{
		inf->x = 'x';
		i = (APPLY) ? (cast_uintmax(i, flag, inf)) : (unsigned int)i;
		tmp = ft_itoa_base_uintmax(i, 16, 'x');
		flag->ban = ft_strlen(tmp);
		inf->un_j += ft_strlen(tmp);
		free(tmp);
		if (LY)
			entry_min_uint(inf);
		tmp = ft_itoa_base_uintmax(i, 16, 'x');
		cast_flag_x(inf, i, flag, tmp);
		ft_strdel(&tmp);
	}
	return (1);
}

int			ft_flag_u(va_list lst, char *format, t_flag *flag, t_inf *inf)
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
		str = ft_itoa_base_uintmax(i, 8, 'X');
		flag->ban = ft_strlen(str);
		inf->un_j += ft_strlen(str);
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
		str = ft_itoa_base_uintmax(i, 8, 'x');
		flag->ban = ft_strlen(str);
		inf->un_j += ft_strlen(str);
		free(str);
		if (LY)
			entry_min_uint(inf);
		str = ft_itoa_base_uintmax(i, 8, 'x');
		cast_flag_o(inf, i, flag, str);
		ft_strdel(&str);
	}
	return (1);
}

int			ft_flag_p(va_list lst, char *format, t_flag *flag, t_inf *inf)
{
	int			k;
	uintmax_t	i;
	char		*str;

	k = 0;
	i = va_arg(lst, uintmax_t);
	if (format[k] == 'p')
	{
		str = ft_itoa_base_uintmax(i, 16, 'x');
		flag->ban = ft_strlen(str);
		inf->un_j += ft_strlen(str);
		free(str);
		if (LY)
			entry_min_uint(inf);
		str = ft_itoa_base_uintmax(i, 16, 'x');
		cast_flag_p(inf, i, flag, str);
		free(str);
	}
	return (1);
}
