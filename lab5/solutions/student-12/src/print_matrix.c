#include "matrix.h"
#include "libft.h" // для ft_putnbr_fd и ft_putchar_fd

void print_matrix(matrix_t *A)
{
    int i; // индекс строки
    int j; // индекс столбца

    if (!A || !A->matrix) // проверяем: матрица не существует или нет данных внутри
        return;

    i = 0;
    while (i < A->rows) // внешний цикл (по строкам)
    {
        j = 0;
        while (j < A->columns) // внутренний цикл (по столбцам)
        {
            ft_putnbr_fd(A->matrix[i][j], 1); // вывод элемента: A->matrix[i][j] → элемент матрицы, 1 → в stdout (стандартный вывод (экран))
            if (j < A->columns - 1) // пробел между элементами, кроме последнего
                ft_putchar_fd(' ', 1);
            j++;
        }
        ft_putchar_fd('\n', 1); // перевод строки
        i++;
    }
}