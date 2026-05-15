NAME = philosophers
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread -I./inc

SRC_DIR = src
INC_DIR = inc

SRCS = $(SRC_DIR)/philosophers.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/philosophers.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re