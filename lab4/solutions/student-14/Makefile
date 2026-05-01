NAME = filter
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = -I./inc -I./libft/inc
LIBFT = ./libft/libft.a

SRC_DIR = src
OBJ_DIR = obj
SRCS = $(SRC_DIR)/main.c
OBJS = $(OBJ_DIR)/main.o

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C ./libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re