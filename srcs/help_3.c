/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 18:19:28 by amasol            #+#    #+#             */
/*   Updated: 2018/09/04 18:19:29 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		initialization_flag_h(t_flag *flag, t_inf *inf)
{
	flag->ban = 0;
	inf->wid = 0;
	inf->wid_t = 0;
	inf->cou = 0;
	inf->cou_t = 0;
	inf->cou_three = 0;
	inf->cou_four = 0;
	inf->tmp = 0;
	inf->cou_format = 0;
	inf->min_v = 0;
	inf->un_j = 0;
	inf->intm_j = 0;
	inf->nothi = 0;
	flag->nothi_flag = 0;
}

void			initialization_flag(t_flag *flag, t_inf *inf)
{
	flag->pls = 0;
	flag->min = 0;
	flag->slash = 0;
	flag->space = 0;
	flag->zero = 0;
	flag->wid = 0;
	flag->preci = 0;
	flag->check_preci = 0;
	flag->zero_preci = 0;
	flag->hh = 0;
	flag->h = 0;
	flag->ll = 0;
	flag->l = 0;
	flag->j = 0;
	flag->z = 0;
	initialization_flag_h(flag, inf);
}

void			parsing_four(char *str, t_flag *flag, t_inf *inf)
{
	int i;

	i = 0;
	while (str[i] == '+' || (str[i] == '0' && flag->zero != 1)
			|| str[i] == '-' || str[i] == ' ' || ft_flag_check(str[i]))
		i++;
	if (ft_isdigit(str[i]) && inf->cou_three != 1)
	{
		if (str[i] >= '0' && str[i] <= '9')
			inf->wid_t = ft_atoi(&str[i]);
	}
}

void			parsing_five(char *str, t_inf *inf, t_flag *flag)
{
	int i;
	int k;

	i = 0;
	k = 0;
	if (inf->wid_t > 0 && inf->wid == 0 && inf->cou_four == 0
		&& flag->zero_preci != 1)
		inf->wid = inf->wid_t;
	while (ft_flag_check(str[i]))
		i++;
	if (str[i])
	{
		while (ft_isdigit(str[i++]))
			k = 1;
		while (ft_flag_check(str[i]))
			i++;
		while (ft_isdigit(str[i++]))
			k = 2;
		if (k == 1)
			inf->wid_t = 0;
	}
	inf->cou_three = 1;
}
