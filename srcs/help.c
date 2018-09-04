/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 18:04:58 by amasol            #+#    #+#             */
/*   Updated: 2018/09/03 18:04:59 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			cast_flag_di_h5(t_inf *inf, intmax_t i, t_flag *flag, char *str)
{
	if (flag->slash == 0 &&
		flag->zero == 0 && flag->wid == 0 && flag->preci == 0)
	{
		if ((inf->min_v == 1 || flag->min == 1) && i != LONG_MIN && i > 0)
			inf->r += write(1, "-", 1);
		else if (inf->min_v == 1 && i == -1)
			inf->r += 1;
		inf->r += ft_cou_int(ft_putnbr_intmax(i));
	}
	else if (inf->nothi == 0)
		inf->r += ft_cou_int(ft_putnbr_intmax(i));
	return (0);
}

int			cast_flag_p_h5(t_inf *inf, uintmax_t i, t_flag *flag, char *str)
{
	if (flag->pls == 0 && flag->slash == 0 && flag->zero == 0
		&& flag->wid == 0 && flag->preci == 0)
	{
		inf->r += ft_strlen_uintmax(str);
		inf->r += write(1, "0x", 2);
		ft_putstr(str);
	}
	return (0);
}

int			cast_flag_s_h5(t_inf *inf, t_flag *flag, char *str, char *tmp)
{
	if ((flag->pls == 1 && flag->preci == 0 && inf->wid == 0)
		|| (flag->space == 1 && flag->preci != 1)
		|| (flag->preci == 1 && inf->cou_t == 0 && *str == '\0'))
	{
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
	}
	else if (flag->preci == 1 && flag->min == 1)
	{
		tmp = ft_strsub(str, 0, inf->wid);
		inf->r += ft_strlen_uintmax(tmp);
		ft_putstr(tmp);
		inf->r = (inf->cou > 0 && *str == '\0')
				? inf->r += ps_l(" ", inf->cou) : inf->r;
		inf->r = (inf->cou_t > 0 && flag->min == 1)
				? inf->r += ps_l(" ", inf->cou_t) : inf->r;
		ft_strdel(&tmp);
	}
	else if (inf->nothi == 0)
	{
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
	}
	return (0);
}

int			cast_flag_ss_h5(t_inf *inf, t_flag *flag, wchar_t *str)
{
	int i;

	i = 0;
	if ((flag->space == 1 || flag->pls == 1)
			|| (flag->preci == 1 || flag->l == 1) || (flag->wid == 0))
	{
		while (str[i])
			ft_putwchar(str[i++], inf);
	}
	return (0);
}

uintmax_t	ft_cou_uint(uintmax_t n)
{
	uintmax_t i;

	i = 0;
	if (n <= 0)
	{
		i++;
		n *= -1;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
