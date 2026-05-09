#include "../inc/txtfile.h"

size_t	count_occurrences(const char *str, const char *sub)
{
	size_t	count;
	size_t	len;

	if (!str || !sub || !sub[0]) // если строки некорректные или sub пустая — возвращаем 0
		return (0);
	count = 0;
	len = ft_strlen(sub); // длина подстроки, которую ищем
    // проходим по всей строке, если нашли совпадение — увеличиваем счётчик
	while (*str)
	{
		if (ft_strncmp(str, sub, len) == 0) // если текущий участок строки совпадает с sub
		{
			count++;  // нашли одно вхождение
			str += len; // пропускаем подстроку целиком
		}
		else
			str++; // иначе двигаемся по строке на 1 символ
	}
	return (count);
}