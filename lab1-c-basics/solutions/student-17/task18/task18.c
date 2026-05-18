// 18. Сумма первых n натуральных чисел

#include <stdio.h>

int main() {

    int number;
    int sum = 0;
    
    if (scanf("%d", &number) != 1) {
        printf("Ошибка! Нужно ввести число.\n");
        return 1;
    }

    for (int num = 1; num <= number; num++) {
        sum = num + sum;
    }

    printf("Сумма первых %d натуральных чисел: %d\n", number, sum);
    
    return 0;
}