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
#include <stdarg.h>

int				ft_printf(const char *str, ...);
int				ft_qualifier(char s);
int				parsing(char *str, va_list lst);
int				parsing_d(int d, va_list lst);

#endif