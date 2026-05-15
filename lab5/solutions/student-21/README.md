# Лабораторная работа №5 — Решение студента №21

## Вариант
Номер варианта = `21 % 4 = 1` → **Вариант 1: сложение и вычитание двух матриц**.

## Описание
Библиотека `matrix` для операций над матрицами целых чисел и программа
`matrix`, демонстрирующая её работу. Без использования `stdio.h`,
`string.h` и `stdlib.h` в `main.c` — весь ввод/вывод идёт через `libft`,
`malloc`/`free` — только внутри `libft` и модулей библиотеки `matrix`.

## Реализованные функции

### matrix.h
```c
typedef struct matrix_struct {
    int  **matrix;
    int    rows;
    int    columns;
} matrix_t;

matrix_t *create_matrix(int rows, int cols);
void      remove_matrix(matrix_t *A);
void      print_matrix(matrix_t *A);
matrix_t *sum_matrix(matrix_t *A, matrix_t *B);
matrix_t *sub_matrix(matrix_t *A, matrix_t *B);
```

- `create_matrix` — возвращает `NULL`, если `rows <= 0`, `cols <= 0` или
  при неудаче `malloc` (частично выделенная память освобождается).
- `remove_matrix` — корректно работает с `NULL` и с частично заполненной
  структурой.
- `print_matrix` — выводит матрицу в `stdout`, элементы разделены пробелами,
  каждая строка заканчивается `\n`.
- `sum_matrix` / `sub_matrix` — возвращают новую матрицу того же размера;
  `NULL`, если размеры не совпадают или одна из матриц `NULL`.

## Структура

```
student-21/
├── inc/
│   ├── libft.h
│   └── matrix.h
├── libft/
│   ├── Makefile
│   ├── ft_bzero.c
│   ├── ft_calloc.c
│   ├── ft_memset.c
│   ├── ft_putchar_fd.c
│   ├── ft_putendl_fd.c
│   ├── ft_putnbr_fd.c
│   ├── ft_putstr_fd.c
│   └── ft_strlen.c
├── src/
│   ├── create_matrix.c
│   ├── main.c
│   ├── print_matrix.c
│   ├── remove_matrix.c
│   ├── sub_matrix.c
│   └── sum_matrix.c
├── Makefile
└── README.md
```

## Сборка

```
make          # собрать libft и ./matrix
make clean    # объектные файлы
make fclean   # + бинарник и libft.a
make re       # пересборка
```

Флаги: `-Wall -Wextra -Werror`. Компиляция без единого warning.

## Запуск

```
./matrix
```

Вывод (из демонстрации в `main.c`):

```
Matrix A:
1 2 3
0 4 5
0 0 6

Matrix B:
1 0 0
2 0 0
3 4 1

C = A + B:
2 2 3
2 4 5
3 4 7

D = A - B:
0 2 3
-2 4 5
-3 -4 5

Mismatched sizes sum_matrix(2x2, 2x3) -> expected NULL:
NULL (ok)
```

## Проверка утечек памяти

```
valgrind --leak-check=full --show-leak-kinds=all ./matrix
```

Ожидается `All heap blocks were freed -- no leaks are possible` на всех путях
(успех + ошибочный путь с несовместимыми размерами).

## Соответствие чек-листу

- [x] Библиотека `matrix` (заголовок + отдельные `.c`-файлы).
- [x] `create_matrix` / `remove_matrix` / `print_matrix` на `matrix_t`.
- [x] `sum_matrix` / `sub_matrix` (вариант 1).
- [x] `main.c` — демонстрация, вывод только через `libft`,
  `malloc`/`free` не используются.
- [x] Обработка ошибок: `NULL`-матрицы, нулевые/отрицательные размеры,
  несовпадение размеров, провал `malloc`.
- [x] `-Wall -Wextra -Werror` — чисто.
- [x] `valgrind` — нет утечек.
