NAME = calc
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./inc

# Все исходники из src/
LIBFT_SRCS = $(wildcard src/*.c)
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

# Основной файл программы
OBJS = main.o $(LIBFT_OBJS)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Компиляция файлов libft из src/
src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /Q main.o 2>nul || true
	del /Q src\*.o 2>nul || true

fclean: clean
	del /Q $(NAME).exe 2>nul || true

re: fclean all

.PHONY: all clean fclean re