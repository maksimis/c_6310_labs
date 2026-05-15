NAME = txtfile

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./inc

SRC_DIR = src
LIBFT_DIR = libft

SRCS = $(SRC_DIR)/main.c \
	$(SRC_DIR)/read_file.c \
	$(SRC_DIR)/free_lines.c \
	$(SRC_DIR)/print_lines.c \
	$(SRC_DIR)/grep_lines.c \
	$(LIBFT_DIR)/libft.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
