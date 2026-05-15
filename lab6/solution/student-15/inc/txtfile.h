#ifndef TXTFILE_H
# define TXTFILE_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	**read_file(const char *filename);
void	free_lines(char **lines);
void	print_lines(char **lines);
char	**replace_substr(char **lines, const char *old, const char *new_str);

#endif