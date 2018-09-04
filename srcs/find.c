/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 17:49:03 by amasol            #+#    #+#             */
/*   Updated: 2018/07/16 17:49:09 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	pars_spec_h2(char *format, va_list lst, t_flag *flag, t_inf *inf)
{
	int i;

	i = 0;
	if (ft_refinement(format[i]) == 6)
		ft_flag_u(lst, &format[i], flag, inf);
	else if (ft_refinement(format[i]) == 7)
		ft_flag_p(lst, &format[i], flag, inf);
	else if (format[i] == '%')
		pars_no_spec(flag, inf);
}

static void	pars_spec_h(char *format, va_list lst, t_flag *flag, t_inf *inf)
{
	int i;

	i = 0;
	if (ft_refinement(format[i]) == 3)
	{
		if (format[i] == 's' || (*format == 's' && flag->l == 1))
			ft_flag_s(lst, &format[i], flag, inf);
		else
			ft_flag_ss(lst, &format[i], flag, inf);
	}
	else if (ft_refinement(format[i]) == 4)
	{
		if (format[i] == 'x')
			ft_flag_x(lst, &format[i], flag, inf);
		else
			ft_flag_xx(lst, &format[i], flag, inf);
	}
	else if (ft_refinement(format[i]) == 5)
	{
		if (format[i] == 'o')
			ft_flag_o(lst, &format[i], flag, inf);
		else
			ft_flag_oo(lst, &format[i], flag, inf);
	}
	pars_spec_h2(&format[i], lst, flag, inf);
}

void		pars_spec(char *format, va_list lst, t_flag *flag, t_inf *inf)
{
	int	i;

	i = 0;
	if (format[i])
	{
		if (ft_qualifier(format[i]))
		{
			if (ft_refinement(format[i]) == 1)
			{
				if (format[i] == 'd' || format[i] == 'i')
					ft_flag_di(lst, &format[i], flag, inf);
				else
					ft_flag_dd(lst, &format[i], flag, inf);
			}
			else if (ft_refinement(format[i]) == 2)
			{
				if (format[i] == 'c' || (*format == 'c' && flag->l == 1))
					ft_flag_c(lst, &format[i], flag, inf);
				else
					ft_flag_cc(lst, &format[i], flag, inf);
			}
			pars_spec_h(&format[i], lst, flag, inf);
		}
	}
}

int			ft_flag_dd(va_list lst, char *format, t_flag *flag, t_inf *inf)
{
	int			k;
	intmax_t	j;

	k = 0;
	j = 0;
	if (format[k] == 'D')
	{
		if (flag->hh)
			j = (unsigned short)va_arg(lst, int);
		else
			j = va_arg(lst, long);
		min_v_di(j, flag, inf);
		cancellation_flags_di(flag, inf);
		if (LY)
			entry_min_intm(j, inf, flag);
		cast_flag_di(inf, j, flag, format);
	}
	return (1);
}

int			ft_flag_di(va_list lst, char *format, t_flag *flag, t_inf *inf)
{
	int			k;
	intmax_t	i;

	k = 0;
	i = 0;
	if (format[k] == 'd' || format[k] == 'i')
	{
		i = va_arg(lst, intmax_t);
		i = (APPLY) ? (cast_intmax(i, flag, inf)) : (int)i;
		i = min_v_di(i, flag, inf);
		cancellation_flags_di(flag, inf);
		if (LY)
			entry_min_intm(i, inf, flag);
		cast_flag_di(inf, i, flag, format);
	}
	return (1);
}
