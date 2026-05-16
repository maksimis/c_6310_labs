#ifndef TXTFILE_H
# define TXTFILE_H

# include "libft.h"

// Определения для системных вызовов (вместо fcntl.h)
# ifndef O_RDONLY
#  define O_RDONLY 0x0000
# endif

# ifndef O_WRONLY
#  define O_WRONLY 0x0001
# endif

# ifndef O_RDWR
#  define O_RDWR 0x0002
# endif

// Прототипы системных вызовов
int	open(const char *path, int flags, ...);
int	close(int fd);
ssize_t	read(int fd, void *buf, size_t count);
ssize_t	write(int fd, const void *buf, size_t count);

// Обязательные функции
char	**read_file(const char *filename);
void	free_lines(char **lines);
void	print_lines(char **lines);

// Функции варианта 1 (grep)
char	**grep_lines(char **lines, const char *pattern);

#endif