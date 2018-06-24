
#include "ft_printf.h"

intmax_t		cast_intmax(intmax_t i, t_flag *flag)
{
	if (flag->z == 1)
		return ((size_t)i);
	if (flag->j == 1)
		return ((intmax_t)i);
	if (flag->ll == 1)
		return ((long long)i);
	if (flag->l == 1)
		return ((long)i);
	if (flag->h == 1)
		return ((short)i);
	if (flag->hh == 1)
		return ((char)i);
	return (0);
}


uintmax_t		cast_uintmax(uintmax_t i, t_flag *flag)
{
	if (flag->z)
		return ((size_t)i);
	if (flag->j)
		return ((uintmax_t)i);
	if (flag->ll)
		return ((unsigned long long)i);
	if (flag->l)
		return ((unsigned long)i);
	if (flag->h)
		return ((unsigned short)i);
	if (flag->hh)
		return ((unsigned char)i);
	return (0);
}

intmax_t	cast_minus(intmax_t i, t_inf *inf)
{
	int	k;
	int j;

	k = 0;
	j = 0;
	inf->count = 0;

	j = ft_count(i);
	k = ft_atoi(inf->minus);

	inf->count = (j < k) ? k - j : j;
	return (0);
}

intmax_t 	ft_count(intmax_t n)
{
	intmax_t i;

	i = 0;
	if (n <= 0)
	{
		i++;
		n *= -1;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
