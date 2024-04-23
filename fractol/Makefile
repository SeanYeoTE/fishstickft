# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Minilibx
MLX_PATH	= minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)


LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

# Source files
SRC_PATH = src/
SRC =	main.c \
		utils.c \
		init.c \
		actions.c \
		render.c \

SRCS		= $(addprefix $(SRC_PATH), $(SRC))

# Object files
OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

# Target executable
NAME = fractol

# Default target
all: $(MLX) $(LIBFT) $(NAME)

# Other Prototypes
RM = rm -f
# Compile source files into object files
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(MLX):
	make -C $(MLX_PATH)

$(LIBFT):
	make -C $(LIBFT_PATH)

# Link object files into target executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) -lXext -lX11 -Lminilibx-linux -lmlx_Linux

# Clean up object files and target executable
clean:
	rm -rf $(OBJS) $(NAME)
	make clean -C $(MLX_PATH)
	make clean -C $(LIBFT_PATH)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all

.PHONY: all re clean fclean