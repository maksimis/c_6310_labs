#ifndef TXTFILE_H
# define TXTFILE_H

# include "../libft/inc/libft.h"
# include <fcntl.h>
# include <unistd.h>

# define BUFFER_SIZE 1024
# define MAX_LINES 1024

char	**read_file(const char *filename);
void	free_lines(char **lines);
void	print_lines(char **lines);
char	**grep_lines(char **lines, const char *pattern);
void	print_error(char *message);

#endif