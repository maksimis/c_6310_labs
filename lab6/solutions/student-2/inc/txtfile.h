#ifndef TXTFILE_H
#define TXTFILE_H

#include "libft.h"

char    **read_file(const char *filename);
void    free_lines(char **lines);
void    print_lines(char **lines);
char    **cut_lines(char **lines, int start, int end);

#endif
