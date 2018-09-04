/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_flag_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 21:02:06 by amasol            #+#    #+#             */
/*   Updated: 2018/09/03 21:02:07 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	g_lob;

static int		cast_flag_o_h3(t_inf *inf, uintmax_t i, t_flag *flag, char *str)
{
	if (flag->preci == 1 && inf->cou_t >= 0 && flag->min == 0)
	{
		inf->r = (i != 0) ? inf->r += ps_l(" ", inf->cou_t) : inf->r;
		inf->r = (i == 0) ? inf->r += ps_l(" ", inf->wid_t) : inf->r;
		inf->r = (inf->cou > 0) ? inf->r += ps_l("0", inf->cou) : inf->r;
		inf->r = (flag->slash == 1) ? inf->r += write(1, "0", 1) : inf->r;
		inf->r += (i != 0) ? ft_strlen_uintmax(str) : 0;
		ft_putstr(str = (i == 0) ? 0 : str);
	}
	else if (flag->pls == 0 && flag->slash == 0
		&& flag->zero == 0 && flag->wid == 0 && flag->preci == 0)
	{
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
	}
	else if (flag->wid == 1 && flag->preci == 0 && flag->min == 1)
	{
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
		inf->r = (inf->cou > 0) ? inf->r += ps_l(" ", inf->cou) : inf->r;
	}
	return (0);
}

static int		cast_flag_o_h2(t_inf *inf, uintmax_t i, t_flag *flag, char *str)
{
	if ((flag->zero == 0 || flag->min == 0) && flag->pls == 1
		&& flag->preci == 0 && inf->wid == 0)
	{
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
	}
	else if (flag->preci == 1 && inf->cou > 0
			&& inf->cou_t == 0 && flag->min != 1)
	{
		inf->r += (i != 0) ? ps_l("0", inf->cou) : ps_l(" ", inf->cou);
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str = (i == 0) ? " " : str);
	}
	else if (flag->preci == 1 && flag->min == 1)
	{
		inf->r = (inf->cou > 0) ? inf->r += ps_l("0", inf->cou) : 0;
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
		inf->r = (inf->cou_t > 0) ? inf->r += ps_l(" ", inf->cou_t) : inf->r;
	}
	if (g_lob < inf->r)
		return (1);
	cast_flag_o_h3(inf, i, flag, str);
	return (0);
}

static int		cast_flag_o_h(t_inf *inf, uintmax_t i, t_flag *flag, char *str)
{
	if (flag->zero == 1 && flag->min != 1 && flag->slash != 1)
	{
		inf->r = (inf->cou > 0) ? inf->r += ps_l("0", inf->cou) : inf->r;
		inf->r += (i != 0) ? ft_strlen_uintmax(str) : 0;
		ft_putstr(str = (i == 0) ? 0 : str);
	}
	else if (flag->zero == 1 && flag->min != 1 && flag->slash != 1)
	{
		inf->r = (inf->cou > 0) ? inf->r += ps_l("0", inf->cou) : inf->r;
		inf->r += (i != 0) ? ft_strlen_uintmax(str) : 0;
		ft_putstr(str = (i == 0) ? 0 : str);
	}
	else if (flag->wid == 1 && flag->preci == 0 && flag->min != 1)
	{
		inf->r = (inf->cou > 0) ? inf->r += ps_l(" ", inf->cou) : inf->r;
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
	}
	if (g_lob < inf->r)
		return (1);
	cast_flag_o_h2(inf, i, flag, str);
	return (0);
}

int				cast_flag_o(t_inf *inf, uintmax_t i, t_flag *flag, char *str)
{
	g_lob = inf->r;
	if (flag->slash == 1 && flag->preci == 0)
	{
		inf->cou -= 1;
		inf->r = (flag->min != 1 && inf->cou > 0) ?
			inf->r += ps_l(" ", inf->cou) : inf->r;
		inf->r += write(1, "0", 1);
		inf->r += (i != 0) ? ft_strlen_uintmax(str) : 0;
		ft_putstr(str = (i == 0) ? 0 : str);
		inf->r = (flag->min == 1) ? inf->r += ps_l(" ", inf->cou) : inf->r;
	}
	else if (flag->preci == 1 && flag->pls == 1)
	{
		inf->r = (inf->cou > 0) ? inf->r += ps_l(" ", inf->cou) : inf->r;
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
	}
	if (g_lob < inf->r)
		return (1);
	cast_flag_o_h(inf, i, flag, str);
	return (0);
}
