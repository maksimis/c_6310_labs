#ifndef TXTFILE_H
# define TXTFILE_H

# include "../inc/libft.h"
# include <unistd.h> // нужен для read, write
# include <fcntl.h> // нужен для open/close и работы с файлами

/*
** Основная функция чтения файла построчно.
** Возвращает массив строк (char **), где последним элементом стоит NULL.
** Если произошла ошибка — возвращает NULL.
*/

char	**read_file(const char *filename);
/*
** Освобождает память, выделенную под массив строк.
** Сначала освобождает каждую строку, потом сам массив.
*/
void	free_lines(char **lines); //Выводит все строки массива в стандартный вывод (stdout).
void	print_lines(char **lines);
// Проходит по всем строкам и заменяет подстроку old на new_str, озвращает новый массив строк (исходный не изменяется)

char	**replace_substr(char **lines,
			const char *old,
			const char *new_str);

char	*replace_in_line(const char *line, //Замена подстроки в одной строке
			const char *old,
			const char *new_str);

size_t	count_occurrences(const char *str, const char *sub); // cчитает количество вхождений подстроки sub в строке str

char	*get_next_line(int fd); // Читает файл построчно, возвращает одну строку за вызов

char	*ft_strjoin_free(char *s1, char *s2); // Склеивает две строки и освобождает первую

#endif