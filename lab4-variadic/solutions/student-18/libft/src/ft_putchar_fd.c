//Выводит символ в файловый дескриптор
#include "libft.h"

void ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}