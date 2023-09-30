# Source files
SRCP = ./srcs/
SRCP_CHECK = $(SRCP)check/
SRCP_LIST = $(SRCP)list/
SRCP_MEMORY = $(SRCP)memory/
SRCP_PRINT = $(SRCP)print/
SRCP_STRING = $(SRCP)string/

SRCS_CHECK =	ft_isalnum.c \
				ft_isalpha.c \
				ft_isprint.c \
				ft_isascii.c \
				ft_isdigit.c \

SRCS_LIST =		ft_lstadd_front.c \
				ft_lstnew.c  \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c

SRCS_MEMORY =	ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_calloc.c \

SRCS_PRINT = 	ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \

SRCS_STRING =	ft_strchr.c \
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


SRC_CHECK		= $(addprefix $(SRCP_CHECK),$(SRCS_CHECK))
SRC_LIST		= $(addprefix $(SRCP_LIST),$(SRCS_LIST))
SRC_MEMORY		= $(addprefix $(SRCP_MEMORY),$(SRCS_MEMORY))
SRC_PRINT		= $(addprefix $(SRCP_PRINT),$(SRCS_PRINT))
SRC_STRING		= $(addprefix $(SRCP_STRING),$(SRCS_STRING))

OBJS_CHECK		= $(SRC_CHECK:.c=.o)
OBJS_LIST		= $(SRC_LIST:.c=.o)
OBJS_MEMORY		= $(SRC_MEMORY:.c=.o)
OBJS_PRINT		= $(SRC_PRINT:.c=.o)
OBJS_STRING		= $(SRC_STRING:.c=.o)

HEAD			= ./includes/

# Variables
NAME = libft.a
AR  = ar rcs
RM  = rm -f
LIB = ranlib
GCC = gcc
CFLAGS = -Wall -Wextra -Werror

# Targets
all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

check: $(OBJS_CHECK)
	@$(AR) $(NAME) $(OBJS_CHECK)
	@$(LIB) $(NAME)

list: $(OBJS_LIST)
	@$(AR) $(NAME) $(OBJS_LIST)
	@$(LIB) $(NAME)

memory: $(OBJS_MEMORY)
	@$(AR) $(NAME) $(OBJS_MEMORY)
	@$(LIB) $(NAME)

print: $(OBJS_PRINT)
	@$(AR) $(NAME) $(OBJS_PRINT)
	@$(LIB) $(NAME)

string: $(OBJS_STRING)
	@$(AR) $(NAME) $(OBJS_STRING)
	@$(LIB) $(NAME)

bonus: $(OBJS_CHECK) $(OBJS_LIST) $(OBJS_MEMORY) $(OBJS_PRINT) $(OBJS_STRING)
	@$(AR) $(NAME) $(OBJS_CHECK) $(OBJS_LIST) $(OBJS_MEMORY) $(OBJS_PRINT) $(OBJS_STRING)
	@$(LIB) $(NAME)

clean:
	@$(RM) $(OBJS_CHECK) $(OBJS_LIST) $(OBJS_MEMORY) $(OBJS_PRINT) $(OBJS_STRING) error.txt

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean re bonus check list memory print string