/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 20:36:43 by amasol            #+#    #+#             */
/*   Updated: 2018/08/28 20:36:44 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


int				ft_lenwchar(wchar_t c, t_inf *inf)
{
	if (c <= 0x7F)
	{
//		inf->uint_j += 1;
		return (1);
	}
	else if (c <= 0x7FF)
	{
//		inf->uint_j += 2;
		return (2);
	}
	else if (c <= 0xFFFF)
	{
//		inf->uint_j += 3;
		return (3);
	}
	else if (c <= 0x10FFFF)
	{
//		inf->uint_j += 4;
		return (4);
	}
	return (0);
}
