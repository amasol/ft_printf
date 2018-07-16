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

#include "ft_printf.h"

			//спецификаторы
int			ft_qualifier(char s)
{
	if (s == 's' || s == 'S'
		|| s == 'p' || s == 'd'
		|| s == 'P' || s == 'i'
		|| s == 'o' || s == 'O'
		|| s == 'u' || s == 'U'
		|| s == 'x' || s == 'X'
		|| s == 'c' || s == 'C'
		|| s == '%' || s == 'D')
		return (1);
	else
		return (0);
}

//			refinement - уточнение ...
//	использовать уже когда пройдут вся возможная длинна, если она есть!

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


void				output_after(char *format, t_inf *inf)
{
	int i;

	i = 0;
	while (ft_isdigit(format[i]) || (format[i] == '-') || (format[i] == '+')
		   || ft_flag_check(format[i]) || (format[i] == ' ') || (format[i] == '.'))
		i++;
	if (ft_qualifier(format[i]))
		i++;
	while (format[i] != '%' && format[i] != '\0')
	{
		ft_putchar(format[i]);
		i++;
	}
	inf->count_format = i;
}

//-------------------проверить отдельно функцию ....


int			ft_flag_check(char c)
{
	if (c == '+' || c == '-'
		|| c == '#' || c == '.'
		|| c == ' ' || c == 'h'
		|| c == 'j' || c == 'z'
		|| c == 'l' || (c == 'l' && c + 1 == 'l') ||
		(c == 'h' && c + 1 == 'h'))
		return (1);
	else
		return (0);
}
/*
int			ft_flag(char format)
{
	if (format == 'h' && format + 1 == 'h')
		return (1);
	else if (format == 'l' && format + 1 == 'l')
		return (2);
	else if (format == 'z')
		return (3);
	else if (format == 'j')
		return (4);
	else if (format == 'l')
		return (5);
	else if (format == 'h')
		return (6);
	else if (format == '+')
		return (7);
	else if (format == '-')
		return (8);
	else if (format == '0')
		return (9);
	else if (format == '#')
		return (10);
	else if (format == '%' && format + 1 == '%')
		return (11);
	return (0);
}
*/
