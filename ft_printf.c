/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 13:21:09 by amasol            #+#    #+#             */
/*   Updated: 2018/05/16 15:06:23 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	va_list		lst;

	va_start(lst, format);
	while (*format)
	{

		if (*format == '%')
		{
			format++;
			parsing(*format);
//			pars(*format, lst);
		}
		else
		{
			ft_putchar(*format);
		}
//		pars((char *)format, lst);
//		form(&format);
		format++;
	}
	write(1, "\n", 1);
	va_end(lst);
	return (0);
}
