# Название библиотеки
NAME = libft.a

# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./inc

# Папки
SRC_DIR = src
OBJ_DIR = obj

# Все .c файлы из папки src автоматически
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Объектные файлы в папке obj
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Цель сборки библиотеки
all: $(NAME)

# Создание самой библиотеки
$(NAME): $(OBJS)
	ar rcs $@ $^

# Компиляция .c -> .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Создание папки obj, если её нет
$(OBJ_DIR):
	mkdir -p $@

# Очистка объектных файлов
clean:
	rm -rf $(OBJ_DIR)

# Очистка объектов + библиотеки
fclean: clean
	rm -f $(NAME)

# Полная пересборка
re: fclean all

# Бонус (можно использовать для дополнительных функций)
bonus: all

# Чтобы make понимал эти цели как "файлы не нужны"
.PHONY: all clean fclean re bonus