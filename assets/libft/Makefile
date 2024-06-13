NAME = libft.a

CC = cc
CFLAGS =  -Wall -Wextra -Werror -fPIC
ARFLAGS = ar -rcs
REMOVE = rm -rf

OBJ_PATH = obj
SRC_PATH = src
INC_PATH = include

SRC := $(SRC_PATH)/ft_aredigits.c $(SRC_PATH)/ft_atof.c $(SRC_PATH)/ft_atoi.c $(SRC_PATH)/ft_bzero.c $(SRC_PATH)/ft_calloc.c $(SRC_PATH)/ft_free.c $(SRC_PATH)/ft_get_rgba.c \
		$(SRC_PATH)/ft_isalnum.c $(SRC_PATH)/ft_isalpha.c $(SRC_PATH)/ft_isascii.c $(SRC_PATH)/ft_isdigit.c $(SRC_PATH)/ft_isprint.c $(SRC_PATH)/ft_isspace.c $(SRC_PATH)/ft_itoa.c \
		$(SRC_PATH)/ft_itoalong.c $(SRC_PATH)/ft_lstadd_back.c $(SRC_PATH)/ft_lstadd_front.c $(SRC_PATH)/ft_lstlast.c $(SRC_PATH)/ft_lstnew.c $(SRC_PATH)/ft_lstsize.c $(SRC_PATH)/ft_matrxlen.c \
		$(SRC_PATH)/ft_memchr.c $(SRC_PATH)/ft_memcmp.c $(SRC_PATH)/ft_memcpy.c $(SRC_PATH)/ft_memmove.c $(SRC_PATH)/ft_memset.c $(SRC_PATH)/ft_putstr_fd.c $(SRC_PATH)/ft_realloc.c \
		$(SRC_PATH)/ft_split.c $(SRC_PATH)/ft_split_free.c $(SRC_PATH)/ft_str_del_space.c $(SRC_PATH)/ft_strchr.c $(SRC_PATH)/ft_strdup.c $(SRC_PATH)/ft_striteri.c $(SRC_PATH)/ft_strjoin.c \
		$(SRC_PATH)/ft_strlcat.c $(SRC_PATH)/ft_strlcpy.c $(SRC_PATH)/ft_strlen.c $(SRC_PATH)/ft_strmapi.c $(SRC_PATH)/ft_strncmp.c $(SRC_PATH)/ft_strnstr.c $(SRC_PATH)/ft_strrchr.c \
		$(SRC_PATH)/ft_strtrim.c $(SRC_PATH)/ft_substr.c $(SRC_PATH)/ft_tolower.c $(SRC_PATH)/ft_toupper.c $(SRC_PATH)/get_next_line.c

OBJ = $(addprefix $(OBJ_PATH)/, $(notdir $(SRC:.c=.o)))

HEADERS = -I $(INC_PATH)

.PHONY: all clean fclean re

.SILENT:

VIOLET = \033[38;5;129m
RESET = \033[0m
U_LINE = \033[4m
PINK = \033[1;38;5;206m

all: $(NAME)

$(NAME): $(OBJ)
	$(ARFLAGS) $@ $(OBJ)
	echo "\n$(VIOLET)$(U_LINE)🌸 $(NAME): Compiled 🌸 $(RESET) \n"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	echo "$(PINK)libft Compiling:$(RESET) $(notdir $<)"

clean:
	$(REMOVE) $(OBJ_PATH)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all
