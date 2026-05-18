/*
 * Лабораторная работа №1
 * Студент: Гимадиев Адель (номер: 9)
 * Вариант: 10
 * Задание: 25 (Проверка строки на панграмму)
*/

#include <stdio.h>
#include <ctype.h> 

#define ALPHABET_SIZE 26
#define MAX_STRING 1024

int main(void) {
    char line[MAX_STRING];
    int letters[ALPHABET_SIZE] = {0};   
    int all_present = 1;                

    printf("Введите строку на английском для проверки на панграмму: ");

    if (fgets(line, sizeof(line), stdin) == NULL) {
        printf("Ошибка ввода.\n");
        return 1;
    }

    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '\n') {
            line[i] = '\0';
            break;
        }
    }

    for (int i = 0; line[i] != '\0'; i++) {
        char ch = line[i];
        if (isalpha(ch)) {
            char lower = tolower(ch);        
            int idx = lower - 'a';          
            if (idx >= 0 && idx < ALPHABET_SIZE) {
                letters[idx] = 1;
            }
        }
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (letters[i] == 0) {
            all_present = 0;
            break;
        }
    }

    if (all_present) {
        printf("Строка является панграммой (содержит все буквы английского алфавита).\n");
    } else {
        printf("Строка не является панграммой.\n");
    }

    return 0;
}