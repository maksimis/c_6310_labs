NAME = replace_file

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

INC = -I./inc -I./libft

SRC_DIR = src

SRCS = $(SRC_DIR)/main.c \
	$(SRC_DIR)/read_file.c \
	$(SRC_DIR)/free_lines.c \
	$(SRC_DIR)/print_lines.c \
	$(SRC_DIR)/replace_substr.c \
	$(SRC_DIR)/replace_utils.c \
	$(SRC_DIR)/get_next_line.c \
	$(SRC_DIR)/gnl_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re