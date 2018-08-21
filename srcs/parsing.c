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

#include "../includes/ft_printf.h"

void				parsing(char *str, va_list lst, t_inf *inf)
{
	t_flag	flag;
	int 	i;

	i = 0;
	if (str[i])
	{
		initialization_flag(&flag, inf);
		parsing_one(&str[i], &flag);
		parsing_two(&str[i], &flag);
	}
	while (!(ft_qualifier(str[i])))
	{
		if (inf->width_two == 0)
			parsing_four(str, &flag, inf);
		if (inf->width == 0)
			parsing_three(&str[i], inf, &flag);
		if (inf->count_three == 0)
			parsing_five(&str[i], inf, &flag);
		if (inf->width == 0)
			parsing_three(&str[i], inf, &flag);
		i++;
	}
	if (ft_qualifier(str[i]))
		pars_spec(&str[i], lst, &flag, inf);
	output_after(&str[i], inf);
	inf->count_format +=  i;
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
	inf->width_two			= 0;
	inf->count				= 0;
	inf->count_two			= 0;
	inf->count_three		= 0;
	inf->count_four			= 0;
	inf->tmp				= 0;
	inf->count_format		= 0;
	inf->minus_value		= 0;
	inf->uint_j				= 0;
	inf->intm_j				= 0;
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
		if (ft_isdigit(str[i]))
			flag->width = 1;
		i++;
	}
}

void			parsing_two(char *str, t_flag *flag)
{
	int i;

	i = 0;
	// поменять местами по приоритетности с z по hh
	while (str[i])
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

int			parsing_three(char *str, t_inf *inf, t_flag *flag)
{
	int i;

	i = 0;
	flag->zero_precision = 0;
//	if (ft_isdigit(*str) && flag->precision == 1 )
	if ((ft_flag_check((*str)) ||ft_isdigit(*str)) && flag->precision == 1 )
	{
		while (*str != '.')
			str++;
		if (str[i] == '.' && flag->precision == 1)
		{
			if ((str[i + 1] == '+' || str[i + 1] == '-' ||
				str[i + 1] == ' ' || str[i + 1] == '#' || ft_flag_check(str[i + 1])))
			{
				flag->precision = 0;
				inf->width_two = 0;
			}
		}
		if (ft_isdigit(str[i + 1]) && flag->precision == 1)
		{
			inf->width = ft_atoi(&str[i + 1]);
			flag->zero_precision = 1;
		}
	}
//	if ((flag->minus == 1 || flag->zero == 1 || flag->width == 1 ||
//		flag->plus == 1 || flag->precision == 1) && k != 1)
	if (flag->zero_precision != 1)
	{
		while (str[i] == '+' || str[i] == '0' || str[i] == '-' ||
				str[i] == '.' || str[i] == ' ' || ft_flag_check(str[i]))
			i++;
		if  (str[i] >= '1' && str[i] <= '9')
		{
			inf->width = ft_atoi(&str[i]);
			inf->count_four = 1;
		}
	}
	while (*str == '+' || *str == '-' || *str == ' ' || *str == '#' || ft_flag_check(*str))
		str++;
	if (ft_isdigit(*str) && inf->width_two > 0 && flag->zero_precision != 1)
	{
		inf->width = 0;
		inf->count_four = 1;
	}
	return (1);
}

void			parsing_four(char *str, t_flag *flag, t_inf *inf)
{
	int i;

	i = 0;
//	if (flag->space == 1) // просмотреть что делает и зачем
//		flag->width = 0;
	while (str[i] == '+' || (str[i] == '0' && flag->zero != 1) || str[i] == '-' || str[i] == ' ' || ft_flag_check(str[i]))
		i++;
	if (str[i] == '.' && flag->precision == 1)
	{
		i++;
		if (str[i] >= '1' && str[i] <= '9')
			inf->width_two = ft_atoi(&str[i]);
	}
	else if (ft_isdigit(str[i]) && inf->count_three != 1)
	{
		// было начало с 1 я поставил с 0.
		if  (str[i] >= '0' && str[i] <= '9')
			inf->width_two = ft_atoi(&str[i]);
	}
}


void		parsing_five(char *str, t_inf *inf, t_flag *flag)
{
	int i;
	int k;

	i = 0;
	k = 0;
	if (inf->width_two > 0 && inf->width == 0 && inf->count_four == 0 && flag->zero_precision != 1)
		inf->width = inf->width_two;
	while (ft_flag_check(str[i]))
		i++;
	if (str[i])
	{
		while (ft_isdigit(str[i]))
		{
			k = 1;
			i++;
		}
		while (ft_flag_check(str[i]))
			i++;
		while (ft_isdigit(str[i]))
		{
			k = 2;
			i++;
		}
		if (k == 1)
			inf->width_two = 0;
	}
	inf->count_three = 1;
}

int		is_zero(char *str)
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