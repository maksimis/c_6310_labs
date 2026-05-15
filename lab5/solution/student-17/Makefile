CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./libft/inc -I./matrix

LIBFT = ./libft/libft.a

MATRIX_DIR = matrix
MATRIX_SRC = $(MATRIX_DIR)/matrix_create.c $(MATRIX_DIR)/matrix_remove.c \
             $(MATRIX_DIR)/matrix_print.c $(MATRIX_DIR)/matrix_sum.c \
             $(MATRIX_DIR)/matrix_sub.c
MATRIX_OBJ = $(MATRIX_DIR)/matrix_create.o $(MATRIX_DIR)/matrix_remove.o \
             $(MATRIX_DIR)/matrix_print.o $(MATRIX_DIR)/matrix_sum.o \
             $(MATRIX_DIR)/matrix_sub.o

all: lab05

lab05: main.o $(MATRIX_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o lab05.exe main.o $(MATRIX_OBJ) $(LIBFT)

main.o: main.c matrix/matrix.h
	$(CC) $(CFLAGS) $(INCLUDES) -c main.c

$(MATRIX_DIR)/%.o: $(MATRIX_DIR)/%.c $(MATRIX_DIR)/matrix.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f main.o
	rm -f $(MATRIX_DIR)/*.o

fclean: clean
	rm -f lab05.exe

re: fclean all

.PHONY: all clean fclean re