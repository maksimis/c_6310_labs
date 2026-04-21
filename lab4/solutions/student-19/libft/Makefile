# ----------------------------
# Название библиотеки
# ----------------------------
NAME = libft.a

# ----------------------------
# Компилятор и флаги
# ----------------------------
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./inc

# ----------------------------
# Директории
# ----------------------------
SRC_DIR = src
OBJ_DIR = obj

# ----------------------------
# Исходные файлы (42 функции)
# ----------------------------
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_toupper.c ft_tolower.c ft_strlen.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c \
ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_isspace.c ft_strlcpy.c ft_strlcat.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
ft_lstclear.c ft_lstiter.c ft_lstmap.c 

# ----------------------------
# Объектные файлы
# ----------------------------
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# ----------------------------
# Основная цель
# ----------------------------
all: $(NAME)

# ----------------------------
# Сборка библиотеки
# ----------------------------
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# ----------------------------
# Компиляция .c → .o
# ----------------------------
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# ----------------------------
# Создание папки obj
# ----------------------------
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# ----------------------------
# Очистка
# ----------------------------
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

# ----------------------------
# Пересборка
# ----------------------------
re: fclean all

# ----------------------------
# Флаги phony
# ----------------------------
.PHONY: all clean fclean re bonus