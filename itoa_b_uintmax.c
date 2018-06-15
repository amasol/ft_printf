#include "ft_printf.h"

static	int		count(uintmax_t nbr, int base)
{
	int i;

	i = 1;
	while (nbr >= base)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

static	void		ft_bukv_b(uintmax_t nbr, int len, char *str)
{
	if (nbr == 10)
		str[len] = 'A';
	if (nbr == 11)
		str[len] = 'B';
	if (nbr == 12)
		str[len] = 'C';
	if (nbr == 13)
		str[len] = 'D';
	if (nbr == 14)
		str[len] = 'E';
	if (nbr == 15)
		str[len] = 'F';
}

static	void		ft_bukv_m(uintmax_t nbr, int len, char *str)
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

static	void		transform(uintmax_t nbr, int len, int base, char *str, char c)
{
	while (nbr >= base)
	{
		if (nbr % base >= 10 && nbr % base <= 15 && base > 10)
		{
			if (c == 'X')
				ft_bukv_b(nbr % base, len, str);
			else if (c == 'x')
				ft_bukv_m(nbr % base, len, str);
		}
		else
			str[len] = nbr % base + 48;
		nbr /= base;
		len--;
	}
	if (nbr % base >= 10 && nbr % base <= 15 && base > 10)
	{
		if (c == 'X')
			ft_bukv_b(nbr % base, len, str);
		else if (c == 'x')
			ft_bukv_m(nbr % base, len, str);
	}
	else
		str[len] = nbr % base + 48;
}

char			*ft_itoa_base_uintmax(uintmax_t nbr, int base, char c)
{
	char	*str;
	int		len;

	len = count(nbr, base);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len--] = '\0';
	transform(nbr, len, base, str, c);
	return (str);
}