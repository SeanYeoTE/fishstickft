# Source files
SRCS =	ft_isalnum.c \
		ft_isalpha.c \
		ft_isprint.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_lstadd_front.c \
		ft_lstnew.c  \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_calloc.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strlcat.c \
		ft_tolower.c \
		ft_strlcpy.c \
		ft_toupper.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \

# Variables
NAME = libft.a
AR  = ar rcs
RM  = rm -f
LIB = ranlib
GCC = gcc
CFLAGS = -Wall -Wextra -Werror

# Targets

OBJS = $(SRCS:.c=.o)

all: $(NAME)


$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@$(LIB) $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean re