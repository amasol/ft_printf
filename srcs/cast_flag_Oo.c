/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_flag_Oo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 17:13:37 by amasol            #+#    #+#             */
/*   Updated: 2018/07/16 17:13:38 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		cast_flag_Oo(t_inf *inf, uintmax_t i, t_flag *flag, char *str)
{
	// флаг -
	if (flag->ban > 0 && flag->plus == 1 && flag->minus != 1)
		flag->ban -= 1;
	if (inf->count > 0 && flag->minus == 1 && flag->precision == 0 && inf->width == 0)
	{
		if (flag->space == 1)
			inf->result += write(1, " ", 1);
		inf->result += ft_strlen_uintmax(str);
		ft_putstr(str);
		while (inf->count > 0)
		{
			inf->result += write(1, " ", 1);
			inf->count--;
		}
	}

	else if (flag->slash == 1)
	{
		inf->count -= 1;
		while (inf->count > 0 && flag->minus != 1)
		{
			inf->result += write(1, " ", 1);
			inf->count--;
		}
		while (inf->count_two > 0)
		{
			inf->result += write(1, " ", 1);
			inf->count_two--;
		}
		inf->result += write(1, "0", 1);
		inf->result += (i != 0) ? ft_strlen_uintmax(str) : 0;
		ft_putstr(str = (i == 0) ? 0 : str);
		while (inf->count > 0 && flag->minus == 1)
		{
			inf->result += write(1, " ", 1);
			inf->count--;
		}
	}


	else if (flag->precision == 1 && flag->plus == 1)
	{
		while (inf->count > 0)
		{
			inf->result += write(1, " ", 1);
			inf->count--;
		}
		inf->result += ft_strlen_uintmax(str);
		ft_putstr(str);
	}

//		флан zero
	else if (flag->zero == 1 && flag->minus != 1 && flag->slash != 1)
	{
		while (inf->count > 0/* && i != 0*/)
		{
			inf->result += write(1, "0", 1);
			inf->count--;
		}
//		inf->result += ft_strlen_uintmax(str);
		inf->result += (i != 0) ? ft_strlen_uintmax(str) : 0;
//		ft_putstr(str);
		ft_putstr(str = (i == 0) ? 0 : str);
		while (inf->count_two > 0)
		{
			inf->result += write(1, " ", 1);
			inf->count_two--;
		}
	}
		// 		флаг	 ширины
	else if (inf->count >= 0 && flag->width == 1 && flag->precision == 0 &&
			 flag->minus != 1 && inf->minus_value != 1)
	{
		if (flag->slash == 1)
			inf->count -= 1;
		while (inf->count > 0)
		{
			inf->result += write(1, " ", 1);
			inf->count--;
		}
		if (flag->slash == 1)
			inf->result += write(1, "0", 1);
		inf->result += ft_strlen_uintmax(str);
		ft_putstr(str);
	}
		//	флаг	 ширины и флаг minus
	else if (flag->width == 1 && flag->precision == 0 &&
			 inf->width > 0 && (flag->minus == 1) && flag->h == 0)
	{
		inf->count = (flag->plus == 1 && flag->ban != inf->width && flag->minus != 1) ? inf->count + 1 : inf->count;
		if (flag->slash == 1)
		{
			inf->result += write(1, "0", 1);
			inf->count -= 1;
		}
		if (flag->space == 1)
			inf->count = inf->count + 1;
		if (flag->space == 1)
			inf->result += write(1, " ", 1);
		inf->result += ft_strlen_uintmax(str);
		ft_putstr(str);
		if (flag->minus == 1 && flag->ban < inf->width && inf->tmp == 1)
			inf->result += write(1, " ", 1);
		while (inf->count > 0 && flag->space != 1)
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
		inf->result += ft_strlen_uintmax(str);
		ft_putstr(str);
	}
		// 		флаг	 ширины + когда аргумент по кол-ву с оденаковый с шириной !
	else if (inf->count == 0 && flag->width == 1 && flag->precision == 0 )
	{
		if (inf->count == 1 && flag->plus == 1)
			inf->count -= 1;
		if (flag->space == 1)
			inf->count = inf->count + 1;
		inf->result += ft_strlen_uintmax(str);
		ft_putstr(str);
		while (inf->count_two > 0 && inf->count == 0)
		{
			inf->result += write(1, " ", 1);
			inf->count_two--;
		}
	}

	else if ((flag->zero == 0 || flag->minus == 0) && flag->plus == 1 && flag->precision == 0 &&
			 inf->width == 0)
	{
		inf->result += ft_strlen_uintmax(str);
		ft_putstr(str);
	}


//	else if (flag->space == 1 && flag->precision != 1 && inf->nothing == 1)
//	{
//		inf->result += write(1, " ", 1);
//		inf->result += ft_strlen_uintmax(str);
//		ft_putstr(str);
//	}



//		точность (.)
	else if (flag->precision == 1 && inf->count > 0 && inf->count_two == 0 && flag->minus != 1 )
	{
		if ((flag->plus == 1) && flag->minus == 0 && (inf->width < inf->width_two))
			inf->result += write(1, " ", 1);
		while (inf->count > 0)
		{
			inf->result += (i != 0) ? write(1, "0", 1) : write(1, " ", 1);
//			inf->result += write(1, "0", 1);
			inf->count--;
		}
		inf->result += ft_strlen_uintmax(str);
		ft_putstr(str = (i == 0) ? " " : str);
//		ft_putstr(str);
//		if (flag->minus == 1)
//			inf->result += write(1, " ", 1);
	}


//		точность (ширина + точность)
	else if (flag->precision == 1 && inf->count >= 0 && inf->count_two >= 0 && flag->minus == 0)
	{
		inf->count_two = (inf->minus_value == 1) ? inf->count_two -= 1 : inf->count_two;
		if (flag->slash == 1 && inf->count_two > inf->count)
			inf->count_two -= 1;
		while (inf->count_two > 0 && i != 0)
		{
			inf->result += write(1, " ", 1);
			inf->count_two--;
		}
		while (i == 0 && inf->width_two > 0)
		{
			inf->result += write(1, " ", 1);
			inf->width_two--;
		}
		while (inf->count > 0)
		{
			inf->result += write(1, "0", 1);
			inf->count--;
		}
//		if (flag->slash == 1 && i == 0)
//			inf->result += write(1, "0", 1);
		if (flag->slash == 1 && (uintmax_t)inf->count_two < inf->uint_j)
			inf->result += write(1, "0", 1);
		inf->result += (i != 0) ? ft_strlen_uintmax(str) : 0;
		ft_putstr(str = (i == 0) ? 0 : str);
	}

		//		точность (ширина точность и флаг минут)
	else if (flag->precision == 1 && flag->minus == 1 && inf->count >= 0 &&
			 inf->count_two >= 0)
	{
//		if ((flag->plus == 1 || inf->tmp == 1) && inf->minus_value != 1)
//			inf->result += write(1, "+", 1);
		while (inf->count > 0)
		{
			inf->result += write(1, "0", 1);
			inf->count--;
		}
		inf->result += ft_strlen_uintmax(str);
		ft_putstr(str);
//		while (inf->count_two + 1 > 0)

//		if (flag->minus == 1 && flag->ban > inf->width)
//			inf->result += write(1, " ", 1);
		while (inf->count_two > 0)
		{
			inf->result += write(1, " ", 1);
			inf->count_two--;
		}
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
//		if (flag->plus == 1 || inf->tmp == 1)
//			inf->result += write(1, "+", 1);
		inf->result += ft_strlen_uintmax(str);
		ft_putstr(str);
	}

		// не правильно работает если у нас нету флагов и мы должны вывести остачу || у нас
//		есть флаг и мы должны вывести остачу послу отработки тут !!!

	else if (flag->plus == 0 && flag->slash == 0
			&& flag->zero == 0 && flag->width == 0 && flag->precision == 0)
//	else if (inf->nothing == 0)
	{
//		if (flag->plus == 1 || inf->tmp == 1)
//			inf->result += write(1, "+", 1);
		inf->result += ft_strlen_uintmax(str);
		ft_putstr(str);
	}
}

//void				cancellation_flags_Oo(t_flag *flag, t_inf *inf)
//{
//	if (flag->minus == 1 && flag->plus == 1)
//	{
//		inf->tmp = flag->plus;
//		flag->plus = 0;
//	}
//	if ((flag->plus == 1 || inf->tmp == 1) && flag->space == 1)
//		flag->space = 0;
//	if ((flag->minus == 1 || flag->precision == 1) && flag->zero == 1)
//		flag->zero = 0;
//}
