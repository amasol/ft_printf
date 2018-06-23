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

# define APPLY (flag->hh || flag->h || flag->l || flag->ll || flag->j || flag->z)

# include "./libft/libft.h"

# include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>


typedef struct s_flag
{
//	int	z		= 1;
//	int	j		= 2;
//	int	ll		= 3;
//	int	l		= 4;
//	int	h		= 5;
//	int	hh		= 6;
	int		plus;
	int		minus;
	int		slash;
	int		space;
	int 	zero;
	int		width;
	int		precision;
	int		zero_precision;

	int		hh;
	int		h;
	int		ll;
	int		l;
	int		j;
	int		z;
}				t_flag;

void			initialization_flag(t_flag *flag);

// hh = char(- 128 +127)			(6)
// h  = short int(- 32768 + 32767)	(5)
// ll = long long int (-----------)	(3)
// l  = long int	(меньше ll)		(2)
// z  = size_t 						(1)
// j  = int max;					(0)

int				ft_printf(const char *format, ...);
void			pars_spec(char *format, va_list lst, t_flag *flag);
int				ft_qualifier(char s);
char			*ft_itoa_base(intmax_t num, int base, char c);
char			*ft_itoa_base_uintmax(uintmax_t nbr, int base, char c);
//void			cast(va_list lst, char *format);
intmax_t		cats_intmax(intmax_t i, t_flag *flag);
uintmax_t		cats_uintmax(uintmax_t i, t_flag *flag);

//-------------------------специфыкаторы
int				ft_refinement(char s);
int				ft_flag_Ddi(va_list lst, char *format, t_flag *flag);
int				ft_flag_Ss(va_list lst, char *format);
int				ft_flag_Cc(va_list lst, char *format, t_flag *flag);
int				ft_flag_Xx(va_list lst, char *format, t_flag *flag);
int				ft_flag_Uu(va_list lst, char *format, t_flag *flag);
int				ft_flag_Oo(va_list lst, char *format, t_flag *flag);
int				ft_flag_p(va_list lst, char *format);
//----------------------------------------------------

//-------------------флаги
//---------------обработка длинный всех флагов!
void				parsing(char *str, va_list lst);
void				parsing_one(char *str, t_flag *flag);
void				parsing_two(char *str, t_flag *flag);
int					ft_flag_check(char c);


//int					ft_flag(char format);
//int					ft_length_hh(char format);
//int				ft_length_h(char *tmp);
//int				ft_length_ll(char *tmp);
//int				ft_length_l(char *tmp);
//int				ft_length_j(char *tmp);
//int				ft_length_z(char *tmp);
//int				treatment(char *str, va_list lst);

void				ft_putnbr_intmax(long nb);

#endif