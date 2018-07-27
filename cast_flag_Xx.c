/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_flag_Xx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 17:13:13 by amasol            #+#    #+#             */
/*   Updated: 2018/07/16 17:13:14 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		cast_flag_Xx(t_inf *inf, uintmax_t i, t_flag *flag, char *str)
{
	// флаг -
	if (inf->count > 0 && flag->minus == 1 && flag->precision == 0 && inf->width == 0)
	{
		if (flag->space == 1)
			inf->result += write(1, " ", 1);
//		if (flag->plus == 1 || inf->tmp == 1)
//			inf->result += write(1, "+", 1);
//		inf->result += ft_strlen_uintmax(str = (ft_itoa_base_uintmax(i, 16, 'x')));
		ft_putstr(str);
		while (inf->count > 0 && (!(inf->width == 1 && i == 1)))
		{
			inf->result += write(1, " ", 1);
			inf->count--;
		}
	}

//		флан zero
	else if (flag->zero == 1)
	{
		if (flag->space == 1)
			inf->result += write(1, " ", 1);
//		if (flag->plus == 1 || inf->tmp == 1)
//			inf->result += write(1, "+", 1);
		while (inf->count > 0)
		{
			inf->result += write(1, "0", 1);
			inf->count--;
		}
//		inf->result += ft_strlen_uintmax(str = (ft_itoa_base_uintmax(i, 16, 'x')));
		ft_putstr(str);
	}
		// 		флаг	 ширины
	else if (inf->count >= 0 && flag->width == 1 && flag->precision == 0 &&
			 flag->minus != 1 && inf->minus_value != 1)
	{
		if (flag->space == 1)
			inf->count = inf->count + 1;
		if (flag->plus == 1 && flag->ban != inf->width)
			inf->count = inf->count + 1;
		while (inf->count > 0)
		{
			inf->result += write(1, " ", 1);
			inf->count--;
		}
//		if ((flag->plus == 1 && flag->minus != 1) ||
//			(inf->tmp == 1 && flag->minus == 1))
//			inf->result += write(1, "+", 1);
//		inf->result += ft_strlen_uintmax(str = (ft_itoa_base_uintmax(i, 16, 'x')));
		ft_putstr(str);
	}
		//	флаг	 ширины и флаг minus
	else if (flag->width == 1 && flag->precision == 0 &&
			 inf->width > 0 && (flag->minus == 1) && flag->h == 0)
	{
		if (flag->space == 1)
			inf->count = inf->count + 1;
//		if (inf->tmp == 1 && inf->minus_value == 0)
//			inf->result += write(1, "+", 1);
		if (flag->space == 1)
			inf->result += write(1, " ", 1);
//		inf->result += ft_strlen_uintmax(str = (ft_itoa_base_uintmax(i, 16, 'x')));
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
//		inf->result += ft_strlen_uintmax(str = (ft_itoa_base_uintmax(i, 16, 'x')));
		ft_putstr(str);
	}
		// 		флаг	 ширины + когда аргумент по кол-ву с оденаковый с шириной !
	else if (inf->count == 0 && flag->width == 1 && flag->precision == 0 )
	{
		if (inf->count == 1 && flag->plus == 1)
			inf->count -= 1;
		if (flag->space == 1)
			inf->count = inf->count + 1;
//		if (flag->space == 1)
//			inf->result += write(1, " ", 1);
//		if (flag->plus == 1 || inf->tmp == 1)
//			inf->result += write(1, "+", 1);
//		inf->result += ft_strlen_uintmax(str = (ft_itoa_base_uintmax(i, 16, 'x')));
		ft_putstr(str);
	}

	else if ((flag->zero == 0 || flag->minus == 0) && flag->plus == 1 && flag->precision == 0 &&
			 inf->width == 0)
	{
//		if (flag->plus == 1 || inf->tmp == 1)
//			inf->result += write(1, "+", 1);
//		inf->result += ft_strlen_uintmax(str = (ft_itoa_base_uintmax(i, 16, 'x')));
		ft_putstr(str);
	}


	else if (flag->space == 1 && flag->precision != 1)
	{
		inf->result += write(1, " ", 1);
//		inf->result += ft_strlen_uintmax(str = (ft_itoa_base_uintmax(i, 16, 'x')));
		ft_putstr(str);
	}



//		точность (.)
	else if (flag->precision == 1 && inf->count > 0 && inf->count_two == 0)
	{
//		if ((flag->minus == 0) && flag->plus == 0)
//			;
		if ((flag->plus == 1) && flag->minus == 0 && (inf->width < inf->width_two))
			inf->result += write(1, "+", 1);
		while (inf->count > 0)
		{
			inf->result += write(1, "0", 1);
			inf->count--;
		}
//		inf->result += ft_strlen_uintmax(str = (ft_itoa_base_uintmax(i, 16, 'x')));
		ft_putstr(str);
//		if (flag->minus == 1)
//			inf->result += write(1, " ", 1);
	}


//		точность (ширина + точность)
	else if (flag->precision == 1 && inf->count >= 0 && inf->count_two >= 0 && flag->minus == 0)
	{
		inf->count_two = (inf->minus_value == 1) ? inf->count_two -= 1 : inf->count_two;
		inf->count_two = (flag->plus == 1) ? inf->count_two += 1 : inf->count_two;
		while (inf->count_two > 0)
		{
			inf->result += write(1, " ", 1);
			inf->count_two--;
		}
//		if (flag->plus == 1  && flag->ban < inf->width_two)
//			inf->result += write(1, " ", 1);
		while (inf->count > 0 )
		{
			inf->result += write(1, "0", 1);
			inf->count--;
		}
//		inf->result += ft_strlen_uintmax(str = (ft_itoa_base_uintmax(i, 16, 'x')));
		ft_putstr(str);
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
//		inf->result += ft_strlen_uintmax(str = (ft_itoa_base_uintmax(i, 16, 'x')));
		ft_putstr(str);
//		while (inf->count_two + 1 > 0)

		if (flag->minus == 1 && flag->ban < inf->width_two && inf->width == 0)
			inf->result += write(1, " ", 1);
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
//		inf->result += ft_strlen_uintmax(str = (ft_itoa_base_uintmax(i, 16, 'x')));
		ft_putstr(str);
	}



//	else if (flag->slash == 1)
//	{
//		if (*str == 'X')
//			inf->result += write(1, "0X", 2);
//		if (*str == 'x')
//			inf->result += write(1, "0x", 2);
//		if (*str == 'o' || *str == 'O')
//			inf->result += write(1, "0", 1);
//	}
	else if (flag->precision == 1 && flag->plus == 1)
	{
		while (inf->count > 0)
		{
			inf->result += write(1, " ", 1);
			inf->count--;
		}
//		if (flag->plus == 1 || inf->tmp == 1)
//			inf->result += write(1, "+", 1);
//		inf->result += ft_strlen_uintmax(str = (ft_itoa_base_uintmax(i, 16, 'x')));
		ft_putstr(str);
	}
		// не правильно работает если у нас нету флагов и мы должны вывести остачу || у нас
//		есть флаг и мы должны вывести остачу послу отработки тут !!!

	else if (flag->plus == 0 && flag->slash == 0 && flag->space == 0
			 && flag->zero == 0 && flag->width == 0 && flag->precision == 0)
	{
//		if (flag->plus == 1 || inf->tmp == 1)
//			inf->result += write(1, "+", 1);
//		inf->result += ft_count(ft_putnbr_uintmax_t(i));
//		str = (ft_itoa_base_uintmax(i, 16, 'x'));
//		inf->result += ft_strlen_uintmax(str = (ft_itoa_base_uintmax(i, 16, 'x')));
		ft_putstr(str);
	}
}

//void				cancellation_flags_Uu(t_flag *flag, t_inf *inf)
//{
//	 доделать и проверить со всеми флагами !
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
