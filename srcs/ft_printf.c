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

#include "../includes/ft_printf.h"

int				ft_printf(const char *format, ...)
{
	va_list		lst;
	t_inf		inf;

	inf.result = 0;
	va_start(lst, format);
	while (*format != '%' && *format != '\0')
//	while ((*format != '%') && (!(ft_flag_check(*format))))
	{
//		ft_putchar(*format);
		inf.result += write(1, format, 1);
		format++;
	}
	if (*format)
	{
//		if (*format == '%' && *(format + 1) != '%')
		while (*format == '%' && *(format + 1) != '%')
		{
			format++;
			parsing((char *)format, lst, &inf);
			format += inf.count_format;
		}
		if (*format == '%' && *(format + 1) == '%')
		{
			inf.result += write(1, "%", 1);
			format = format + 2;
			while (ft_isdigit(*format) || (*format == '-') || (*format == '+')
					|| ft_flag_check(*format) || (*format == ' ') || (*format == '.'))
				format++;
			if (ft_qualifier(*format))
				format++;
			while (*format != '\0')
			{
				ft_putchar(*format);
				format++;
			}
		}
	}
//	write(1, "\n", 1);
	va_end(lst);
	return (inf.result);
}

/*
 * //			output_after((char *)format);
 *
 *
int		output_after(char *format)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (format[j])
	{
//		if (ft_qualifier(format[j])) // не пропустит если будет какие то флаги без %
//			i++;
		if (format[j] && i == 0)
		{
			write(1, &format[j], 1);
			j++;
		}
	}
	return (0);
}
*/






/*
int				ft_printf(const char *format, ...)
{
	int i;
	va_list		lst;

	i = 0;
	va_start(lst, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
//			parsing(*format);
			parsing((char *)&format[i]);
//			pars(*format, lst);
		}
		else
			ft_putchar(format[i]);
//		pars((char *)format, lst);
//		form(&format);
		i++;
	}
//	write(1, "\n", 1);
	va_end(lst);
	return (0);
}
*/