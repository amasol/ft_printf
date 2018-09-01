/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_flag_Uu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 17:13:22 by amasol            #+#    #+#             */
/*   Updated: 2018/07/16 17:13:23 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		cast_flag_Uu(t_inf *inf, uintmax_t i, t_flag *flag, char *str)
{
	// флаг -
	if (inf->cou > 0 && flag->min == 1 && flag->preci == 0 && inf->width == 0)
	{
		if (flag->space == 1)
			inf->r += write(1, " ", 1);
//		if (flag->plus == 1 || inf->tmp == 1)
//			inf->r += write(1, "+", 1);
		inf->r += ft_cou_uint(ft_putnbr_uintmax_t(i));
		while (inf->cou > 0 && (!(inf->width == 1 && i == 1)))
		{
			inf->r += write(1, " ", 1);
			inf->cou--;
		}
	}

//		флан zero
	else if (flag->zero == 1 && i != 0)
	{
		if (flag->space == 1)
			inf->r += write(1, " ", 1);
		while (inf->cou > 0)
		{
			inf->r += write(1, "0", 1);
			inf->cou--;
		}
		inf->r += ft_cou_uint(ft_putnbr_uintmax_t(i));
	}
		// 		флаг	 ширины
	else if (inf->cou >= 0 && flag->width == 1 && flag->preci == 0 &&
			 flag->min != 1 && inf->min_v != 1)
	{
		while (inf->cou > 0)
		{
			inf->r += write(1, " ", 1);
			inf->cou--;
		}
		inf->r += ft_cou_uint(ft_putnbr_uintmax_t(i));
	}
		//	флаг	 ширины и флаг min
	else if (flag->width == 1 && flag->preci == 0 &&
			 inf->width > 0 && (flag->min == 1) && flag->h == 0)
	{
		if (flag->space == 1)
			inf->r += write(1, " ", 1);
		inf->r += ft_cou_uint(ft_putnbr_uintmax_t(i));
		while (inf->cou > 0 && flag->space != 1)
		{
			inf->r += write(1, " ", 1);
			inf->cou--;
		}
	}
		//	флаг	 ширины + модификаторы и флаг min
	else if (inf->cou >= 0 && flag->width == 1 && flag->preci == 0 &&
			 inf->min_v == 1 && flag->h == 1)
	{
		if (flag->space == 1)
			inf->cou = inf->cou + 1;
		if (flag->space == 1)
			inf->r += write(1, " ", 1);
		while (inf->cou > 0 && flag->space != 1)
		{
			inf->r += write(1, " ", 1);
			inf->cou--;
		}
		inf->r += ft_cou_uint(ft_putnbr_uintmax_t(i));
	}
		// 		флаг	 ширины + когда аргумент по кол-ву с оденаковый с шириной !
	else if (inf->cou == 0 && flag->width == 1 && flag->preci == 0 )
		inf->r += ft_cou_uint(ft_putnbr_uintmax_t(i));

	else if ((flag->zero == 0 || flag->min == 0) && flag->plus == 1 && flag->preci == 0 &&
			 inf->width == 0)
	{
		inf->r += ft_cou_uint(ft_putnbr_uintmax_t(i));
	}
	else if (flag->space == 1 && flag->preci != 1)
	{
		inf->r += ft_cou_uint(ft_putnbr_uintmax_t(i));
	}

//		точность (.)
	else if (flag->preci == 1 && inf->cou > 0 && inf->cou_t == 0)
	{
		if ((flag->plus == 1) && flag->min == 0 && (inf->width < inf->width_two))
			inf->r += write(1, "+", 1);
		while (inf->cou > 0)
		{
			inf->r += write(1, "0", 1);
			inf->cou--;
		}
		inf->r += ft_cou_uint(ft_putnbr_uintmax_t(i));
	}


//		точность (ширина + точность)
	else if (flag->preci == 1 && inf->cou >= 0 && inf->cou_t >= 0 && flag->min == 0)
	{
		inf->cou_t = (inf->min_v == 1) ? inf->cou_t -= 1 : inf->cou_t;
		while (inf->cou_t > 0)
		{
			inf->r += write(1, " ", 1);
			inf->cou_t--;
		}
		while (inf->cou > 0 )
		{
			inf->r += write(1, "0", 1);
			inf->cou--;
		}
		if (i != 0)
		inf->r += ft_cou_uint(ft_putnbr_uintmax_t(i));
	}

	//		точность (ширина точность и флаг минут)
	else if (flag->preci == 1 && flag->min == 1 && inf->cou >= 0 &&
			 inf->cou_t >= 0)
	{
		while (inf->cou > 0)
		{
			inf->r += write(1, "0", 1);
			inf->cou--;
		}
		inf->r += ft_cou_uint(ft_putnbr_uintmax_t(i));

		if (flag->min == 1 && flag->ban < inf->width_two && inf->width == 0)
			inf->r += write(1, " ", 1);
		while (inf->cou_t > 0)
		{
			inf->r += write(1, " ", 1);
			inf->cou_t--;
		}
	}
	else if (flag->preci == 1 && inf->cou == 0 && inf->cou_t > 0)
	{
		while (inf->cou > 0)
		{
			inf->r += write(1, "0", 1);
			inf->cou--;
		}
		while (inf->cou_t > 0)
		{
			inf->r += write(1, " ", 1);
			inf->cou_t--;
		}
		inf->r += ft_cou_uint(ft_putnbr_uintmax_t(i));
	}
	else if (flag->slash == 1)
	{
		if (*str == 'X')
			inf->r += write(1, "0X", 2);
		if (*str == 'x')
			inf->r += write(1, "0x", 2);
		if (*str == 'o' || *str == 'O')
			inf->r += write(1, "0", 1);
	}
	else if (flag->preci == 1 && flag->plus == 1)
	{
		while (inf->cou > 0)
		{
			inf->r += write(1, " ", 1);
			inf->cou--;
		}
		inf->r += ft_cou_uint(ft_putnbr_uintmax_t(i));
	}
	else if (flag->plus == 0 && flag->slash == 0 && flag->space == 0
			 && flag->zero == 0 && flag->width == 0 && flag->preci == 0)
	{
		inf->r += ft_cou_uint(ft_putnbr_uintmax_t(i));
	}
}