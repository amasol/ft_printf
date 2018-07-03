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
		initialization_flag(&flag, &inf);
	while (!(ft_qualifier(str[i])))
	{
		parsing_one(&str[i], &flag);
		parsing_two(&str[i], &flag);
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

	inf->width				= 0;
}

void			parsing_one(char *str, t_flag *flag)
{
	int i;

	i = 0;
//	while (str[i])
	if (str[i])
	{
		if (str[i] == '+')
			flag->plus = 1;
		if (str[i] == '-')
			flag->minus = 1;
		if (str[i] == '#')
			flag->slash = 1;
		if (str[i] == ' ')
			flag->space = 1;
		if (str[i] == '0')
			flag->zero = 1;
//		i++;
	}
}


void			parsing_two(char *str, t_flag *flag)
{
	int i;

	i = 0;
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
	// нету диклорации итератора k...если дикларирую то итератор слитает!
//	не правильно выделяю malloc! не работает условие если не !
	// нужно как то добавить что бы только если знак - был...заходило сюда и записывало!
	int i;

	i = 0;
//	inf->minus = 0;
//	if (!(inf->minus = (char *)malloc(sizeof(char))))
//		return (0);
	if (flag->minus == 1)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
//			inf->minus = str[i];
			inf->width = ft_atoi(&str[i]);
			flag->minus = 0;
		}
	}
//	printf("minus->[%d]\n", inf->minus);
	return (1);
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