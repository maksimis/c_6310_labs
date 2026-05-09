cat > Makefile << 'EOF'
NAME = stats
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./inc
LIBFT = ./libft/libft.a
SRC_DIR = src
SRCS = $(SRC_DIR)/main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
	@echo "Using existing libft.a"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
EOF