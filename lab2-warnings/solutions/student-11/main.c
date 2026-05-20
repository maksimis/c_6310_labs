/*
 * Лабораторная работа №2
 * Студент: Дунаев Владислав (номер: 11)
 * Вариант: 12
 * Задание: 12 (Проверка числа на палиндром в двоичной системе)
 * Количество предупреждений: 18 (из них 6 -Wextra)
 */

#include <stdio.h>
#include <stdlib.h>

// Прототип для избежания ошибки неявного объявления
int implicit_func(int x);

// Неиспользуемая статическая функция (unused function) - Wall
static void unused_helper(void) {
    int x = 10; // Неиспользуемая переменная (unused variable) - Wall
}

// Функция без прототипа (deprecated) - Wall
int old_style_function();
int old_style_function(p)
int p;
{
    return p * 2;
}

static int read_integer(long *value);
static void print_binary_representation(unsigned long number);
static int is_binary_palindrome(unsigned long number);

// Неиспользуемый параметр (unused parameter) - Wall, плюс unused-but-set (Wextra)
static void unused_param_example(int a, int b) {
    a = a + 1;   // параметр используется, но b - не используется
    int c = b;   // b не используется далее? нет, c не используется -> unused variable
}

// Функция, которая не возвращает значение (non-void function without return) - Wall
int missing_return(int x) {
    x = x * 2;
    // нет return
}

int main(int argc, char *argv[])   // argc, argv не используются -> unused parameter (Wall)
{
    long number = 0;
    int unused_but_set;          // unused-but-set-variable (Wextra)

    printf("Enter an integer: ");
    if (!read_integer(&number)) {
        fprintf(stderr, "Error: invalid input.\n");
        return 1;
    }

    // Сравнение знакового и беззнакового (sign-compare) - Wall
    unsigned int dummy_unsigned = 5;
    if (number < dummy_unsigned) {
        ; // пустое тело (empty body) - Wall
    }

    if (number < 0) {
        fprintf(stderr, "Error: negative numbers are not supported.\n");
        return 1;
    }

    unsigned long unsigned_number = (unsigned long)number;

    // Сравнение, которое всегда истинно (type-limits) - Wextra
    if (unsigned_number >= 0) {
        // бессмысленно, но безопасно
    }

    // Неинициализированная переменная (uninitialized) - Wall
    int uninitialized_val;
    unused_but_set = uninitialized_val;  // предупреждение: uninitialized

    // Неиспользуемый результат выражения (expression result unused) - Wall
    number + 10;

    // char как индекс массива (char-subscripts) - Wall
    int dummy_array[10] = {0};
    char idx = 5;
    dummy_array[idx] = 42;

    // Вызов функции, объявленной позже (теперь есть прототип)
    implicit_func(100);

    // Переполнение при сдвиге (shift-count-overflow) - Wextra
    unsigned long shift_test = 1UL << 64;  // сдвиг на 64 бита, для 64-битной платформы

    // Структура с неполной инициализацией (missing-field-initializers) - Wextra
    struct Point {
        int x;
        int y;
        int z;
    };
    struct Point p = {10, 20};  // пропущено поле z

    printf("Decimal number: %ld\n", number);
    printf("Binary representation: ");
    print_binary_representation(unsigned_number);
    printf("\n");

    if (is_binary_palindrome(unsigned_number)) {
        printf("Result: the number is a palindrome in binary.\n");
    } else {
        printf("Result: the number is not a palindrome in binary.\n");
    }

    return 0;
}

// Функция, вызванная ранее (теперь определена после main, но прототип есть)
int implicit_func(int x) {
    return x * 2;
}

static int read_integer(long *value)
{
    int result = scanf("%ld", value);
    if (result != 1) {
        return 0;
    }
    return 1;
}

static void print_binary_representation(unsigned long number)
{
    if (number == 0) {
        printf("0");
        return;
    }

    char buffer[65];
    int index = 0;

    while (number > 0) {
        buffer[index++] = (char)('0' + (number & 1UL));
        number >>= 1;
    }

    while (index > 0) {
        putchar(buffer[--index]);
    }
}

static int is_binary_palindrome(unsigned long number)
{
    if (number == 0) {
        return 1;
    }

    unsigned long reversed = 0;
    unsigned long original = number;

    while (number > 0) {
        reversed = (reversed << 1) | (number & 1UL);
        number >>= 1;
    }

    return reversed == original;
}