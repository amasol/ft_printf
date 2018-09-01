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

void	cast_flag_c(t_inf *inf, t_flag *flag, char str)
{
	// флаг -
	inf->cou = (inf->uint_j > (uintmax_t)inf->width)? inf->uint_j: inf->width - inf->uint_j;
	if (inf->width_two > inf->width)
		inf->cou_t = (inf->width_two > inf->width) ? inf->width_two - inf->width : 0;

	else if (inf->cou > 0 && flag->min == 1 && flag->preci == 0 && inf->width == 0)
	{
		inf->r = (flag->space == 1) ? inf->r += write(1, " ", 1) : inf->r;
		ft_putchar(str);
	}
//		флан zero
	else if (flag->zero == 1)
	{
		inf->cou -= 1;
		inf->r = (inf->cou > 0) ? inf->r += ft_ps_l("0", inf->cou) : inf->r;
		if (str == '\0')
		{
			ft_putchar('0');
			ft_putchar('\0');
			inf->r += 1;
		}
	}
	// 		флаг	 ширины
	else if (inf->cou >= 0 && flag->width == 1 && flag->preci == 0 &&
			 flag->min != 1 && inf->min_v != 1)
	{
		inf->r = (inf->cou > 0) ? inf->r += ft_ps_l(" ", inf->cou) : inf->r;
		ft_putchar(str);
	}
	//	флаг	 ширины и флаг min
	else if (flag->width == 1 && flag->preci == 0 && flag->min == 1)
	{
		ft_putchar(str);
		inf->r = (inf->cou > 0) ? inf->r += ft_ps_l(" ", inf->cou) : inf->r;
	}
//		точность (.)
	else if (flag->preci == 1 && inf->cou > 0 && inf->cou_t == 0 && flag->min != 1 )
	{
		if ((flag->plus == 1) && flag->min == 0 && (inf->width < inf->width_two))
			inf->r += write(1, " ", 1);
		ft_putchar(str);
	}
	else if (inf->nothi == 0)
		ft_putchar(str);
	else if (flag->space == 1)
		ft_putchar(str);
	inf->r += 1;
}

void	cast_flag_C(t_inf *inf, t_flag *flag, wchar_t c)
{
	inf->uint_j = ft_lenwchar(c);
	if (flag->width == 1 && flag->preci == 0)
	{
		inf->cou = (inf->uint_j < inf->width) ? inf->width - inf->uint_j : inf->r;
		inf->r = (inf->cou > 0) ? inf->r += ft_ps_l(" ", inf->cou) : inf->r;
		ft_putwchar(c, inf);
	}
	else if (flag->width == 1 && flag->preci == 1 && flag->check_preci == 1)
	{
		inf->cou = (inf->uint_j < inf->width) ? inf->width - inf->uint_j : inf->r;
		inf->r = (inf->cou > 0) ? inf->r += ft_ps_l(" ", inf->cou) : inf->r;
		ft_putwchar(c, inf);
	}
	else if (flag->space == 1 || flag->plus == 1)
	{
		inf->cou = (inf->uint_j < inf->width) ? inf->width - inf->uint_j : inf->cou;
		inf->r = (inf->cou > 0) ? inf->r += ft_ps_l(" ", inf->cou) : inf->r;
		ft_putwchar(c, inf);
	}
	else if (flag->preci == 1)
		ft_putwchar(c, inf);
	else if (flag->width == 0 && flag->preci == 0 && flag->space == 0 && flag->plus == 0)
		ft_putwchar(c, inf);
}


