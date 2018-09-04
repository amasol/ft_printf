/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_flag_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:47:47 by amasol            #+#    #+#             */
/*   Updated: 2018/09/04 15:47:54 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		cast_flag_u(t_inf *inf, uintmax_t i, t_flag *flag)
{
	if (flag->zero == 1 && i != 0)
	{
		inf->r = (inf->cou > 0) ? inf->r += ps_l("0", inf->cou) : inf->r;
		inf->r += ft_cou_uint(ft_putnbr_uintmax_t(i));
	}
	else if ((flag->wid == 1 && flag->preci == 0 && flag->min != 1) ||
			(flag->wid == 1 && flag->min == 1))
	{
		inf->r = (flag->min != 1) ? inf->r += ps_l(" ", inf->cou) : inf->r;
		inf->r += ft_cou_uint(ft_putnbr_uintmax_t(i));
		inf->r = (flag->min == 1) ? inf->r += ps_l(" ", inf->cou) : inf->r;
	}
	else if ((flag->pls == 1) || (flag->space == 1 && flag->preci != 1))
		inf->r += ft_cou_uint(ft_putnbr_uintmax_t(i));
	else if (flag->preci == 1 && flag->min == 0)
	{
		inf->r = (inf->cou_t > 0) ? inf->r += ps_l(" ", inf->cou_t) : inf->r;
		inf->r = (inf->cou > 0) ? inf->r += ps_l("0", inf->cou) : inf->r;
		if (i != 0)
			inf->r += ft_cou_uint(ft_putnbr_uintmax_t(i));
	}
	else if (flag->pls == 0 && flag->slash == 0 && flag->space == 0
			&& flag->zero == 0 && flag->wid == 0 && flag->preci == 0)
		inf->r += ft_cou_uint(ft_putnbr_uintmax_t(i));
}
