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
		|| s == '%')
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
	else if (s == '%')
		return (8);
	return (0);
}

//---------------------------

/*
//-------------------проверить отдельно функцию ....
//			lenght - длинна
int			ft_length(char *tmp)
{
	int i;

	i = 0;
	if (tmp[i] == 'h' && tmp[i + 1] == 'h')
		return (ft_length_hh(&tmp[i]));
	else if (tmp[i] == 'l' && tmp[i + 1] == 'l')
		return (ft_length_ll(&tmp[i]));
	else if (tmp[i] == 'z')
		return (ft_length_z(&tmp[i]));
	else if (tmp[i] == 'j')
		return (ft_length_j(&tmp[i]));
	else if (tmp[i] == 'l')
		return (ft_length_l(&tmp[i]));
	else if (tmp[i] == 'h')
		return (ft_length_h(&tmp[i]));
	return (0);
}
*/
// -------------------------------------------------
/*
int		ft_length_hh(char *tmp)
{
	int i;

	i = 0;
	if (tmp[i])
	{
		tmp = (char)va_arg(int, lst);
	}
	return (0);
}
*/
/*
int		ft_length_h(char *tmp)
{
	int i;

	i = 0;
	return (0);
}

int		ft_length_ll(char *tmp)
{
	int i;

	i = 0;
	return (0);
}

int		ft_length_l(char *tmp)
{
	int i;

	i = 0;
	return (0);
}

int		ft_length_j(char *tmp)
{
	int i;

	i = 0;
	return (0);
}

int		ft_length_z(char *tmp)
{
	int i;

	i = 0;
	return (0);
}
*/