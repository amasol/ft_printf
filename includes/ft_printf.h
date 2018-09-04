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
# define LY (inf->wid  || inf->wid_t || flag->zero)

// # include "./libft/libft.h"

# include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>


#include <limits.h>
#include <locale.h>

typedef struct s_flag
{
//	int	z		= 1;
//	int	j		= 2;
//	int	ll		= 3;
//	int	l		= 4;
//	int	h		= 5;
//	int	hh		= 6;
	int			pls;
	int			min;
	int			slash;
	int			space;
	int 		zero;
	int			wid;
	int			preci;
	int			check_preci;
	int			zero_preci;

	int			hh;
	int			h;
	int			l;
	int			ll;
	int			j;
	int			z;
	int			nothi_flag;

	intmax_t 	ban;
}				t_flag;

typedef	struct	s_inf
{
	int			nothi;
	char		x;
	int			wid;
	int			wid_t;
	int 		cou;
	int 		cou_t;
	int 		cou_three;
	int 		cou_four;
	int			tmp;
	int			cou_format;
	int			min_v;
	intmax_t	r;
	intmax_t	r_h;
	uintmax_t	un_j;
	intmax_t	intm_j;
}				t_inf;

void			initialization_flag(t_flag *flag, t_inf *inf);

// hh = char(- 128 +127)			(6)
// h  = short int(- 32768 + 32767)	(5)
// ll = long long int (-----------)	(3)
// l  = long int	(меньше ll)		(2)
// z  = size_t 						(1)
// j  = int max;					(0)

int			ft_printf(const char *format, ...);
void		pars_spec(char *format, va_list lst, t_flag *flag, t_inf *inf);
void		pars_no_spec(t_flag *flag, t_inf *inf);
int			pars_hi_z(char *format, t_flag *flag, t_inf *inf, va_list lst);
int			ft_qualifier(char s);
char		*ft_itoa_base_uintmax(uintmax_t nbr, unsigned base, char c);

//----------------------------------------------------
intmax_t	min_v_di(intmax_t i, t_flag *flag, t_inf *inf);
intmax_t	cast_intmax(intmax_t i, t_flag *flag, t_inf *inf);
uintmax_t	cast_uintmax(uintmax_t i, t_flag *flag , t_inf *inf);
intmax_t	entry_min_intm(intmax_t i, t_inf *inf, t_flag *flag);
void		entry_min_uint(t_inf *inf);

//-------------------------------------
int			cast_flag_di(t_inf *inf, intmax_t i, t_flag *flag, char *format);
void		cast_flag_u(t_inf *inf, uintmax_t i, t_flag *flag);
int			cast_flag_x(t_inf *inf, uintmax_t i, t_flag *flag, char *str);
int			cast_flag_o(t_inf *inf, uintmax_t i, t_flag *flag, char *str);
int			cast_flag_s(t_inf *inf, t_flag *flag, char *format);
int			cast_flag_ss(t_inf *inf, t_flag *flag, wchar_t *str);
void		cast_flag_c(t_inf *inf, t_flag *flag, char format);
void		cast_flag_cc(t_inf *inf, t_flag *flag, wchar_t c);
int			cast_flag_p(t_inf *inf, uintmax_t i, t_flag *flag, char *format);



void		cancellation_flags_di(t_flag *flag, t_inf *inf);

//-------------------------специфыкаторы
int			ft_refinement(char s);
int			ft_flag_di(va_list lst, char *format, t_flag *flag, t_inf *inf);
int			ft_flag_dd(va_list lst, char *format, t_flag *flag, t_inf *inf);
int			ft_flag_s(va_list lst, char *format, t_flag *flag, t_inf *inf);
int			ft_flag_ss(va_list lst, char *format, t_flag *flag, t_inf *inf);
int			ft_flag_c(va_list lst, char *format, t_flag *flag, t_inf *inf);
int			ft_flag_cc(va_list lst, char *format, t_flag *flag, t_inf *inf);
int			ft_flag_x(va_list lst, char *format, t_flag *flag, t_inf *inf);
int			ft_flag_xx(va_list lst, char *format, t_flag *flag, t_inf *inf);
int			ft_flag_u(va_list lst, char *format, t_flag *flag, t_inf *inf);
int			ft_flag_o(va_list lst, char *format, t_flag *flag, t_inf *inf);
int			ft_flag_oo(va_list lst, char *format, t_flag *flag, t_inf *inf);
int			ft_flag_p(va_list lst, char *format, t_flag *flag, t_inf *inf);
//----------------------------------------------------


//-------------------флаги
//---------------обработка длинный всех флагов!
void		parsing(char *str, va_list lst, t_inf *inf);
void		parsing_one(char *str, t_flag *flag);
void		parsing_two(char *str, t_flag *flag);
void		parsing_three(char *str, t_inf *inf, t_flag *flag);
void		parsing_four(char *str, t_flag *flag, t_inf *inf);
void		parsing_five(char *str, t_inf *inf, t_flag *flag);
int			ft_flag_check(char c);
int			output_after(char *format, va_list lst, t_flag *flag, t_inf *inf);
int			is_zero(char *str);
int			is_check_specs(char s);
int			is_check_preci(char *str, t_flag *flag);


intmax_t	ft_putnbr_intmax(intmax_t nb);
uintmax_t	ft_putnbr_uintmax_t(uintmax_t nb);
uintmax_t	ft_strlen_uintmax(const char *s);
intmax_t	ft_cou_int(intmax_t n);
uintmax_t	ft_cou_uint(uintmax_t n);

int			cast_flag_di_h5(t_inf *inf, intmax_t i, t_flag *flag, char *str);
int			cast_flag_p_h5(t_inf *inf, uintmax_t i, t_flag *flag, char *str);
int			cast_flag_s_h5(t_inf *inf, t_flag *flag, char *str, char *tmp);
int			cast_flag_ss_h5(t_inf *inf, t_flag *flag, wchar_t *str);
int			cast_flag_x_h5(t_inf *inf, uintmax_t i, t_flag *flag, char *str);


//libft

int			ft_atoi(const char *str);
void		ft_putchar(char c);
void		ft_putnbr(int nb);
void		ft_putstr(char const *str);
int			ps_l(char const *str, int i);
void		ft_strdel(char **as);
size_t		ft_strlen(const char *s);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
void		ft_strdel(char **as);
int			ft_isdigit(int c);
int			ft_isspace(int c);
char		*ft_strnew(size_t size);
void		ft_bzero(void *s, size_t n);
int			ft_isspace(int c);
void		ft_putwchar(wchar_t c, t_inf *inf);
int			ft_lenwchar(wchar_t c);

#endif