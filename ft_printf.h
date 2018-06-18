/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 14:07:40 by amasol            #+#    #+#             */
/*   Updated: 2018/04/12 14:07:42 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
//# define CAST (f->hh || f->h || f->l || f->ll || f->j || f->z)

# include "./libft/libft.h"

# include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct s_flag
{
//	int	z		= 1;
//	int	j		= 2;
//	int	ll		= 3;
//	int	l		= 4;
//	int	h		= 5;
//	int	hh		= 6;
	int plus	= 0;
	int minus	= 0;
	int rechet	= 0;
	int probel	= 0;
	int nol		= 0;
}				t_flag;

// hh = char(- 128 +127)			(6)
// h  = short int(- 32768 + 32767)	(5)
// ll = long long int (-----------)	(3)
// l  = long int	(меньше ll)		(2)
// z  = size_t 						(1)
// j  = int max;					(0)

int				ft_printf(const char *format, ...);
void			pars(char format, va_list lst);
int				ft_qualifier(char s);
char			*ft_itoa_base(intmax_t num, int base, char c);
char			*ft_itoa_base_uintmax(uintmax_t nbr, int base, char c);
//intmax_t		cats_intmax(char format, va_list lst);
//uintmax_t		cats_uintmax(char format, va_list lst);

//-------------------------специфыкаторы
int				ft_refinement(char s);
int				ft_flag_Ddi(va_list lst, char format);
int				ft_flag_Ss(va_list lst, char format);
int				ft_flag_Cc(va_list lst, char format);
int				ft_flag_Xx(va_list lst, char format);
int				ft_flag_Uu(va_list lst, char format);
int				ft_flag_Oo(va_list lst, char format);
int				ft_flag_p(va_list lst, char format);
//----------------------------------------------------

//-------------------флаги
//---------------обработка длинный всех флагов!
void				parsing(char format);
int					ft_flag_check(char c);
int					ft_flag(char format);
int					ft_length_hh(char format);
//int				ft_length_h(char *tmp);
//int				ft_length_ll(char *tmp);
//int				ft_length_l(char *tmp);
//int				ft_length_j(char *tmp);
//int				ft_length_z(char *tmp);
//int				treatment(char *str, va_list lst);

#endif