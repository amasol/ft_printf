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

# define APPLY (flag->hh || flag->h || flag->l \
			|| flag->ll || flag->j || flag->z)
# define LY (inf->width  || inf->width_two || flag->zero)

// # include "./libft/libft.h"

# include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <limits.h>

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
	int		l;
	int		ll;
	int		j;
	int		z;

	intmax_t 	ban;
}				t_flag;

typedef	struct	s_inf
{
	int			nothing;
	char		x;
	int			width;
	int			width_two;
	int 		count;
	int 		count_two;
	int 		count_three;
	int 		count_four;
	int			tmp;
	int			count_format;
	int			minus_value;
	intmax_t	result;
	uintmax_t	uint_j;
	intmax_t	intm_j;
}				t_inf;

void			initialization_flag(t_flag *flag, t_inf *inf);

// hh = char(- 128 +127)			(6)
// h  = short int(- 32768 + 32767)	(5)
// ll = long long int (-----------)	(3)
// l  = long int	(меньше ll)		(2)
// z  = size_t 						(1)
// j  = int max;					(0)

int				ft_printf(const char *format, ...);
void			pars_spec(char *format, va_list lst, t_flag *flag, t_inf *inf);
void			pars_no_spec(char *format, va_list lst, t_flag *flag, t_inf *inf);
int				ft_qualifier(char s);
char			*ft_itoa_base(intmax_t num, int base, char c);
char			*ft_itoa_base_uintmax(uintmax_t nbr, unsigned base, char c);

//----------------------------------------------------
//void			cast(va_list lst, char *format);
intmax_t		minus_value_Ddi(intmax_t i, t_flag *flag, t_inf *inf);
//intmax_t		minus_value_Uu(intmax_t i, t_flag *flag, t_inf *inf);
intmax_t		cast_intmax(intmax_t i, t_flag *flag);
uintmax_t		cast_uintmax(uintmax_t i, t_flag *flag);
intmax_t		entry_minus_intm(intmax_t i, t_inf *inf, t_flag *flag);
void			entry_minus_uint(t_inf *inf/*, t_flag *flag*/);
//entry_minus нужно что бы принемал и uintmax_t!!!!

//-------------------------------------
void			cast_flag_Ddi(t_inf *inf, intmax_t i, t_flag *flag, char *format);
void			cast_flag_Uu(t_inf *inf, uintmax_t i, t_flag *flag, char *format);
void			cast_flag_Xx(t_inf *inf, uintmax_t i, t_flag *flag, char *str);
void			cast_flag_Oo(t_inf *inf, uintmax_t i, t_flag *flag, char *str);
void			cast_flag_Ss(t_inf *inf, t_flag *flag, char *format);
void			cast_flag_Cc(t_inf *inf, t_flag *flag, char format);
void			cast_flag_p(t_inf *inf, t_flag *flag, char *format);



void			cancellation_flags_Ddi(t_flag *flag, t_inf *inf);
//void			cancellation_flags_Cc(t_flag *flag, t_inf *inf);
void			cancellation_flags_Uu(t_flag *flag, t_inf *inf);
void			cancellation_flags_Oo(t_flag *flag, t_inf *inf);

//-------------------------специфыкаторы
int				ft_refinement(char s);
int				ft_flag_Ddi(va_list lst, char *format, t_flag *flag, t_inf *inf);
int				ft_flag_Ss(va_list lst, char *format, t_flag *flag, t_inf *inf);
int				ft_flag_Cc(va_list lst, char *format, t_flag *flag, t_inf *inf);
int				ft_flag_Xx(va_list lst, char *format, t_flag *flag, t_inf *inf);
int				ft_flag_Uu(va_list lst, char *format, t_flag *flag, t_inf *inf);
int				ft_flag_Oo(va_list lst, char *format, t_flag *flag, t_inf *inf);
int				ft_flag_p(va_list lst, char *format, t_flag *flag, t_inf *inf);
//----------------------------------------------------

//-------------------флаги
//---------------обработка длинный всех флагов!
void			parsing(char *str, va_list lst, t_inf *inf);
void			parsing_one(char *str, t_flag *flag);
void			parsing_two(char *str, t_flag *flag);
int				parsing_three(char *str, t_inf *inf, t_flag *flag);
void			parsing_four(char *str, t_flag *flag, t_inf *inf);
void			parsing_five(char *str, t_inf *inf, t_flag *flag);
int				ft_flag_check(char c);
void			output_after(char *format, t_inf *inf);
int				is_zero(char *str);


//int				is_check_specs(char *str, t_inf *inf);

//int					ft_flag(char format);
//int					ft_length_hh(char format);
//int					treatment(char *str, va_list lst);

//void			ft_putnbr_intmax(intmax_t nb);

intmax_t		ft_putnbr_intmax(intmax_t nb);
uintmax_t		ft_putnbr_uintmax_t(uintmax_t nb);
uintmax_t		ft_strlen_uintmax(const char *s);
intmax_t		ft_count_int(intmax_t n);
uintmax_t		ft_count_uint(uintmax_t n);


//libft

int		ft_atoi(const char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char const *str);
void	ft_strdel(char **as);
size_t	ft_strlen(const char *s);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
void	ft_strdel(char **as);
int		ft_isdigit(int c);
int		ft_isspace(int c);
char	*ft_strnew(size_t size);
void	ft_bzero(void *s, size_t n);
int		ft_isspace(int c);
char	*ft_strchr(const char *str, int ch);

#endif