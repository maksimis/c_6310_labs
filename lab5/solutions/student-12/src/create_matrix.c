#include "matrix.h"
#include "libft.h" // для ft_calloc и free

matrix_t *create_matrix(int rows, int cols) // создаёт матрицу в памяти и возвращает указатель на неё
{
    matrix_t *res; // будущая матрица (указатель)
    int i; // счётчик для цикла

    if (rows <= 0 || cols <= 0) // проверка входных данных
        return (NULL);
    
    // выделение памяти под структуру
    res = (matrix_t *)ft_calloc(1, sizeof(matrix_t)); // sizeof(matrix_t) → размер структуры, 1 → одна структура, ft_calloc → выделяет память + заполняет нулями
    if (!res) // проверка, если память не выделилась
        return (NULL);
    
    // сохраняем размеры внутри структуры
    res->rows = rows;
    res->columns = cols;
    
    // выделение памяти под массив строк (создаём массив указателей)
    res->matrix = (int **)ft_calloc(rows, sizeof(int *));
    if (!res->matrix) // проверка, если чет не получилось освобождаем структуру и выходим
    {
        free(res);
        return (NULL);
    }

    // выделение памяти для каждой строки
    i = 0;
    while (i < rows)
    {
        res->matrix[i] = (int *)ft_calloc(cols, sizeof(int)); // создаём массив чисел: [0, 0, 0, ..., 0]
        if (!res->matrix[i]) // Проверка ошибки, если не удалось выделить строку
        {
            while (i > 0) // Если ошибка на строке i: освобождаем уже созданные строки
                free(res->matrix[--i]);
            free(res->matrix); // освобождаем массив указателей
            free(res); // освобождаем структуру
            return (NULL);
        }
        i++;
    }

    return (res);
}