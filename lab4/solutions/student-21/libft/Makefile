NAME    = libft.a
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -I../inc

SRCS    = ft_isdigit.c \
          ft_isspace.c \
          ft_strlen.c \
          ft_strncmp.c \
          ft_atoi.c \
          ft_putchar_fd.c \
          ft_putstr_fd.c \
          ft_putendl_fd.c \
          ft_putnbr_fd.c

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
