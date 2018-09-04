/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 15:35:07 by amasol            #+#    #+#             */
/*   Updated: 2018/08/31 15:35:08 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

intmax_t		cast_intmax(intmax_t i, t_flag *flag, t_inf *inf)
{
	if (flag->z == 1)
		return ((size_t)i);
	if (flag->j == 1)
		return ((intmax_t)i);
	if (flag->ll == 1)
		return ((long long)i);
	if (flag->l == 1)
		return ((long)i);
	if (flag->h == 1)
		return ((short)i);
	if (flag->hh == 1)
		return ((char)i);
	return (0);
}

uintmax_t		cast_uintmax(uintmax_t i, t_flag *flag, t_inf *inf)
{
	if (flag->z)
		return ((size_t)i);
	if (flag->j)
		return ((uintmax_t)i);
	if (flag->ll)
		return ((unsigned long long)i);
	if (flag->l)
		return ((unsigned long)i);
	if (flag->h)
		return ((unsigned short)i);
	if (flag->hh)
		return ((unsigned char)i);
	return (0);
}

void			entry_min_uint(t_inf *inf)
{
	if (inf->wid > 0)
		inf->cou = (inf->un_j <= (uintmax_t)inf->wid)
			? inf->wid - inf->un_j : 0;
	if (inf->wid_t > 0 && inf->cou != 0)
		inf->cou_t = (inf->wid_t > inf->wid)
			? inf->wid_t - inf->wid : 0;
	else
		inf->cou_t = ((uintmax_t)inf->wid_t >= inf->un_j)
			? inf->wid_t - inf->un_j : 0;
	if (inf->cou == 0 && inf->cou_t == 1 && inf->min_v == 1)
		inf->cou_t -= 1;
}

intmax_t		entry_min_intm(intmax_t i, t_inf *inf, t_flag *flag)
{
	inf->intm_j = ft_cou_int(i);
	if (inf->wid > 0)
		inf->cou = (inf->intm_j <= inf->wid) ? inf->wid - inf->intm_j : 0;
	if (flag->pls == 1 || inf->tmp == 1 || flag->space == 1 || inf->min_v == 1)
	{
		if (inf->cou > 0 && inf->wid_t == 0)
			inf->cou -= 1;
	}
	if (inf->wid_t > 0 && inf->cou != 0)
		inf->cou_t = (inf->wid_t > inf->wid) ? inf->wid_t - inf->wid : 0;
	else
		inf->cou_t = (inf->wid_t >= inf->intm_j)
			? inf->wid_t - inf->intm_j : 0;
	if (inf->cou_t > 0 && (flag->pls == 1 || inf->tmp == 1))
		inf->cou_t = inf->cou_t - 1;
	else if (inf->cou == 0 && inf->cou_t == 1 && inf->min_v == 1)
		inf->cou_t -= 1;
	return (0);
}

intmax_t		ft_cou_int(intmax_t n)
{
	intmax_t i;

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
