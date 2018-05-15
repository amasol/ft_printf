#include "ft_printf.h"

void		pars(char *format, va_list lst)
{
	format = format + 1;
	if (ft_qualifier(*format))
	{
		if (ft_refinement(*format) == 1)
			ft_flag_Ddi(lst);
//		else if (ft_refinement(*format) == 2)
//			ft_flag_Cc(lst, format);
		else if (ft_refinement(*format) == 3)
			ft_flag_Ss(lst, format);
	/*	else if (ft_refinement(*format) == 4)
			ft_flag_Xx();
		else if (ft_refinement(*format) == 5)
			ft_flag_Oo();
		else if (ft_refinement(*format) == 6)
			ft_flag_Uu();
		else if (ft_refinement(*format) == 7)
			ft_flag_p();*/
	}
}

int		ft_flag_Ddi(va_list lst)
{
	int	i;

	i = va_arg(lst, int);
	if (i)
	{
		ft_putnbr(i);
		i++;
	}
	return (i);
}

// (c)Вывод символа, соответстветсвующего числу указанному в аргументе функции.
// Приводится к типу unsigned char.
//(С) рассматриваеться как (с) с подификатором (l)
/*
void		ft_flag_Cc(va_list lst, char *format)
{
	int j;

	j = 0;
	j = va_arg(lst, unsigned char);
	{
		//////////;
	}
}

 */

//----------------------
// Строка выводится пока не будет встречен символ конец строки (/0).
// По умолчанию строка должна обозначаться как char*.
// Если указан модификатор l, то строка интерпитируется как wchar_t*.
// Для функции wprintf строка по умолчанию обрабатывается как wchar_t*.
//

char		*ft_flag_Ss(va_list lst, char *format)
{
	char *str;
	int i;

	i = 0;
	if (*format == 's')
	{
		str = va_arg(lst, char *);
		while (str[i])
		{
			ft_putstr(&str[i]);
			i++;
		}
	}
	return (str);
}