/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_flag_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:07:32 by amasol            #+#    #+#             */
/*   Updated: 2018/09/03 16:07:34 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		cast_flag_c_help(t_inf *inf, t_flag *flag, char str)
{
	if (flag->wid == 1 && flag->preci == 0 && flag->min == 1)
	{
		ft_putchar(str);
		inf->r = (inf->cou > 0) ? inf->r += ps_l(" ", inf->cou) : inf->r;
	}
	else if (flag->preci == 1 && inf->cou > 0 &&
			inf->cou_t == 0 && flag->min != 1)
	{
		if ((flag->pls == 1) && flag->min == 0 && (inf->wid < inf->wid_t))
			inf->r += write(1, " ", 1);
		ft_putchar(str);
	}
	else if (inf->nothi == 0)
		ft_putchar(str);
	else if (flag->space == 1)
		ft_putchar(str);
	inf->r += 1;
}

void			cast_flag_c(t_inf *inf, t_flag *flag, char str)
{
	inf->cou = (inf->un_j > inf->wid) ? inf->un_j : inf->wid - inf->un_j;
	if (inf->wid_t > inf->wid)
		inf->cou_t = (inf->wid_t > inf->wid) ? inf->wid_t - inf->wid : 0;
	else if (flag->min == 1 && flag->preci == 0 && inf->wid == 0)
	{
		inf->r = (flag->space == 1) ? inf->r += write(1, " ", 1) : inf->r;
		ft_putchar(str);
	}
	else if (flag->zero == 1)
	{
		inf->r = (inf->cou > 0) ? inf->r += ps_l("0", inf->cou -= 1) : inf->r;
		if (str == '\0')
		{
			ft_putchar('0');
			ft_putchar('\0');
			inf->r += 1;
		}
	}
	else if (inf->cou >= 0 && flag->wid == 1 && flag->preci == 0
		&& flag->min != 1 && inf->min_v != 1)
	{
		inf->r = (inf->cou > 0) ? inf->r += ps_l(" ", inf->cou) : inf->r;
		ft_putchar(str);
	}
	cast_flag_c_help(inf, flag, str);
}

void			cast_flag_cc(t_inf *inf, t_flag *flag, wchar_t c)
{
	inf->un_j = ft_lenwchar(c);
	if (flag->wid == 1 && flag->preci == 0)
	{
		inf->cou = (inf->un_j < inf->wid) ? inf->wid - inf->un_j : inf->r;
		inf->r = (inf->cou > 0) ? inf->r += ps_l(" ", inf->cou) : inf->r;
		ft_putwchar(c, inf);
	}
	else if (flag->wid == 1 && flag->preci == 1 && flag->check_preci == 1)
	{
		inf->cou = (inf->un_j < inf->wid) ? inf->wid - inf->un_j : inf->r;
		inf->r = (inf->cou > 0) ? inf->r += ps_l(" ", inf->cou) : inf->r;
		ft_putwchar(c, inf);
	}
	else if (flag->space == 1 || flag->pls == 1)
	{
		inf->cou = (inf->un_j < inf->wid) ? inf->wid - inf->un_j : inf->cou;
		inf->r = (inf->cou > 0) ? inf->r += ps_l(" ", inf->cou) : inf->r;
		ft_putwchar(c, inf);
	}
	else if (flag->preci == 1)
		ft_putwchar(c, inf);
	else if (flag->wid == 0 && flag->preci == 0 && flag->pls == 0)
		ft_putwchar(c, inf);
}
