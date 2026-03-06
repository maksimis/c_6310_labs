/*
* Лабораторная работа №2
 * Студент: Гимадиев Адель (номер: 9)
 * Вариант: 10
 * Задание: 10 (Перевод десятичного числа в двоичное)
 * Количество предупреждений: 10 (из них 5 -Wextra)
*/

#include <stdio.h>
#include <string.h>

// 1. Неиспользуемая статическая функция 
static void helper_for_binary_conversion() {
    printf("Эта функция никогда не используется\n");
}

// 2. Функция без явного типа возврата
int old_style_processor(int value)
{
    // 3. Нет return 
    int local_copy = value * 2;
}

// 4. Функция с неиспользуемым параметром 
void print_result_info(int main_result, int extra_info_unused) {
    printf("Результат обработки: %d\n", main_result);
    (void)extra_info_unused;  
}

int main(void)
{
    int input_number;
    int binary_bits[64];
    int bit_position = 0;


    // 5. Неиспользуемая переменная 
    int debug_counter = 999;

    // 6. Переменная присвоена, но не используется 
    int temporary_sum = 0;
    temporary_sum = input_number + 1;

    printf("Введите неотрицательное целое число: ");
    if (scanf("%d", &input_number) != 1) {
        printf("Ошибка: необходимо ввести целое число.\n");
        return 1;
    }

    if (input_number < 0) {
        printf("Ошибка: число должно быть неотрицательным.\n");
        return 1;
    }

    if (input_number == 0) {
        printf("Двоичное представление: 0\n");
        return 0;
    }

    int working_copy = input_number;

    while (working_copy > 0) {
        binary_bits[bit_position] = working_copy % 2;
        working_copy /= 2;
        bit_position++;
    }

    printf("Двоичное представление числа %d: ", input_number);

    for (int i = bit_position - 1; i >= 0; i--) {
        printf("%d", binary_bits[i]);
    }
    printf("\n");

    // 7. Несоответствие signed/unsigned указателей 
    signed char sign_char = 'A';
    unsigned char *unsigned_view = &sign_char;

    // 8. Сдвиг на количество >= ширины типа 
    int dangerous_shift = 1 << 32;

    // 9. Пустое тело условного оператора 
    if (input_number > 1000)
        ;  

    // 10. Сравнение указателя с целым числом 
    if (binary_bits == 0) {
        printf("Это никогда не сработает\n");
    }


    // ------- Предупреждения -Wextra -------

    // 1. возможное всегда истинное/ложное сравнение / переполнение константы
    if (input_number < 0x7FFFFFFF + 1) {
        printf("число меньше или равно INT_MAX\n");
    }
    // 2. возможное использование неинициализированной переменной
    int maybe_uninit;
    if (input_number > 500) {
        maybe_uninit = 42;
    }
    maybe_uninit += 0;

    // 3. Неполная инициализация структуры
    struct Point {
        int x;
        int y;
        int z;
    };
    struct Point p = {10};           

    // 4. сравнение, которое всегда истинно/ложно
    unsigned char uc = 200;
    if (uc <= 255) {             
        ;
    }

    // 5. приведение с возможным нарушением выравнивания
    char buffer[16] = "test123";
    int *misaligned = (int *)(buffer + 1);     

    return 0;
}