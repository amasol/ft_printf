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
        srcs/itoa_b.c
        srcs/itoa_b_uintmax.c
        srcs/parsing.c
        srcs/ft_putnbr_long.c
        srcs/cast.c
        srcs/cast_flag_Ddi.c
        srcs/cast_flag_Ss.c
        srcs/cast_flag_Cc.c
        srcs/cast_flag_Xx.c
        srcs/cast_flag_Uu.c
        srcs/cast_flag_Oo.c
        srcs/cast_flag_p.c
        main2.c
        srcs/ft_strlen_uintmax.c
        srcs/no_spec.c
        srcs/ft_strchr.c)
#        print_test.c)
