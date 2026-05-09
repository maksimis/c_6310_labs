#include "../inc/txtfile.h"

char	*ft_strjoin_free(char *s1, char *s2) // функция объединяет две строки s1 и s2 в одну новую строку
{
	char	*result;
	size_t	len1;
	size_t	len2;

	if (!s1) // если s1 нет, просто возвращаем копию s2
		return (ft_strdup(s2));
    // считаем длины строк
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);

	result = malloc(len1 + len2 + 1); // выделяем память под новую строку
	if (!result)
		return (NULL);
	ft_memcpy(result, s1, len1); // копируем первую строку в result
	ft_memcpy(result + len1, s2, len2); // дописываем вторую строку сразу после первой
	result[len1 + len2] = '\0'; // добавляем символ конца строки
	free(s1); // освобождаем старую строку, так как она больше не нужна
	return (result); // возвращаем новую объединённую строку
}