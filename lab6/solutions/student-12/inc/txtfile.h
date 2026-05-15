// заголовочный файл
// он не содержит реализацию, но показывает какие функции существуют, какие аргументы принимают и что возращают
// если файл ещё не определен - помечает файл как уже подключенный
#ifndef TXTFILE_H
# define TXTFILE_H

# include "libft.h" // " " - значит файл в проекте, < > - значит системная библиотека
# include <fcntl.h> // для open() в read_file.c
# include <unistd.h> // для read, write, close

char    **read_file(const char *filename); // char ** - что возращается
void    free_lines(char **lines);
void    print_lines(char **lines);

int     count_lines(char **lines);
int     count_words(char **lines);
int     count_chars(char **lines);
int     longest_line_length(char **lines);

#endif