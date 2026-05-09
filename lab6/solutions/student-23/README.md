# Лабораторная работа №6 — Вариант 3. Замена подстроки во всём файле 

## Описание

В рамках лабораторной работы реализуется библиотека `txtfile`, предназначенная для работы с текстовыми файлами построчно, а также программа-демонстрация `replace_file`, выполняющая замену подстроки во всём файле.

Операция замены заключается в том, что каждое вхождение подстроки `old` заменяется на строку `new_str`.

Пример:

Исходный файл:
```text
cat is here
black cat
```
После замены cat → fox:

```text
fox is here
black fox
dog and fox
```

### Реализованные функции
Обязательные функции библиотеки txtfile:

```text
char    **read_file(const char *filename);
void    free_lines(char **lines);
void    print_lines(char **lines);
```
### Основная функция варианта

```text
char    **replace_substr(char **lines,
            const char *old,
            const char *new_str);
```
### Вспомогательные функции

```text
char    *replace_in_line(const char *line,
            const char *old,
            const char *new_str);

size_t  count_occurrences(const char *str, const char *sub);

char    *get_next_line(int fd);

char    *ft_strjoin_free(char *s1, char *s2);
```

### Структура проекта

```
lab6/solutions/student-19
├── libft/
├── inc/
│   ├── libft.h
│   └── txtfile.h
├── src/
│   ├── main.c
│   ├── read_file.c
│   ├── free_lines.c
│   ├── print_lines.c
│   ├── replace_substr.c
│   ├── replace_utils.c
│   ├── get_next_line.c
│   ├── gnl_utils.c
├── data/
│   └── input.txt
├── Makefile
└── README.md
```
### Сборка проекта

```
make
```

Очистка:

```
make fclean
```
Пересборка:
```
make re
```

### Запуск программы

```
./replace_file data/input.txt <old> <new>
```
### Пример работы
Входной файл:

```
cat is here
black cat
dog and cat
```
Запуск:

```
./replace_file data/input.txt cat fox
```

Вывод:

```
Original file:
cat is here
black cat
dog and cat

Modified file:
fox is here
black fox
dog and fox
```

### Особенности реализации
- Используется собственная библиотека libft
- Запрещено использование:
stdio.h
stdlib.h
string.h
- Все выводы выполняются через функции libft
- Работа с файлом выполняется построчно
- read_file возвращает массив строк, завершённый NULL
- Исходный массив строк не изменяется
- Все изменения создают новый массив строк

### Обработка ошибок

Программа корректно обрабатывает:

- отсутствие файла
- неверное количество аргументов
- ошибки выделения памяти
- пустой файл
- некорректные входные параметры

При ошибке выводится:

```
Usage: ./replace_file <filename> <old> <new>
```
или:

```
Error reading file
```
### Требования к коду
Компиляция с флагами:
```
-Wall -Wextra -Werror
```
- Отсутствие утечек памяти
- Использование только разрешённых системных вызовов:
read
write
open
close
malloc
free