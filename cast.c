
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

intmax_t	entry_minus(intmax_t i, t_inf *inf, t_flag *flag)
{// можно приминить эту функцию как для ширины так и для минуса !!!
	int j;

	j = 0;

	inf->count 		= 0;
	inf->count_two	= 0;
	j = ft_count(i);
	if (inf->width > 0)
		inf->count = (j <= inf->width) ? inf->width - j : j;
	if (flag->plus == 1 || inf->tmp == 1 || flag->space == 1 || inf->minus_value == 1)
	{
		if (inf->width_two == 0 || inf->minus_value == 1)
			inf->count = inf->count - 1;
	}
	if (inf->width_two > 0)
		inf->count_two = (inf->width_two > inf->width) ? inf->width_two - inf->width : 0;
//		inf->count_two = inf->width_two - inf->width;
	if (inf->count_two > 0 && (flag->plus == 1 || inf->tmp == 1))
		inf->count_two = inf->count_two - 1;
	return (0);
}

intmax_t 	ft_count(intmax_t n) // считает кол-во символов в строке
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
