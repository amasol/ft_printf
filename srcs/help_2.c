/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:36:05 by amasol            #+#    #+#             */
/*   Updated: 2018/09/04 14:36:07 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int g_lob;

static int	cast_flag_x_h7(t_inf *inf, uintmax_t i, t_flag *flag, char *str)
{
	if (flag->wid == 1 && flag->preci == 0 && flag->min != 1)
	{
		if (flag->slash == 1)
			inf->cou -= 2;
		inf->r = (inf->cou > 0) ? inf->r += ps_l(" ", inf->cou) : inf->r;
		if (inf->x == 'x' && flag->slash == 1 && i != 0)
			inf->r += write(1, "0x", 2);
		else if (flag->slash == 1 && i != 0)
			inf->r += write(1, "0X", 2);
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
	}
	else if ((flag->zero == 0 || flag->min == 0)
			&& flag->pls == 1 && flag->preci == 0 && inf->wid == 0)
	{
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
	}
	else if (flag->pls == 0 && flag->slash == 0
			&& flag->zero == 0 && flag->wid == 0 && flag->preci == 0)
	{
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
	}
	return (0);
}

static int	cast_flag_x_h6(t_inf *inf, uintmax_t i, t_flag *flag, char *str)
{
	if (flag->preci == 1 && inf->cou == 0 && inf->cou_t > 0)
	{
		inf->r = (inf->wid_t > 0) ? inf->r += ps_l(" ", inf->wid_t) : inf->r;
		if (i != 0)
		{
			inf->r += ft_strlen_uintmax(str);
			ft_putstr(str);
		}
	}
	else if (flag->slash == 1)
	{
		if (inf->x == 'x' && i != 0)
			inf->r += write(1, "0x", 2);
		else if (inf->x == 'X' && i != 0)
			inf->r += write(1, "0X", 2);
		else if (i != 0)
			inf->r += write(1, "0", 1);
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
	}
	if (g_lob < inf->r)
		return (1);
	cast_flag_x_h7(inf, i, flag, str);
	return (0);
}

int			cast_flag_x_h5(t_inf *inf, uintmax_t i, t_flag *flag, char *str)
{
	g_lob = inf->r;
	if (flag->preci == 1 && flag->min == 0 && i != 0)
	{
		inf->r = (inf->cou_t > 0) ? inf->r += ps_l(" ", inf->cou_t) : inf->r;
		if (inf->x == 'x' && flag->slash == 1)
			inf->r += write(1, "0x", 2);
		else if (flag->slash == 1)
			inf->r += write(1, "0X", 2);
		inf->r = (inf->cou > 0) ? inf->r += ps_l("0", inf->cou) : inf->r;
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
	}
	else if (flag->preci == 1 && flag->min == 1)
	{
		inf->r = (inf->cou > 0) ? inf->r += ps_l("0", inf->cou) : inf->r;
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
		inf->r = (inf->cou_t > 0) ? inf->r += ps_l(" ", inf->cou_t) : inf->r;
	}
	if (g_lob < inf->r)
		return (1);
	cast_flag_x_h6(inf, i, flag, str);
	return (0);
}
