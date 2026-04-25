NAME = matrix
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./inc
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = src
SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/create_matrix.c \
       $(SRC_DIR)/remove_matrix.c \
       $(SRC_DIR)/print_matrix.c \
       $(SRC_DIR)/eq_matrix.c \
       $(SRC_DIR)/is_symmetric.c \
       $(SRC_DIR)/is_diagonal.c \
       $(SRC_DIR)/is_identity.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
