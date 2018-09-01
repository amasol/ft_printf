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
	if (inf->cou > 0 && flag->preci == 0 && inf->width == 0)
	{
		inf->r += ft_cou_int(ft_putnbr_intmax(i));
		if (inf->cou > 0 && (!(inf->width == 1 && i == 1)))
			inf->r += ft_ps_l(" ", inf->cou);
	}
//		флан zero
	else if (flag->zero == 1)
	{
		inf->r = (flag->space == 1) ? inf->r += write(1, " ", 1) : inf->r;
		inf->r = (inf->min_v == 1) ? inf->r += write(1, "-", 1) : inf->r;
		inf->r = (flag->plus == 1) ? inf->r += write(1, "+", 1) : inf->r;
//		if (inf->cou > 0)
//			inf->r += ft_ps_l("0", inf->cou);
		inf->r = (inf->cou > 0) ? inf->r += ft_ps_l("0", inf->cou) : inf->r;
		inf->r += ft_cou_int(ft_putnbr_intmax(i));
	}
	// 		флаг	 ширины
	else if (flag->width == 1 && flag->preci == 0 &&
				flag->min != 1 && inf->min_v != 1)
	{
		inf->r = (inf->cou > 0) ? inf->r += ft_ps_l(" ", inf->cou) : inf->r;
		inf->r += ft_cou_int(ft_putnbr_intmax(i));
	}
		//	флаг	 ширины и флаг min
	else if (flag->width == 1 && flag->preci == 0 && flag->h == 0)
	{
		if (( flag->min == 1 && inf->min_v == 1) && flag->plus == 0)
			inf->r += write(1, "-", 1);
		inf->min_v = (flag->min == 1) ? inf->min_v = 0 : inf->min_v;
		if (inf->cou > 0 && flag->space != 1 && inf->min_v == 1)
			inf->r += ft_ps_l(" ", inf->cou);
		inf->r = (inf->min_v == 1) ? inf->r += write(1, "-", 1) : inf->r;
		inf->r += ft_cou_int(ft_putnbr_intmax(i));
		if (inf->cou > 0 && flag->space != 1 && inf->min_v == 0)
			inf->r += ft_ps_l(" ", inf->cou);
	}
	else if ((flag->min == 0) && flag->plus == 1 && flag->preci == 0)
	{
		inf->r += write(1, "+", 1);
		inf->r += ft_cou_int(ft_putnbr_intmax(i));
	}
	else if (flag->space == 1 && flag->preci != 1 && i > 0 && inf->nothi == 1)
	{
		inf->r += write(1, " ", 1);
		inf->r += ft_cou_int(ft_putnbr_intmax(i));
	}
//		точность (.)
	else if (flag->preci == 1 && inf->cou > 0 && inf->cou_t == 0)
	{
		inf->cou = (inf->min_v == 1 && inf->width_two == 0)
					 ? inf->cou += 1 : inf->cou;
		if ((inf->min_v == 0 && flag->min == 0) && flag->plus == 0)
			;
		inf->r = (inf->min_v == 1) ? inf->r += write(1, "-", 1) : inf->r;
		if (inf->cou > 0 && i != 0)
			inf->r += ft_ps_l("0", inf->cou);
		if (i == 0 && inf->width != inf->width_two)
			inf->r += ft_ps_l(" ", inf->width);
		inf->r += (i != 0) ? ft_cou_int(ft_putnbr_intmax(i)) : 0;
	}
//		точность (ширина + точность)
	else if (flag->preci == 1 && inf->cou >= 0
			 && inf->cou_t >= 0 && flag->min == 0 && i != 0)
	{
		inf->cou_t = (inf->min_v == 1) ? inf->cou_t -= 1 : inf->cou_t;
		inf->r = (inf->cou_t > 0) ? inf->r += ft_ps_l(" ", inf->cou_t) : inf->r;
		inf->r = (flag->plus == 1) ? inf->r += write(1, "+", 1) : inf->r;
		inf->r = (inf->min_v == 1) ? inf->r += write(1, "-", 1) : inf->r;
		inf->r = (inf->cou > 0) ? inf->r += ft_ps_l("0", inf->cou) : inf->r;
		inf->r += ft_cou_int(ft_putnbr_intmax(i));
	}
//		ширина и точность с i == 0.
	else if (flag->preci == 1 && i == 0)
	{
		if (inf->cou != 0  && inf->cou_t > 0)
			inf->r += ft_ps_l(" ", inf->cou_t);
		if (inf->width_two > 0 && i == 0 && inf->cou == 0)
			inf->r += ft_ps_l(" ", inf->width_two);
		if (inf->width > 0 && i == 0)
			inf->r += ft_ps_l("0", inf->width);
	}
	else if (flag->preci == 1 && flag->min == 1)
	{
		if ((flag->plus == 1 || inf->tmp == 1) && inf->min_v != 1)
			inf->r += write(1, "+", 1);
		inf->r = (inf->cou > 0) ? inf->r += ft_ps_l("0", inf->cou) : inf->r;
		inf->r += ft_cou_int(ft_putnbr_intmax(i));
		inf->r = (inf->cou_t > 0) ? inf->r += ft_ps_l(" ", inf->cou_t) : inf->r;
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
	else if (flag->slash == 0 &&
			flag->zero == 0 && flag->width == 0 && flag->preci == 0)
	{
		if ((inf->min_v == 1 || flag->min == 1) && i != LONG_MIN  && i > 0)
			inf->r += write(1, "-", 1);
		else if (inf->min_v == 1 && i == -1)
			inf->r += 1;
		inf->r += ft_cou_int(ft_putnbr_intmax(i));
	}
	else if (inf->nothi == 0)
		inf->r += ft_cou_int(ft_putnbr_intmax(i));
}

void				cancellation_flags_Ddi(t_flag *flag, t_inf *inf)
{
	if (flag->min == 1 && flag->plus == 1)
	{
		inf->tmp = flag->plus;
		flag->plus = 0;
	}
	if ((flag->min == 1 || flag->preci == 1) && flag->zero == 1)
		flag->zero = 0;
}

intmax_t 			min_v_Ddi(intmax_t i, t_flag *flag, t_inf *inf)
{
	if (i < 0)
	{
		flag->space	= 0;
		flag->plus 	= 0;
	}
	if ((i < 0 && flag->min == 0) || (i < 0 && flag->min == 1))
	{
		inf->min_v = 1;
		i *= -1;
	}
	return (i);
}