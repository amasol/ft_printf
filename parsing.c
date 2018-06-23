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

void			parsing(char *str)
{
	t_flag	flag;
	int 	i;

	i = 0;
//	возможно не должно быть \0;
	if (str[i])
		initialization_flag(&flag);
	while (str[i] != '\0')
	{
		parsing_one(&str[i], &flag);
		parsing_two(&str[i], &flag);
		i++;
	}
//	printf("slash[%d]\n", flag.slash);
//	printf("space[%d]\n", flag.space);
//	printf("h[%d]\n", flag.h);
}

void			initialization_flag(t_flag *flag)
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