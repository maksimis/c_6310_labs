/*
 * Лабораторная работа №2
 * Студент: Багаутдинова Диана (номер: 3)
 * Вариант: 4
 * Задание: 4 (Факториал числа)
 * Количество предупреждений: 15 (из них 5 -Wextra)
 */

#include <stdio.h>

// Предупреждение 2: неиспользуемый параметр
void print_hello(int x) {
    printf("Hello\n");
}

// Предупреждение 3: неиспользуемая статическая функция
static void unused_helper(void) {
    printf("This function is never called\n");
}

// Предупреждение 4: отсутствие return
int get_number(void) {
    // нет return
}

int main(void) {
    int n;
    long long factorial = 1;
    
    // Предупреждение 1: неиспользуемая переменная
    int unused_counter = 0;

    printf("Задание 4. Вычисление факториала числа.\n");
    printf("Введите неотрицательное целое число n: ");

    if (scanf("%d", &n) != 1) {
        printf("Ошибка: необходимо ввести целое число.\n");
        return 1;
    }

    if (n < 0) {
        printf("Ошибка: факториал для отрицательного числа не определен.\n");
        return 1;
    }

    // Предупреждение 5: сравнение знакового и беззнакового
    size_t size_val = 10;
    if (size_val < n) {
        printf("size_val меньше n\n");
    }

    // НОВОЕ: Предупреждение 6: точная неинициализированная переменная (-Wuninitialized)
    int exact_uninit;
    printf("exact_uninit = %d\n", exact_uninit);

    // Предупреждение 7: отсутствие скобок (-Wparentheses)
    int x = 5, y = 10;
    if (x = 5 || y == 10) {
        printf("Condition true\n");
    }

    // Предупреждение 8: char как индекс массива (-Wchar-subscripts)
    char index_char = 'A';
    int array[10] = {0};
    int val = array[index_char];
    (void)val;

    // Предупреждение 9: пустое тело if (-Wempty-body)
    if (n == 0); {
        printf("n равно нулю\n");
    }

    // Предупреждение 10: деление на ноль (-Wdiv-by-zero)
    volatile int zero = 0;
    if (0) {
        volatile int result = 10 / zero;
        (void)result;
    }

    // Предупреждение (дополнительное): несоответствие указателей по знаковости
    char *str = "hello";
    unsigned char *ustr = (unsigned char*)str;
    (void)ustr;

    // ===== БОНУСНЫЕ ПРЕДУПРЕЖДЕНИЯ -Wextra =====
    
    // Бонус 1: -Wtype-limits (сравнение всегда истинно)
    unsigned int u_val = 5;
    if (u_val >= 0) {
        printf("u_val >= 0 всегда истинно\n");
    }
    
    // Бонус 2: -Wunused-but-set-variable (переменная присваивается, но не используется)
    int temp_var = 10;
    temp_var = 20;
    // temp_var больше нигде не используется
    
    // Бонус 3: -Woverflow (переполнение при присваивании)
    char overflow_char = 300;
    (void)overflow_char;
    
    // Бонус 4: -Wshift-count-overflow (переполнение при сдвиге)
    int shift_overflow = 1 << 40;
    (void)shift_overflow;
    
    // Бонус 5: -Wmaybe-uninitialized (возможно неинициализирована)
    int maybe_uninit;
    if (n > 100) {
        maybe_uninit = 42;
    }
    printf("maybe_uninit = %d\n", maybe_uninit);
    
    // ===== КОНЕЦ БОНУСНЫХ ПРЕДУПРЕЖДЕНИЙ =====

    // основная логика программы
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }

    printf("%d! = %lld\n", n, factorial);

    return 0;
}