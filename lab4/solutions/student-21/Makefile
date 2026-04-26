NAME      = calc
CC        = gcc
CFLAGS    = -Wall -Wextra -Werror -I./inc

LIBFT_DIR = ./libft
LIBFT     = $(LIBFT_DIR)/libft.a

SRC_DIR   = src
SRCS      = $(SRC_DIR)/main.c
OBJS      = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $@

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
