NAME = philosophers
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread

SRC = philosophers.c
OBJ = philosophers.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME).exe $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)

clean:
	if exist $(OBJ) del $(OBJ)

fclean: clean
	if exist $(NAME).exe del $(NAME).exe

re: fclean all

.PHONY: all clean fclean re