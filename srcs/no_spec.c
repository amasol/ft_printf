/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_spec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:19:24 by amasol            #+#    #+#             */
/*   Updated: 2018/08/22 15:19:25 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		pars_no_spec(char *format, va_list lst, t_flag *flag, t_inf *inf)
{
	if (inf->width_two > 0)
		inf->width = inf->width_two;
	inf->width -= 1;
	if (flag->width == 1 && flag->min != 1)
	{
		while (inf->width > 0 && flag->preci == 0)
		{
			inf->r += write(1, " ", 1);
			inf->width--;
		}
		while (inf->width > 0 && flag->preci == 1 && flag->check_preci == 1)
		{
			inf->r += write(1, "0", 1);
			inf->width--;
		}
		inf->r += write(1, "%", 1);
	}
	else if (flag->width == 1 && flag->min == 1)
	{
		inf->r += write(1, "%", 1);
		while (inf->width > 0)
		{
			inf->r += write(1, " ", 1);
			inf->width--;
		}
	}
	else if (flag->width == 0)
		inf->r += write(1, "%", 1);
}

void		pars_hi_z(char *format, t_flag *flag, t_inf *inf, va_list lst)
{
	intmax_t i;

	i = va_arg(lst, intmax_t);
	inf->width -= 1;
	if (inf->width > 0 && flag->min == 0 && flag->zero == 0)
	{
		while (inf->width > 0  && i != 0)
		{
			inf->r += write(1, " ", 1);
			inf->width--;
		}
		inf->r += write(1, "Z", 1);
	}
	else if (inf->width > 0 && flag->min == 1 && flag->zero == 0)
	{
		inf->r += write(1, "Z", 1);
		while (inf->width > 0  && i != 0)
		{
			inf->r += write(1, " ", 1);
			inf->width--;
		}
	}
	else if (inf->width > 0 && flag->min == 0 && flag->zero == 1 && i != 0)
	{
		while (inf->width > 0)
		{
			inf->r += write(1, "0", 1);
			inf->width--;
		}
		inf->r += write(1, "Z", 1);
	}
	else if (inf->width > 0 && flag->min == 0 && flag->zero == 1 && i == 0)
	{
		while (inf->width > 0)
		{
			inf->r += write(1, "0", 1);
			inf->width--;
		}
		inf->r += write(1, "Z", 1);
	}
	else
		while (*format)
		{
			ft_putchar(*format);
			inf->r += 1;
			format++;
		}
}
