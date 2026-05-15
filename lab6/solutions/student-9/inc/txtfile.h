#ifndef TXTFILE_H
# define TXTFILE_H

# include "libft.h"
# include <fcntl.h>

char    **read_file(const char *filename);
void    free_lines(char **lines);
void    print_lines(char **lines);

char    **grep_lines(char **lines, const char *pattern);

#endif