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

int				parsing(char **format/*, va_list lst*/)
{
	char *tmp;
//	char	*pos;
	int j;
	int i;

	j = 0;
	i = 0;
	tmp = (char *) malloc(sizeof(char) * ft_strlen(&str[j]));
//	if (pos = ft_strchr(*format, "%"))
//	{
//		write(1, str, ft_strlen(pos - format));
//	}
	if (str[j] != '%')
	{
//		write(1, &format[j], 1);
		j++;
	}
	else
	{
		while (format[j] == '%')
		{
			j = j + 1;
			while (ft_strchr(&format[j], ft_qualifier(format[j])))
			{
				tmp = ft_strncpy(&tmp[i], &format[j], i);
				j++;
				i++;
			}
		}
		station_flags_qualifiers(&tmp[i]/*, lst*/);
	}
	return (0);
}
			//  station_flags_qualifiers - участок флагов и спецификаторов..
int				station_flags_qualifiers(char *tmp/*, va_list lst*/)  // буду обрабатывать всю длинну, дальше
//																	переходить посимвольно...
//	если мы видим сразу длинну, то мы отсылаем в функцию с длинной...если ее нету а идет специ-
//	фикатор, работаем с ним и отсылаем его в проверку ft_refinement(tmp[j]);
{
	int i;

	i = 0;
	// тут лежит наш участок обрезаный, без % и до спецификатора!
	if (ft_length(&tmp[i]))  // если нету длинный , то переходим к спецификатору !
	{
		return (0);
	}
	else
	{
		if (ft_qualifier(tmp[i]))
		{
			return (0);
		}
	}
	return (0);
}

//	determination_of - определение.. после функции  ft_refinement - уточнение какой именно спцф

static	int 	ft_determination_of(char s, va_list lst)
{

}
//*/

/*
{
	intmax_t i;

	i = va_arg(lst, intmax_t);
	while (i)
	{
		ft_putnbr(i);
		i++;
	}
	return (0);
}
*/