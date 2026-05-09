#include "../inc/txtfile.h"

char	*replace_in_line(const char *line,
			const char *old,
			const char *new_str)
{
	char	*result;
	size_t	new_len;
	size_t	old_len;
	size_t	count;
	size_t	i;
	size_t	j;

	if (!line || !old || !new_str) // проверяем входные данные
		return (NULL);
    // считаем длины строк    
	old_len = ft_strlen(old);
	new_len = ft_strlen(new_str);
	count = count_occurrences(line, old); // считаем сколько раз встречается old в line

    /*
	** выделяем память под новую строку:
	** длина исходной строки + разница замен * количество замен
	*/
	result = malloc(ft_strlen(line)
			+ count * (new_len - old_len) + 1);
	if (!result)
		return (NULL);
	i = 0; // индекс по исходной строке
	j = 0;// индекс по новой строке

    /*
	** проходим по строке и копируем символы
	** либо заменяем подстроку, либо копируем как есть
	*/
	while (line[i])
	{
		if (ft_strncmp(&line[i], old, old_len) == 0) // если нашли подстроку old
		{
			ft_memcpy(&result[j], new_str, new_len); // копируем new_str в результат
			j += new_len;
			i += old_len;
		}
		else
			result[j++] = line[i++]; // иначе просто копируем символ
	}
	result[j] = '\0'; // завершаем строку
	return (result);
}

char	**replace_substr(char **lines,
			const char *old,
			const char *new_str)
{
	char	**result;
	int		i;
	int		count;

	if (!lines || !old || !new_str) // проверка входных данных
		return (NULL);
    // считаем количество строк в массиве    
	count = 0;
	while (lines[count])
		count++;
	result = malloc(sizeof(char *) * (count + 1)); // выделяем память под новый массив строк
	if (!result)
		return (NULL);
	i = 0;
    // проходим по всем строкам и заменяем подстроки
	while (i < count)
	{
		result[i] = replace_in_line(lines[i], old, new_str);
		if (!result[i]) // если ошибка — освобождаем память
			return (free_lines(result), NULL);
		i++;
	}
    // обязательно завершаем массив NULL
	result[i] = NULL;
	return (result);
}