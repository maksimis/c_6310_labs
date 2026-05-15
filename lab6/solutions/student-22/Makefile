NAME = cut_file
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./inc
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = src/main.c \
       src/read_file.c \
       src/free_lines.c \
       src/print_lines.c \
       src/cut_lines.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re