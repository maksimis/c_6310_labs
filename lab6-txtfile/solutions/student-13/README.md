

# Лабораторная работа 6 — библиотека работы с текстовыми файлами
Студент 13
Вариант 1 — поиск строк по подстроке.

## Задание

Реализована библиотека для работы с текстовыми файлами.

Базовые функции библиотеки:

```c
char	**read_file(const char *filename);
void	free_lines(char **lines);
void	print_lines(char **lines);
```

Функция варианта 1:

```c
char	**grep_lines(char **lines, const char *pattern);
```

Программа читает текстовый файл, ищет строки, содержащие указанную подстроку, и выводит найденные строки.

## Сборка

```bash
make
```

После сборки создается исполняемый файл:

```bash
grep_file
```

## Запуск

```bash
./grep_file <file> <pattern>
```

Пример:

```bash
./grep_file data/input.txt apple
```

## Тестовый файл

Файл `data/input.txt` содержит:

```text
apple pie
banana bread
green apple
orange juice
pineapple cake
grape
```

## Примеры работы

Поиск строк с подстрокой `apple`:

```bash
./grep_file data/input.txt apple
```

Результат:

```text
apple pie
green apple
pineapple cake
```

Поиск строки с подстрокой `banana`:

```bash
./grep_file data/input.txt banana
```

Результат:

```text
banana bread
```

Если совпадений нет:

```bash
./grep_file data/input.txt xyz
```

Программа ничего не выводит.

## Обработка ошибок

Если программа запущена с неправильным количеством аргументов:

```bash
./grep_file
```

Результат:

```text
Error: usage: ./grep_file <file> <pattern>
```

Если файл не существует или не может быть открыт:

```bash
./grep_file no_file.txt apple
```

Результат:

```text
Error: cannot read file
```

## Проверка Makefile

```bash
make
make clean
make fclean
make re
```

Назначение целей:

- `make` — собирает проект;
- `make clean` — удаляет объектные файлы;
- `make fclean` — удаляет объектные файлы, исполняемый файл и `libft.a`;
- `make re` — полностью пересобирает проект.

## Использованные возможности

В работе используются:

- чтение файла через `open`, `read`, `close`;
- динамическое выделение памяти;
- массив строк `char **`;
- собственная библиотека `libft`;
- вывод через функции `libft`;
- сборка через `Makefile`.

## Тестирование

Были выполнены команды:

```bash
make
./grep_file data/input.txt apple
./grep_file data/input.txt banana
./grep_file data/input.txt xyz
./grep_file
./grep_file no_file.txt apple
make clean
make fclean
make re
./grep_file data/input.txt apple
```

Сборка, запуск и обработка ошибок прошли корректно.