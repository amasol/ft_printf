/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 17:19:18 by amasol            #+#    #+#             */
/*   Updated: 2018/05/08 17:19:20 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		parsing_h(char *str, va_list lst, t_inf *inf, t_flag *flag)
{
	int i;

	i = 0;
	while (!(ft_qualifier(str[i])))
	{
		inf->nothi = 1;
		if (is_check_specs(str[i]))
			break ;
		if (inf->wid_t == 0)
			parsing_four(str, flag, inf);
		if (inf->wid == 0)
			parsing_three(&str[i], inf, flag);
		if (inf->cou_three == 0)
			parsing_five(&str[i], inf, flag);
		if (inf->wid == 0)
			parsing_three(&str[i], inf, flag);
		i++;
	}
	if (ft_qualifier(str[i]))
		pars_spec(&str[i], lst, flag, inf);
	output_after(&str[i], lst, flag, inf);
	inf->cou_format += i;
}

void			parsing(char *str, va_list lst, t_inf *inf)
{
	int		i;
	t_flag	flag;

	i = 0;
	if (str[i])
	{
		initialization_flag(&flag, inf);
		parsing_one(&str[i], &flag);
		parsing_two(&str[i], &flag);
	}
	parsing_h(str, lst, inf, &flag);
}

void			parsing_one(char *str, t_flag *flag)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+')
			flag->pls = 1;
		if (str[i] == '-')
			flag->min = 1;
		if (str[i] == '#')
			flag->slash = 1;
		if (str[i] == ' ')
			flag->space = 1;
		if (!is_zero(str))
			flag->zero = 1;
		if (str[i] == '.' || (ft_isdigit(str[i]) && str[i + 1] == '.'))
		{
			is_check_preci(&str[i], flag);
			flag->preci = 1;
		}
		if (ft_isdigit(str[i]))
			flag->wid = 1;
		i++;
	}
}

void			parsing_two(char *str, t_flag *flag)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '%')
	{
		if (str[i] == 'h' && str[i + 1] == 'h')
		{
			flag->hh = 1;
			i++;
		}
		else if (str[i] == 'h')
			flag->h = 1;
		else if (str[i] == 'l' && str[i + 1] == 'l')
		{
			flag->ll = 1;
			i++;
		}
		else if (str[i] == 'l')
			flag->l = 1;
		else if (str[i] == 'j')
			flag->j = 1;
		else if (str[i] == 'z')
			flag->z = 1;
		i++;
	}
}

void			parsing_three(char *str, t_inf *inf, t_flag *flag)
{
	int i;

	i = 0;
	flag->zero_preci = 0;
	if ((ft_flag_check((*str)) || ft_isdigit(*str)) && flag->preci == 1)
	{
		while (*str != '.')
			str++;
		if (ft_isdigit(str[i + 1]) && flag->preci == 1)
		{
			inf->wid = ft_atoi(&str[i + 1]);
			flag->zero_preci = 1;
		}
	}
	while (str[i] == '0' && ft_flag_check(str[i]))
		i++;
	if (str[i] >= '1' && str[i] <= '9')
	{
		inf->wid = ft_atoi(&str[i]);
		inf->cou_four = 1;
	}
	while (ft_flag_check(*str))
		str++;
}
