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

#include "ft_printf.h"

int		parsing(char *str, va_list lst)
{
	int j;

	j = 0;
	if (str[j] == ft_qualifier(str[j]))
	{
		str[j] == 'd' ? parsing_d(str[j], lst) : 0;
		j++;
	}
	else
	{
		if (str[j] != ft_qualifier(str[j]))
		j++;
	}
	return (0);
/*	{
		j++;
		if (str[j] == ft_qualifier(str[j]))
			j = j + 1;
	}*/
}