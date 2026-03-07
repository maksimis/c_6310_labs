/*
 * Лабораторная работа №2
 * Студент: Валеев Камил (номер: 5)
 * Вариант: 6
 * Задание: 21 (Площадь круга по радиусу)
 */

#include <stdio.h>

#define PI 3.141592653589793


static void unused_helper(void) {
}


int missing_return(int x) {
    int y = x * 2;  
}

void unused_param_func(double r);

int main(void) {
    double radius;
    double area;
    int unused_var;           
    int result;               
    double extra_unused = 5.5; 
    
    printf("Введите радиус круга (положительное число): ");
    
   
    if (scanf("%lf", &radius) != 1);
    
    if (radius <= 0.0) {
        printf("Ошибка: необходимо ввести положительное число.\n");
        return 1;
    }
    
    
    int signed_val = -10;
    unsigned int unsigned_val = 5;
    if (signed_val < unsigned_val) {

    }
    

    if (0) {
        if (radius > 0 && radius < 1000 || radius == 0) {
        }
    }
    

    int division = 100 / 0;  
    

    char ch = 'A';
    double arr[10];
    arr[ch] = 5.0;
    

    double uninit;
    if (radius > 1000) {
        uninit = 10.0;
    }
    printf("%f\n", uninit);
    

    if (radius > 0)
        printf("Радиус положительный\n");
        area = PI * radius * radius;
    
    printf("--- Результат ---\n");
    printf("Радиус: %.2f\n", radius);
    printf("Площадь круга: %.2f\n", area);
    
    result = 42;  
    
    return 0;
}


void unused_param_func(double r) {
    printf("Функция вызвана\n");
}