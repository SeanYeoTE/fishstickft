NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

SRCS =	src/pipex.c\
		src/utils.c\

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a\

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

clean :
	$(RM) $(OBJS)
	make clean -C libft
	
fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

re : fclean all