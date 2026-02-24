   /*
    * Лабораторная работа №1
    * Студент: Котова Алиса (номер: 19)
    * Вариант: 19
    * Задание: 19 (Вычисление значения функции y = x² + 2x + 1)
    */

    #include <stdio.h>
    #include <windows.h> 

// Именованные константы 
#define COEFFICIENT_A 1
#define COEFFICIENT_B 2
#define COEFFICIENT_C 1

// Функция вычисляет значение выражения y = x^2 + 2x + 1
double calculate_function(double input_value) {
    double result;

    // Формула функции
    result = COEFFICIENT_A * input_value * input_value +
             COEFFICIENT_B * input_value +
             COEFFICIENT_C;

    return result; // Возвращаем вычисленное значение
}

int main(void) {
   SetConsoleOutputCP(CP_UTF8);
   SetConsoleCP(CP_UTF8);
    double user_input;   // Переменная для хранения введённого x
    double function_result; // Переменная для результата функции

    // Просим пользователя ввести значение
    printf("Введите значение x: ");

    // Проверяем, что введено число
    if (scanf("%lf", &user_input) != 1) {
        printf("Ошибка: нужно ввести число.\n");
        return 1; // Завершаем программу с кодом ошибки
    }

    // Вызываем функцию вычисления
    function_result = calculate_function(user_input);

    // Выводим результат
    printf("Значение функции y = x^2 + 2x + 1 при x = %.2f равно %.2f\n",
           user_input,
           function_result);

    return 0; // Успешное завершение программы
}