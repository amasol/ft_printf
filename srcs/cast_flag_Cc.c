/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_flag_Cc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 17:13:03 by amasol            #+#    #+#             */
/*   Updated: 2018/07/16 17:13:04 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	cast_flag_Cc(t_inf *inf, t_flag *flag, char str)
{
	// флаг -
	inf->count = (inf->uint_j > (uintmax_t)inf->width) ? inf->uint_j : inf->width - inf->uint_j;
	if (inf->width_two > inf->width)
		inf->count_two = (inf->width_two > inf->width) ? inf->width_two - inf->width : 0;
	else if ((uintmax_t)inf->width_two > inf->uint_j)
		inf->count_two = ((uintmax_t)inf->width_two > inf->uint_j) ? inf->width_two - inf->uint_j : 0;





	if (inf->count > 0 && flag->minus == 1 && flag->precision == 0 && inf->width == 0)
	{
		if (flag->space == 1)
			inf->result += write(1, " ", 1);
		ft_putchar(str);
	}

//		флан zero
	else if (flag->zero == 1)
	{
		ft_putchar(str);
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
		while (inf->count > 0)
		{
			inf->result += write(1, " ", 1);
			inf->count--;
		}
		ft_putchar(str);
	}
		//	флаг	 ширины и флаг minus
	else if (flag->width == 1 && flag->precision == 0 &&
			 inf->width > 0 && (flag->minus == 1) && flag->h == 0)
	{
		if (flag->space == 1)
			inf->count = inf->count + 1;
		if (flag->space == 1)
			inf->result += write(1, " ", 1);
		ft_putchar(str);
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
		ft_putchar(str);
	}
		// 		флаг	 ширины + когда аргумент по кол-ву с оденаковый с шириной !
	else if (inf->count == 0 && flag->width == 1 && flag->precision == 0 )
	{
		if (inf->count == 1 && flag->plus == 1)
			inf->count -= 1;
		if (flag->space == 1)
			inf->count = inf->count + 1;
		ft_putchar(str);
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
		ft_putchar(str);
	}


	else if (flag->space == 1 && flag->precision != 1)
	{
		inf->result += write(1, " ", 1);
		ft_putchar(str);
	}



//		точность (.)
	else if (flag->precision == 1 && inf->count > 0 && inf->count_two == 0 && flag->minus != 1 )
	{
		if ((flag->plus == 1) && flag->minus == 0 && (inf->width < inf->width_two))
			inf->result += write(1, " ", 1);
		while (inf->count_two > 0)
		{
			inf->result += write(1, " ", 1);
			inf->count_two--;
		}
		ft_putchar(str);
	}


//		точность (ширина + точность)
	else if (flag->precision == 1 && inf->count >= 0 && inf->count_two >= 0 && flag->minus == 0)
	{
		inf->count_two = (inf->minus_value == 1) ? inf->count_two -= 1 : inf->count_two;
		while (inf->count_two > 0)
		{
			inf->result += write(1, " ", 1);
			inf->count_two--;
		}
		ft_putchar(str);
	}

		//		точность (ширина точность и флаг минут)
	else if (flag->precision == 1 && flag->minus == 1 && inf->count >= 0 &&
			 inf->count_two >= 0)
	{
		ft_putchar(str);

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
		ft_putchar(str);
	}
	else if (flag->precision == 1 && flag->plus == 1)
	{
		while (inf->count > 0)
		{
			inf->result += write(1, " ", 1);
			inf->count--;
		}
		ft_putchar(str);
	}

	else if (flag->plus == 0 && flag->slash == 0 && flag->space == 0
			 && flag->zero == 0 && flag->width == 0 && flag->precision == 0)
	{
//		inf->result += ft_strlen_uintmax(&str);
		ft_putchar(str);
	}
}

