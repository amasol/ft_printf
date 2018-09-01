/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_flag_Ss.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 17:12:50 by amasol            #+#    #+#             */
/*   Updated: 2018/07/16 17:12:52 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		cast_flag_s(t_inf *inf, t_flag *flag, char *str)
{
	// флаг -
	char *tmp;
	inf->cou = (inf->uint_j > (uintmax_t)inf->width) ? inf->uint_j : inf->width - inf->uint_j;
	if (inf->width_two > inf->width)
		inf->cou_t = (inf->width_two > inf->width) ? inf->width_two - inf->width : 0;

	if (str == NULL  && (inf->width == 6 || flag->space == 1 || inf->nothi == 0 || flag->plus == 1))
	{
		inf->width = (inf->width == 6 || inf->width > 6) ? 6 : inf->width;
		if (flag->width == 1 && inf->width)
		{
			inf->r += write(1, "(null)", inf->width);
			inf->width--;
		}
		else
			inf->r += write(1, "(null)", 6);
	}
	else if (str == NULL)
	{
		while (flag->width == 1 && inf->width > 0)
		{
			inf->r += write(1, "0", 1);
			inf->width--;
		}
	}
	else if (inf->cou > 0 && flag->min == 1 && flag->preci == 0 && inf->width == 0)
	{
		if (flag->space == 1)
			inf->r += write(1, " ", 1);
		tmp = ft_strsub(str, 0, inf->cou);
		inf->r += ft_strlen_uintmax(tmp);
		ft_putstr(tmp);
//		ft_strdel(&tmp);
	}
//		флан zero
	else if (flag->zero == 1)
	{
		while (inf->cou > 0)
		{
			inf->r += write(1, "0", 1);
			inf->cou--;
		}
		tmp = ft_strsub(str, 0, inf->width);
		inf->r += ft_strlen_uintmax(tmp);
		ft_putstr(tmp);
//		ft_strdel(&tmp);
		while (inf->cou_t > 0)
		{
			inf->r += write(1, " ", 1);
			inf->cou_t--;
		}}
	// 		флаг	 ширины
	else if (inf->cou >= 0 && flag->width == 1 && flag->preci == 0 &&
			 flag->min != 1 && inf->min_v != 1 && inf->nothi == 1)
	{
		while (inf->cou > 0)
		{
			inf->r += write(1, " ", 1);
			inf->cou--;
		}
		tmp = ft_strsub(str, 0, inf->width);
		inf->r += ft_strlen_uintmax(tmp);
		ft_putstr(tmp);
		ft_strdel(&tmp);
	}
		//	флаг	 ширины и флаг min
	else if (flag->width == 1 && flag->preci == 0 &&
			 inf->width > 0 && (flag->min == 1) && flag->h == 0)
	{
		tmp = ft_strsub(str, 0, inf->width);
		inf->r += ft_strlen_uintmax(tmp);
		ft_putstr(tmp);
//		ft_strdel(&tmp);
		if (flag->min == 1 && flag->ban < inf->width && inf->tmp == 1)
			inf->r += write(1, " ", 1);
		while (inf->cou > 0)
		{
			inf->r += write(1, " ", 1);
			inf->cou--;
		}
	}
	else if ((flag->zero == 0 || flag->min == 0) && flag->plus == 1 && flag->preci == 0 &&
			 inf->width == 0)
	{
		if (inf->width == 0 && inf->cou > 0)
		{
			inf->r += ft_strlen_uintmax(str);
			ft_putstr(str);
		}
		tmp = ft_strsub(str, 0, inf->width);
		inf->r += ft_strlen_uintmax(tmp);
		ft_putstr(tmp);
//		ft_strdel(&tmp);
	}
	else if (flag->space == 1 && flag->preci != 1)
	{
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
	}
	else if (flag->preci == 1 && inf->cou > 0 && inf->cou_t == 0 && *str == '\0')
	{
		if ((flag->plus == 1) && flag->min == 0 && (inf->width < inf->width_two))
			inf->r += write(1, " ", 1);
		while (inf->cou_t > 0)
		{
			inf->r += write(1, " ", 1);
			inf->cou_t--;
		}
		tmp = ft_strsub(str, 0, inf->width);
		inf->r += ft_strlen_uintmax(tmp);
		ft_putstr(tmp);
	}
//		точность (.)
	else if (flag->preci == 1 && inf->cou > 0 && inf->width_two == 0
			 && flag->min != 1  && inf->nothi == 1 && flag->check_preci == 0)
	{
		inf->cou = (inf->width > inf->uint_j) ? inf->uint_j : inf->width;
		if ((flag->plus == 1) && flag->min == 0 && (inf->width < inf->width_two))
			inf->r += write(1, " ", 1);
		tmp = ft_strsub(str, 0, inf->cou);
		inf->r += ft_strlen_uintmax(tmp);
		ft_putstr(tmp);
		ft_strdel(&tmp);
	}

//		точность (.) && flag->preci == 1
	else if (flag->preci == 1 && inf->cou > 0 && inf->width_two == 0
			 && flag->min != 1  && inf->nothi == 1 && flag->check_preci == 1)
	{
		if ((flag->plus == 1) && flag->min == 0 && (inf->width < inf->width_two))
			inf->r += write(1, " ", 1);
		while (inf->width > 0)
		{
			inf->r += write(1, " ", 1);
			inf->width--;
		}
	}
//		точность (ширина + точность когда ширина больше точности!)
	else if (flag->preci == 1 && inf->width_two >= inf->width
			 && flag->min == 0 && inf->nothi == 1)
	{
		inf->width_two = (inf->width > inf->uint_j) ? inf->width_two - inf->uint_j : inf->width_two;
		inf->width_two = (inf->width < inf->uint_j) ? inf->width_two - inf->width : inf->width_two;
		while (inf->width_two > 0)
		{
			inf->r += write(1, " ", 1);
			inf->width_two--;
		}
		tmp = ft_strsub(str, 0, inf->width);
		inf->r += ft_strlen_uintmax(tmp);
		ft_putstr(tmp);
		ft_strdel(&tmp);
	}

//		точность (ширина точность и флаг минут)
	else if (flag->preci == 1 && flag->min == 1 && inf->cou >= 0 &&
			 inf->cou_t >= 0)
	{
		tmp = ft_strsub(str, 0, inf->width);
		inf->r += ft_strlen_uintmax(tmp);
		ft_putstr(tmp);
		while (inf->cou > 0 && flag->min == 1 && *str == '\0')
		{
			inf->r += write(1, " ", 1);
			inf->cou--;
		}
		while (inf->cou_t > 0 && flag->min == 1)
		{
			inf->r += write(1, " ", 1);
			inf->cou_t--;
		}
		ft_strdel(&tmp);
	}

	else if (flag->preci == 1 && inf->cou == 0 && inf->cou_t > 0)
	{
		while (inf->cou > 0)
		{
			inf->r += write(1, "0", 1);
			inf->cou--;
		}
		while (inf->cou_t > 0)
		{
			inf->r += write(1, " ", 1);
			inf->cou_t--;
		}
		tmp = ft_strsub(str, 0, inf->width);
		inf->r += ft_strlen_uintmax(tmp);
		ft_putstr(tmp);
	}
	else if (flag->preci == 1 && flag->plus == 1)
	{
		while (inf->cou > 0)
		{
			inf->r += write(1, " ", 1);
			inf->cou--;
		}
		tmp = ft_strsub(str, 0, inf->width);
		inf->r += ft_strlen_uintmax(tmp);
		ft_putstr(tmp);
	}
	else if (inf->nothi == 0)
	{
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
	}
}

void		cast_flag_S(t_inf *inf, t_flag *flag, wchar_t *str)
{
	int i;

	i = 0;

	while (str && str[i])
	{
		inf->uint_j += ft_lenwchar(str[i]);
		i++;
	}
	i = 0;
	if (str == NULL && (flag->space == 1 || inf->width == 6 || inf->nothi == 0 || flag->plus == 1))
	{
		inf->width = (inf->width == 6 || inf->width > 6) ? 6 : inf->width;
		if (flag->width == 1 && inf->width)
		{
			inf->r += write(1, "(null)", inf->width);
			inf->width--;
		}
		else
			inf->r += write(1, "(null)", 6);
	}
	else if (str == NULL)
	{
		while (flag->width == 1 && inf->width > 0)
		{
			inf->r += write(1, "0", 1);
			inf->width--;
		}
	}
//	без точности
	else if (flag->width == 1 && flag->preci == 0 && flag->zero == 0)
	{
		inf->cou = (inf->uint_j < inf->width) ? inf->width - inf->uint_j : inf->r;
		while (inf->cou > 0)
		{
			inf->r += write(1, " ", 1);
			inf->cou--;
		}
		while (str[i])
		{
			ft_putwchar(str[i], inf);
			i++;
		}
	}
	else if (flag->zero == 1 && flag->preci == 0 && flag->width == 1)
	{
		inf->cou = (inf->uint_j < inf->width) ? inf->width - inf->uint_j : inf->r;
		while (inf->cou > 0)
		{
			inf->r += write(1, "0", 1);
			inf->cou--;
		}
		while (str[i])
		{
			ft_putwchar(str[i], inf);
			i++;
		}
	}
	else if (flag->width == 1 && flag->preci == 1
			 && flag->check_preci == 1 && flag->zero == 1)
	{
		inf->cou = inf->width;
		while (inf->cou > 0 && str[i] != '\0')
		{
			inf->r += write(1, "0", 1);
			inf->cou--;
		}
	}
//	с точностью и шириной по левому краю
	else if (flag->width == 1 && flag->preci == 1
			&& flag->check_preci == 1 && inf->width_two == 0)
	{
		inf->cou = inf->width;
		while (inf->cou > 0 && str[i] != '\0')
		{
			inf->r += write(1, " ", 1);
			inf->cou--;
		}
	}
//		с точностью и шириной по правому краю
	else if (flag->width == 1 && flag->preci == 1 && flag->check_preci == 0)
	{
		inf->uint_j = 0;
		while (str[i] && inf->width != 0 &&  inf->uint_j < inf->width)
		{
			inf->uint_j += ft_lenwchar(str[i]);
			if (inf->width >= inf->uint_j && inf->uint_j <= inf->width)
			{
				ft_putwchar(str[i], inf);
				inf->width -= inf->uint_j;
				inf->uint_j = 0;
			}
			i++;
		}
	}
	else if (flag->width == 1 && flag->preci == 1 && inf->width > 0 && inf->width_two > 0)
	{
		inf->uint_j = 0;
		inf->cou_t = (inf->width_two > inf->width) ? inf->width_two - inf->width : 0;
		while (inf->cou_t > 0)
		{
			inf->r += write(1, " ", 1);
			inf->cou_t--;
		}
		while (str[i] && inf->width != 0 &&  inf->uint_j < inf->width)
		{
			inf->uint_j += ft_lenwchar(str[i]);
			if (inf->width >= inf->uint_j && inf->uint_j <= inf->width)
			{
				ft_putwchar(str[i], inf);
				inf->width -= inf->uint_j;
				inf->uint_j = 0;
			}
			i++;
		}
	}
	else if ((flag->space == 1 || flag->plus == 1) && flag->l == 0)
	{
		while (str[i])
		{
			ft_putwchar(str[i], inf);
			i++;
		}
	}

	else if (flag->preci == 1 || flag->l == 1)
	{
		while (str[i])
		{
			ft_putwchar(str[i], inf);
			i++;
		}
	}
	else if (flag->width == 0 && flag->preci == 0 && flag->space == 0 && flag->plus == 0)
	{
		while (str[i])
		{
			ft_putwchar(str[i], inf);
			i++;
		}
	}
}
