#include "libft.h"
#include <stdarg.h>

// Коды метрик
#define METRIC_MIN 0
#define METRIC_MAX 1
#define METRIC_SUM 2
#define METRIC_AVG 3

// Прототипы функций статистики
int min_impl(int count, ...);
int max_impl(int count, ...);
int sum_impl(int count, ...);
int avg_impl(int count, ...);

// Таблица переходов (массив указателей на вариативные функции)
int (*g_metrics[])(int, ...) = {
    min_impl,
    max_impl,
    sum_impl,
    avg_impl
};

// Реализация MIN (вариативная функция)
int min_impl(int count, ...)
{
    va_list args;
    int min_val;
    int current;
    int i;

    if (count <= 0)
        return (0);
    va_start(args, count);
    min_val = va_arg(args, int);
    i = 1;
    while (i < count)
    {
        current = va_arg(args, int);
        if (current < min_val)
            min_val = current;
        i++;
    }
    va_end(args);
    return (min_val);
}

// Реализация MAX
int max_impl(int count, ...)
{
    va_list args;
    int max_val;
    int current;
    int i;

    if (count <= 0)
        return (0);
    va_start(args, count);
    max_val = va_arg(args, int);
    i = 1;
    while (i < count)
    {
        current = va_arg(args, int);
        if (current > max_val)
            max_val = current;
        i++;
    }
    va_end(args);
    return (max_val);
}

// Реализация SUM
int sum_impl(int count, ...)
{
    va_list args;
    int total;
    int i;

    total = 0;
    va_start(args, count);
    i = 0;
    while (i < count)
    {
        total += va_arg(args, int);
        i++;
    }
    va_end(args);
    return (total);
}

// Реализация AVG (округление вниз)
int avg_impl(int count, ...)
{
    va_list args;
    int total;
    int i;

    total = 0;
    va_start(args, count);
    i = 0;
    while (i < count)
    {
        total += va_arg(args, int);
        i++;
    }
    va_end(args);
    if (count > 0)
        return (total / count);
    return (0);
}

// Получение кода метрики по строковому имени
int get_metric_code(char *name)
{
    if (ft_strncmp(name, "min", 3) == 0 && ft_strlen(name) == 3)
        return (METRIC_MIN);
    if (ft_strncmp(name, "max", 3) == 0 && ft_strlen(name) == 3)
        return (METRIC_MAX);
    if (ft_strncmp(name, "sum", 3) == 0 && ft_strlen(name) == 3)
        return (METRIC_SUM);
    if (ft_strncmp(name, "avg", 3) == 0 && ft_strlen(name) == 3)
        return (METRIC_AVG);
    return (-1);
}
// Проверка, является ли строка числом
int is_number(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!str[i])
        return (0);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int main(int argc, char **argv)
{
    int metric_code;
    int *numbers;
    int count;
    int result;
    int i;

    // Проверка минимального количества аргументов: программа + метрика + хотя бы одно число
    if (argc < 3)
    {
        ft_putstr_fd("Ошибка: недостаточно аргументов.\n", 2);
        ft_putstr_fd("Формат: ./stats <min|max|sum|avg> [числа...]\n", 2);
        return (1);
    }

    // Получение кода метрики
    metric_code = get_metric_code(argv[1]);
    if (metric_code == -1)
    {
        ft_putstr_fd("Ошибка: неизвестная метрика.\n", 2);
        ft_putstr_fd("Доступные метрики: min, max, sum, avg\n", 2);
        return (1);
    }

    // Количество чисел
    count = argc - 2;
    if (count == 0)
    {
        ft_putstr_fd("Ошибка: список чисел пуст.\n", 2);
        return (1);
    }

    // Выделение памяти под массив чисел (можно и без массива, но для проверки корректности)
    numbers = (int *)malloc(count * sizeof(int));
    if (!numbers)
    {
        ft_putstr_fd("Ошибка: не удалось выделить память.\n", 2);
        return (1);
    }

    // Преобразование строк в числа и проверка
    i = 0;
    while (i < count)
    {
        if (!is_number(argv[i + 2]))
        {
            ft_putstr_fd("Ошибка: аргумент '", 2);
            ft_putstr_fd(argv[i + 2], 2);
            ft_putstr_fd("' не является целым числом.\n", 2);
            free(numbers);
            return (1);
        }
        numbers[i] = ft_atoi(argv[i + 2]);
        i++;
    }

    // Вызов функции через таблицу переходов с переменным числом аргументов
    // Передаем count и все числа через ...
    switch (metric_code)
    {
    case METRIC_MIN:
        result = g_metrics[METRIC_MIN](count, 
                    numbers[0], (count > 1) ? numbers[1] : 0, 
                    (count > 2) ? numbers[2] : 0, (count > 3) ? numbers[3] : 0,
                    (count > 4) ? numbers[4] : 0, (count > 5) ? numbers[5] : 0,
                    (count > 6) ? numbers[6] : 0, (count > 7) ? numbers[7] : 0,
                    (count > 8) ? numbers[8] : 0, (count > 9) ? numbers[9] : 0);
        break;
    case METRIC_MAX:
        result = g_metrics[METRIC_MAX](count, 
                    numbers[0], (count > 1) ? numbers[1] : 0, 
                    (count > 2) ? numbers[2] : 0, (count > 3) ? numbers[3] : 0,
                    (count > 4) ? numbers[4] : 0, (count > 5) ? numbers[5] : 0,
                    (count > 6) ? numbers[6] : 0, (count > 7) ? numbers[7] : 0,
                    (count > 8) ? numbers[8] : 0, (count > 9) ? numbers[9] : 0);
        break;
    case METRIC_SUM:
        result = g_metrics[METRIC_SUM](count, 
                    numbers[0], (count > 1) ? numbers[1] : 0, 
                    (count > 2) ? numbers[2] : 0, (count > 3) ? numbers[3] : 0,
                    (count > 4) ? numbers[4] : 0, (count > 5) ? numbers[5] : 0,
                    (count > 6) ? numbers[6] : 0, (count > 7) ? numbers[7] : 0,
                    (count > 8) ? numbers[8] : 0, (count > 9) ? numbers[9] : 0);
        break;
    case METRIC_AVG:
        result = g_metrics[METRIC_AVG](count, 
                    numbers[0], (count > 1) ? numbers[1] : 0, 
                    (count > 2) ? numbers[2] : 0, (count > 3) ? numbers[3] : 0,
                    (count > 4) ? numbers[4] : 0, (count > 5) ? numbers[5] : 0,
                    (count > 6) ? numbers[6] : 0, (count > 7) ? numbers[7] : 0,
                    (count > 8) ? numbers[8] : 0, (count > 9) ? numbers[9] : 0);
        break;
    default:
        result = 0;
        break;
    }

    // Вывод результата
    ft_putnbr_fd(result, 1);
    ft_putchar_fd('\n', 1);

    // Очистка памяти
    free(numbers);
    return (0);
}