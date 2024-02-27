# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS =	main.c \
		stack_utils.c \
		swap.c \
		push.c \
		\
		ft_atoi.c \
		ft_split.c \

# Object files
OBJS = $(SRCS:.c=.o)

# Target executable
NAME = push_swap

# Default target
all: $(NAME)

# Other Prototypes
RM = rm -f
# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into target executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Clean up object files and target executable
clean:
	rm -f $(OBJS) $(NAME)

fclean: clean
	$(RM) $(NAME)

re: fclean all