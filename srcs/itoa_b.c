/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 13:55:44 by amasol            #+#    #+#             */
/*   Updated: 2018/06/10 13:55:45 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	int		count(intmax_t nbr, int base)
{
	int i;

	i = 1;
	if (nbr < 0 && base == 10)
	{
		nbr = -nbr;
		i++;
	}
	if (nbr < 0 && base >= 11)
		nbr *= -1;
	while (nbr >= base)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

//static	void		ft_bukv_b(intmax_t nbr, int len, char *str)
//{
//	if (nbr == 10)
//		str[len] = 'A';
//	if (nbr == 11)
//		str[len] = 'B';
//	if (nbr == 12)
//		str[len] = 'C';
//	if (nbr == 13)
//		str[len] = 'D';
//	if (nbr == 14)
//		str[len] = 'E';
//	if (nbr == 15)
//		str[len] = 'F';
//}

static	void		ft_bukv_m(intmax_t nbr, int len, char *str)
{
	if (nbr == 10)
		str[len] = 'a';
	if (nbr == 11)
		str[len] = 'b';
	if (nbr == 12)
		str[len] = 'c';
	if (nbr == 13)
		str[len] = 'd';
	if (nbr == 14)
		str[len] = 'e';
	if (nbr == 15)
		str[len] = 'f';
}

static	void		transform(intmax_t nbr, int len, int base, char *str)
{
	while (nbr >= base)
	{
		if (nbr % base >= 10 && nbr % base <= 15 && base > 10)
			ft_bukv_m(nbr % base, len, str);
		else
			str[len] = nbr % base + 48;
		nbr /= base;
		len--;
	}
	if (nbr % base >= 10 && nbr % base <= 15 && base > 10)
		ft_bukv_m(nbr % base, len, str);
	else
		str[len] = nbr % base + 48;
}

static	void		transform_b(char *str, char c)
{
	int j;

	j = 0;
	if (c == 'X')
	{
		while (str[j])
		{
			if (str[j] >= 'a' && str[j] <= 'z')
				str[j] -= 32;
			j++;
		}
	}
}

char			*ft_itoa_base(intmax_t nbr, int base, char c)
{
	char	*str;
	int		len;

	len = count(nbr, base);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (nbr < 0 && base == 10)
	{
		nbr = -nbr;
		str[0] = '-';
	}
	if (nbr < 0 && base >= 11)
		nbr *= -1;
	str[len--] = '\0';
	transform(nbr, len, base, str);
	transform_b(str, c);
	return (str);
}