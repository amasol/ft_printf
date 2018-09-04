cmake_minimum_required(VERSION 3.9)
project(ft_printf)

set(CMAKE_CXX_STANDARD 11)

add_executable(ft_printf
        srcs/ft_atoi.c
        srcs/ft_isdigit.c
        srcs/ft_isspace.c
        srcs/ft_putchar.c
        srcs/ft_putnbr.c
        srcs/ft_putstr.c
        srcs/ft_strdel.c
        srcs/ft_atoi.c
        srcs/ft_strnew.c
        srcs/ft_bzero.c
        srcs/ft_isspace.c
        srcs/ft_strsub.c
        srcs/ft_strlen.c
        srcs/find.c
        srcs/ft_printf.c
        includes/ft_printf.h
        srcs/ft_qualifier.c
#        main.c
        srcs/itoa_b_uintmax.c
        srcs/parsing.c
        srcs/ft_putnbr_long.c
        srcs/cast.c
        srcs/cast_flag_di.c
        srcs/cast_flag_s.c
        srcs/cast_flag_c.c
        srcs/cast_flag_x.c
        srcs/cast_flag_u.c
        srcs/cast_flag_o.c
        srcs/cast_flag_p.c
        main2.c
        srcs/ft_strlen_uintmax.c
        srcs/no_spec.c
        srcs/ft_putwchar.c
        srcs/ft_lenwchar.c
        srcs/ft_putstr_len.c
        srcs/help.c
        srcs/cast_flag_ss.c
        srcs/help_2.c)
#        print_test.c)
