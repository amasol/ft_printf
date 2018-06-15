
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


static	int		count(long num, int base)
{
	int i;

	i = 1;
	if (num < 0 && base == 10)
	{
		num = -num;
		i++;
	}
	while (num >= base)
	{
		num /= base;
		i++;
	}
	return (i);
}

static	void		ft_bukv_b(int nbr, int len, char *str)
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

static	void		ft_bukv_m(int nbr, int len, char *str)
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


static	void		transform(long nbr, int len, int base, char *str)
{
	while (nbr >= base)
	{
		if (nbr % base >= 10 && nbr % base <= 15 && base > 10)
				ft_bukv_b(nbr % base, len, str);
		else
			str[len] = nbr % base + 48;
		nbr /= base;
		len--;
	}
	if (nbr >= 10 && nbr <= 15 && base > 10)
		ft_bukv_b(nbr, len, str);
	else
		str[len] = nbr % base + 48;
}

char			*ft_itoa_base(int num, int base)
{
	long	nbr;
	char	*str;
	int		len;

	nbr = num;
	len = count(nbr, base);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (nbr < 0 && base == 10)
	{
		nbr = -nbr;
		str[0] = '-';
	}
	str[len--] = '\0';
	transform(nbr, len, base, str);
	return (str);
}

int 	main(void)
{
	printf("%s\n", ft_itoa_base(-12345432, 10));
	return (0);
}