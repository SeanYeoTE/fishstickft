GCC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs
NAME = get_next_line


SRC_FILES = get_next_line.c \
			get_next_line_utils.c \

BONUS_FILES =	get_next_line_bonus.c \
				get_next_line_utils_bonus.c \


OBJ_FILES = $(SRC_FILES:.c=.o)
BONUS_OBJS = $(BONUS_FILE:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES) $(BONUS_OBJS)
	$(AR) $(NAME) $(OBJ_FILES) $(BONUS_OBJS)

clean:
	$(RM) $(OBJ_FILES) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(BONUS_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus