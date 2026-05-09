NAME = matrix
CFLAGS = -Wall -Wextra -Werror -I./inc -std=c11
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = src/main.c \
       src/create_matrix.c \
       src/remove_matrix.c \
       src/print_matrix.c \
       src/eq_matrix.c \
       src/is_symmetric.c \
       src/is_diagonal.c \
       src/is_identity.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	gcc $(CFLAGS) $^ -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
