/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_flag_Ddi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 17:12:40 by amasol            #+#    #+#             */
/*   Updated: 2018/07/16 17:12:41 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		cast_flag_Ddi(t_inf *inf, intmax_t i, t_flag *flag, char *str)
{
	// флаг -
	if (/*inf->count > 0 && */flag->minus == 1 && flag->precision == 0)
	{
//		if (inf->minus_value == 1)
//			write(1, "-", 1);
		if (flag->space == 1)
			write(1, " ", 1);
		if (flag->plus == 1 || inf->tmp == 1)
			write(1, "+", 1);
		ft_putnbr_intmax(i);
		while (inf->count > 0 && (!(inf->width == 1 && i == 1)))
		{
			write(1, " ", 1);
			inf->count--;
		}
	}

//		флан zero
//	else if (((inf->count > 0 && flag->zero == 1) ||
// 			(flag->minus == 1 && flag->precision == 1)) &&
//			inf->width_two == 0)
	else if (flag->zero == 1)
	{
		if (flag->space == 1)
			write(1, " ", 1);
		if (flag->plus == 1 || inf->tmp == 1)
			write(1, "+", 1);
		while (inf->count > 0)
		{
			write(1, "0", 1);
			inf->count--;
		}
		ft_putnbr_intmax(i);
	}

		// 		флаг	 ширины (99)
	else if ((inf->count > 0 && flag->width == 1 && flag->precision == 0) ||
			((inf->count > 0 && flag->width == 1 && flag->precision == 1 && inf->width_two > 0)))
	{
		if (flag->space == 1)
			inf->count = inf->count + 1;
		while (inf->count > 0)
		{
			write(1, " ", 1);
			inf->count--;
		}
		if (flag->plus == 1 || inf->tmp == 1)
			write(1, "+", 1);
		if (inf->minus_value == 1)
			write(1, "-", 1);
		ft_putnbr_intmax(i);
	}
		// 		флаг	 ширины + когда аргумент по кол-ву с оденаковый с шириной !
	else if (inf->count == 0 && flag->width == 1 && flag->precision == 0)
	{
		if (flag->space == 1)
			inf->count = inf->count + 1;
		ft_putnbr_intmax(i);
	}
	else if ((flag->zero == 0 || flag->minus == 0) && flag->plus == 1 && flag->precision == 0 &&
			 inf->width == 0)
	{
		if (flag->plus == 1 || inf->tmp == 1)
			write(1, "+", 1);
		ft_putnbr_intmax(i);
	}


	else if (flag->space == 1 && flag->precision != 1)
	{
		write(1, " ", 1);
		ft_putnbr_intmax(i);
	}

//		точность (.)
	else if (flag->precision == 1 && inf->count > 0 && inf->count_two == 0)
	{
		if (inf->minus_value == 1 && flag->minus == 0)
			write(1, "-", 1);
		if (flag->plus == 1 || inf->tmp == 1)
			write(1, "+", 1);
		while (inf->count > 0)
		{
			write(1, "0", 1);
			inf->count--;
		}
		ft_putnbr_intmax(i);
	}
//		точность (ширина + точность )
	else if (flag->precision == 1 && flag->plus == 1 && inf->count > 0 &&
			 inf->count_two > 0)
	{
		while (inf->count_two > 0)
		{
			write(1, " ", 1);
			inf->count_two--;
		}
		if (flag->plus == 1 || inf->tmp == 1)
			write(1, "+", 1);
		while (inf->count > 0)
		{
			write(1, "0", 1);
			inf->count--;
		}
		ft_putnbr_intmax(i);
	}
//		точность (ширина - точность )
	else if (flag->precision == 1 && flag->minus == 1 && inf->count > 0 &&
			 inf->count_two > 0)
	{
		if (flag->plus == 1 || inf->tmp == 1)
			write(1, "+", 1);
		while (inf->count > 0)
		{
			write(1, "0", 1);
			inf->count--;
		}
		ft_putnbr_intmax(i);
		while (inf->count_two > 0)
		{
			write(1, " ", 1);
			inf->count_two--;
		}
	}
	else if (flag->slash == 1)
	{
		if (*str == 'X')
			write(1, "0X", 2);
		if (*str == 'x')
			write(1, "0x", 2);
		if (*str == 'o' || *str == 'O')
			write(1, "0", 1);
	}


	else if (flag->precision == 1 && flag->width == 1 && inf->count > 0 && inf->count_two > 0)
	{
//		inf->width = inf->width - inf->width_two;
		while (inf->count_two > 0)
		{
			write(1, " ", 1);
			inf->count_two--;
		}
		while (inf->count > 0)
		{
			write(1, "0", 1);
			inf->count--;
		}
		ft_putnbr_intmax(i);
	}


	else if (flag->precision == 1 && flag->plus == 1)
	{
		while (inf->count > 0)
		{
			write(1, " ", 1);
			inf->count--;
		}
		if (flag->plus == 1 || inf->tmp == 1)
			write(1, "+", 1);
		ft_putnbr_intmax(i);
	}
		// не правильно работает если у нас нету флагов и мы должны вывести остачу || у нас
//		есть флаг и мы должны вывести остачу послу отработки тут !!!

	else if (flag->plus == 0 && flag->minus == 0 && flag->slash == 0 && flag->space == 0
			 && flag->zero == 0 && flag->width == 0 && flag->precision == 0)
		ft_putnbr_intmax(i);
}

void				cancellation_flags_Ddi(t_flag *flag, t_inf *inf)
{
	// доделать и проверить со всеми флагами !
	if (flag->minus == 1 && flag->plus == 1)
	{
		inf->tmp = flag->plus;
		flag->plus = 0;
	}
	if ((flag->plus == 1 || inf->tmp == 1) && flag->space == 1)
		flag->space = 0;
	if ((flag->minus == 1 || flag->precision == 1) && flag->zero == 1)
		flag->zero = 0;
}

intmax_t 			minus_value_Ddi(intmax_t i, t_flag *flag, t_inf *inf)
{
	if (i < 0 && flag->minus == 0)
	{
		inf->minus_value = 1;
		i *= -1;
	}
	return (i);
}