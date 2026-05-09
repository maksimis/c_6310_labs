#include "../inc/txtfile.h"

int	main(int argc, char **argv)
{
	char	**lines;
	char	**result;

    // проверяем количество аргументов
	// если их меньше или больше — выводим usage
	if (argc != 4)
	{
		ft_putendl_fd(
			"Usage: ./replace_file <filename> <old> <new>",
			2);
		return (1);
	}
	lines = read_file(argv[1]); // читаем файл построчно в массив строк
	if (!lines) 
	{
		ft_putendl_fd("Error reading file", 2); // если файл не удалось прочитать — ошибка
		return (1);
	}
	ft_putendl_fd("Original file:", 1); // выводим оригинальное содержимое файла
	print_lines(lines);
	result = replace_substr(lines, argv[2], argv[3]); // выполняем замену подстроки во всех строках
	if (!result)
	{
		ft_putendl_fd("Replace error", 2); // если ошибка при замене — освобождаем память
		free_lines(lines);
		return (1);
	}
	ft_putendl_fd("\nModified file:", 1); // выводим результат после замены
	print_lines(result);
    // освобождаем всю выделенную память
	free_lines(lines);
	free_lines(result);
	return (0);
}