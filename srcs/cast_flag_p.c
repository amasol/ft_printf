/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_flag_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 17:13:47 by amasol            #+#    #+#             */
/*   Updated: 2018/07/16 17:13:47 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			cast_flag_p(t_inf *inf, uintmax_t i, t_flag *flag, char *str)
{
	if (inf->cou_t <= 2 && flag->min == 0)
		inf->cou_t = 0;
	else if (inf->cou_t > 2)
		;
	if (inf->cou_t == 0 && inf->cou <= 2)
		inf->cou = 0;
	else if (inf->cou_t ==  0 && inf->cou >= 4 && i == 0)
		inf->cou -= 2;

// флаг -
	if (inf->cou > 0 && flag->min == 1 && flag->preci == 0 && inf->width == 0)
	{
		if (flag->space == 1)
			inf->r += write(1, " ", 1);
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
		while (inf->cou > 0 && (!(inf->width == 1)))
		{
			inf->r += write(1, " ", 1);
			inf->cou--;
		}
	}
	else if (flag->zero == 1 && inf->width_two == 0 && flag->preci == 0)
	{
		inf->cou += 1;
		inf->r += write(1, "0x", 2);
		while (inf->cou > 0)
		{
			inf->r += write(1, "0", 1);
			inf->cou--;
		}
	}
//		флан zero
	else if (flag->zero == 1)
	{
		inf->r += write(1, "0x", 2);
		while (inf->cou > 0)
		{
			inf->r += write(1, "0", 1);
			inf->cou--;
		}
		if (i != 0)
		{
			inf->r += ft_strlen_uintmax(str);
			ft_putstr(str);
		}
		while (inf->cou_t > 0)
		{
			inf->r += write(1, " ", 1);
			inf->cou_t--;
		}
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
		inf->r += ft_strlen_uintmax(str);
		inf->r += write(1, "0x", 2);
		ft_putstr(str);
	}
	//	флаг	 ширины и флаг min
	else if (flag->width == 1 && flag->preci == 0 &&
			 inf->width > 0 && (flag->min == 1) && flag->h == 0)
	{
		if (flag->space == 1)
			inf->cou = inf->cou + 1;
		if (flag->space == 1)
			inf->r += write(1, " ", 1);
		inf->r += ft_strlen_uintmax(str);
		inf->r += write(1, "0x", 2);
		ft_putstr(str);
		if (flag->min == 1 && flag->ban < inf->width && inf->tmp == 1)
			inf->r += write(1, " ", 1);
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
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
	}
// 		флаг	 ширины + когда аргумент по кол-ву с оденаковый с шириной !
	else if (inf->cou == 0 && flag->width == 1 && flag->preci == 0 )
	{
		if (inf->cou == 1 && flag->plus == 1)
			inf->cou -= 1;
		if (flag->space == 1)
			inf->cou = inf->cou + 1;
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
		while (inf->cou_t > 0 && inf->cou == 0)
		{
			inf->r += write(1, " ", 1);
			inf->cou_t--;
		}
	}
	else if ((flag->zero == 0 || flag->min == 0) && flag->plus == 1 && flag->preci == 0 &&
			 inf->width == 0)
	{
		inf->r += ft_strlen_uintmax(str);
		inf->r += write(1, "0x", 2);
		ft_putstr(str);
	}
	else if (flag->space == 1 && flag->preci != 1 && inf->nothi == 1)
	{
		inf->r += write(1, " ", 1);
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
	}
//		точность (.)
	else if (flag->preci == 1 && inf->cou > 0 && inf->cou_t == 0 && flag->min != 1 )
	{
		if (inf->cou_t ==  0 && inf->width >= 4 && i == 0)
			inf->cou += 2;
		if ((flag->plus == 1) && flag->min == 0 && (inf->width < inf->width_two))
			inf->r += write(1, " ", 1);
		inf->r += write(1, "0x", 2);
		while (inf->cou > 0)
		{
			inf->r += write(1, "0", 1);
			inf->cou--;
		}
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
	}
//		точность (ширина + точность)
	else if (flag->preci == 1 && inf->cou >= 0 && inf->cou_t >= 0 && flag->min == 0)
	{
		inf->cou = (inf->width > inf->uint_j) ? inf->width - inf->uint_j : 0;
		inf->uint_j += 2;
		inf->cou_t = (inf->width_two > inf->uint_j + inf->cou) ?
		 inf->width_two - (inf->uint_j + inf->cou) : 0;
		while (inf->cou_t > 0)
		{
			inf->r += write(1, " ", 1);
			inf->cou_t--;
		}
		inf->r += write(1, "0x", 2);
		while (inf->cou > 0 )
		{
			inf->r += write(1, "0", 1);
			inf->cou--;
		}
		if (i != 0)
		{
			inf->r += ft_strlen_uintmax(str);
			ft_putstr(str);
		}
	}
	//		точность (ширина точность и флаг минут)
	else if (flag->preci == 1 && flag->min == 1 && inf->cou >= 0 &&
			 inf->cou_t >= 0)
	{
		if (inf->width_two > inf->width + 2 && inf->width != 0)
		{
			inf->cou_t = inf->width_two;
			inf->cou_t -= inf->width + 2;
		}
		inf->r += write(1, "0x", 2);
		while (inf->cou > 0)
		{
			inf->r += write(1, "0", 1);
			inf->cou--;
		}
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);

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
		inf->r += ft_strlen_uintmax(str);
		inf->r += write(1, "0x", 2);
		ft_putstr(str);
	}
	else if (flag->preci == 1 && flag->plus == 1)
	{
		while (inf->cou > 0)
		{
			inf->r += write(1, " ", 1);
			inf->cou--;
		}
		inf->r += ft_strlen_uintmax(str);
		inf->r += write(1, "0x", 2);
		ft_putstr(str);
	}
	else if (flag->plus == 0 && flag->slash == 0 && flag->zero == 0 && flag->width == 0 && flag->preci == 0)
	{
		inf->r += ft_strlen_uintmax(str);
		inf->r += write(1, "0x", 2);
		ft_putstr(str);
	}
}