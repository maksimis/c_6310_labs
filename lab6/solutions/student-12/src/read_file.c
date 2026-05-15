#include "txtfile.h"

#define BUFFER_SIZE 1024 // компилятор заменит BUFFER_SIZE на 1024, размер временного массива памяти в байтах для чтения файла

static int	count_file_lines(const char *filename) // static - чтобы функция была видно только в этом файле
{
	char	buffer[BUFFER_SIZE]; // массив символов
	int		fd; // номер открытого файла, ОС выдает этот номер после open()
	int		bytes; // сколько байт прочитал read()
	int		count; // счетчик строк
	int		i; // счетчик цикла

	fd = open(filename, O_RDONLY); // открытие файла только для чтения
	if (fd < 0) // проверка открылся ли файл, если все норм вернет число больше 0
		return (-1);
	count = 0;
	bytes = read(fd, buffer, BUFFER_SIZE); // чтение файла, fd - откуда читать, buffer - куда записывать, BUFFER_SIZE - сколько максимум читать. возращает количество прочитанных байт
	// read() помнит позицию. после каждого чтения указатель внутри файла сдвигается.
	while (bytes > 0) // пока файл не закончился
	{
		i = 0;
		while (i < bytes) // проходим по всем считанным символам
		{
			if (buffer[i] == '\n')
				count++;
			i++; // следующий символ
		}
		bytes = read(fd, buffer, BUFFER_SIZE); // чтение следующей порции файла, если до этого не все прочитаталось. если уже прочиталось все, то bytes = 0 и цикл закончится
	}
	close(fd); // закрытие файла
	if (bytes < 0)
		return (-1);
	return (count + 1); // +1 потому что у последней строки не будет перехода \n
}
static void	free_partial(char **lines, int size) // освобождение частично заполненного массива, нужна когда произошла ошибка ов время чтения файла
{
	int	i;

	i = 0;
	while (i < size) // идем по заполенным строкам
	{
		free(lines[i]); // освобождение строки
		i++;
	}
	free(lines); // освобождение массива указателей на эти строки 
}

static char	*join_and_free(char *s1, char *s2) // склеивание строк и освобождение старой строки
{
	char	*result;

	result = ft_strjoin(s1, s2); // создание новой строки: s1 + s2
	free(s1); // освобождение, потому что s1 создано через ft_strdup в куче и надо обязательно освободить, а s2 в стеке освободится само 
	return (result);
}
static char	*read_one_line(int fd) // чтение одной строки из файла, и возвращает её
{
	char	buffer[2]; // 2 потому что, 1 символ + \0
	char	*line;
	char	*temp;
	int		bytes;

	line = ft_strdup(""); // пока пустая строка, в неё будут добавляться символы
	if (!line)
		return (NULL);
	bytes = read(fd, buffer, 1); // чтение по одному символу, чтобы словить \n
	while (bytes > 0) // пока файл не закончился
	{
		buffer[1] = '\0'; // делаем буфер строкой так как сейчас в нем просто один символ в buffer[0], потому что всем строковым функциям нужен \0 в конце 
		temp = join_and_free(line, buffer); // добавляем новый символ к строке
		if (!temp)
			return (NULL);
		line = temp; // теперь line на новую строку указывает
		if (buffer[0] == '\n') // если дошли до конца строки - прекращаем чтение
			break ;
		bytes = read(fd, buffer, 1); // читаем след символ
	}
	if (bytes < 0 || (bytes == 0 && ft_strlen(line) == 0)) // проверка ошибок
	{
		free(line);
		return (NULL);
	}
	return (line);
}
char	**read_file(const char *filename) // чтение всего файла
{
	char	**lines;
	int		fd;
	int		line_count;
	int		i;

	if (!filename)
		return (NULL);
	line_count = count_file_lines(filename);
	if (line_count <= 0)
		return (NULL);
	lines = ft_calloc(line_count + 1, sizeof(char *)); // выделение памяти под массив указателей на строки, +1 для NULL в конце 
	if (!lines)
		return (NULL);
	fd = open(filename, O_RDONLY); // открытие файла для чтения
	if (fd < 0)
		return (free(lines), NULL);
	i = 0;
	while (i < line_count) // чтение всех строк
	{
		lines[i] = read_one_line(fd); // чтение одной строки
		if (!lines[i]) // если ошибка чтения
			return (close(fd), free_partial(lines, i), NULL); // первые два аргумента выполняются, третий возвращается
		i++;
	}
	lines[i] = NULL; // в конец массива ставим NULL 
	close(fd);
	return (lines); // возвращаем массив строк
}