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
	if (inf->wid_t > 0)
		inf->wid = inf->wid_t;
	inf->wid -= 1;
	if (flag->wid == 1 && flag->min != 1)
	{
		while (inf->wid > 0 && flag->preci == 0)
		{
			inf->r += write(1, " ", 1);
			inf->wid--;
		}
		while (inf->wid > 0 && flag->preci == 1 && flag->check_preci == 1)
		{
			inf->r += write(1, "0", 1);
			inf->wid--;
		}
		inf->r += write(1, "%", 1);
	}
	else if (flag->wid == 1 && flag->min == 1)
	{
		inf->r += write(1, "%", 1);
		while (inf->wid > 0)
		{
			inf->r += write(1, " ", 1);
			inf->wid--;
		}
	}
	else if (flag->wid == 0)
		inf->r += write(1, "%", 1);
}

void		pars_hi_z(char *format, t_flag *flag, t_inf *inf, va_list lst)
{
	intmax_t i;

	i = va_arg(lst, intmax_t);
	inf->wid -= 1;
	if (inf->wid > 0 && flag->min == 0 && flag->zero == 0)
	{
		while (inf->wid > 0  && i != 0)
		{
			inf->r += write(1, " ", 1);
			inf->wid--;
		}
		inf->r += write(1, "Z", 1);
	}
	else if (inf->wid > 0 && flag->min == 1 && flag->zero == 0)
	{
		inf->r += write(1, "Z", 1);
		while (inf->wid > 0  && i != 0)
		{
			inf->r += write(1, " ", 1);
			inf->wid--;
		}
	}
	else if (inf->wid > 0 && flag->min == 0 && flag->zero == 1 && i != 0)
	{
		while (inf->wid > 0)
		{
			inf->r += write(1, "0", 1);
			inf->wid--;
		}
		inf->r += write(1, "Z", 1);
	}
	else if (inf->wid > 0 && flag->min == 0 && flag->zero == 1 && i == 0)
	{
		while (inf->wid > 0)
		{
			inf->r += write(1, "0", 1);
			inf->wid--;
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


void				cancellation_flags_di(t_flag *flag, t_inf *inf)
{
	if (flag->min == 1 && flag->pls == 1)
	{
		inf->tmp = flag->pls;
		flag->pls = 0;
	}
	if ((flag->min == 1 || flag->preci == 1) && flag->zero == 1)
		flag->zero = 0;
}

intmax_t 			min_v_di(intmax_t i, t_flag *flag, t_inf *inf)
{
	if (i < 0)
	{
		flag->space	= 0;
		flag->pls 	= 0;
	}
	if ((i < 0 && flag->min == 0) || (i < 0 && flag->min == 1))
	{
		inf->min_v = 1;
		i *= -1;
	}
	return (i);
}
