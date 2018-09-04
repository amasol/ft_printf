/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qualifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 17:17:30 by amasol            #+#    #+#             */
/*   Updated: 2018/05/08 17:17:31 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int help;
			//спецификаторы
int			ft_qualifier(char s)
{
	if (s == 's' || s == 'S' || s == 'Z'
		|| s == 'p' || s == 'd'
		|| s == 'P' || s == 'i'
		|| s == 'o' || s == 'O'
		|| s == 'u' || s == 'U'
		|| s == 'x' || s == 'X'
		|| s == 'c' || s == 'C'
		|| s == '%' || s == 'D')
	{
		help = 1;
		return (1);
	}
	else
	{
		help = 0;
		return (0);
	}
}

//			refinement - уточнение ...
int			ft_refinement(char s)
{
	if (s == 'D' || s == 'd' || s == 'i')
		return (1);
	else if (s == 'c' || s == 'C')
		return (2);
	else if (s == 's' || s == 'S')
		return (3);
	else if (s == 'x' || s == 'X')
		return (4);
	else if (s == 'o' || s == 'O')
		return (5);
	else if (s == 'u' || s == 'U')
		return (6);
	else if (s == 'p')
		return (7);
	return (0);
}

int			output_after(char *format, va_list lst, t_flag *flag, t_inf *inf)
{
	int i;

	i = 0;

	if (format[i] == 'Z')
	{
		pars_hi_z(&format[i], flag, inf, lst);
		return (1);
	}
	while (ft_isdigit(format[i]) || (format[i] == '-')
		|| (format[i] == '+') || ft_flag_check(format[i])
		|| (format[i] == ' ') || (format[i] == '.'))
		i++;
	if (ft_qualifier(format[i]))
		i++;
	if (help == 0 && flag->min == 0)
	{
		inf->wid -= 1;
		inf->r = (flag->wid == 1) ? inf->r += ps_l(" ", inf->wid) :inf->r;
	}
	while (format[i] != '%' && format[i] != '\0')
	{
		inf->r += write(1, &format[i], 1);
		i++;
	}
	inf->cou_format = i;
	return (1);
}

int			ft_flag_check(char c)
{
	if (c == '+' || c == '-' || c == 'Z'
		|| c == '#' || c == '.'
		|| c == ' ' || c == 'h'
		|| c == 'j' || c == 'z'
		|| c == 'l' || (c == 'l' && c + 1 == 'l') ||
		(c == 'h' && c + 1 == 'h'))
		return (1);
	else
		return (0);
}
