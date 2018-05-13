/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 13:21:09 by amasol            #+#    #+#             */
/*   Updated: 2018/05/02 20:38:46 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	va_list		lst;
//	int i;
//	int j;

//	i = 0;
	va_start(lst, format);
	while (*format)
	{
//		j = parsing((char *)&str[i]);
//		i = parsing((char *)&str[i], lst);
//		i++;
		find((char *)format);
		pars((char *)format);
//		form(&format);
		format++;
	}
//	write(1, "\n", 1);
	va_end(lst);
	return (0);
}

int		main(int ac, char **av)
{
	int i = 1;

	if (ac < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (ac > i)
	{
		ft_printf(av[i]);
		i++;
	}
	return (0);
}


