NAME := libftprintf.a

SRC := 	ft_printf.c ft_qualifier.c find.c cast.c ft_putnbr_long.c itoa_b.c itoa_b_uintmax.c parsing.c
        cast_flag_Ddi.c print_test.c

OBJ_DIR := obj

FLAGS := -Wall -Wextra -Werror

LIBDIR := ./libft

OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBDIR)
	@cd $(LIBDIR) && mv *.o ../obj
	@ar rc $(NAME) obj/*.o

$(OBJ_DIR)/%.o: ./%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBDIR)
	@rm -rf obj

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIBDIR)

re: fclean all

.PHONY: all clean fclean re
