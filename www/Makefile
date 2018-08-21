NAME = libftprintf.a
CC := gcc
FLAGS := -Wall -Wextra -Werror
source_dirs := . src
HEADER := ft_printf.h
MAKE := make

sublibft := $(MAKE) -C libft
search_wildcards := $(addsuffix /*.c, $(source_dirs))
OBJ = $(notdir $(patsubst %.c, %.o, $(wildcard $(search_wildcards))))

LIBFT = $(addprefix libft/, ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o	\
ft_memmove.o ft_memchr.o ft_memcmp.o ft_memalloc.o ft_memdel.o ft_strlen.o	\
ft_strdup.o ft_strcpy.o ft_strncpy.o ft_strcat.o ft_strncat.o ft_strlcat.o	\
ft_strchr.o ft_strrchr.o ft_strstr.o ft_strnstr.o ft_strcmp.o ft_strncmp.o	\
ft_atoi.o ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o	\
ft_toupper.o ft_tolower.o ft_strnew.o ft_strdel.o ft_strclr.o ft_striter.o	\
ft_striteri.o ft_strmap.o ft_strmapi.o ft_strequ.o ft_strnequ.o ft_strsub.o	\
ft_strjoin.o ft_strtrim.o ft_strsplit.o ft_itoa.o ft_putchar.o ft_putstr.o	\
ft_putendl.o ft_putnbr.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o		\
ft_putnbr_fd.o)

# Executes the program 
all: $(NAME)

# notdir - deletes name of all directories;
# patsubst - creates from .c to .o;
# wildcard - extends the requisites of variable
# @$(CC) $(FLAGS) $^ $(LIBFT) -o $@ 
$(NAME): $(OBJ)
	$(sublibft)
	ar rc $@ $^ $(LIBFT)
	ranlib $(NAME)

# Finds pass for rule (%.o: %.c)
VPATH := $(source_dirs)

# Instruction for makefile which explains him how he can get ".o" files
%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $(addprefix -I, $(source_dirs)) $<

re: fclean all

clean:
	$(MAKE) clean -C ./libft
	rm -rf *.o

fclean: clean
	rm -rf $(NAME) libft/libft.a

.PHONY: clean fclean re all