NAME = txtfile
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./inc -I./libft/inc

LIBFT = ./libft/libft.a

SRC_DIR = src
SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/read_file.c \
       $(SRC_DIR)/free_lines.c \
       $(SRC_DIR)/print_lines.c \
       $(SRC_DIR)/grep_lines.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	make -C ./libft

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re