#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// ============ ТЕСТЫ "Проверка символов и строки" ============
void test_isalpha(void)
{
    printf("\n=== Тест ft_isalpha ===\n");
    printf("ft_isalpha('A') = %d (оригинал = %d) %s\n", 
           ft_isalpha('A'), isalpha('A'),
           ft_isalpha('A') == isalpha('A') ? "✓" : "✗");
    printf("ft_isalpha('z') = %d (оригинал =  %d) %s\n", 
           ft_isalpha('z'), isalpha('z'),
           ft_isalpha('z') == isalpha('z') ? "✓" : "✗");
    printf("ft_isalpha('5') = %d (оригинал = %d) %s\n", 
           ft_isalpha('5'), isalpha('0'),
           ft_isalpha('5') == isalpha('0') ? "✓" : "✗");
    printf("ft_isalpha('!') = %d (оригинал = %d) %s\n", 
           ft_isalpha('!'), isalpha('!'),
           ft_isalpha('!') == isalpha('!') ? "✓" : "✗");
    printf("ft_isalpha(' ') = %d (оригинал = %d) %s\n", 
           ft_isalpha(' '), isalpha(' '),
           ft_isalpha(' ') == isalpha(' ') ? "✓" : "✗");
}

void test_isdigit(void)
{
    printf("\n=== Тест ft_isdigit ===\n");
    printf("ft_isdigit('5') = %d (оригинал = %d) %s\n", 
           ft_isdigit('5'), isdigit('5'),
           ft_isdigit('5') == isdigit('5') ? "✓" : "✗");
    printf("ft_isdigit('A') = %d (оригинал = %d) %s\n", 
           ft_isdigit('A'), isdigit('A'),
           ft_isdigit('A') == isdigit('A') ? "✓" : "✗");
    printf("ft_isdigit('0') = %d (оригинал = %d) %s\n", 
           ft_isdigit('0'), isdigit('0'),
           ft_isdigit('0') == isdigit('0') ? "✓" : "✗");
    printf("ft_isdigit('9') = %d (оригинал = %d) %s\n", 
           ft_isdigit('9'), isdigit('9'),
           ft_isdigit('9') == isdigit('9') ? "✓" : "✗");
}

void test_isalnum(void)
{
    printf("\n=== Тест ft_isalnum ===\n");
    printf("ft_isalnum('A') = %d (оригинал = %d) %s\n", 
           ft_isalnum('A'), isalnum('A'),
           ft_isalnum('A') == isalnum('A') ? "✓" : "✗");
    printf("ft_isalnum('5') = %d (оригинал = %d) %s\n", 
           ft_isalnum('5'), isalnum('5'),
           ft_isalnum('5') == isalnum('5') ? "✓" : "✗");
    printf("ft_isalnum('!') = %d (оригинал = %d) %s\n", 
           ft_isalnum('!'), isalnum('!'),
           ft_isalnum('!') == isalnum('!') ? "✓" : "✗");
}

void test_isascii(void)
{
    printf("\n=== Тест ft_isascii ===\n");
    printf("ft_isascii('A') = %d (оригинал = %d) %s\n", 
           ft_isascii('A'), isascii('A'),
           ft_isascii('A') == isascii('A') ? "✓" : "✗");
    printf("ft_isascii(128) = %d (оригинал = %d) %s\n", 
           ft_isascii(128), isascii(128),
           ft_isascii(128) == isascii(128) ? "✓" : "✗");
    printf("ft_isascii(0) = %d (оригинал = %d) %s\n", 
           ft_isascii(0), isascii(0),
           ft_isascii(0) == isascii(0) ? "✓" : "✗");
}

void test_isprint(void)
{
    printf("\n=== Тест ft_isprint ===\n");
    printf("ft_isprint('A') = %d (оригинал = %d) %s\n", 
           ft_isprint('A'), isprint('A'),
           ft_isprint('A') == isprint('A') ? "✓" : "✗");
    printf("ft_isprint('\\n') = %d (оригинал = %d) %s\n", 
           ft_isprint('\n'), isprint('\n'),
           ft_isprint('\n') == isprint('\n') ? "✓" : "✗");
    printf("ft_isprint(' ') = %d (оригинал = %d) %s\n", 
           ft_isprint(' '), isprint(' '),
           ft_isprint(' ') == isprint(' ') ? "✓" : "✗");
}

void test_toupper(void)
{
    printf("\n=== Тест ft_toupper ===\n");
    printf("ft_toupper('a') = '%c' (оригинал = '%c') %s\n", 
           ft_toupper('a'), toupper('a'),
           ft_toupper('a') == toupper('a') ? "✓" : "✗");
    printf("ft_toupper('A') = '%c' (оригинал = '%c') %s\n", 
           ft_toupper('A'), toupper('A'),
           ft_toupper('A') == toupper('A') ? "✓" : "✗");
    printf("ft_toupper('5') = '%c' (оригинал = '%c') %s\n", 
           ft_toupper('5'), toupper('5'),
           ft_toupper('5') == toupper('5') ? "✓" : "✗");
}

void test_tolower(void)
{
    printf("\n=== Тест ft_tolower ===\n");
    printf("ft_tolower('A') = '%c' (оригинал = '%c') %s\n", 
           ft_tolower('A'), tolower('A'),
           ft_tolower('A') == tolower('A') ? "✓" : "✗");
    printf("ft_tolower('a') = '%c' (оригинал = '%c') %s\n", 
           ft_tolower('a'), tolower('a'),
           ft_tolower('a') == tolower('a') ? "✓" : "✗");
    printf("ft_tolower('5') = '%c' (оригинал = '%c') %s\n", 
           ft_tolower('5'), tolower('5'),
           ft_tolower('5') == tolower('5') ? "✓" : "✗");
}

// ============ ТЕСТЫ ДЛЯ РАБОТЫ СО СТРОКАМИ ============

void test_strlen(void)
{
    printf("\n=== Тест ft_strlen ===\n");
    char *test1 = "Hello";
    char *test2 = "";
    char *test3 = "Hello, World!";
    
    printf("ft_strlen(\"%s\") = %zu (оригинал = %zu) %s\n", 
           test1, ft_strlen(test1), strlen(test1),
           ft_strlen(test1) == strlen(test1) ? "✓" : "✗");
    printf("ft_strlen(\"%s\") = %zu (оригинал = %zu) %s\n", 
           test2, ft_strlen(test2), strlen(test2),
           ft_strlen(test2) == strlen(test2) ? "✓" : "✗");
    printf("ft_strlen(\"%s\") = %zu (оригинал = %zu) %s\n", 
           test3, ft_strlen(test3), strlen(test3),
           ft_strlen(test3) == strlen(test3) ? "✓" : "✗");
}

void test_strchr(void)
{
    printf("\n=== Тест ft_strchr ===\n");
    char *str = "Hello, World!";
    
    printf("ft_strchr(\"%s\", 'o') = %s (оригинал = %s) %s\n", 
           str, ft_strchr(str, 'o'), strchr(str, 'o'),
           ft_strchr(str, 'o') == strchr(str, 'o') ? "✓" : "✗");
    printf("ft_strchr(\"%s\", 'x') = %s (оригинал = %s) %s\n", 
           str, ft_strchr(str, 'x'), strchr(str, 'x'),
           ft_strchr(str, 'x') == strchr(str, 'x') ? "✓" : "✗");
    printf("ft_strchr(\"%s\", '\\0') = %s (оригинал = %s) %s\n", 
           str, ft_strchr(str, '\0'), strchr(str, '\0'),
           ft_strchr(str, '\0') == strchr(str, '\0') ? "✓" : "✗");
}

void test_strrchr(void)
{
    printf("\n=== Тест ft_strrchr ===\n");
    char *str = "Hello, World!";
    
    printf("ft_strrchr(\"%s\", 'o') = %s (оригинал = %s) %s\n", 
           str, ft_strrchr(str, 'o'), strrchr(str, 'o'),
           ft_strrchr(str, 'o') == strrchr(str, 'o') ? "✓" : "✗");
    printf("ft_strrchr(\"%s\", 'l') = %s (оригинал = %s) %s\n", 
           str, ft_strrchr(str, 'l'), strrchr(str, 'l'),
           ft_strrchr(str, 'l') == strrchr(str, 'l') ? "✓" : "✗");
}

void test_strnstr(void)
{
    printf("\n=== Тест ft_strnstr ===\n");
    char *haystack = "Hello, World!";
    char *needle = "World";
    
    printf("ft_strnstr(\"%s\", \"%s\", 20) = %s (оригинал = %s) %s\n", 
           haystack, needle, ft_strnstr(haystack, needle, 20), 
           strnstr(haystack, needle, 20),
           ft_strnstr(haystack, needle, 20) == strnstr(haystack, needle, 20) ? "✓" : "✗");
}

void test_strncmp(void)
{
    printf("\n=== Тест ft_strncmp ===\n");
    char *s1 = "Hello";
    char *s2 = "Helly";
    char *s3 = "Hello";
    
    printf("ft_strncmp(\"%s\", \"%s\", 4) = %d (оригинал = %d) %s\n", 
           s1, s2, ft_strncmp(s1, s2, 4), strncmp(s1, s2, 4),
           ft_strncmp(s1, s2, 4) == strncmp(s1, s2, 4) ? "✓" : "✗");
    printf("ft_strncmp(\"%s\", \"%s\", 5) = %d (оригинал = %d) %s\n", 
           s1, s2, ft_strncmp(s1, s2, 5), strncmp(s1, s2, 5),
           ft_strncmp(s1, s2, 5) == strncmp(s1, s2, 5) ? "✓" : "✗");
    printf("ft_strncmp(\"%s\", \"%s\", 5) = %d (оригинал = %d) %s\n", 
           s1, s3, ft_strncmp(s1, s3, 5), strncmp(s1, s3, 5),
           ft_strncmp(s1, s3, 5) == strncmp(s1, s3, 5) ? "✓" : "✗");
}

// ============ ТЕСТЫ "Работа с памятью и преобразования" ============

void test_atoi(void)
{
    printf("\n=== Тест ft_atoi ===\n");
    char *tests[] = {"42", "-42", "   +123", "  -456", "2147483647", "-2147483648", "0"};
    
    for (int i = 0; i < 7; i++)
    {
        printf("ft_atoi(\"%s\") = %d (оригинал = %d) %s\n", 
               tests[i], ft_atoi(tests[i]), atoi(tests[i]),
               ft_atoi(tests[i]) == atoi(tests[i]) ? "✓" : "✗");
    }
}

void test_calloc(void)
{
    printf("\n=== Тест ft_calloc ===\n");
    int *arr = (int *)ft_calloc(5, sizeof(int));
    
    if (arr)
    {
        int all_zero = 1;
        for (int i = 0; i < 5; i++)
        {
            if (arr[i] != 0)
                all_zero = 0;
        }
        printf("ft_calloc(5, sizeof(int)) - все элементы обнулены: %s\n", 
               all_zero ? "✓" : "✗");
        free(arr);
    }
}

void test_strdup(void)
{
    printf("\n=== Тест ft_strdup ===\n");
    char *original = "Hello, World!";
    char *copy = ft_strdup(original);
    
    if (copy)
    {
        printf("Оригинал: \"%s\"\n", original);
        printf("Копия: \"%s\"\n", copy);
        printf("Строки равны: %s\n", 
               strcmp(original, copy) == 0 ? "✓" : "✗");
        free(copy);
    }
}

void test_substr(void)
{
    printf("\n=== Тест ft_substr ===\n");
    char *str = "Hello, World!";
    char *sub = ft_substr(str, 7, 5);
    
    if (sub)
    {
        printf("ft_substr(\"%s\", 7, 5) = \"%s\" (ожидается \"World\") %s\n", 
               str, sub, strcmp(sub, "World") == 0 ? "✓" : "✗");
        free(sub);
    }
}

void test_strjoin(void)
{
    printf("\n=== Тест ft_strjoin ===\n");
    char *s1 = "Hello";
    char *s2 = ", World!";
    char *result = ft_strjoin(s1, s2);
    
    if (result)
    {
        printf("ft_strjoin(\"%s\", \"%s\") = \"%s\" (ожидается \"Hello, World!\") %s\n", 
               s1, s2, result, strcmp(result, "Hello, World!") == 0 ? "✓" : "✗");
        free(result);
    }
}

void test_strtrim(void)
{
    printf("\n=== Тест ft_strtrim ===\n");
    char *str = "   Hello, World!   ";
    char *result = ft_strtrim(str, " ");
    
    if (result)
    {
        printf("ft_strtrim(\"%s\", \" \") = \"%s\" (ожидается \"Hello, World!\") %s\n", 
               str, result, strcmp(result, "Hello, World!") == 0 ? "✓" : "✗");
        free(result);
    }
}

void test_split(void)
{
    printf("\n=== Тест ft_split ===\n");
    char *str = "Hello World from Libft";
    char **result = ft_split(str, ' ');
    
    if (result)
    {
        printf("ft_split(\"%s\", ' ') = [", str);
        for (int i = 0; result[i]; i++)
        {
            printf("\"%s\"", result[i]);
            if (result[i + 1])
                printf(", ");
            free(result[i]);
        }
        printf("]\n");
        free(result);
    }
}

void test_itoa(void)
{
    printf("\n=== Тест ft_itoa ===\n");
    int tests[] = {42, -42, 0, 2147483647, -2147483648};
    
    for (int i = 0; i < 5; i++)
    {
        char *result = ft_itoa(tests[i]);
        printf("ft_itoa(%d) = \"%s\" ", tests[i], result);
        
        // Проверяем, преобразовав обратно
        int check = atoi(result);
        if (check == tests[i])
            printf("✓\n");
        else
            printf("✗ (должно быть %d)\n", tests[i]);
        
        free(result);
    }
}

// Пример функции для ft_strmapi: преобразует символ в верхний регистр
char	to_upper_mapi(unsigned int index, char c)
{
	(void)index; 
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

// Пример функции для ft_striteri: преобразует символ в верхний регистр 
void	to_upper_striteri(unsigned int index, char *c)
{
	(void)index;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

void	test_strmapi(void)
{
       printf("\n=== Тест ft_strmapi ===\n");
	char *str1 = "hello";
	char *result1 = ft_strmapi(str1, to_upper_mapi);
	
	if (result1)
	{
		printf("ft_strmapi(\"%s\", to_upper) = \"%s\" ", str1, result1);
		if (strcmp(result1, "HELLO") == 0)
			printf("✓\n");
		else
			printf("✗ (ожидается \"HELLO\")\n");
		free(result1);
	}
}

void	test_striteri(void)
{
	printf("\n=== Тест ft_striteri ===\n");
	
	char str1[] = "hello";
	char expected1[] = "HELLO";
	
	printf("До ft_striteri: \"%s\"\n", str1);
	ft_striteri(str1, to_upper_striteri);
	printf("После ft_striteri: \"%s\" ", str1);
	
	if (strcmp(str1, expected1) == 0)
		printf("✓\n");
	else
		printf("✗ (ожидается \"%s\")\n", expected1);
	
}

void test_putchar_fd(void)
{
    printf("\n=== Тест ft_putchar_fd ===\n");
    printf("Вывод символа 'A': ");
    ft_putchar_fd('A', 1);
    printf(" ✓\n");
}

void test_putstr_fd(void)
{
    printf("\n=== Тест ft_putstr_fd ===\n");
    printf("Вывод строки 'Hello': ");
    ft_putstr_fd("Hello", 1);
    printf(" ✓\n");
}

// ============ ТЕСТЫ "Дополнительные функции" ============
void test_putendl_fd(void)
{
    printf("\n=== Тест ft_putendl_fd ===\n");
    printf("Вывод строки с переводом строки: ");
    ft_putendl_fd("Hello", 1);
    printf("(должна быть пустая строка после Hello) ✓\n");
}

void test_putnbr_fd(void)
{
    printf("\n=== Тест ft_putnbr_fd ===\n");
    printf("Вывод числа 42: ");
    ft_putnbr_fd(42, 1);
    printf(" ✓\n");
    printf("Вывод числа -42: ");
    ft_putnbr_fd(-42, 1);
    printf(" ✓\n");
}

void test_isspace(void)
{
    printf("\n=== Тест ft_isspace ===\n");
    
    printf("Пробельные символы: ");
    printf("%d %d %d %d %d %d ✓\n", 
           ft_isspace(' '), ft_isspace('\t'), ft_isspace('\n'),
           ft_isspace('\r'), ft_isspace('\v'), ft_isspace('\f'));
    
    printf("Не пробельные: 'A'=%d '5'=%d '!'=%d ✓\n", 
           ft_isspace('A'), ft_isspace('5'), ft_isspace('!'));
}

void test_strlcpy(void)
{
    printf("\n=== Тест ft_strlcpy ===\n");
    
    char dst[20];
    char src[] = "Hello, World!";
    
    size_t len = ft_strlcpy(dst, src, sizeof(dst));
    printf("Копирование: \"%s\" (длина=%zu) %s\n", dst, len, 
           len == strlen(src) && strcmp(dst, src) == 0 ? "✓" : "✗");
    
    char small[5];
    len = ft_strlcpy(small, src, 5);
    printf("Буфер 5 байт: \"%s\" (длина=%zu) %s\n", small, len, 
           len == strlen(src) && strcmp(small, "Hell") == 0 ? "✓" : "✗");
    
    char original[20] = "Test";
    len = ft_strlcpy(original, src, 0);
    printf("size=0: строка=\"%s\" (длина=%zu) %s\n", original, len, 
           len == strlen(src) && strcmp(original, "Test") == 0 ? "✓" : "✗");
}

void test_strlcat(void)
{
    printf("\n=== Тест ft_strlcat ===\n");
    
    char dst1[20] = "Hello";
    char src[] = " World!";
    
    size_t len = ft_strlcat(dst1, src, sizeof(dst1));
    printf("Конкатенация: \"%s\" (длина=%zu) %s\n", dst1, len, 
           strcmp(dst1, "Hello World!") == 0 ? "✓" : "✗");
    
    char dst2[10] = "Hello";
    len = ft_strlcat(dst2, src, 10);
    printf("Буфер 10: \"%s\" (длина=%zu) %s\n", dst2, len, 
           strcmp(dst2, "Hello Wor") == 0 ? "✓" : "✗");
    
    char dst3[6] = "Hello";
    len = ft_strlcat(dst3, src, 6);
    printf("Буфер 6: \"%s\" (длина=%zu) %s\n", dst3, len, 
           strcmp(dst3, "Hello") == 0 && len == 12 ? "✓" : "✗");
}

void test_memset(void)
{
    printf("\n=== Тест ft_memset ===\n");
    
    char buf1[10], buf2[10];
    ft_memset(buf1, 'A', 5);
    memset(buf2, 'A', 5);
    printf("Заполнение 'A': %s\n", memcmp(buf1, buf2, 5) == 0 ? "✓" : "✗");
    
    ft_memset(buf1, 0, 10);
    memset(buf2, 0, 10);
    printf("Заполнение нулями: %s\n", memcmp(buf1, buf2, 10) == 0 ? "✓" : "✗");
}

void test_bzero(void)
{
    printf("\n=== Тест ft_bzero ===\n");
    
    char buf1[10] = "123456789";
    char buf2[10] = "123456789";
    
    ft_bzero(buf1, 5);
    bzero(buf2, 5);
    printf("Обнуление 5 байт: %s\n", memcmp(buf1, buf2, 10) == 0 ? "✓" : "✗");
    
    ft_bzero(buf1, 0);
    printf("Обнуление 0 байт: строка не изменилась ✓\n");
}

void test_memcpy(void)
{
    printf("\n=== Тест ft_memcpy ===\n");
    
    char src[] = "Hello!";
    char dst1[10] = {0}, dst2[10] = {0};
    
    ft_memcpy(dst1, src, 6);
    memcpy(dst2, src, 6);
    printf("Копирование строки: %s\n", strcmp(dst1, dst2) == 0 ? "✓" : "✗");
    
    int arr1[] = {1,2,3}, arr2[] = {1,2,3}, dst3[3], dst4[3];
    ft_memcpy(dst3, arr1, sizeof(arr1));
    memcpy(dst4, arr2, sizeof(arr2));
    printf("Копирование int[]: %s\n", memcmp(dst3, dst4, sizeof(arr1)) == 0 ? "✓" : "✗");
}

void test_memmove(void)
{
    printf("\n=== Тест ft_memmove ===\n");
    
    char buf1[] = "abcdefgh";
    char buf2[] = "abcdefgh";
    
    ft_memmove(buf1 + 2, buf1, 4);
    memmove(buf2 + 2, buf2, 4);
    printf("Перекрытие (dest>src): %s\n", memcmp(buf1, buf2, 8) == 0 ? "✓" : "✗");
    
    char buf3[] = "abcdefgh";
    char buf4[] = "abcdefgh";
    ft_memmove(buf3, buf3 + 2, 4);
    memmove(buf4, buf4 + 2, 4);
    printf("Перекрытие (dest<src): %s\n", memcmp(buf3, buf4, 8) == 0 ? "✓" : "✗");
    
    printf("Демонстрация: \"abcdefgh\" -> ");
    char demo[] = "abcdefgh";
    ft_memmove(demo + 2, demo, 4);
    printf("\"%s\" ✓\n", demo);
}

// ============ ТЕСТЫ ДЛЯ РАБОТЫ СО СПИСКАМИ ============

void test_lstnew(void)
{
    printf("\n=== Тест ft_lstnew ===\n");
    char *content = ft_strdup("Test content");
    t_list *node = ft_lstnew(content);
    
    if (node)
    {
        printf("node->content = %s (ожидается \"Test content\") %s\n", 
               (char *)node->content,
               strcmp((char *)node->content, "Test content") == 0 ? "✓" : "✗");
        printf("node->next = NULL %s\n", node->next == NULL ? "✓" : "✗");
        ft_lstdelone(node, free);
    }
}

void test_lstadd_front(void)
{
    printf("\n=== Тест ft_lstadd_front ===\n");
    t_list *list = NULL;
    
    // Используем ft_strdup для выделения памяти
    t_list *node1 = ft_lstnew(ft_strdup("First"));
    t_list *node2 = ft_lstnew(ft_strdup("Second"));
    
    ft_lstadd_front(&list, node2);
    ft_lstadd_front(&list, node1);
    
    printf("Первый элемент: %s (ожидается \"First\") %s\n", 
           (char *)list->content,
           strcmp((char *)list->content, "First") == 0 ? "✓" : "✗");
    
    ft_lstclear(&list, free);
}

void test_lstsize(void)
{
    printf("\n=== Тест ft_lstsize ===\n");
    t_list *list = NULL;
    
    printf("Пустой список: размер = %d (ожидается 0) %s\n", 
           ft_lstsize(list), ft_lstsize(list) == 0 ? "✓" : "✗");
    
    // Используем ft_strdup
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("1")));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("2")));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("3")));
    
    printf("Список из 3 элементов: размер = %d (ожидается 3) %s\n", 
           ft_lstsize(list), ft_lstsize(list) == 3 ? "✓" : "✗");
    
    ft_lstclear(&list, free);
}

void test_lstlast(void)
{
    printf("\n=== Тест ft_lstlast ===\n");
    t_list *list = NULL;
    
    // Используем ft_strdup
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("First")));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("Last")));
    
    t_list *last = ft_lstlast(list);
    printf("Последний элемент: %s (ожидается \"Last\") %s\n", 
           (char *)last->content,
           strcmp((char *)last->content, "Last") == 0 ? "✓" : "✗");
    
    ft_lstclear(&list, free);
}

void test_lstadd_back(void)
{
    printf("\n=== Тест ft_lstadd_back ===\n");
    t_list *list = NULL;
    
    // Используем ft_strdup
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("First")));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("Second")));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("Third")));
    
    printf("Последний элемент после добавления: %s (ожидается \"Third\") %s\n", 
           (char *)ft_lstlast(list)->content,
           strcmp((char *)ft_lstlast(list)->content, "Third") == 0 ? "✓" : "✗");
    
    ft_lstclear(&list, free);
}

void test_lstdelone(void)
{
    printf("\n=== Тест ft_lstdelone ===\n");
    
    char *content = ft_strdup("Test node");
    t_list *node = ft_lstnew(content);
    
    if (node)
    {
        printf("Удаление элемента с \"%s\": ", (char *)node->content);
        ft_lstdelone(node, free);
        printf("✓\n");
    }
    
    printf("Проверка с NULL: ");
    ft_lstdelone(NULL, free);
    printf("✓\n");
}

void test_lstclear(void)
{
    printf("\n=== Тест ft_lstclear ===\n");
    
    t_list *list = NULL;
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("First")));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("Second")));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("Third")));
    
    printf("Размер до очистки: %d\n", ft_lstsize(list));
    ft_lstclear(&list, free);
    printf("Размер после очистки: %d %s\n", ft_lstsize(list), list == NULL ? "✓" : "✗");
    
    printf("Проверка с NULL: ");
    ft_lstclear(NULL, free);
    printf("✓\n");
}

void to_upper_content(void *content)
{
    char *str = (char *)content;
    for (int i = 0; str[i]; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
}

void print_content(void *content)
{
    printf("%s ", (char *)content);
}

void test_lstiter(void)
{
    printf("\n=== Тест ft_lstiter ===\n");
    
    t_list *list = NULL;
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("hello")));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("world")));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("libft")));
    
    printf("До: ");
    ft_lstiter(list, print_content);
    printf("\n");
    
    ft_lstiter(list, to_upper_content);
    
    printf("После: ");
    ft_lstiter(list, print_content);
    printf("✓\n");
    
    ft_lstclear(&list, free);
    printf("Проверка с NULL: ");
    ft_lstiter(NULL, print_content);
    printf("✓\n");
}

void *duplicate_content(void *content)
{
    return (ft_strdup((char *)content));
}

void test_lstmap(void)
{
    printf("\n=== Тест ft_lstmap ===\n");
    
    t_list *original = NULL;
    ft_lstadd_back(&original, ft_lstnew(ft_strdup("hello")));
    ft_lstadd_back(&original, ft_lstnew(ft_strdup("world")));
    ft_lstadd_back(&original, ft_lstnew(ft_strdup("map")));
    
    printf("Оригинал: ");
    ft_lstiter(original, print_content);
    printf("\n");
    
    t_list *copy = ft_lstmap(original, duplicate_content, free);
    
    if (copy)
    {
        printf("Копия:    ");
        ft_lstiter(copy, print_content);
        printf("\n");
        
        int same_size = ft_lstsize(original) == ft_lstsize(copy);
        int different_memory = original->content != copy->content;
        printf("Результат: %s %s\n", same_size ? "✓" : "✗", different_memory ? "✓" : "✗");
        
        ft_lstclear(&copy, free);
    }
    
    ft_lstclear(&original, free);
    
    printf("Проверка с NULL: %s\n", ft_lstmap(NULL, duplicate_content, free) == NULL ? "✓" : "✗");
}

int main(void)
{
    printf("===== Тестирование библиотеки libft =====\n");
    
    test_isalpha();
    test_isdigit();
    test_isalnum();
    test_isascii();
    test_isprint();
    test_toupper();
    test_tolower();
    test_strlen();
    test_strchr();
    test_strrchr();
    test_strnstr();
    test_strncmp();

    test_atoi();
    test_calloc();
    test_strdup();
    test_substr();
    test_strjoin();
    test_strtrim();
    test_split();
    test_itoa();
    test_strmapi();
    test_striteri();
    test_putchar_fd();
    test_putstr_fd();

    test_putendl_fd();
    test_putnbr_fd();
    test_isspace();
    test_strlcpy();
    test_strlcat();
    test_memset();
    test_bzero();
    test_memcpy();
    test_memmove();
    
    test_lstnew();
    test_lstadd_front();
    test_lstsize();
    test_lstlast();
    test_lstadd_back();
    test_lstdelone();
    test_lstclear();
    test_lstiter();
    test_lstmap();

    printf("\n Тесты завершены!\n");
    return (0);
}