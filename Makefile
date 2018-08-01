NAME = libftprintf.a

SRC = ft_printf.c ft_qualifier.c find.c cast.c ft_putnbr_long.c itoa_b.c itoa_b_uintmax.c parsing.c cast_flag_Ddi.c cast_flag_Uu.c cast_flag_Cc.c cast_flag_Oo.c cast_flag_Ss.c cast_flag_p.c cast_flag_Xx.c ft_strlen_uintmax.c

CC=gcc
HDDIRS=-I ft_printf.h

LIBDIR = ./libft

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBDIR)
	$(CC) -c $(SRC) $(HDDIRS) -I libft.h
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_DIR)/%.o: ./%.c
	@gcc -c $< -o $@

clean:
	@make clean -C $(LIBDIR)
	@rm -rf $(OBJ)

main: all
	$(CC) main.c $(NAME) libft/libft.a
fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIBDIR)

re: fclean all

.PHONY: all clean fclean re
