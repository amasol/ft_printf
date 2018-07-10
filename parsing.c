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


//	char c;
//	c = str[i];  для дебагера ! удобно!
//		printf("str[%d] = %c\n", i, str[i]);

#include "ft_printf.h"

void				parsing(char *str, va_list lst)
{
	t_flag	flag;
	t_inf 	inf;
	int 	i;

	i = 0;
	if (str[i])
	{
		initialization_flag(&flag, &inf);
		parsing_one(&str[i], &flag);
		parsing_two(&str[i], &flag);
	}
	while (!(ft_qualifier(str[i])))
	{
		parsing_four(&str[i], &flag);
		if (inf.width == 0)
			parsing_three(&str[i], &inf, &flag);
		i++;
	}
	if (ft_qualifier(str[i]))
		pars_spec(&str[i], lst, &flag, &inf);
//	printf("slash[%d]\n", flag.slash);
//	printf("space[%d]\n", flag.l);
}

void			initialization_flag(t_flag *flag, t_inf *inf)
{
	flag->plus				= 0;
	flag->minus				= 0;
	flag->slash				= 0;
	flag->space				= 0;
	flag->zero				= 0;
	flag->width				= 0;
	flag->precision			= 0;
	flag->zero_precision	= 0;

	flag->hh 				= 0;
	flag->h 				= 0;
	flag->ll 				= 0;
	flag->l 				= 0;
	flag->j 				= 0;
	flag->z 				= 0;

	flag->ban				= 0;
	inf->width				= 0;
}

void			parsing_one(char *str, t_flag *flag)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+')
			flag->plus = 1;
		if (str[i] == '-')
			flag->minus = 1;
		if (str[i] == '#')
			flag->slash = 1;
		if (str[i] == ' ')
			flag->space = 1;
		if (!is_zero(str))
			flag->zero = 1;
		if (str[i] == '.')
			flag->precision = 1;
		i++;
	}
}

void			parsing_two(char *str, t_flag *flag)
{
	int i;

	i = 0;
	// поменять местами по приоритетности с z по hh
	if (str[i])
	{
		if (str[i] == 'h' && str[i + 1] == 'h')
			flag->hh = 1;
		if (str[i] == 'h')
			flag->h = 1;
		if (str[i] == 'l' && str[i + 1] == 'l')
			flag->ll = 1;
		if (str[i] == 'l')
			flag->l = 1;
		if (str[i] == 'j')
			flag->j = 1;
		if (str[i] == 'z')
			flag->z = 1;
//		i++;
	}
}

int			parsing_three(char *str, t_inf *inf, t_flag *flag)
{
	int i;

	i = 0;
	if (flag->minus == 1 || flag->zero == 1 || flag->width == 1 ||
		flag->plus == 1 || flag->precision == 1)
	{
		while (str[i] == '+' || str[i] == '0')
			i++;
		if  (str[i] >= '1' && str[i] <= '9')
		{
			inf->width = ft_atoi(&str[i]);
//			flag->minus = 0;
		}
	}
	return (1);
}

void			parsing_four(char *str, t_flag *flag)
{
	if (ft_isdigit(*str))
		flag->width = 1;
	if (flag->space == 1)
	{
//		flag->minus = 0;
		flag->width = 0;
	}
}

static int		is_zero(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '9')
			return (1);
		else if (str[i] == '0')
			return (0);
		i++;
	}
	return (0);
}















/*void			parsing(char format)
{
	if (ft_flag_check(format))
	{
		if (ft_flag(format) == 1)
			ft_length_hh(format);
		else if (ft_flag(format) == 2)
			ft_length_ll(format);
		else if (ft_flag(format) == 3)
			ft_length_z(format);
		else if (ft_flag(format) == 4)
			ft_length_j(format);
		else if (ft_flag(format) == 5)
			ft_length_l(format);
		else if (ft_flag(format) == 6)
			ft_length_h(format);
		else if (ft_flag(format) == 7)
			ft_length_+(format);
		else if (ft_flag(format) == 8)
			ft_length_-(format);
		else if (ft_flag(format) == 9)
			ft_length_0(format);
		else if (ft_flag(format) == 10)
			ft_length_#(format);
		else if (ft_flag(format) == 11)
			ft_length_%%(format);
	}
}
 */