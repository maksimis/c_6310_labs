NAME = matrix

CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = -I./inc -I./libft

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = ./src
SRCS = $(SRC_DIR)/main.c \
	$(SRC_DIR)/create_matrix.c \
	$(SRC_DIR)/remove_matrix.c \
	$(SRC_DIR)/print_matrix.c \
	$(SRC_DIR)/mult_matrix.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re