# Лабораторная работа №5 — Решение студента №8

## Вариант
Номер варианта = `8 % 4 = 0` → **Вариант 4: сравнение матриц и анализ свойств**.

## Описание
Библиотека `matrix` для операций над матрицами целых чисел и программа
`matrix`, демонстрирующая её работу. В `main.c` не используются ни `printf`,
ни `malloc`/`free` — только функции `libft` и библиотеки `matrix`.

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

int       eq_matrix(matrix_t *A, matrix_t *B);
int       is_symmetric(matrix_t *A);
int       is_diagonal(matrix_t *A);
int       is_identity(matrix_t *A);
```

- `create_matrix` — `NULL`, если `rows <= 0`, `cols <= 0` или провал `malloc`
  (частично выделенная память освобождается).
- `remove_matrix` — корректно работает с `NULL`/частично заполненной структурой.
- `print_matrix` — вывод в `stdout`, элементы через пробел, строки через `\n`.
- `eq_matrix` — `1`, если размеры совпадают и все элементы равны.
- `is_symmetric` — `1`, если матрица квадратная и `A(i,j) == A(j,i)`.
- `is_diagonal` — `1`, если матрица квадратная и `A(i,j) == 0` при `i != j`.
- `is_identity` — `1`, если матрица квадратная, `A(i,i) == 1` и
  `A(i,j) == 0` при `i != j`.
- На `NULL`/некорректных входных данных все предикаты возвращают `0`.

## Структура

```
student-8/
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
│   ├── eq_matrix.c
│   ├── is_diagonal.c
│   ├── is_identity.c
│   ├── is_symmetric.c
│   ├── main.c
│   ├── print_matrix.c
│   └── remove_matrix.c
├── Makefile
└── README.md
```

## Сборка и запуск

```
make
./matrix
make fclean
```

Флаги: `-Wall -Wextra -Werror`. Без warnings.

## Пример вывода

```
Matrix A:
1 2
3 4

Matrix B (== A):
1 2
3 4

eq_matrix(A, B): 1
is_symmetric(A): 0

Matrix S (symmetric):
1 2 3
2 5 6
3 6 9

is_symmetric(S): 1
is_diagonal(S): 0
is_identity(S): 0

Matrix D (diagonal):
1 0 0
0 5 0
0 0 9

is_symmetric(D): 1
is_diagonal(D): 1
is_identity(D): 0

Matrix E (identity):
1 0 0
0 1 0
0 0 1

is_symmetric(E): 1
is_diagonal(E): 1
is_identity(E): 1
```

## Утечки памяти

```
valgrind --leak-check=full --show-leak-kinds=all ./matrix
```
Ожидается `All heap blocks were freed -- no leaks are possible`.
