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

#include "../includes/ft_printf.h"

void		cast_flag_Ddi(t_inf *inf, intmax_t i, t_flag *flag, char *str)
{
	// флаг -
	if (inf->count > 0 && flag->minus == 1 && flag->precision == 0 && inf->width == 0)
	{
//		if (inf->minus_value == 1)
//			write(1, "-", 1);
		if (flag->space == 1)
			inf->result += write(1, " ", 1);
		if (flag->plus == 1 || inf->tmp == 1)
			inf->result += write(1, "+", 1);
		inf->result += ft_count_int(ft_putnbr_intmax(i));
		while (inf->count > 0 && (!(inf->width == 1 && i == 1)))
		{
			inf->result += write(1, " ", 1);
			inf->count--;
		}
	}

//		флан zero
//	else if (((inf->count > 0 && flag->zero == 1) ||
// 			(flag->minus == 1 && flag->precision == 1)) &&
//			inf->width_two == 0)
	else if (flag->zero == 1)
	{
		if (inf->minus_value == 1)
			inf->result += write(1, "-", 1);
		if (flag->space == 1)
			inf->result += write(1, " ", 1);
		if (flag->plus == 1 || inf->tmp == 1)
			inf->result += write(1, "+", 1);
		while (inf->count > 0)
		{
			inf->result += write(1, "0", 1);
			inf->count--;
		}
		inf->result += ft_count_int(ft_putnbr_intmax(i));
	}
		// просто флаг d, i
//	else if ()
//	{
//		if (flag->space == 1)
//			write(1, " ", 1);
//		if (flag->plus == 1 || inf->tmp == 1)
//			write(1, "+", 1);
//		while (inf->count > 0)
//		{
//			write(1, "0", 1);
//			inf->count--;
//		}
//		ft_putnbr_intmax(i);
//	}
		// 		флаг	 ширины
	else if (inf->count >= 0 && flag->width == 1 && flag->precision == 0 &&
				flag->minus != 1 && inf->minus_value != 1)
	{
		if (flag->space == 1)
			inf->count = inf->count + 1;
		while (inf->count > 0)
		{
			inf->result += write(1, " ", 1);
			inf->count--;
		}
		if ((flag->plus == 1 && flag->minus != 1) ||
					(inf->tmp == 1 && flag->minus == 1))
			inf->result += write(1, "+", 1);
//		if (inf->minus_value == 1)
//			write(1, "-", 1);
		inf->result += ft_count_int(ft_putnbr_intmax(i));
	}
		//	флаг	 ширины и флаг minus
	else if (flag->width == 1 && flag->precision == 0 &&
			inf->width > 0 && (flag->minus == 1 || inf->minus_value == 1) && flag->h == 0)
	{
		if (flag->space == 1)
			inf->count = inf->count + 1;
		if (( flag->minus == 1 && inf->minus_value == 1) && flag->plus == 0)
			inf->result += write(1, "-", 1);
		if (flag->minus == 1)
			inf->minus_value = 0;
		else if (inf->tmp == 1 && inf->minus_value == 0)
			inf->result += write(1, "+", 1);
		if (flag->space == 1)
			inf->result += write(1, " ", 1);

		while (inf->count > 0 && flag->space != 1 && inf->minus_value == 1)
		{
			inf->result += write(1, " ", 1);
			inf->count--;
		}
//		нужно передалть
		if ((inf->minus_value == 1) && flag->plus == 0)
			inf->result += write(1, "-", 1);
		inf->result += ft_count_int(ft_putnbr_intmax(i));
		while (inf->count > 0 && flag->space != 1 && inf->minus_value == 0)
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
		if ((inf->minus_value == 1) && flag->plus == 0)
			inf->result += write(1, "-", 1);
		inf->result += ft_count_int(ft_putnbr_intmax(i));
	}
		// 		флаг	 ширины + когда аргумент по кол-ву с оденаковый с шириной !
	else if (inf->count == 0 && flag->width == 1 && flag->precision == 0 )
	{
		if (inf->count == 1 && flag->plus == 1)
			inf->count -= 1;
		if (flag->space == 1)
			inf->count = inf->count + 1;
		if (flag->space == 1)
			inf->result += write(1, " ", 1);
		if (flag->plus == 1 || inf->tmp == 1)
			inf->result += write(1, "+", 1);
		inf->result += ft_count_int(ft_putnbr_intmax(i));
	}

	else if ((flag->zero == 0 || flag->minus == 0) && flag->plus == 1 && flag->precision == 0 &&
			 inf->width == 0)
	{
		if (flag->plus == 1 || inf->tmp == 1)
			inf->result += write(1, "+", 1);
		inf->result += ft_count_int(ft_putnbr_intmax(i));
	}


	else if (flag->space == 1 && flag->precision != 1 && i > 0 && inf->nothing == 1)
	{
		inf->result += write(1, " ", 1);
		inf->result += ft_count_int(ft_putnbr_intmax(i));
	}



//		точность (.)
	else if (flag->precision == 1 && inf->count > 0 && inf->count_two == 0)
	{
		inf->count = (inf->minus_value == 1 && inf->width_two == 0)
					 ? inf->count += 1 : inf->count;
		if ((inf->minus_value == 0 && flag->minus == 0) && flag->plus == 0)
			;
		else if ((inf->minus_value == 1 || flag->minus == 0) && flag->plus == 0)
			inf->result += write(1, "-", 1);
		if ((flag->plus == 1 || inf->tmp == 1) && inf->minus_value == 0)
			inf->result += write(1, "+", 1);
		while (inf->count > 0 && i != 0)
		{
			inf->result += write(1, "0", 1);
			inf->count--;
		}
		if (inf->width == inf->width_two)
		{
			while (inf->width > 0)
			{
				inf->result += write(1, "0", 1);
				inf->width--;
			}
		}
		while (inf->width > 0 && i == 0 && inf->width != inf->width_two)
		{
			inf->result += write(1, " ", 1) ;
			inf->width--;
		}
		inf->result += (i != 0) ? ft_count_int(ft_putnbr_intmax(i)) : 0;
//		inf->result += (i != 0) ? ft_count(ft_putnbr_intmax(i)) : write(1, " ", 1);
	}


//		точность (ширина + точность)
	else if (flag->precision == 1 && inf->count >= 0
			 && inf->count_two >= 0 && flag->minus == 0 && i != 0)
	{
		inf->count_two = (inf->minus_value == 1) ? inf->count_two -= 1 : inf->count_two;
//		inf->count = (i == 0 && inf->count > 0) ? inf->count += 1 : inf->count;
		while (inf->count_two > 0)
		{
			inf->result += write(1, " ", 1);
			inf->count_two--;
		}
		if (flag->plus == 1 || inf->tmp == 1)
			inf->result += write(1, "+", 1);
		if (inf->minus_value == 1 && flag->minus == 0)
			inf->result += write(1, "-", 1);
		while (inf->count > 0)
		{
			inf->result += write(1, "0", 1);
			inf->count--;
		}
//		while (inf->width > 0 && i == 0)
//		{
//			inf->result += write(1, "0", 1);
//			inf->width--;
//		}
//		ft_putstr(str = (i == 0) ? 0 : str);
//		inf->result += ft_count(ft_putnbr_intmax(i));
		inf->result += ft_count_int(ft_putnbr_intmax(i));
//		while (i == 0 && inf->count_two > 0)
//		{
//			inf->result += write(1, " ", 1);
//			inf->count_two--;
//		}
	}
//		ширина и точность с i == 0.
	else if (flag->precision == 1 && inf->count >= 0 &&
			inf->count_two >= 0 && flag->minus == 0 && i == 0)
	{
		inf->count_two = (inf->minus_value == 1) ? inf->count_two -= 1 : inf->count_two;
		inf->count = (i == 0 && inf->count > 0) ? inf->count += 1 : inf->count;
		while ((inf->count_two > 0 ) && i == 0 && inf->count != 0)
		{
			inf->result += write(1, " ", 1);
			inf->count_two--;
		}
		while (inf->width_two > 0 && i == 0 && inf->count == 0)
		{
			inf->result += write(1, " ", 1);
			inf->width_two--;
		}
		if (flag->plus == 1 || inf->tmp == 1)
			inf->result += write(1, "+", 1);
		if (inf->minus_value == 1 && flag->minus == 0)
			inf->result += write(1, "-", 1);
		while (inf->count > 0 && i != 0)
		{
//			inf->result += (i != 0) ? write(1, "0", 1) : write(1, " ", 1);
			inf->result += write(1, "0", 1);
			inf->count--;
		}
		while (inf->width > 0 && i == 0)
		{
			inf->result += write(1, "0", 1);
			inf->width--;
		}
//		ft_putstr(str = (i == 0) ? 0 : str);
//		inf->result += ft_count(ft_putnbr_intmax(i));
		inf->result += (i == 0) ? 0 : ft_count_int(ft_putnbr_intmax(i));
//		while (i == 0 && inf->count_two > 0)
//		{
//			inf->result += write(1, " ", 1);
//			inf->count_two--;
//		}
	}


	else if (flag->precision == 1 && flag->minus == 1 && inf->count >= 0 &&
			 inf->count_two >= 0)
	{
		if ((flag->plus == 1 || inf->tmp == 1) && inf->minus_value != 1)
			inf->result += write(1, "+", 1);
		if (inf->minus_value == 1 && flag->minus == 1 )
			inf->result += write(1, "-", 1);
		while (inf->count > 0)
		{
			inf->result += write(1, "0", 1);
			inf->count--;
		}
		inf->result += ft_count_int(ft_putnbr_intmax(i));
		while (inf->count_two > 0)
		{
			inf->result += write(1, " ", 1);
			inf->count_two--;
		}
	}
	else if (flag->precision == 1 && inf->count == 0 && inf->count_two > 0)
	{
//		if (flag->plus == 1 || inf->tmp == 1)
//			write(1, "+", 1);
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
		if (flag->plus == 1 || inf->tmp == 1)
			inf->result += write(1, "+", 1);
		inf->result += ft_count_int(ft_putnbr_intmax(i));
	}



	else if (flag->slash == 1)
	{
		if (*str == 'X')
			inf->result += write(1, "0X", 2);
		if (*str == 'x')
			inf->result += write(1, "0x", 2);
		if (*str == 'o' || *str == 'O')
			inf->result += write(1, "0", 1);
	}
	else if (flag->precision == 1 && flag->plus == 1)
	{
		while (inf->count > 0)
		{
			inf->result += write(1, " ", 1);
			inf->count--;
		}
		if (flag->plus == 1 || inf->tmp == 1)
			inf->result += write(1, "+", 1);
		inf->result += ft_count_int(ft_putnbr_intmax(i));
	}

	else if (inf->nothing == 0 && inf->minus_value == 1 && i == LONG_MIN)
	{
		inf->result += ft_count_int(ft_putnbr_intmax(i));
	}

	else if (flag->slash == 0 &&
			flag->zero == 0 && flag->width == 0 && flag->precision == 0)
	{
		if ((inf->minus_value == 1 || flag->minus == 1) && i != LONG_MIN  && i > 0)
			inf->result += write(1, "-", 1);
			// кастыляка !!!!!
		else if (inf->minus_value == 1 && i == -1)
			inf->result += 1;
		if (flag->plus == 1 || inf->tmp == 1)
			inf->result += write(1, "+", 1);
		inf->result += ft_count_int(ft_putnbr_intmax(i));
	}
	else if (inf->nothing == 0)
		inf->result += ft_count_int(ft_putnbr_intmax(i));
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
	if (i < 0)
	{
		flag->space	= 0;
		flag->plus 	= 0;
	}
	if ((i < 0 && flag->minus == 0) || (i < 0 && flag->minus == 1))
	{
		inf->minus_value = 1;
		i *= -1;
	}
	return (i);
}