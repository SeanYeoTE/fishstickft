
GCC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs
NAME = libftprintf.a

SRC_FILES = ft_printf.c \
			print_char.c \
			print_str.c \
			print_digit.c \
			print_hex.c \
			print_void.c \
			print_unsigned.c \


OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(AR) $(NAME) $(OBJ_FILES)

clean:
	$(RM) $(OBJ_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
