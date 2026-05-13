#ifndef TXTFILE_H
# define TXTFILE_H

# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 4096

char	**read_file(const char *filename);
void	free_lines(char **lines);
void	print_lines(char **lines);
char	**cut_lines(char **lines, int start, int end);

#endif