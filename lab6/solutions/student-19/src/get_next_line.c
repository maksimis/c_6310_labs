#include "../inc/txtfile.h"

#ifndef BUFFER_SIZE // размер буфера для чтения из файла
# define BUFFER_SIZE 32
#endif

/*
** extract_line:
** извлекает одну строку из stash (временного буфера).
**
** stash хранит "остаток" после прошлого чтения.
** функция возвращает одну строку до '\n' включительно (если есть).
*/

static char	*extract_line(char **stash)
{
	char	*line;
	char	*new_stash;
	int		i;

	if (!*stash || !(*stash)[0]) // если stash пустой — возвращать нечего
		return (NULL);
	i = 0;
	while ((*stash)[i] && (*stash)[i] != '\n') // ищем символ конца строки '\n'
		i++;
	if ((*stash)[i] == '\n') // если нашли '\n', включаем его в строку
		i++;
	line = ft_substr(*stash, 0, i); // создаём строку для возврата
	if (!line)
		return (NULL);
	if ((*stash)[i] != '\0') // если после строки остались данные — сохраняем их обратно в stash
	{
		new_stash = ft_strdup(*stash + i);
		if (!new_stash)
		{
			free(line);
			return (NULL);
		}
	}
	else
		new_stash = NULL;
	free(*stash); // старый stash больше не нужен
	*stash = new_stash;
	return (line);
}

static int	read_to_stash(int fd, char **stash) // читает данные из файла и добавляет их в stash, пока не встретится '\n' или конец файла
{
	char	buffer[BUFFER_SIZE + 1];
	char	*tmp;
	int		bytes;

	bytes = 1;
	while ((!*stash || !ft_strchr(*stash, '\n')) && bytes > 0) // продолжаем читать, пока не нашли '\n'
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0) // ошибка чтения
			return (-1);
		buffer[bytes] = '\0';
		tmp = ft_strjoin_free(*stash, buffer); // объединяем старый stash и новый буфер
		if (!tmp)
			return (-1);
		*stash = tmp;
	}
	return (0);
}

/*
** get_next_line:
** основная функция, которая возвращает по одной строке
** при каждом вызове.
**
** stash — статическая переменная, сохраняет остаток между вызовами.
*/

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0) // проверка корректности fd и BUFFER_SIZE
		return (NULL);
	if (read_to_stash(fd, &stash) == -1) // читаем данные в stash
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	if (!stash || stash[0] == '\0') // если ничего не осталось — файл закончился
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = extract_line(&stash); // извлекаем одну строку
	return (line);
}