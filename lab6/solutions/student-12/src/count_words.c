#include "txtfile.h"

static int	is_separator(char c) // static так как функция нужна только внутри этого файла
{
	return (c == ' ' || c == '\t' || c == '\n'); // \t - табуляция
}

int	count_words(char **lines)
{
	int	words;
	int	i;
	int	j;

	if (!lines)
		return (-1);
	words = 0;
	i = 0;
	while (lines[i]) // пока строки есть
	{
		j = 0; // по символам строки
		while (lines[i][j]) // пока символ не равен \0
		{
			if (!is_separator(lines[i][j]) && (j == 0 || is_separator(lines[i][j - 1]))) // пока текущий символ это не разделитель И это начало строки или пред символ разделителем был (то есть нашлось начало нового слова)
				words++;
			j++;
		}
		i++;
	}
	return (words);
}