/*
 * Лабораторная работа №1
 * Студент: Королева Диана Дмитриевна (номер: 18)
 * Вариант: 19
 * Задание: 19 (Вычисление значения функции y = x² + 2x + 1)
 */

#include <stdio.h>

int unused_result(int x) {
    x * 2; //1. Неиспользуемый результат выражения x * 2 (expression result unused)
} //2. Отсутствие возвращаемого значения в функции (non-void function does not return a value)


static void unused_function(void) { //11. Неиспользуемая функция (unused function)
    int x = 1; //3. Неиспользуемая переменная (warning: unused variable)
}

double calculate_function(double argument) {
    const int const signed_value = -5; //4. Избыточный спецификатор объявления (duplicate 'const' declaration specifier)
    unsigned int unsigned_counter = 5;
    if (signed_value > unsigned_counter) {  //Сравнение знаковых и беззнаковых типов (comparison of integers of different signs)
    }

    return argument * argument + 2.0 * argument + 1.0;
}

int function_with_unused_param(int param1, int param2) { //6. Неиспользуемый параметр (unused parameter)
    return param1;  
}

int function(p) //5. Функция без прототипа (a function definition without a prototype is deprecated in all versions of C and is not supported in C23)
int p;
{
    return p * 2;
}

void char_subscript_warning(void) {
    int arr[5] = {0};
    char c = 10;
    arr[c] = 42;  //6. char как индекс массива (array subscript is of type 'char')
}

void pointer(void) {
    signed char *signed_ptr = "hello";  //7. Несоответствие указателей по знаковости (initializing 'signed char *' with an expression of type 'char[6]' converts between pointers to integer types where one is of the unique plain 'char' type and the other is not)
    unsigned char *unsigned_ptr = "world";  //8. Несоответствие указателей по знаковости
}

int main(void) {
    double input_value;
    int scanf_result;
    int unused; //9. Переменной присваивается значение, но не используется (variable 'unused' set but not used)

    int uninitialized; //10. Неинициализированная переменная (variable 'uninitialized_var' is uninitialized when used here)

    unused = uninitialized;


    printf("Вычисление значения функции y = x² + 2x + 1\n");
    printf("Введи значение аргумента x: ");
    
    scanf_result = scanf("%lf", &input_value);
    
    if (scanf_result != 1) {
        printf("Ошибка ввода числа\n");
        return 1;
    }
    
    double function_result = calculate_function(input_value);
    printf("При аргументе x = %.2f, значение функции y = %.2f\n", input_value, function_result);
    
    return 0;
}