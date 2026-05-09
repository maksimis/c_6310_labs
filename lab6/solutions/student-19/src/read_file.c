#include "../inc/txtfile.h"

static int	count_lines(const char *filename)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(filename, O_RDONLY); // открываем файл только для чтения
	if (fd < 0)
		return (-1);
	count = 0;
	line = get_next_line(fd); // читаем первую строку
	while (line) // пока строки есть — увеличиваем счётчик
	{
		count++;
		free(line); // освобождаем текущую строку
		line = get_next_line(fd);
	}
    // закрываем файл после чтения
	close(fd);
	return (count);
}

char	**read_file(const char *filename)
{
	int		fd;
	int		i;
	int		lines_count;
	char	**lines;

	if (!filename) // проверка входного параметра
		return (NULL);
    // сначала считаем количество строк в файле
	lines_count = count_lines(filename);
	if (lines_count < 0)
		return (NULL);
	lines = malloc(sizeof(char *) * (lines_count + 1)); // выделяем массив указателей на строки (+1 под NULL)
	if (!lines)
		return (NULL);
    // открываем файл повторно для чтения строк
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (free(lines), NULL);
	i = 0;
	while (i < lines_count) // читаем файл построчно и сохраняем в массив
	{
		lines[i] = get_next_line(fd);
		if (!lines[i]) // если ошибка чтения — освобождаем всю память
			return (close(fd), free_lines(lines), NULL);
		i++;
	}
	lines[i] = NULL; // обязательно ставим NULL в конце массива
	close(fd); // закрываем файл
	return (lines);
}