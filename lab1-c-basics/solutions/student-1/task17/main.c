/*
    * Лабораторная работа №1
    * Студент: Асфандияров Камиль (номер: 1)
    * Вариант: 2
    * Задание: 17 (Наименьшее общее кратное двух чисел)
    */

#include <stdio.h>     
#include <stdlib.h>     

int nod(int a, int b) {     
    while (b != 0) {        
        int temp = b;       
        b = a % b;          

        a = temp;           

    }
    return a;               
}

int main() {

    int a = 12;             
    int b = 18;             

    int result = abs(a * b) / nod(a, b);  

    printf("NOK = %d\n", result);  
    return 0;               
}