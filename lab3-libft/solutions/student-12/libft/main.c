#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void test_ft_isalpha(void)
{
    int tests[] = {'A', 'Z', 'a', 'z', 'M', 'm', '0', '9', '!', ' '};
    size_t n = sizeof(tests) / sizeof(tests[0]);

    for (size_t i = 0; i < n; i++)
    {
        int c = tests[i];
        printf("ft_isalpha('%c') = %d (base isalpha: %d)\n", 
               c, ft_isalpha(c), isalpha(c));
    }
}

void test_ft_isdigit(void)
{
    int tests[] = {'0', '5', '9', 'a', 'Z', '!', ' ', '/', ':'};
    size_t n = sizeof(tests) / sizeof(tests[0]);

    for (size_t i = 0; i < n; i++)
    {
        int c = tests[i];
        printf("ft_isdigit('%c') = %d (base isdigit: %d)\n",
               c, ft_isdigit(c), isdigit(c));
    }
}

void test_ft_isalnum(void)
{
    int tests[] = {
        'A', 'Z', 'a', 'z',     // буквы
        '0', '5', '9',          // цифры
        '!', '@', ' ',          // спецсимволы
        '/', ':', '[', '`'      // границы диапазонов
    };

    size_t n = sizeof(tests) / sizeof(tests[0]);

    for (size_t i = 0; i < n; i++)
    {
        int c = tests[i];
        printf("ft_isalnum('%c') = %d (base isalnum: %d)\n",
               c, ft_isalnum(c), isalnum(c) != 0);
    }
}

void test_ft_isascii(void)
{
    int tests[] = {
        0, 1, 50, 127,   // валидный ASCII
        -1,                 // отрицательные
        128, 1000      // вне диапазона
    };

    size_t n = sizeof(tests) / sizeof(tests[0]);

    for (size_t i = 0; i < n; i++)
    {
        int c = tests[i];
        printf("ft_isascii(%d) = %d\n", c, ft_isascii(c));
    }
}

void test_ft_isprint(void)
{
    int tests[] = {
        31,        // не печатный (перед пробелом)
        32,        // пробел (печатный)
        65,        // 'A'
        97,        // 'a'
        126,       // '~'
        127,       // DEL (не печатный)
        '\n',      // newline
        '\t',      // tab
        '0',       // цифра
        '!'        // спецсимвол
    };

    size_t n = sizeof(tests) / sizeof(tests[0]);

    for (size_t i = 0; i < n; i++)
    {
        int c = tests[i];
        printf("ft_isprint(%d) = %d (base isprint: %d)\n",
               c, ft_isprint(c), isprint(c) != 0);
    }
}

void test_ft_toupper(void)
{
    int tests[] = {
        'a', 'z', 'm',   // строчные буквы
        'A', 'Z',        // заглавные
        '0', '9',        // цифры
        '!', '@',        // спецсимволы
        ' ',             // пробел
        '\n'             // непечатный
    };

    size_t n = sizeof(tests) / sizeof(tests[0]);

    for (size_t i = 0; i < n; i++)
    {
        int c = tests[i];
        printf("ft_toupper('%c') = '%c' (base toupper: '%c')\n",
               c,
               ft_toupper(c),
               toupper(c));
    }
}

void test_ft_tolower(void)
{
    int tests[] = {
        'A', 'Z', 'M',   // заглавные буквы
        'a', 'z',        // строчные
        '0', '9',        // цифры
        '!', '@',        // спецсимволы
        ' ',             // пробел
        '\n'             // непечатный
    };

    size_t n = sizeof(tests) / sizeof(tests[0]);

    for (size_t i = 0; i < n; i++)
    {
        int c = tests[i];
        printf("ft_tolower('%c') = '%c' (base tolower: '%c')\n",
               c,
               ft_tolower(c),
               tolower(c));
    }
}

void test_ft_strlen(void)
{
    char *test1 = "Hello, world!";
    char *test2 = "";
    char *test3 = "42";
    char *test4 = "a";
    char *test5 = NULL;

    printf("ft_strlen(\"%s\") = %zu (base strlen: %zu)\n",
           test1, ft_strlen(test1), strlen(test1));

    printf("ft_strlen(\"\") = %zu (base strlen: %zu)\n",
           ft_strlen(test2), strlen(test2));

    printf("ft_strlen(\"%s\") = %zu (base strlen: %zu)\n",
           test3, ft_strlen(test3), strlen(test3));

    printf("ft_strlen(\"%s\") = %zu (base strlen: %zu)\n",
           test4, ft_strlen(test4), strlen(test4));

    // стандартный strlen(NULL) вызовет SEGFAULT
    printf("ft_strlen(NULL) = %zu\n", ft_strlen(test5));
}

void test_ft_strchr(void)
{
    char *test1 = "Hello, world!";
    char *test2 = "";
    char *test3 = "42";
    char *test4 = "a";
    char *test5 = NULL;

    printf("ft_strchr(\"%s\", 'o') = %s (base strchr: %s)\n", test1, ft_strchr(test1, 'o'), strchr(test1, 'o'));
    printf("ft_strchr(\"%s\", 'H') = %s (base strchr: %s)\n", test1, ft_strchr(test1, 'H'), strchr(test1, 'H'));
    printf("ft_strchr(\"%s\", 'z') = %p (base strchr: %p)\n", test1, ft_strchr(test1, 'z'), strchr(test1, 'z'));
    printf("ft_strchr(\"%s\", '\\0') = %p (base strchr: %p)\n", test1, ft_strchr(test1, '\0'), strchr(test1, '\0'));
    printf("ft_strchr(\"\") = %p (base strchr: %p)\n", ft_strchr(test2, 'a'), strchr(test2, 'a'));
    printf("ft_strchr(\"%s\", '2') = %s (base strchr: %s)\n", test3, ft_strchr(test3, '2'), strchr(test3, '2'));
    printf("ft_strchr(\"%s\", 'a') = %s (base strchr: %s)\n", test4, ft_strchr(test4, 'a'), strchr(test4, 'a'));
    // стандартный strchr(NULL, ...) вызовет SEGFAULT
    printf("ft_strchr(NULL, 'a') = %p\n", ft_strchr(test5, 'a'));
}

void test_ft_strrchr(void)
{
    char *test1 = "Hello, world!";
    char *test2 = "";
    char *test3 = "42";
    char *test4 = "a";
    char *test5 = NULL;

    printf("ft_strrchr(\"%s\", 'o') = %s (base strrchr: %s)\n", test1, ft_strrchr(test1, 'o'), strrchr(test1, 'o'));
    printf("ft_strrchr(\"%s\", 'l') = %s (base strrchr: %s)\n", test1, ft_strrchr(test1, 'l'), strrchr(test1, 'l'));
    printf("ft_strrchr(\"%s\", 'z') = %p (base strrchr: %p)\n", test1, ft_strrchr(test1, 'z'), strrchr(test1, 'z'));
    printf("ft_strrchr(\"%s\", '\\0') = %p (base strrchr: %p)\n", test1, ft_strrchr(test1, '\0'), strrchr(test1, '\0'));
    printf("ft_strrchr(\"\") = %p (base strrchr: %p)\n", ft_strrchr(test2, 'a'), strrchr(test2, 'a'));
    printf("ft_strrchr(\"%s\", '2') = %s (base strrchr: %s)\n", test3, ft_strrchr(test3, '2'), strrchr(test3, '2'));
    printf("ft_strrchr(\"%s\", 'a') = %s (base strrchr: %s)\n", test4, ft_strrchr(test4, 'a'),strrchr(test4, 'a'));
    // стандартный strrchr(NULL, ...) вызовет SEGFAULT
    printf("ft_strrchr(NULL, 'a') = %p\n", ft_strrchr(test5, 'a'));
}

void test_ft_strnstr(void)
{
    char *test1 = "Hello, world!";
    char *test2 = "";
    char *test3 = "42";
    char *test4 = NULL;

    printf("ft_strnstr(\"%s\", \"lo\", 5) = %s\n", test1, ft_strnstr(test1, "lo", 5));
    printf("ft_strnstr(\"%s\", \"lo\", 4) = %p\n", test1, ft_strnstr(test1, "lo", 4));
    printf("ft_strnstr(\"%s\", \"world\", 13) = %s\n", test1, ft_strnstr(test1, "world", 13));
    printf("ft_strnstr(\"%s\", \"world\", 5) = %p\n", test1, ft_strnstr(test1, "world", 5));
    printf("ft_strnstr(\"%s\", \"\", 5) = %s\n", test1, ft_strnstr(test1, "", 5));
    printf("ft_strnstr(\"%s\", \"2\", 2) = %s\n", test3, ft_strnstr(test3, "2", 2));
    printf("ft_strnstr(\"%s\", \"a\", 1) = %p\n", test2, ft_strnstr(test2, "a", 1));
    printf("ft_strnstr(NULL, \"a\", 1) = %p\n", ft_strnstr(test4, "a", 1));
}

void test_ft_strncmp(void)
{
    char *test1 = "Hello";
    char *test2 = "Hello";
    char *test3 = "Hellp";
    char *test4 = "Hell";
    char *test5 = "";
    char *test6 = NULL;

    printf("ft_strncmp(\"%s\", \"%s\", 5) = %d (base strncmp: %d)\n", test1, test2, ft_strncmp(test1, test2, 5), strncmp(test1, test2, 5));
    printf("ft_strncmp(\"%s\", \"%s\", 5) = %d (base strncmp: %d)\n", test1, test3, ft_strncmp(test1, test3, 5), strncmp(test1, test3, 5));
    printf("ft_strncmp(\"%s\", \"%s\", 5) = %d (base strncmp: %d)\n", test1, test4, ft_strncmp(test1, test4, 5), strncmp(test1, test4, 5));
    printf("ft_strncmp(\"%s\", \"%s\", 0) = %d (base strncmp: %d)\n", test1, test3, ft_strncmp(test1, test3, 0), strncmp(test1, test3, 0));
    printf("ft_strncmp(\"%s\", \"%s\", 3) = %d (base strncmp: %d)\n", test1, test3, ft_strncmp(test1, test3, 3), strncmp(test1, test3, 3));
    printf("ft_strncmp(\"%s\", \"%s\", 1) = %d (base strncmp: %d)\n", test5, test1, ft_strncmp(test5, test1, 1), strncmp(test5, test1, 1));
    // стандартный strncmp(NULL, ...) вызовет SEGFAULT
    printf("ft_strncmp(NULL, \"%s\", 3) = %d\n", test1, ft_strncmp(test6, test1, 3));
}

void test_ft_atoi(void)
{
    char *test1 = "42";
    char *test2 = "   -42";
    char *test3 = "   +123";
    char *test4 = "4193 with words";
    char *test5 = "words and 987";
    char *test6 = "-2147483648";
    char *test7 = "2147483647";
    char *test8 = "";
    char *test9 = NULL;

    printf("ft_atoi(\"%s\") = %d (base atoi: %d)\n", test1, ft_atoi(test1), atoi(test1));
    printf("ft_atoi(\"%s\") = %d (base atoi: %d)\n", test2, ft_atoi(test2), atoi(test2));
    printf("ft_atoi(\"%s\") = %d (base atoi: %d)\n", test3, ft_atoi(test3), atoi(test3));
    printf("ft_atoi(\"%s\") = %d (base atoi: %d)\n", test4, ft_atoi(test4), atoi(test4));
    printf("ft_atoi(\"%s\") = %d (base atoi: %d)\n", test5, ft_atoi(test5), atoi(test5));
    printf("ft_atoi(\"%s\") = %d (base atoi: %d)\n", test6, ft_atoi(test6), atoi(test6));
    printf("ft_atoi(\"%s\") = %d (base atoi: %d)\n", test7, ft_atoi(test7), atoi(test7));
    printf("ft_atoi(\"\") = %d (base atoi: %d)\n", ft_atoi(test8), atoi(test8));
    // стандартный atoi(NULL) вызовет SEGFAULT
    printf("ft_atoi(NULL) = %d\n", ft_atoi(test9));
}

void test_ft_calloc(void)
{
    size_t n = 5;
    size_t size = sizeof(int);
    int *arr1;
    int *arr2;
    int i;

    arr1 = (int *)ft_calloc(n, size);
    arr2 = (int *)calloc(n, size);

    printf("ft_calloc vs calloc (n=5, size=int):\n");
    for (i = 0; i < 5; i++)
        printf("ft_calloc: %d (base calloc %d)\n", arr1[i], arr2[i]);

    free(arr1);
    free(arr2);

    // проверка нулевого размера
    arr1 = (int *)ft_calloc(0, size);
    arr2 = (int *)calloc(0, size);

    printf("ft_calloc(0, size) = %p (base calloc: %p)\n", arr1, arr2);

    free(arr1);
    free(arr2);

    // проверка overflow
    arr1 = (int *)ft_calloc((size_t)-1, (size_t)-1);
    printf("ft_calloc(overflow) = %p\n", arr1);

    free(arr1);
}

void test_ft_strdup(void)
{
    char *test1 = "Hello, world!";
    char *test2 = "";
    char *test3 = "42";
    char *test4 = "a";
    char *test5 = NULL;

    char *res1 = ft_strdup(test1);
    char *res2 = strdup(test1);

    printf("ft_strdup(\"%s\") = %s (base strdup: %s)\n",
           test1, res1, res2);

    free(res1);
    free(res2);

    res1 = ft_strdup(test2);
    res2 = strdup(test2);

    printf("ft_strdup(\"\") = %s (base strdup: %s)\n",
           res1, res2);

    free(res1);
    free(res2);

    res1 = ft_strdup(test3);
    res2 = strdup(test3);

    printf("ft_strdup(\"%s\") = %s (base strdup: %s)\n",
           test3, res1, res2);

    free(res1);
    free(res2);

    res1 = ft_strdup(test4);
    res2 = strdup(test4);

    printf("ft_strdup(\"%s\") = %s (base strdup: %s)\n",
           test4, res1, res2);

    free(res1);
    free(res2);

    // стандартный strdup(NULL) вызовет SEGFAULT
    printf("ft_strdup(NULL) = %p\n",
           ft_strdup(test5));
}

void test_ft_substr(void)
{
    char *test1 = "Hello, world!";
    char *test2 = "42";
    char *test3 = NULL;

    char *res;

    res = ft_substr(test1, 7, 5);
    printf("ft_substr(\"%s\", 7, 5) = %s\n", test1, res);
    free(res);

    res = ft_substr(test1, 50, 5);
    printf("ft_substr(\"%s\", 50, 5) = %s\n", test1, res);
    free(res);

    res = ft_substr(test2, 0, 10);
    printf("ft_substr(\"%s\", 0, 10) = %s\n", test2, res);
    free(res);

    printf("ft_substr(NULL, 0, 5) = %p\n", ft_substr(test3, 0, 5));
}

void test_ft_strjoin(void)
{
    char *s1 = "Hello, ";
    char *s2 = "world!";
    char *s3 = "";
    char *s5 = NULL;

    char *res1;
    char *res2;

    res1 = ft_strjoin(s1, s2);
    res2 = malloc(strlen(s1) + strlen(s2) + 1);
    if (res2)
    {
        strcpy(res2, s1);
        strcat(res2, s2);
    }
    printf("ft_strjoin(\"%s\", \"%s\") = %s (base join: %s)\n",
           s1, s2, res1, res2);
    free(res1);
    free(res2);

    res1 = ft_strjoin(s1, s3);
    res2 = malloc(strlen(s1) + strlen(s3) + 1);
    if (res2)
    {
        strcpy(res2, s1);
        strcat(res2, s3);
    }
    printf("ft_strjoin(\"%s\", \"%s\") = %s (base join: %s)\n",
           s1, s3, res1, res2);
    free(res1);
    free(res2);

    printf("ft_strjoin(NULL, \"%s\") = %p\n", s2, ft_strjoin(s5, s2));
}

void test_ft_strtrim(void)
{
    char *s1 = "  Hello, world!  ";
    char *set1 = " ";
    char *res1 = ft_strtrim(s1, set1);
    printf("ft_strtrim('%s', '%s') = '%s'\n", s1, set1, res1);
    free(res1);

    char *s2 = "--42--";
    char *set2 = "-";
    char *res2 = ft_strtrim(s2, set2);
    printf("ft_strtrim('%s', '%s') = '%s'\n", s2, set2, res2);
    free(res2);

    char *s3 = "*****";
    char *set3 = "*";
    char *res3 = ft_strtrim(s3, set3);
    printf("ft_strtrim('%s', '%s') = '%s'\n", s3, set3, res3); // ожидание: пустая строка
    free(res3);

    char *s4 = "Hello";
    char *set4 = " ";
    char *res4 = ft_strtrim(s4, set4);
    printf("ft_strtrim('%s', '%s') = '%s'\n", s4, set4, res4);
    free(res4);

    printf("ft_strtrim(NULL, '%s') = %p\n", set3, ft_strtrim(NULL, set3));
    printf("ft_strtrim('%s', NULL) = %p\n", s1, ft_strtrim(s1, NULL));
}

void free_split_local(char **split)
{
    size_t i = 0;
    if (!split)
        return;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}
void test_ft_split(void)
{
    char **res;

    res = ft_split("Hello world 42", ' ');
    for (size_t i = 0; res[i]; i++)
        printf("res[%zu] = '%s'\n", i, res[i]);
    free_split_local(res);

    res = ft_split("42--is--life", '-');
    for (size_t i = 0; res[i]; i++)
        printf("res[%zu] = '%s'\n", i, res[i]);
    free_split_local(res);
}

void test_ft_itoa(void)
{
    char *res;

    res = ft_itoa(0);
    printf("ft_itoa(0) = '%s'\n", res);
    free(res);

    res = ft_itoa(42);
    printf("ft_itoa(42) = '%s'\n", res);
    free(res);

    res = ft_itoa(-12345);
    printf("ft_itoa(-12345) = '%s'\n", res);
    free(res);

    res = ft_itoa(INT_MAX);
    printf("ft_itoa(INT_MAX) = '%s'\n", res);
    free(res);

    res = ft_itoa(INT_MIN);
    printf("ft_itoa(INT_MIN) = '%s'\n", res);
    free(res);
}

char	to_upper_index(unsigned int i, char c)
{
	if (i % 2 == 0 && c >= 'a' && c <= 'z')
		return (c - 32); // делаем букву заглавной на чётных позициях
	return (c);
}
void test_ft_strmapi(void)
{
	char *str = "Hello, World!";
	char *res;

	res = ft_strmapi(str, to_upper_index);
	printf("ft_strmapi(\"%s\", to_upper_index) = %s\n", str, res);
	free(res);
}

void	to_upper_indexx(unsigned int i, char *c)
{
	if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
		*c = *c - 32; // буквы на чётных позициях делаем заглавными
}
void test_ft_striteri(void)
{
	char str1[] = "Hello, World!";

	ft_striteri(str1, to_upper_indexx);
	printf("ft_striteri to_upper_indexx: %s\n", str1);
}

void test_ft_putchar_fd(void)
{
	ft_putchar_fd('A', 1);
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('C', -1);
}

void test_ft_putstr_fd(void)
{
	ft_putstr_fd("Hello, World!\n", 1);
	ft_putstr_fd(NULL, 1);  
	ft_putstr_fd("Test\n", -1); 
}

void test_ft_putendl_fd(void)
{
	ft_putendl_fd("Hello, World!", 1);
	ft_putendl_fd(NULL, 1);   
	ft_putendl_fd("Test", -1); 
}

void test_ft_putnbr_fd(void)
{
	ft_putnbr_fd(12345, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-9876, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(2147483647, 1);
    ft_putchar_fd('\n', 1);
    ft_putnbr_fd(-2147483648, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(100, -1); 
}

void test_ft_isspace(void)
{
    printf("ft_isspace(' ') = %d\n", ft_isspace(' '));   // 1
    printf("ft_isspace('\\t') = %d\n", ft_isspace('\t')); // 1
    printf("ft_isspace('\\n') = %d\n", ft_isspace('\n')); // 1
    printf("ft_isspace('a') = %d\n", ft_isspace('a'));     // 0
    printf("ft_isspace('1') = %d\n", ft_isspace('1'));     // 0
}

void test_ft_strlcpy(void)
{
    char dst[10];

    size_t len = ft_strlcpy(dst, "Hello", sizeof(dst));
    printf("dst = \"%s\", returned = %zu\n", dst, len); 

    len = ft_strlcpy(dst, "LongString", 5);
    printf("dst = \"%s\", returned = %zu\n", dst, len); 

    len = ft_strlcpy(dst, "", sizeof(dst));
    printf("dst = \"%s\", returned = %zu\n", dst, len);

    len = ft_strlcpy(NULL, "Test", 5);
    printf("NULL dst, returned = %zu\n", len); 
}

void test_ft_strlcat(void)
{
    char buf[15] = "Hello, ";
    size_t ret;

    ret = ft_strlcat(buf, "world!", sizeof(buf));
    printf("buf = \"%s\", returned = %zu\n", buf, ret); 

    char buf2[5] = "Hi";
    ret = ft_strlcat(buf2, "There", sizeof(buf2));
    printf("buf2 = \"%s\", returned = %zu\n", buf2, ret); 

    char buf3[10] = "";
    ret = ft_strlcat(buf3, "abc", sizeof(buf3));
    printf("buf3 = \"%s\", returned = %zu\n", buf3, ret); 
}

void test_ft_memset(void)
{
    char buf[10];

    ft_memset(buf, 'A', 5);
    buf[5] = '\0';
    printf("ft_memset 5 bite = %s\n", buf); 

    int arr[5];
    ft_memset(arr, 0, sizeof(arr));
    printf("ft_memset int array = ");
    for (int i = 0; i < 5; i++)
        printf("%d ", arr[i]); 
    printf("\n");
}

void test_ft_bzero(void)
{
    char buf[10] = "abcdefghi";

    ft_bzero(buf, 5); 
    printf("ft_bzero 5 bite = ");
    for (int i = 0; i < 10; i++)
        printf("%d ", buf[i]); 
    printf("\n");

    int arr[5] = {1,2,3,4,5};
    ft_bzero(arr, sizeof(arr)); 
    printf("ft_bzero int array = ");
    for (int i = 0; i < 5; i++)
        printf("%d ", arr[i]); 
    printf("\n");
}

void test_ft_memcpy(void)
{
	char src1[] = "Hello, world!";
	char dest1[20];
	char dest2[20];

	ft_memcpy(dest1, src1, 13);
	memcpy(dest2, src1, 13);
	printf("%s | %s\n", dest1, dest2);

	char src2[] = "Test";
	char dest3[10] = "AAAA";
	char dest4[10] = "AAAA";
	ft_memcpy(dest3, src2, 0);
	memcpy(dest4, src2, 0);
	printf("%s | %s\n", dest3, dest4);

	printf("%p\n", ft_memcpy(NULL, NULL, 0));
}

void test_ft_memmove(void)
{
	char str1[20] = "Hello, world!";
	char str2[20];

	ft_memmove(str2, str1, 13);
	memmove(str2, str1, 13);
	printf("Test 1: %s\n", str2);

	char overlap[] = "1234567890";
	ft_memmove(overlap + 2, overlap, 8);
	printf("Test 2: %s\n", overlap);

	char zero[] = "ABCDEFG";
	ft_memmove(zero, zero + 2, 0);
	printf("Test 3: %s\n", zero);

	printf("Test 4: %p\n", ft_memmove(NULL, NULL, 0));
}

int main(void)
{
    printf("\n=== Testirovanie 01.ft_isalpha ===\n\n");
    test_ft_isalpha();
    printf("\n=== Testirovanie 02.ft_isdigit ===\n\n");
    test_ft_isdigit();
    printf("\n=== Testirovanie 03.ft_isalnum ===\n\n");
    test_ft_isalnum();
    printf("\n=== Testirovanie 04.ft_isascii ===\n\n");
    test_ft_isascii();
    printf("\n=== Testirovanie 05.ft_isprint ===\n\n");
    test_ft_isprint();
    printf("\n=== Testirovanie 06.ft_toupper ===\n\n");
    test_ft_toupper();
    printf("\n=== Testirovanie 07.ft_tolowerr ===\n\n");
    test_ft_tolower();
    printf("\n=== Testirovanie 08.ft_strlen===\n\n");
    test_ft_strlen();
    printf("\n=== Testirovanie 09.ft_strchr===\n\n");
    test_ft_strchr();
    printf("\n=== Testirovanie 10.ft_strrchr===\n\n");
    test_ft_strrchr();
    printf("\n=== Testirovanie 11.ft_strnstr===\n\n");
    test_ft_strnstr();
    printf("\n=== Testirovanie 12.ft_strncmp===\n\n");
    test_ft_strncmp();
    printf("\n=== Testirovanie 13.ft_atoi===\n\n");
    test_ft_atoi();
    printf("\n=== Testirovanie 14.ft_calloc===\n\n");
    test_ft_calloc();
    printf("\n=== Testirovanie 15.ft_strdup===\n\n");
    test_ft_strdup();
    printf("\n=== Testirovanie 16.ft_substr===\n\n");
    test_ft_substr();
    printf("\n=== Testirovanie 17.ft_strjoin===\n\n");
    test_ft_strjoin();
    printf("\n=== Testirovanie 18.ft_strtrim===\n\n");
    test_ft_strtrim();
    printf("\n=== Testirovanie 19.ft_split===\n\n");
    test_ft_split();
    printf("\n=== Testirovanie 20.ft_itoa===\n\n");
    test_ft_itoa();
    printf("\n=== Testirovanie 21.ft_strmapi===\n\n");
    test_ft_strmapi();
    printf("\n=== Testirovanie 22.ft_striteri===\n\n");
    test_ft_striteri();
    printf("\n=== Testirovanie 23.ft_putchar_fd===\n\n");
    test_ft_putchar_fd();
    printf("\n=== Testirovanie 24.ft_putstr_fd===\n\n");
    test_ft_putstr_fd();
    printf("\n=== Testirovanie 25.ft_putendl_fd===\n\n");
    test_ft_putendl_fd();
    printf("\n=== Testirovanie 26.ft_putnbr_fd===\n\n");
    test_ft_putnbr_fd();
    printf("\n=== Testirovanie 27.ft_isspace===\n\n");
    test_ft_isspace();
    printf("\n=== Testirovanie 28.ft_strlcpy===\n\n");
    test_ft_strlcpy();
    printf("\n=== Testirovanie 29.ft_strlcat===\n\n");
    test_ft_strlcat();
    printf("\n=== Testirovanie 30.ft_memset===\n\n");
    test_ft_memset();
    printf("\n=== Testirovanie 31.ft_bzero===\n\n");
    test_ft_bzero();
    printf("\n=== Testirovanie 32.ft_memcpy===\n\n");
    test_ft_memcpy();
    printf("\n=== Testirovanie 33.ft_memmove===\n\n");
    test_ft_memmove();
    return 0;
}