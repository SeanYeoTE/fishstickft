# Compiler flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Source files
SRC_FILES = ft_bzero.c ft_isprint.c ft_strchr.c ft_strrchr.c \
			ft_isalnum.c ft_memchr.c ft_strlcat.c ft_tolower.c \
			ft_isalpha.c ft_memcpy.c ft_strlcpy.c ft_toupper.c \
			ft_isascii.c ft_memmove.c ft_strlen.c ft_isdigit.c \
			ft_memset.c ft_strncmp.c ft_memchr.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c

# Object files
OBJ_FILES = $(SRC_FILES:.c=.o)

# Library name
NAME = libft.a

# Targets
all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re