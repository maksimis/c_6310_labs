/*
Лабораторная работа №2
Студент: Закиева Алина (номер: 13)
Вариант: 14
Задание: 14 (Среднее значение вещественного массива) 
*/

#include <stdio.h>
#define MAX_N 100000

int main(void) { 
    int n;
    printf("Задайте размерность вещественного массива: ");
    
    if (scanf("%d", &n) != 1) {
        printf("Ошибка: нужно ввести целое число.\n");
        return 1;
    }  
    if (n <= 0) {
        printf("Ошибка: n должно быть больше нуля.\n");
        return 1;
    }
    if (n > MAX_N) {
        printf("Ошибка: n слишком большое (максимум %d).\n", MAX_N);
        return 1;
    }

    double mas[n];
    printf("Заполните вещественный массив: ");
    for (int i = 0; i < n; i++) {
        if (scanf("%lf", &mas[i]) != 1) {
            printf("Ошибка: нужно ввести вещественные числа.\n");
            return 1;
        }
    }
    
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += mas[i];
    }
    double sr = sum / n;
    printf("Среднее значение вещественного массива: %.2f\n", sr);

    return 0;
}


// Предупреждения -Wall

// Неиспользуемая переменная
void warn1(void) {
    int x = 1;
}

// Неиспользуемый параметр функции
void warn2(int parametr) {

}

// Неиспользуемая статическая функция
static void warn3(void) {

}

// Отсутствие return в функции
int warn4(void) {

}

// Сравнение знакового и беззнакового
void warn5(void) {
    unsigned int x = 1;
    int y = 2;
    if (x < y) {
        x += 1;
    }
}

// Использование неинициализированной переменной
void warn6(void) {
    int x;
    int v = x;
    (void)v;
}

// Деление на ноль
void warn7(void) {
    int x = 1 / 0;
    (void)x;
}

// Вводящий в заблуждение отступ
void warn8(void) {
    int x = 1;
    if (x < 5)
        x += 1;
        int y = x;
    (void)y;
}

// Пустое тело if/else/while
void warn9(void) {
    int x = 0;
    if (x == 0);
}

// Использование char как индекса массива
void warn10(void) {
    char x = 1;
    int mas[2] = {0, 1};
    int d = mas[x];
    (void)d;
}


// Предупреждения -Wextra

// Сравнение, которое всегда истинно/ложно
void warn11(void) {
    unsigned int x = 2;
    if (x < 0) {
        x += 1;
    }
}

// Параметр присваивается, но не используется
void warn12(int max) {
    max = 15;
}

// Переменная присваивается, но не используется
void warn13(void) {
    int x;
    x = 5 + 5;
}

// Переполнение при константных вычислениях
void warn14(void) {
    int x = 2147483647 + 1;
    (void)x;
}

// Сдвиг на количество бит, превышающее размер типа
void warn15(void) {
    int x = 1 << 40;
    (void)x;
}