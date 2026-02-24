/*
Лабораторная работа №2
Студент: Беляев Влад (номер: 4)
Вариант: 5
Задание: 5 (N-е число Фибоначчи)
Количество предупреждений: 15 (из них 5 -Wextra)
*/

#include <stdio.h>

// -Wall
// 1. Неиспользуемая статическая функция (unused-function)
static void unused_func(void) {
    // пусто
}

// 2. Функция без возвращаемого значения (return-type)
int no_return_func(void) {
    // нет return
}

// 3. Неиспользуемое значение (unused-value)
void unused_value(void) {
    1; // выражение без эффекта
}


// 4. Вводящий в заблуждение отступ (misleading-indentation)
void misleading_indent(void) {
    int x = 0;
    if (x == 0);
    {
        // этот блок с отступом, но не относится к if
    }
}

// 5. Отсутствие скобок в логическом выражении (parentheses)
void parentheses_warn(void) {
    int a = 1, b = 2, c = 3;
    if (a && b || c) {
        // пусто
    }
}

// 6. Использование char в качестве индекса массива (char-subscripts)
void char_subscript(void) {
    char idx = -1;
    int arr[10] = {0};
    int val = arr[idx];
    (void)val; // подавление unused
}

// 7. Несоответствие указателей по знаковости (pointer-sign)
void pointer_sign(void) {
    char c = 'A';
    unsigned char *ucp = &c; // предупреждение
    (void)ucp;
}

// 8. Деление на ноль (div-by-zero)
void div_by_zero(void) {
    int x = 1 / 0; // константное деление на ноль
    (void)x;
}

// 9. Использование неинициализированной переменной (uninitialized)
void uninitialized_var(void) {
    int z;
    int w = z; // чтение неинициализированной переменной
    (void)w;
}

//-Wextra

// 11. Сравнение, которое всегда истинно/ложно (type-limits)
void type_limits_warn(void) {
    unsigned int u = 0;
    if (u < 0) { // всегда ложно
        // пусто
    }
}

// 12. Переменная присваивается, но не используется (unused-but-set-variable)
void unused_but_set_var(void) {
    int x = 5;
    x = 10; // присвоили, но не используем
}

// 13. Параметру присваивается, но не используется (unused-but-set-parameter)
void unused_but_set_param(int x) {
    x = 100; // присвоили, но не используем
}

// 14. Сдвиг на количество бит, превышающее размер типа (shift-count-overflow)
void shift_overflow(void) {
    int x = 1 << 40; // сдвиг на 40 при 32-битном int
    (void)x;
}

// 15. Пропущены поля при инициализации структуры (missing-field-initializers)
struct S {
    int a;
    int b;
    int c;
};

void missing_field_initializers(void) {
    struct S s = {1, 2}; // пропущено поле c
    (void)s;
}

// функция вычисления числа фибоначчи
int fib(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int main(void) {
    // 10. Неиспользуемая переменная (unused-variable)
    int not_used;

    int n;
    printf("Введите номер числа Фибоначчи (n >= 0): ");
    if (scanf("%d", &n) != 1) {
        printf("Ошибка: вы ввели не целое число.\n");
        return 1;
    }
    if (n < 0) {
        printf("Ошибка: номер не может быть отрицательным.\n");
        return 1;
    }

    int result = fib(n);
    printf("fib(%d) = %d\n", n, result);

    return 0;
}