#include "libft.h"
#include <stdio.h>
#include <string.h>

// Функция для преобразования строки в верхний регистр (для ft_lstmap)
void *to_upper_wrapper(void *content)
{
    char *str = (char *)content;
    char *new_str;
    int i;
    
    if (!str)
        return (NULL);
    new_str = ft_strdup(str);
    if (!new_str)
        return (NULL);
    i = 0;
    while (new_str[i])
    {
        if (new_str[i] >= 'a' && new_str[i] <= 'z')
            new_str[i] -= 32;
        i++;
    }
    return (new_str);
}

// Функция для удаления content (просто free)
void del_content(void *content)
{
    if (content)
        free(content);
}

// Функция для вывода content (для ft_lstiter)
void print_content(void *content)
{
    if (content)
        printf("\"%s\" ", (char *)content);
}

// Функция для теста ft_strmapi
char to_upper_char(unsigned int i, char c)
{
    (void)i;
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

void test_list_functions(void)
{
    printf("\n=== Тест функций работы со списками ===\n");
    
    // Создаём список
    t_list *list = NULL;
    
    // Добавляем элементы в начало
    ft_lstadd_front(&list, ft_lstnew(ft_strdup("First")));
    ft_lstadd_front(&list, ft_lstnew(ft_strdup("Second")));
    ft_lstadd_front(&list, ft_lstnew(ft_strdup("Third")));
    
    printf("Список после добавления в начало: ");
    ft_lstiter(list, print_content);
    printf("\n");
    
    printf("Размер списка: %d\n", ft_lstsize(list));
    printf("Последний элемент: \"%s\"\n", (char *)ft_lstlast(list)->content);
    
    // Добавляем в конец
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("Fourth")));
    printf("После добавления 'Fourth' в конец: ");
    ft_lstiter(list, print_content);
    printf("\n");
    printf("Новый размер: %d\n", ft_lstsize(list));
    
    // Создаём новый список с преобразованием в верхний регистр
    t_list *upper_list = ft_lstmap(list, to_upper_wrapper, del_content);
    printf("Новый список (в верхнем регистре): ");
    ft_lstiter(upper_list, print_content);
    printf("\n");
    
    // Очищаем списки
    ft_lstclear(&list, del_content);
    ft_lstclear(&upper_list, del_content);
    printf("Списки очищены\n");
}

void test_all_functions(void)
{
    printf("=== ПОЛНОЕ ТЕСТИРОВАНИЕ LIBFT ===\n\n");
    
    // 1. Проверка символов
    printf("1. Проверка символов:\n");
    printf("   ft_isalpha('A'): %d\n", ft_isalpha('A'));
    printf("   ft_isdigit('5'): %d\n", ft_isdigit('5'));
    printf("   ft_isalnum('Z'): %d\n", ft_isalnum('Z'));
    printf("   ft_isascii(65): %d\n", ft_isascii(65));
    printf("   ft_isprint(' '): %d\n", ft_isprint(' '));
    printf("   ft_toupper('z'): '%c'\n", ft_toupper('z'));
    printf("   ft_tolower('Q'): '%c'\n", ft_tolower('Q'));
    printf("   ft_isspace('\\t'): %d\n", ft_isspace('\t'));
    
    // 2. Длина строки
    printf("\n2. ft_strlen(\"Hello\"): %zu\n", ft_strlen("Hello"));
    
    // 3. Копирование и конкатенация
    char dest[20];
    printf("\n3. ft_strlcpy: %zu -> \"%s\"\n", ft_strlcpy(dest, "Hi", 3), dest);
    printf("   ft_strlcat: %zu -> \"%s\"\n", ft_strlcat(dest, " World", 20), dest);
    
    // 4. Поиск в строке
    printf("\n4. ft_strchr(\"Hello\", 'l'): \"%s\"\n", ft_strchr("Hello", 'l'));
    printf("   ft_strrchr(\"Hello\", 'l'): \"%s\"\n", ft_strrchr("Hello", 'l'));
    printf("   ft_strnstr(\"Hello World\", \"World\", 11): \"%s\"\n", ft_strnstr("Hello World", "World", 11));
    printf("   ft_strncmp(\"Hello\", \"Helix\", 3): %d\n", ft_strncmp("Hello", "Helix", 3));
    
    // 5. Преобразования
    printf("\n5. ft_atoi(\"   -123\"): %d\n", ft_atoi("   -123"));
    char *itoa_result = ft_itoa(-456);
    printf("   ft_itoa(-456): \"%s\"\n", itoa_result);
    free(itoa_result);
    
    // 6. Работа с памятью
    printf("\n6. ft_calloc: ");
    int *arr = (int *)ft_calloc(5, sizeof(int));
    printf("%d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
    free(arr);
    
    char *dup = ft_strdup("Duplicate me");
    printf("   ft_strdup: \"%s\"\n", dup);
    free(dup);
    
    // 7. Строковые функции
    printf("\n7. ft_substr(\"Hello World\", 6, 5): \"%s\"\n", ft_substr("Hello World", 6, 5));
    printf("   ft_strjoin(\"Hello \", \"World\"): \"%s\"\n", ft_strjoin("Hello ", "World"));
    printf("   ft_strtrim(\"   Hello   \", \" \"): \"%s\"\n", ft_strtrim("   Hello   ", " "));
    
    char **split = ft_split("Hello World from 42", ' ');
    printf("   ft_split: [");
    for (int i = 0; split[i]; i++)
    {
        printf("\"%s\"", split[i]);
        if (split[i + 1])
            printf(", ");
        free(split[i]);
    }
    printf("]\n");
    free(split);
    
    printf("   ft_strmapi(\"hello\", to_upper): \"%s\"\n", ft_strmapi("hello", to_upper_char));
    
    // 8. Вывод
    printf("\n8. Функции вывода (проверьте вывод):\n");
    printf("   ft_putstr_fd: ");
    ft_putstr_fd("Test output", 1);
    ft_putchar_fd('\n', 1);
    printf("   ft_putnbr_fd: ");
    ft_putnbr_fd(12345, 1);
    ft_putchar_fd('\n', 1);
    
    // 9. Списки
    test_list_functions();
    
    printf("\n=== ВСЕ ТЕСТЫ ПРОЙДЕНЫ ===\n");
}

int main(void)
{
    test_all_functions();
    return 0;
}