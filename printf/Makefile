
GCC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

NAME = libftprintf.a

<<<<<<< HEAD
SRC_FILES = ft_printf.c \
			print_char.c \
			print_str.c \
			print_digit.c \
			print_hex.c \
			print_void.c \
			print_unsigned.c \
=======
SRC = ft_printf
SRC_FILES = $(addsuffix .c, $(SRC))
>>>>>>> aee60af7ba446c401d5fcfbd3fe7b5b7f220fe01


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
