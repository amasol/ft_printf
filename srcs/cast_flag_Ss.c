/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_flag_Ss.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 17:12:50 by amasol            #+#    #+#             */
/*   Updated: 2018/07/16 17:12:52 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		cast_flag_Ss(t_inf *inf, t_flag *flag, char *str)
{
	// флаг -
	char *tmp;
	inf->count = (inf->uint_j > (uintmax_t)inf->width) ? inf->uint_j : inf->width - inf->uint_j;
	if (inf->width_two > inf->width)
		inf->count_two = (inf->width_two > inf->width) ? inf->width_two - inf->width : 0;
	else if ((uintmax_t)inf->width_two > inf->uint_j)
		inf->count_two = ((uintmax_t)inf->width_two > inf->uint_j) ? inf->width_two - inf->uint_j : 0;


	if (str == NULL)
	{
		inf->width = (inf->width == 6 || inf->width > 6) ? 6 : inf->width;
		if (flag->width == 1 && inf->width)
		{
			inf->result += write(1, "(null)", inf->width);
			inf->width--;
		}
		else
			inf->result += write(1, "(null)", 6);
	}


	else if (inf->count > 0 && flag->minus == 1 && flag->precision == 0 && inf->width == 0)
	{
		if (flag->space == 1)
			inf->result += write(1, " ", 1);
		tmp = ft_strsub(str, 0, inf->count);
		inf->result += ft_strlen_uintmax(tmp);
		ft_putstr(tmp);
		ft_strdel(&tmp);
	}

//		флан zero
	else if (flag->zero == 1)
	{
		while (inf->count > 0)
		{
			inf->result += write(1, "0", 1);
			inf->count--;
		}
		tmp = ft_strsub(str, 0, inf->width);
		inf->result += ft_strlen_uintmax(tmp);
		ft_putstr(tmp);
		ft_strdel(&tmp);
		while (inf->count_two > 0)
		{
			inf->result += write(1, " ", 1);
			inf->count_two--;
		}
	}
		// 		флаг	 ширины
	else if (inf->count >= 0 && flag->width == 1 && flag->precision == 0 &&
			 flag->minus != 1 && inf->minus_value != 1 && inf->nothing == 1)
	{
		while (inf->count > 0)
		{
			inf->result += write(1, " ", 1);
			inf->count--;
		}
		tmp = ft_strsub(str, 0, inf->width);
		inf->result += ft_strlen_uintmax(tmp);
		ft_putstr(tmp);
		ft_strdel(&tmp);
	}
		//	флаг	 ширины и флаг minus
	else if (flag->width == 1 && flag->precision == 0 &&
			 inf->width > 0 && (flag->minus == 1) && flag->h == 0)
	{
//		if (flag->space == 1)
//			inf->count = inf->count + 1;
//		if (flag->space == 1)
//			inf->result += write(1, " ", 1);
		tmp = ft_strsub(str, 0, inf->width);
		inf->result += ft_strlen_uintmax(tmp);
		ft_putstr(tmp);
		ft_strdel(&tmp);
		if (flag->minus == 1 && flag->ban < inf->width && inf->tmp == 1)
			inf->result += write(1, " ", 1);
//		while (inf->count > 0 && flag->space != 1)
		while (inf->count > 0)
		{
			inf->result += write(1, " ", 1);
			inf->count--;
		}
	}
		//	флаг	 ширины + модификаторы и флаг minus
	else if (inf->count >= 0 && flag->width == 1 && flag->precision == 0 &&
			 inf->minus_value == 1 && flag->h == 1)
	{
		if (flag->space == 1)
			inf->count = inf->count + 1;
		if (flag->space == 1)
			inf->result += write(1, " ", 1);
		while (inf->count > 0 && flag->space != 1)
		{
			inf->result += write(1, " ", 1);
			inf->count--;
		}
		tmp = ft_strsub(str, 0, inf->width);
		inf->result += ft_strlen_uintmax(tmp);
		ft_putstr(tmp);
		ft_strdel(&tmp);
	}
		// 		флаг	 ширины + когда аргумент по кол-ву с оденаковый с шириной !
	else if (inf->count == 0 && flag->width == 1 && flag->precision == 0 )
	{
		if (inf->count == 1 && flag->plus == 1)
			inf->count -= 1;
		if (flag->space == 1)
			inf->count = inf->count + 1;
		tmp = ft_strsub(str, 0, inf->width);
		inf->result += ft_strlen_uintmax(tmp);
		ft_putstr(tmp);
		ft_strdel(&tmp);
		while (inf->count_two > 0 && inf->count == 0)
		{
			inf->result += write(1, " ", 1);
			inf->count_two--;
		}
	}

	else if ((flag->zero == 0 || flag->minus == 0) && flag->plus == 1 && flag->precision == 0 &&
			 inf->width == 0)
	{
		if (inf->width == 0 && inf->count > 0)
		{
			inf->result += ft_strlen_uintmax(str);
			ft_putstr(str);
		}
		tmp = ft_strsub(str, 0, inf->width);
		inf->result += ft_strlen_uintmax(tmp);
		ft_putstr(tmp);
		ft_strdel(&tmp);
	}


	else if (flag->space == 1 && flag->precision != 1)
	{
//		inf->result += write(1, " ", 1);
//		write(1, " ", 1);
//		str = ft_strsub(str, 0, inf->width);
		inf->result += ft_strlen_uintmax(str);
		ft_putstr(str);
//		ft_strdel(&str);
	}


	else if (flag->precision == 1 && inf->count > 0 && inf->count_two == 0 && *str == '\0')
	{
		if ((flag->plus == 1) && flag->minus == 0 && (inf->width < inf->width_two))
			inf->result += write(1, " ", 1);
		while (inf->count_two > 0)
		{
			inf->result += write(1, " ", 1);
			inf->count_two--;
		}
		tmp = ft_strsub(str, 0, inf->width);
		inf->result += ft_strlen_uintmax(tmp);
		ft_putstr(tmp);
		ft_strdel(&tmp);
	}


//		точность (.)
	else if (flag->precision == 1 && inf->count > 0 && inf->count_two == 0
			 && flag->minus != 1  && inf->nothing == 1)
	{
		if ((flag->plus == 1) && flag->minus == 0 && (inf->width < inf->width_two))
			inf->result += write(1, " ", 1);
		while (inf->count_two > 0)
		{
			inf->result += write(1, " ", 1);
			inf->count_two--;
		}
		tmp = ft_strsub(str, 0, inf->width);
		inf->result += ft_strlen_uintmax(tmp);
		ft_putstr(tmp);
		ft_strdel(&tmp);
	}


		//		точность (ширина + точность когда ширина больше точности!)
	else if (flag->precision == 1 && inf->count_two >= inf->count
			 && flag->minus == 0 && inf->nothing == 1)
	{
		inf->width_two = (inf->width > inf->uint_j) ? inf->width_two - inf->uint_j : inf->width_two;
		inf->width_two = (inf->width < inf->uint_j) ? inf->width_two - inf->width : inf->width_two;
		while (inf->width_two > 0)
		{
			inf->result += write(1, " ", 1);
			inf->width_two--;
		}
//		while (inf->count > 0 && *str == '\0')
//		{
//			inf->result += write(1, " ", 1);
//			inf->count--;
//		}
		tmp = ft_strsub(str, 0, inf->width);
		inf->result += ft_strlen_uintmax(tmp);
		ft_putstr(tmp);
		ft_strdel(&tmp);
	}




//		точность (ширина + точность)
	else if (flag->precision == 1 && inf->count >= 0 && inf->count_two >= 0
			 && flag->minus == 0 && inf->nothing == 1)
	{
		inf->count_two = (inf->minus_value == 1) ? inf->count_two -= 1 : inf->count_two;
		inf->count_two = (inf->width_two > inf->uint_j)
				? inf->width_two - inf->uint_j : inf->count_two;
		while (inf->count_two > 0)
		{
			inf->result += write(1, " ", 1);
			inf->count_two--;
		}
		while (inf->count > 0 && *str == '\0')
		{
			inf->result += write(1, " ", 1);
			inf->count--;
		}
		tmp = ft_strsub(str, 0, inf->width);
		inf->result += ft_strlen_uintmax(tmp);
		ft_putstr(tmp);
		ft_strdel(&tmp);
	}

		//		точность (ширина точность и флаг минут)
	else if (flag->precision == 1 && flag->minus == 1 && inf->count >= 0 &&
			 inf->count_two >= 0)
	{
		tmp = ft_strsub(str, 0, inf->width);
		inf->result += ft_strlen_uintmax(tmp);
		ft_putstr(tmp);
//		ft_strdel(&tmp);
		while (inf->count > 0 && flag->minus == 1 && *str == '\0')
		{
			inf->result += write(1, " ", 1);
			inf->count--;
		}
		while (inf->count_two > 0 && flag->minus == 1)
		{
			inf->result += write(1, " ", 1);
			inf->count_two--;
		}
		ft_strdel(&tmp);
	}
	else if (flag->precision == 1 && inf->count == 0 && inf->count_two > 0)
	{
		while (inf->count > 0)
		{
			inf->result += write(1, "0", 1);
			inf->count--;
		}
		while (inf->count_two > 0)
		{
			inf->result += write(1, " ", 1);
			inf->count_two--;
		}
		tmp = ft_strsub(str, 0, inf->width);
		inf->result += ft_strlen_uintmax(tmp);
		ft_putstr(tmp);
		ft_strdel(&tmp);
	}
	else if (flag->precision == 1 && flag->plus == 1)
	{
		while (inf->count > 0)
		{
			inf->result += write(1, " ", 1);
			inf->count--;
		}
		tmp = ft_strsub(str, 0, inf->width);
		inf->result += ft_strlen_uintmax(tmp);
		ft_putstr(tmp);
		ft_strdel(&tmp);
	}

//	else if (flag->plus == 0 && flag->slash == 0 && flag->space == 0
//			 && flag->zero == 0 && flag->width == 0 && flag->precision == 0)
	else if (inf->nothing == 0)
	{
//		str = ft_strsub(str, 0, inf->width);
		inf->result += ft_strlen_uintmax(str);
		ft_putstr(str);
//		ft_strdel(&str);
	}
}

