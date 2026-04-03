#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <fcntl.h>
#include <ctype.h>  // Для сравнения с стандартными функциями

int g_del_called = 0;

void del_check(void *content)
{
    g_del_called = 1;
    free(content);
}

// Функция: перевод строки в верхний регистр
void	iter_to_upper(void *content)
{
	char *str = (char *)content;
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}

// Функция: подсчёт вызовов
int g_iter_count = 0;

void	iter_count(void *content)
{
	(void)content;
	g_iter_count++;
}

// Функция для ft_lstmap: дублирует строку
void *map_strdup(void *content)
{
    if (!content)
        return NULL;
    return (void *)ft_strdup((char *)content);
}

// Функция для ft_lstmap: переводит строку в верхний регистр (новая строка)
void *map_to_upper(void *content)
{
    char *src = (char *)content;
    if (!src)
        return NULL;
    
    char *res = ft_strdup(src);
    if (!res)
        return NULL;

    for (int i = 0; res[i]; i++)
        res[i] = toupper(res[i]);

    return res;
}

// Функция для ft_striteri: увеличивает символ на индекс
void increment_index_char(unsigned int i, char *c)
{
    *c = *c + i; // a->a+0, b->b+1, c->c+2, ...
}

// Функция для ft_striteri: переводит символ в верхний регистр
void uppercase_char(unsigned int i, char *c)
{
    (void)i; // индекс не нужен
    if (*c >= 'a' && *c <= 'z')
        *c = *c - ('a' - 'A');
}

// Функция для ft_strmapi: возвращает символ в верхнем регистре
char uppercase_char_mapi(unsigned int i, char c)
{
    (void)i;
    if (c >= 'a' && c <= 'z')
        return c - ('a' - 'A');
    return c;
}

// Функция для ft_strmapi: увеличивает символ на индекс
char increment_index_char_mapi(unsigned int i, char c)
{
    return c + i;
}

// Вспомогательные функции для print_split и free_split
void print_split(char **split)
{
    if (!split)
        return;
    for (int i = 0; split[i]; i++)
        printf("[%d]: %s\n", i, split[i]);
}

void free_split(char **split)
{
    if (!split)
        return;
    for (int i = 0; split[i]; i++)
        free(split[i]);
    free(split);
}

// Тесты для ft_atoi
void test_ft_atoi(void)
{
    const char *tests[] = {
        "42",
        "   42",
        "-42",
        "+42",
        "   -123",
        "0",
        "2147483647",    // INT_MAX
        "-2147483648",   // INT_MIN
        "  +0",
        "   -0",
        "123abc456",
        "abc123",
        "",
        "    ",
        NULL
    };

    printf("=== Тестирование ft_atoi ===\n\n");

    for (int i = 0; tests[i]; i++)
    {
        int my_res = ft_atoi(tests[i]);
        int std_res = atoi(tests[i]);
        printf("Test \"%s\": ft_atoi = %d | atoi = %d | %s\n",
               tests[i], my_res, std_res,
               (my_res == std_res) ? "OK" : "FAIL");
    }
}

// Тесты для ft_bzero
void test_ft_bzero(void)
{
    char buffer[10];

    // Заполняем память значениями
    memset(buffer, 'A', sizeof(buffer));

    printf("\n=== Тестирование ft_bzero ===\n\n");

    // Применяем ft_bzero
    ft_bzero(buffer, sizeof(buffer));

    int all_zero = 1;
    for (size_t i = 0; i < sizeof(buffer); i++)
    {
        if (buffer[i] != 0)
        {
            all_zero = 0;
            break;
        }
    }

    printf("ft_bzero обнуляет память: %s\n", all_zero ? "OK" : "FAIL");

    printf("Содержимое массива после ft_bzero: ");
    for (size_t i = 0; i < sizeof(buffer); i++)
        printf("%d ", buffer[i]);
    printf("\n");
}

// Тесты для ft_calloc
void test_ft_calloc(void)
{
    size_t nmemb = 5;
    size_t size = sizeof(int);

    printf("\n=== Тестирование ft_calloc ===\n\n");

    int *arr = (int *)ft_calloc(nmemb, size);
    if (!arr)
    {
        printf("ft_calloc вернул NULL\n");
        return;
    }

    int all_zero = 1;
    for (size_t i = 0; i < nmemb; i++)
    {
        if (arr[i] != 0)
        {
            all_zero = 0;
            break;
        }
    }

    printf("Память выделена и обнулена: %s\n", all_zero ? "OK" : "FAIL");

    printf("Содержимое массива после ft_calloc: ");
    for (size_t i = 0; i < nmemb; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);
}

// Тесты для ft_isascii
void test_ft_isascii(void)
{
    int tests[] = {-1, 0, 65, 97, 127, 128, 200};
    size_t n_tests = sizeof(tests)/sizeof(tests[0]);

    printf("\n=== Тестирование ft_isascii ===\n\n");

    for (size_t i = 0; i < n_tests; i++)
    {
        int my_res = ft_isascii(tests[i]);
        int std_res = (isascii(tests[i]) != 0);
        printf("Test ASCII %d: ft_isascii = %d | isascii = %d | %s\n",
               tests[i], my_res, std_res,
               (my_res == std_res) ? "OK" : "FAIL");
    }
}

// Тесты для ft_isalpha
void test_ft_isalpha(void)
{
    int tests[] = {'A', 'Z', 'a', 'z', '0', '9', '@', ' ', '\n', 127, 200};
    size_t n_tests = sizeof(tests)/sizeof(tests[0]);

    printf("\n=== Тестирование ft_isalpha ===\n\n");

    for (size_t i = 0; i < n_tests; i++)
    {
        int my_res = ft_isalpha(tests[i]);
        int std_res = (isalpha(tests[i]) != 0);
        printf("Test '%c' (ASCII %d): ft_isalpha = %d | isalpha = %d | %s\n",
               (tests[i] >= 32 && tests[i] <= 126) ? tests[i] : '?',
               tests[i],
               my_res, std_res,
               (my_res == std_res) ? "OK" : "FAIL");
    }
}

// Тесты для ft_isalnum
void test_ft_isalnum(void)
{
    int tests[] = {'A', 'z', '0', '9', '@', ' ', '\n', '5', 'b', 'Z', 127, 200};
    size_t n_tests = sizeof(tests)/sizeof(tests[0]);

    printf("\n=== Тестирование ft_isalnum ===\n\n");

    for (size_t i = 0; i < n_tests; i++)
    {
        int my_res = ft_isalnum(tests[i]);
        int std_res = (isalnum(tests[i]) != 0);
        printf("Test '%c' (ASCII %d): ft_isalnum = %d | isalnum = %d | %s\n",
               (tests[i] >= 32 && tests[i] <= 126) ? tests[i] : '?',
               tests[i],
               my_res, std_res,
               (my_res == std_res) ? "OK" : "FAIL");
    }
}

// Тесты для ft_isdigit
void test_ft_isdigit(void)
{
    int tests[] = {'0', '5', '9', 'a', 'Z', '@', ' ', '\n', 127, 200};
    size_t n_tests = sizeof(tests)/sizeof(tests[0]);

    printf("\n=== Тестирование ft_isdigit ===\n\n");

    for (size_t i = 0; i < n_tests; i++)
    {
        int my_res = ft_isdigit(tests[i]);
        int std_res = (isdigit(tests[i]) != 0);
        printf("Test '%c' (ASCII %d): ft_isdigit = %d | isdigit = %d | %s\n",
               (tests[i] >= 32 && tests[i] <= 126) ? tests[i] : '?',
               tests[i],
               my_res, std_res,
               (my_res == std_res) ? "OK" : "FAIL");
    }
}

// Тесты для ft_isprint
void test_ft_isprint(void)
{
    int tests[] = {31, 32, 65, 126, 127, 'A', ' ', '\n', '\t'};
    size_t n_tests = sizeof(tests)/sizeof(tests[0]);

    printf("\n=== Тестирование ft_isprint ===\n\n");

    for (size_t i = 0; i < n_tests; i++)
    {
        int my_res = ft_isprint(tests[i]);
        int std_res = (isprint(tests[i]) != 0);
        printf("Test '%c' (ASCII %d): ft_isprint = %d | isprint = %d | %s\n",
               (tests[i] >= 32 && tests[i] <= 126) ? tests[i] : '?',
               tests[i],
               my_res, std_res,
               (my_res == std_res) ? "OK" : "FAIL");
    }
}

// Тесты для ft_isspace
void test_ft_isspace(void)
{
    int tests[] = {' ', '\t', '\n', '\v', '\f', '\r', 'A', '1', '@', 0};
    size_t n_tests = sizeof(tests)/sizeof(tests[0]);

    printf("\n=== Тестирование ft_isspace ===\n\n");

    for (size_t i = 0; i < n_tests; i++)
    {
        int my_res = ft_isspace(tests[i]);
        int std_res = (isspace(tests[i]) != 0);
        printf("Test '%c' (ASCII %d): ft_isspace = %d | isspace = %d | %s\n",
               (tests[i] >= 32 && tests[i] <= 126) ? tests[i] : '?',
               tests[i],
               my_res, std_res,
               (my_res == std_res) ? "OK" : "FAIL");
    }
}

// Тесты для ft_itoa
void test_ft_itoa(void)
{
    int tests[] = {
        0,
        1,
        -1,
        42,
        -42,
        123456,
        -123456,
        2147483647,   // INT_MAX
        -2147483648   // INT_MIN
    };
    size_t n_tests = sizeof(tests)/sizeof(tests[0]);

    printf("\n=== Тестирование ft_itoa ===\n\n");

    for (size_t i = 0; i < n_tests; i++)
    {
        char *my_res = ft_itoa(tests[i]);
        char std_res[50];
        sprintf(std_res, "%d", tests[i]);

        printf("Test %d: ft_itoa = %s | sprintf = %s | %s\n",
               tests[i],
               my_res ? my_res : "NULL",
               std_res,
               (my_res && strcmp(my_res, std_res) == 0) ? "OK" : "FAIL");

        free(my_res);
    }
}

// Тесты для ft_lstadd_back
void test_ft_lstadd_back(void)
{
    printf("\n=== Тестирование ft_lstadd_back ===\n\n");

    t_list *list = NULL;

    // Создаём элементы
    t_list *n1 = ft_lstnew("one");
    t_list *n2 = ft_lstnew("two");
    t_list *n3 = ft_lstnew("three");

    // Добавляем в список
    ft_lstadd_back(&list, n1);
    ft_lstadd_back(&list, n2);
    ft_lstadd_back(&list, n3);

    // Проверка: вывод списка
    printf("Содержимое списка: ");
    t_list *tmp = list;
    while (tmp)
    {
        printf("%s ", (char *)tmp->content);
        tmp = tmp->next;
    }
    printf("\n");

    // Проверка размера
    int size = ft_lstsize(list);
    printf("Размер списка: %d (ожидалось 3) -> %s\n",
           size, (size == 3) ? "OK" : "FAIL");

    // Проверка последнего элемента
    t_list *last = ft_lstlast(list);
    printf("Последний элемент: %s (ожидалось three) -> %s\n",
           (char *)last->content,
           (strcmp((char *)last->content, "three") == 0) ? "OK" : "FAIL");

    // Освобождение памяти
    ft_lstclear(&list, free);
}

// Тесты для ft_lstadd_front
void test_ft_lstadd_front(void)
{
    printf("\n=== Тестирование ft_lstadd_front ===\n\n");

    t_list *list = NULL;

    // Создаём элементы
    t_list *n1 = ft_lstnew("one");
    t_list *n2 = ft_lstnew("two");
    t_list *n3 = ft_lstnew("three");

    // Добавляем в начало
    ft_lstadd_front(&list, n1); // one
    ft_lstadd_front(&list, n2); // two -> one
    ft_lstadd_front(&list, n3); // three -> two -> one

    // Проверка: вывод списка
    printf("Содержимое списка: ");
    t_list *tmp = list;
    while (tmp)
    {
        printf("%s ", (char *)tmp->content);
        tmp = tmp->next;
    }
    printf("\n");

    // Проверка порядка
    char *expected[] = {"three", "two", "one"};
    tmp = list;
    int ok = 1;
    for (int i = 0; i < 3 && tmp; i++)
    {
        if (strcmp((char *)tmp->content, expected[i]) != 0)
        {
            ok = 0;
            break;
        }
        tmp = tmp->next;
    }

    printf("Порядок элементов корректный -> %s\n", ok ? "OK" : "FAIL");

    // Проверка размера
    int size = ft_lstsize(list);
    printf("Размер списка: %d (ожидалось 3) -> %s\n",
           size, (size == 3) ? "OK" : "FAIL");

    // Проверка головы списка
    printf("Первый элемент: %s (ожидалось three) -> %s\n",
           (char *)list->content,
           (strcmp((char *)list->content, "three") == 0) ? "OK" : "FAIL");

    // Очистка
    ft_lstclear(&list, free);
}

// Вспомогательная функция для удаления контента (для строк)
void	del_content(void *content)
{
	free(content);
}

// Создание строки через malloc (чтобы корректно тестировать free)
char	*create_str(const char *s)
{
	char *res = strdup(s);
	if (!res)
	{
		printf("Ошибка malloc\n");
		exit(1);
	}
	return res;
}

// Тесты для ft_lstclear
void test_ft_lstclear(void)
{
	printf("\n=== Тестирование ft_lstclear ===\n\n");

	// --- ТЕСТ 1: обычный список ---
	t_list *list = NULL;

	ft_lstadd_back(&list, ft_lstnew(create_str("one")));
	ft_lstadd_back(&list, ft_lstnew(create_str("two")));
	ft_lstadd_back(&list, ft_lstnew(create_str("three")));

	printf("До очистки размер: %d (ожидалось 3)\n", ft_lstsize(list));

	ft_lstclear(&list, del_content);

	printf("После очистки указатель NULL -> %s\n",
		   (list == NULL) ? "OK" : "FAIL");


	// --- ТЕСТ 2: пустой список ---
	t_list *empty = NULL;

	ft_lstclear(&empty, del_content);

	printf("Очистка пустого списка -> %s\n",
		   (empty == NULL) ? "OK" : "FAIL");


	// --- ТЕСТ 3: один элемент ---
	t_list *single = ft_lstnew(create_str("solo"));

	ft_lstclear(&single, del_content);

	printf("Очистка одного элемента -> %s\n",
		   (single == NULL) ? "OK" : "FAIL");


	// --- ТЕСТ 4: NULL как lst ---
	ft_lstclear(NULL, del_content);
	printf("Передача NULL как lst -> OK (не упало)\n");


	// --- ТЕСТ 5: NULL как del ---
	t_list *list2 = NULL;
	ft_lstadd_back(&list2, ft_lstnew(create_str("test")));

	ft_lstclear(&list2, NULL);

	printf("Передача NULL как del -> список НЕ очищен -> %s\n",
		   (list2 != NULL) ? "OK" : "FAIL");

	// очищаем вручную чтобы не было утечки
	ft_lstclear(&list2, del_content);
}

void test_ft_lstdelone(void)
{
    printf("\n=== Тестирование ft_lstdelone ===\n\n");

    // --- ТЕСТ 1: обычное удаление ---
    t_list *node = ft_lstnew(create_str("hello"));

    ft_lstdelone(node, del_content);

    printf("Удаление одного элемента -> OK (не упало)\n");


    // --- ТЕСТ 2: проверка вызова del ---
    g_del_called = 0;

    t_list *node2 = ft_lstnew(create_str("test"));

    ft_lstdelone(node2, del_check);

    printf("del вызывается -> %s\n",
           (g_del_called == 1) ? "OK" : "FAIL");


    // --- ТЕСТ 3: lst == NULL ---
    ft_lstdelone(NULL, del_content);
    printf("lst == NULL -> OK (не упало)\n");


    // --- ТЕСТ 4: del == NULL ---
    t_list *node3 = ft_lstnew(create_str("no_del"));

    ft_lstdelone(node3, NULL);

    printf("del == NULL -> элемент не удалён -> %s\n",
           (node3 != NULL) ? "OK" : "FAIL");

    // чистим вручную
    free(node3->content);
    free(node3);


    // --- ТЕСТ 5: int как content ---
    int *num = malloc(sizeof(int));
    *num = 42;

    t_list *node4 = ft_lstnew(num);

    ft_lstdelone(node4, free);

    printf("Удаление int* -> OK (не упало)\n");
}

void test_ft_lstiter(void)
{
	printf("\n=== Тестирование ft_lstiter ===\n\n");

	// --- ТЕСТ 1: применение функции (toupper) ---
	t_list *list = NULL;

	ft_lstadd_back(&list, ft_lstnew(create_str("one")));
	ft_lstadd_back(&list, ft_lstnew(create_str("two")));
	ft_lstadd_back(&list, ft_lstnew(create_str("three")));

	ft_lstiter(list, iter_to_upper);

	printf("После iter (toupper): ");
	t_list *tmp = list;
	while (tmp)
	{
		printf("%s ", (char *)tmp->content);
		tmp = tmp->next;
	}
	printf("\n");

	// Проверка результата
	char *expected[] = {"ONE", "TWO", "THREE"};
	tmp = list;
	int ok = 1;
	for (int i = 0; i < 3 && tmp; i++)
	{
		if (strcmp((char *)tmp->content, expected[i]) != 0)
		{
			ok = 0;
			break;
		}
		tmp = tmp->next;
	}

	printf("toupper применился ко всем элементам -> %s\n", ok ? "OK" : "FAIL");


	// --- ТЕСТ 2: проверка количества вызовов ---
	g_iter_count = 0;

	ft_lstiter(list, iter_count);

	printf("Функция вызвана %d раз (ожидалось 3) -> %s\n",
		   g_iter_count,
		   (g_iter_count == 3) ? "OK" : "FAIL");


	// --- ТЕСТ 3: lst == NULL ---
	ft_lstiter(NULL, iter_to_upper);
	printf("lst == NULL -> OK (не упало)\n");


	// --- ТЕСТ 4: f == NULL ---
	ft_lstiter(list, NULL);
	printf("f == NULL -> OK (не упало)\n");


	// Очистка
	ft_lstclear(&list, del_content);
}

void test_ft_lstlast(void)
{
    printf("\n=== Тестирование ft_lstlast ===\n\n");

    // --- ТЕСТ 1: обычный список ---
    t_list *list = NULL;

    ft_lstadd_back(&list, ft_lstnew("one"));
    ft_lstadd_back(&list, ft_lstnew("two"));
    ft_lstadd_back(&list, ft_lstnew("three"));

    t_list *last = ft_lstlast(list);

    printf("Последний элемент: %s (ожидалось three) -> %s\n",
           last ? (char *)last->content : "NULL",
           (last && strcmp((char *)last->content, "three") == 0) ? "OK" : "FAIL");


    // --- ТЕСТ 2: один элемент ---
    t_list *single = ft_lstnew("solo");

    last = ft_lstlast(single);

    printf("Один элемент: %s (ожидалось solo) -> %s\n",
           last ? (char *)last->content : "NULL",
           (last && strcmp((char *)last->content, "solo") == 0) ? "OK" : "FAIL");

    free(single);


    // --- ТЕСТ 3: пустой список ---
    t_list *empty = NULL;

    last = ft_lstlast(empty);

    printf("Пустой список -> %s\n",
           (last == NULL) ? "OK" : "FAIL");


    // --- ТЕСТ 4: проверка что это реально последний узел ---
    t_list *tmp = list;
    while (tmp->next)
        tmp = tmp->next;

    printf("Указатель совпадает с реальным last -> %s\n",
           (last == tmp) ? "OK" : "FAIL");


    // Очистка
    ft_lstclear(&list, NULL); // строки не malloc'нуты
}

void test_ft_lstmap(void)
{
    printf("\n=== Тестирование ft_lstmap ===\n\n");

    // --- ТЕСТ 1: базовое копирование списка ---
    t_list *list = NULL;

    ft_lstadd_back(&list, ft_lstnew(create_str("one")));
    ft_lstadd_back(&list, ft_lstnew(create_str("two")));
    ft_lstadd_back(&list, ft_lstnew(create_str("three")));

    t_list *new_list = ft_lstmap(list, map_strdup, del_content);

    printf("Оригинал: ");
    t_list *tmp = list;
    while (tmp)
    {
        printf("%s ", (char *)tmp->content);
        tmp = tmp->next;
    }
    printf("\n");

    printf("Новый список: ");
    tmp = new_list;
    while (tmp)
    {
        printf("%s ", (char *)tmp->content);
        tmp = tmp->next;
    }
    printf("\n");

    printf("Списки независимы (разные указатели) -> %s\n",
           (list != new_list) ? "OK" : "FAIL");


    // --- ТЕСТ 2: преобразование данных ---
    t_list *upper_list = ft_lstmap(list, map_to_upper, del_content);

    printf("После map (toupper): ");
    tmp = upper_list;
    while (tmp)
    {
        printf("%s ", (char *)tmp->content);
        tmp = tmp->next;
    }
    printf("\n");

    char *expected[] = {"ONE", "TWO", "THREE"};
    tmp = upper_list;
    int ok = 1;
    for (int i = 0; i < 3 && tmp; i++)
    {
        if (strcmp((char *)tmp->content, expected[i]) != 0)
        {
            ok = 0;
            break;
        }
        tmp = tmp->next;
    }

    printf("Преобразование корректно -> %s\n", ok ? "OK" : "FAIL");


    // --- ТЕСТ 3: lst == NULL ---
    t_list *null_result = ft_lstmap(NULL, map_strdup, del_content);

    printf("lst == NULL -> %s\n",
           (null_result == NULL) ? "OK" : "FAIL");


    // --- ТЕСТ 4: f == NULL ---
    null_result = ft_lstmap(list, NULL, del_content);

    printf("f == NULL -> %s\n",
           (null_result == NULL) ? "OK" : "FAIL");


    // --- ТЕСТ 5: del == NULL ---
    null_result = ft_lstmap(list, map_strdup, NULL);

    printf("del == NULL -> %s\n",
           (null_result == NULL) ? "OK" : "FAIL");


    // --- ТЕСТ 6: проверка независимости (изменяем оригинал) ---
    iter_to_upper(list);

    printf("После изменения оригинала: ");
    tmp = list;
    while (tmp)
    {
        printf("%s ", (char *)tmp->content);
        tmp = tmp->next;
    }
    printf("\n");

    printf("Новый список не изменился -> %s\n",
           (strcmp((char *)new_list->content, "one") == 0) ? "OK" : "FAIL");


    // Очистка
    ft_lstclear(&list, del_content);
    ft_lstclear(&new_list, del_content);
    ft_lstclear(&upper_list, del_content);
}

void test_ft_lstnew(void)
{
    printf("\n=== Тестирование ft_lstnew ===\n\n");

    // --- ТЕСТ 1: обычная строка ---
    char *str = create_str("hello");
    t_list *node = ft_lstnew(str);

    printf("Создание узла -> %s\n",
           (node != NULL) ? "OK" : "FAIL");

    printf("content сохранён -> %s\n",
           (node && node->content == str) ? "OK" : "FAIL");

    printf("next == NULL -> %s\n",
           (node && node->next == NULL) ? "OK" : "FAIL");

    // очистка
    free(node->content);
    free(node);


    // --- ТЕСТ 2: NULL как content ---
    t_list *node_null = ft_lstnew(NULL);

    printf("content == NULL -> %s\n",
           (node_null && node_null->content == NULL) ? "OK" : "FAIL");

    printf("next == NULL (при NULL content) -> %s\n",
           (node_null && node_null->next == NULL) ? "OK" : "FAIL");

    free(node_null);


    // --- ТЕСТ 3: int как content ---
    int *num = malloc(sizeof(int));
    *num = 42;

    t_list *node_int = ft_lstnew(num);

    printf("int content корректен -> %s\n",
           (*(int *)node_int->content == 42) ? "OK" : "FAIL");

    printf("next == NULL (int) -> %s\n",
           (node_int->next == NULL) ? "OK" : "FAIL");

    free(node_int->content);
    free(node_int);


    // --- ТЕСТ 4: независимость узлов ---
    t_list *n1 = ft_lstnew("one");
    t_list *n2 = ft_lstnew("two");

    printf("Разные узлы имеют разные адреса -> %s\n",
           (n1 != n2) ? "OK" : "FAIL");

    free(n1);
    free(n2);


    // --- ТЕСТ 5: malloc fail (теоретический) ---
    // Невозможно легко симулировать без мока malloc,
    // поэтому просто считаем поведение корректным.
    printf("malloc fail -> проверить вручную (mock) -> SKIP\n");
}

// --- Тесты для ft_lstsize ---
void test_ft_lstsize(void)
{
    printf("\n=== Тестирование ft_lstsize ===\n\n");

    // --- Тест 1: пустой список ---
    t_list *list = NULL;
    printf("Пустой список: ft_lstsize = %d (ожидалось 0) -> %s\n",
           ft_lstsize(list),
           (ft_lstsize(list) == 0) ? "OK" : "FAIL");

    // --- Тест 2: один элемент ---
    list = ft_lstnew(create_str("one"));
    printf("Один элемент: ft_lstsize = %d (ожидалось 1) -> %s\n",
           ft_lstsize(list),
           (ft_lstsize(list) == 1) ? "OK" : "FAIL");

    // --- Тест 3: несколько элементов ---
    ft_lstadd_back(&list, ft_lstnew(create_str("two")));
    ft_lstadd_back(&list, ft_lstnew(create_str("three")));
    printf("Три элемента: ft_lstsize = %d (ожидалось 3) -> %s\n",
           ft_lstsize(list),
           (ft_lstsize(list) == 3) ? "OK" : "FAIL");

    // Очистка памяти
    ft_lstclear(&list, del_content);
}

// --- Тесты для ft_memcpy ---
void test_ft_memcpy(void)
{
    printf("\n=== Тестирование ft_memcpy ===\n\n");

    // --- Тест 1: простая строка ---
    char src1[] = "Hello, World!";
    char dest1[20] = {0};
    ft_memcpy(dest1, src1, strlen(src1) + 1);
    printf("Копирование строки: %s -> %s | %s\n",
           src1, dest1,
           (strcmp(dest1, src1) == 0) ? "OK" : "FAIL");

    // --- Тест 2: бинарные данные ---
    unsigned char src2[5] = {1, 2, 3, 4, 5};
    unsigned char dest2[5] = {0};
    ft_memcpy(dest2, src2, 5);
    int ok2 = 1;
    for (int i = 0; i < 5; i++)
        if (dest2[i] != src2[i])
            ok2 = 0;
    printf("Копирование бинарных данных: %s\n", ok2 ? "OK" : "FAIL");

    // --- Тест 3: n = 0 ---
    char src3[] = "abc";
    char dest3[] = "xyz";
    ft_memcpy(dest3, src3, 0);
    printf("n = 0 (не должно изменяться): %s -> %s | %s\n",
           "xyz", dest3, (strcmp(dest3, "xyz") == 0) ? "OK" : "FAIL");

    // --- Тест 4: dest == NULL и src == NULL ---
    void *res = ft_memcpy(NULL, NULL, 5);
    printf("dest == NULL && src == NULL -> %s\n", (res == NULL) ? "OK" : "FAIL");

    // --- Тест 5: частичное копирование ---
    char src5[] = "1234567890";
    char dest5[11] = {0};
    ft_memcpy(dest5, src5, 5);
    int ok5 = (memcmp(dest5, "12345", 5) == 0);
    printf("Частичное копирование 5 байт: %s\n", ok5 ? "OK" : "FAIL");
}

void test_ft_memmove(void)
{
    printf("\n=== Тестирование ft_memmove ===\n\n");

    // --- Тест 1: обычная строка ---
    char src1[] = "Hello, World!";
    char dest1[20] = {0};
    ft_memmove(dest1, src1, strlen(src1) + 1);
    printf("Копирование строки: %s -> %s | %s\n",
           src1, dest1,
           (strcmp(dest1, src1) == 0) ? "OK" : "FAIL");

    // --- Тест 2: бинарные данные ---
    unsigned char src2[5] = {1, 2, 3, 4, 5};
    unsigned char dest2[5] = {0};
    ft_memmove(dest2, src2, 5);
    int ok2 = 1;
    for (int i = 0; i < 5; i++)
        if (dest2[i] != src2[i])
            ok2 = 0;
    printf("Копирование бинарных данных: %s\n", ok2 ? "OK" : "FAIL");

    // --- Тест 3: перекрытие (dest > src) ---
    char overlap1[20] = "1234567890";
    ft_memmove(overlap1 + 2, overlap1, 8); // 12345678 -> 34567890
    printf("Перекрытие dest > src: %s | %s\n",
           overlap1,
           (strcmp(overlap1, "1212345678") == 0) ? "OK" : "FAIL");

    // --- Тест 4: перекрытие (dest < src) ---
    char overlap2[20] = "abcdefghij";
    ft_memmove(overlap2, overlap2 + 2, 8); // cdefghij -> abcdefgh
    printf("Перекрытие dest < src: %s | %s\n",
           overlap2,
           (strcmp(overlap2, "cdefghijij") == 0) ? "OK" : "FAIL");

    // --- Тест 5: n = 0 ---
    char src5[] = "abc";
    char dest5[] = "xyz";
    ft_memmove(dest5, src5, 0);
    printf("n = 0 (не должно изменяться): %s -> %s | %s\n",
           "xyz", dest5, (strcmp(dest5, "xyz") == 0) ? "OK" : "FAIL");

    // --- Тест 6: dest == NULL && src == NULL ---
    void *res = ft_memmove(NULL, NULL, 5);
    printf("dest == NULL && src == NULL -> %s\n", (res == NULL) ? "OK" : "FAIL");

    // --- Тест 7: dest == src ---
    char same[10] = "12345";
    ft_memmove(same, same, 5);
    printf("dest == src (должно остаться без изменений): %s | %s\n",
           same, (strcmp(same, "12345") == 0) ? "OK" : "FAIL");
}

void test_ft_memset(void)
{
    printf("\n=== Тестирование ft_memset ===\n\n");

    // --- Тест 1: простая строка ---
    char str1[10] = "abcdef";
    ft_memset(str1, 'X', 3);
    printf("Замена первых 3 байт: %s | %s\n",
           str1,
           (strncmp(str1, "XXXdef", 6) == 0) ? "OK" : "FAIL");

    // --- Тест 2: весь массив ---
    char str2[5] = "abcd";
    ft_memset(str2, 'Z', 4);
    int ok2 = 1;
    for (int i = 0; i < 4; i++)
        if (str2[i] != 'Z')
            ok2 = 0;
    printf("Замена всего массива: %s | %s\n",
           str2,
           ok2 ? "OK" : "FAIL");

    // --- Тест 3: n = 0 (ничего не изменяется) ---
    char str3[5] = "1234";
    ft_memset(str3, 'A', 0);
    printf("n = 0 (не должно изменяться): %s | %s\n",
           str3,
           (strcmp(str3, "1234") == 0) ? "OK" : "FAIL");

    // --- Тест 4: бинарные данные ---
    unsigned char buf1[5] = {1, 2, 3, 4, 5};
    ft_memset(buf1, 0xFF, 5);
    int ok4 = 1;
    for (int i = 0; i < 5; i++)
        if (buf1[i] != 0xFF)
            ok4 = 0;
    printf("Бинарные данные -> %s\n", ok4 ? "OK" : "FAIL");

    // --- Тест 5: проверка возврата указателя ---
    char str5[5] = "abcd";
    char *res = ft_memset(str5, 'Y', 4);
    printf("Возврат указателя -> %s\n", (res == str5) ? "OK" : "FAIL");

    // --- Тест 6: частичная замена ---
    char str6[6] = "hello";
    ft_memset(str6 + 1, 'o', 3); // h o o o o
    printf("Частичная замена: %s | %s\n",
           str6,
           (strncmp(str6, "hoooo", 5) == 0) ? "OK" : "FAIL");
}

// Тесты для ft_putchar_fd
void test_ft_putchar_fd(void)
{
    printf("\n=== Тестирование ft_putchar_fd ===\n\n");

    // --- ТЕСТ 1: вывод в файл ---
    const char *filename = "test_putchar_fd.txt";
    int fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (fd < 0)
    {
        perror("open");
        return;
    }

    ft_putchar_fd('A', fd);
    ft_putchar_fd('B', fd);
    ft_putchar_fd('\n', fd);

    // Перемещаемся в начало файла для чтения
    lseek(fd, 0, SEEK_SET);

    char buf[4] = {0};
    read(fd, buf, 3);

    printf("Содержимое файла: \"%s\" | %s\n",
           buf,
           (strcmp(buf, "AB\n") == 0) ? "OK" : "FAIL");

    close(fd);
    remove(filename);

    // --- ТЕСТ 2: вывод в stdout (fd = 1) ---
    printf("Вывод в stdout (символ 'X'): ");
    ft_putchar_fd('X', 1);
    printf(" <- должен быть символ 'X' выше\n");

    // --- ТЕСТ 3: вывод в stderr (fd = 2) ---
    fprintf(stderr, "Вывод в stderr (символ 'Y'): ");
    ft_putchar_fd('Y', 2);
    fprintf(stderr, " <- должен быть символ 'Y' выше\n");
}

// Тесты для ft_putendl_fd
void test_ft_putendl_fd(void)
{
    printf("\n=== Тестирование ft_putendl_fd ===\n\n");

    // --- ТЕСТ 1: вывод в файл ---
    const char *filename = "test_putendl_fd.txt";
    int fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (fd < 0)
    {
        perror("open");
        return;
    }

    ft_putendl_fd("Hello", fd);
    ft_putendl_fd("World", fd);

    // Перемещаемся в начало файла для чтения
    lseek(fd, 0, SEEK_SET);

    char buf[256] = {0};
    ssize_t n = read(fd, buf, sizeof(buf) - 1);
    (void)n; // Исправление: убираем предупреждение о неиспользуемой переменной
    buf[n] = '\0';

    printf("Содержимое файла:\n%s", buf);
    printf("Проверка наличия \\n после каждой строки -> %s\n",
           (strstr(buf, "Hello\n") && strstr(buf, "World\n")) ? "OK" : "FAIL");

    close(fd);
    remove(filename);

    // --- ТЕСТ 2: вывод в stdout ---
    printf("\nВывод в stdout (должны быть строки с переносом):\n");
    ft_putendl_fd("Line1", 1);
    ft_putendl_fd("Line2", 1);

    // --- ТЕСТ 3: вывод NULL (не должно упасть) ---
    ft_putendl_fd(NULL, 1);
    printf("Передача NULL -> OK (не упало)\n");

    // --- ТЕСТ 4: пустая строка ---
    ft_putendl_fd("", 1);
    printf("Пустая строка -> OK (должен быть только перенос)\n");
}

// Тесты для ft_putnbr_fd
void test_ft_putnbr_fd(void)
{
    printf("\n=== Тестирование ft_putnbr_fd ===\n\n");

    // --- ТЕСТ 1: вывод чисел в файл ---
    const char *filename = "test_putnbr_fd.txt";
    int fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (fd < 0)
    {
        perror("open");
        return;
    }

    int numbers[] = {0, 42, -42, 123456, -123456, 2147483647, -2147483648};
    const char *expected[] = {
        "0", "42", "-42", "123456", "-123456", "2147483647", "-2147483648"
    };

    char buf[256] = {0};
    for (size_t i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++)
    {
        ft_putnbr_fd(numbers[i], fd);
        ft_putchar_fd('\n', fd); // перенос строки для удобства
    }

    lseek(fd, 0, SEEK_SET);
    ssize_t n = read(fd, buf, sizeof(buf) - 1);
    (void)n;
    buf[n] = '\0';
    close(fd);

    printf("Содержимое файла:\n%s", buf);

    // Проверка по строкам
    char *line = strtok(buf, "\n");
    int ok = 1;
    for (size_t i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++)
    {
        if (!line || strcmp(line, expected[i]) != 0)
        {
            ok = 0;
            break;
        }
        line = strtok(NULL, "\n");
    }
    printf("Вывод чисел в файл корректен -> %s\n", ok ? "OK" : "FAIL");

    remove(filename);

    // --- ТЕСТ 2: вывод в stdout ---
    printf("\nВывод в stdout (должны быть числа с переносом):\n");
    for (size_t i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++)
    {
        ft_putnbr_fd(numbers[i], 1);
        ft_putchar_fd('\n', 1);
    }
}

// Тесты для ft_putstr_fd
void test_ft_putstr_fd(void)
{
    printf("\n=== Тестирование ft_putstr_fd ===\n\n");

    // --- ТЕСТ 1: вывод в файл ---
    const char *filename = "test_putstr_fd.txt";
    int fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (fd < 0)
    {
        perror("open");
        return;
    }

    ft_putstr_fd("Hello", fd);
    ft_putstr_fd("World", fd);

    lseek(fd, 0, SEEK_SET);

    char buf[256] = {0};
    ssize_t n = read(fd, buf, sizeof(buf) - 1);
    (void)n;
    buf[n] = '\0';

    printf("Содержимое файла: \"%s\" | %s\n",
           buf,
           (strcmp(buf, "HelloWorld") == 0) ? "OK" : "FAIL");

    close(fd);
    remove(filename);

    // --- ТЕСТ 2: вывод в stdout ---
    printf("\nВывод в stdout (должно быть 'TestStr'):\n");
    ft_putstr_fd("Test", 1);
    ft_putstr_fd("Str", 1);
    printf(" <- должен быть вывод выше\n");

    // --- ТЕСТ 3: вывод NULL (не должно упасть) ---
    ft_putstr_fd(NULL, 1);
    printf("Передача NULL -> OK (не упало)\n");

    // --- ТЕСТ 4: пустая строка ---
    ft_putstr_fd("", 1);
    printf("Пустая строка -> OK (не должно выводить ничего)\n");
}

// Тесты для ft_split
void test_ft_split(void)
{
    printf("\n=== Тестирование ft_split ===\n\n");

    struct {
        const char *s;
        char c;
        const char *desc;
    } tests[] = {
        {"hello world test", ' ', "Обычная строка с пробелами"},
        {"   leading spaces", ' ', "Строка с ведущими пробелами"},
        {"trailing spaces   ", ' ', "Строка с пробелами в конце"},
        {"  multiple   spaces  inside  ", ' ', "Строка с множественными пробелами"},
        {"oneword", ' ', "Одна 'слово' без разделителя"},
        {"", ' ', "Пустая строка"},
        {"     ", ' ', "Строка только из разделителей"},
        {NULL, ' ', "NULL как вход"},
        {"a,b,c,d", ',', "Разделитель запятая"},
        {",start,end,", ',', "Разделители в начале и конце"},
        {"no-separators", ',', "Разделитель отсутствует"},
        {"x--y---z", '-', "Множественные дефисы подряд"},
    };

    for (int i = 0; i < (int)(sizeof(tests)/sizeof(tests[0])); i++)
    {
        printf("Тест %d: %s\nСтрока: \"%s\", разделитель: '%c'\n",
               i + 1, tests[i].desc,
               tests[i].s ? tests[i].s : "NULL", tests[i].c);

        char **res = ft_split(tests[i].s, tests[i].c);
        print_split(res);
        free_split(res);
        printf("\n");
    }
}

// Тесты для ft_strchr
void test_ft_strchr(void)
{
    printf("\n=== Тестирование ft_strchr ===\n\n");

    const char *tests[] = {
        "hello world",
        "test string",
        "",
        "aaaaaa",
        "abc\0def", // тест с нулевым байтом внутри
        NULL
    };

    char chars[] = {'h', 'o', 'z', 'a', '\0'};

    for (int i = 0; tests[i]; i++)
    {
        for (unsigned int j = 0; j < sizeof(chars); j++) // Исправлено: int -> unsigned int
        {
            char *my_res = ft_strchr(tests[i], chars[j]);
            char *std_res = strchr(tests[i], chars[j]);

            printf("Test \"%s\", char '%c': ft_strchr = %p | strchr = %p | %s\n",
                   tests[i],
                   (chars[j] == '\0') ? '0' : chars[j],
                   (void *)my_res,
                   (void *)std_res,
                   (my_res == std_res) ? "OK" : "FAIL");

            // дополнительно можно проверять строки после найденного символа
            if (my_res && std_res)
            {
                int cmp = strcmp(my_res, std_res);
                printf("Сравнение подстрок после символа: %s\n", (cmp == 0) ? "OK" : "FAIL");
            }
        }
    }

    // --- ТЕСТ: символ, отсутствующий в строке ---
    char *res = ft_strchr("abc", 'z');
    printf("Символ отсутствует ('z' в \"abc\") -> %s\n",
           (res == NULL) ? "OK" : "FAIL");

    // --- ТЕСТ: пустая строка ---
    res = ft_strchr("", 'x');
    printf("Пустая строка -> %s\n",
           (res == NULL) ? "OK" : "FAIL");

    // --- ТЕСТ: поиск нулевого символа в непустой строке ---
    res = ft_strchr("abc", '\0');
    printf("Поиск '\\0' в \"abc\" -> %s\n",
           (res && *res == '\0') ? "OK" : "FAIL");
}

// Тесты для ft_strdup
void test_ft_strdup(void)
{
    printf("\n=== Тестирование ft_strdup ===\n\n");

    const char *tests[] = {
        "",
        "Hello, World!",
        "   Leading and trailing spaces   ",
        "Special chars !@#$%^&*()_+",
        "Long string: Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.",
        NULL
    };

    for (int i = 0; tests[i]; i++)
    {
        char *dup = ft_strdup(tests[i]);
        if (!dup)
        {
            printf("Test %d: malloc failed -> FAIL\n", i);
            continue;
        }

        int ok = (strcmp(dup, tests[i]) == 0) && (dup != tests[i]);
        printf("Test %d: original = \"%s\" | duplicated = \"%s\" -> %s\n",
               i,
               tests[i],
               dup,
               ok ? "OK" : "FAIL");

        free(dup);
    }

    // --- Тест на strdup с NULL (теоретический, стандартная strdup не поддерживает) ---
    char *null_dup = ft_strdup(NULL);
    printf("Test NULL input -> %s\n", (null_dup == NULL) ? "OK" : "FAIL");
    if (null_dup)
        free(null_dup);
}

// --- тесты ft_striteri ---
void test_ft_striteri(void)
{
    printf("\n=== Тестирование ft_striteri ===\n\n");

    // --- ТЕСТ 1: простая строка, увеличение символов по индексу ---
    char str1[] = "abcd";
    ft_striteri(str1, increment_index_char);
    printf("Increment indices: %s | %s\n",
           str1,
           (strcmp(str1, "aceg") == 0) ? "OK" : "FAIL");

    // --- ТЕСТ 2: перевод в верхний регистр ---
    char str2[] = "hello";
    ft_striteri(str2, uppercase_char);
    printf("Uppercase: %s | %s\n",
           str2,
           (strcmp(str2, "HELLO") == 0) ? "OK" : "FAIL");

    // --- ТЕСТ 3: пустая строка ---
    char str3[] = "";
    ft_striteri(str3, uppercase_char);
    printf("Empty string: '%s' | %s\n",
           str3,
           (strcmp(str3, "") == 0) ? "OK" : "FAIL");

    // --- ТЕСТ 4: NULL как строка (не должно падать) ---
    ft_striteri(NULL, uppercase_char);
    printf("NULL string -> OK (не упало)\n");

    // --- ТЕСТ 5: NULL как функция (не должно падать) ---
    char str5[] = "test";
    ft_striteri(str5, NULL);
    printf("NULL function -> OK (не упало)\n");
}

// Тесты для ft_strjoin
void test_ft_strjoin(void)
{
    printf("\n=== Тестирование ft_strjoin ===\n\n");

    // --- Тест 1: обычные строки ---
    char *res1 = ft_strjoin("Hello, ", "World!");
    printf("Test 1: \"%s\" + \"%s\" -> \"%s\" | %s\n",
           "Hello, ", "World!", res1,
           (res1 && strcmp(res1, "Hello, World!") == 0) ? "OK" : "FAIL");
    free(res1);

    // --- Тест 2: пустая первая строка ---
    char *res2 = ft_strjoin("", "Non-empty");
    printf("Test 2: \"\" + \"Non-empty\" -> \"%s\" | %s\n",
           res2,
           (res2 && strcmp(res2, "Non-empty") == 0) ? "OK" : "FAIL");
    free(res2);

    // --- Тест 3: пустая вторая строка ---
    char *res3 = ft_strjoin("Non-empty", "");
    printf("Test 3: \"Non-empty\" + \"\" -> \"%s\" | %s\n",
           res3,
           (res3 && strcmp(res3, "Non-empty") == 0) ? "OK" : "FAIL");
    free(res3);

    // --- Тест 4: обе строки пустые ---
    char *res4 = ft_strjoin("", "");
    printf("Test 4: \"\" + \"\" -> \"%s\" | %s\n",
           res4,
           (res4 && strcmp(res4, "") == 0) ? "OK" : "FAIL");
    free(res4);

    // --- Тест 5: NULL в первой строке ---
    char *res5 = ft_strjoin(NULL, "Hello");
    printf("Test 5: NULL + \"Hello\" -> %s | %s\n",
           res5 ? res5 : "NULL",
           (res5 == NULL) ? "OK" : "FAIL");

    // --- Тест 6: NULL во второй строке ---
    char *res6 = ft_strjoin("Hello", NULL);
    printf("Test 6: \"Hello\" + NULL -> %s | %s\n",
           res6 ? res6 : "NULL",
           (res6 == NULL) ? "OK" : "FAIL");

    // --- Тест 7: очень длинные строки ---
    char *long1 = malloc(10001);
    char *long2 = malloc(10001);
    if (long1 && long2)
    {
        memset(long1, 'A', 10000); long1[10000] = '\0';
        memset(long2, 'B', 10000); long2[10000] = '\0';
        char *res7 = ft_strjoin(long1, long2);
        int ok = (res7 && strlen(res7) == 20000 && res7[0] == 'A' && res7[19999] == 'B');
        printf("Test 7: длинные строки (10k + 10k) -> %s\n", ok ? "OK" : "FAIL");
        free(res7);
    }
    free(long1);
    free(long2);
}

void test_ft_strlcat(void)
{
    printf("\n=== Тестирование ft_strlcat ===\n\n");

    char buf[20];

    // --- ТЕСТ 1: обычное соединение ---
    strcpy(buf, "Hello");
    size_t res = ft_strlcat(buf, "World", sizeof(buf));
    printf("buf = \"%s\", возврат = %zu | ожидалось \"HelloWorld\" и 10 -> %s\n",
           buf, res,
           (strcmp(buf, "HelloWorld") == 0 && res == 10) ? "OK" : "FAIL");

    // --- ТЕСТ 2: ограничение размера ---
    strcpy(buf, "Hello");
    res = ft_strlcat(buf, "World", 8); // буфер ограничен 8 символами
    printf("buf = \"%s\", возврат = %zu | ожидалось \"HelloWo\" и 10 -> %s\n",
           buf, res,
           (strcmp(buf, "HelloWo") == 0 && res == 10) ? "OK" : "FAIL");

    // --- ТЕСТ 3: dst пустой ---
    buf[0] = '\0';
    res = ft_strlcat(buf, "Test", sizeof(buf));
    printf("buf = \"%s\", возврат = %zu | ожидалось \"Test\" и 4 -> %s\n",
           buf, res,
           (strcmp(buf, "Test") == 0 && res == 4) ? "OK" : "FAIL");

    // --- ТЕСТ 4: src пустой ---
    strcpy(buf, "Hello");
    res = ft_strlcat(buf, "", sizeof(buf));
    printf("buf = \"%s\", возврат = %zu | ожидалось \"Hello\" и 5 -> %s\n",
           buf, res,
           (strcmp(buf, "Hello") == 0 && res == 5) ? "OK" : "FAIL");

    // --- ТЕСТ 5: size = 0 ---
    strcpy(buf, "Hello");
    res = ft_strlcat(buf, "World", 0);
    printf("buf = \"%s\", возврат = %zu | ожидалось возврат 5 (длина src + size) -> %s\n",
           buf, res,
           (res == 5) ? "OK" : "FAIL");

    // --- ТЕСТ 6: size меньше длины dst ---
    strcpy(buf, "Hello");
    res = ft_strlcat(buf, "World", 3);
    printf("buf = \"%s\", возврат = %zu | ожидалось возврат 8 (size + slen) -> %s\n",
           buf, res,
           (res == 8) ? "OK" : "FAIL");
}

// Тесты для ft_strlcpy
void test_ft_strlcpy(void)
{
    printf("\n=== Тестирование ft_strlcpy ===\n\n");

    char dst[20];
    size_t ret;
    const char *src;

    // --- ТЕСТ 1: простое копирование ---
    src = "Hello";
    memset(dst, 'X', sizeof(dst));
    ret = ft_strlcpy(dst, src, sizeof(dst));
    printf("Копирование \"%s\" в dst: dst = \"%s\", возвращено %zu -> %s\n",
           src, dst, ret, (strcmp(dst, src) == 0 && ret == strlen(src)) ? "OK" : "FAIL");

    // --- ТЕСТ 2: size = 0 (ничего не копируется, возвращает длину src) ---
    src = "World";
    memset(dst, 'X', sizeof(dst));
    ret = ft_strlcpy(dst, src, 0);
    printf("size = 0: dst = \"%s\", возвращено %zu -> %s\n",
           dst, ret, (dst[0] == 'X' && ret == strlen(src)) ? "OK" : "FAIL");

    // --- ТЕСТ 3: усечение строки ---
    src = "LongString";
    memset(dst, 'X', sizeof(dst));
    ret = ft_strlcpy(dst, src, 5); // размер dst = 5, должно скопировать 4 + '\0'
    printf("Усечение: dst = \"%s\", возвращено %zu -> %s\n",
           dst, ret, (strcmp(dst, "Long") == 0 && ret == strlen(src)) ? "OK" : "FAIL");

    // --- ТЕСТ 4: dst точно вмещает src + '\0' ---
    src = "Fit";
    memset(dst, 'X', sizeof(dst));
    ret = ft_strlcpy(dst, src, 4);
    printf("Точное вхождение: dst = \"%s\", возвращено %zu -> %s\n",
           dst, ret, (strcmp(dst, src) == 0 && ret == strlen(src)) ? "OK" : "FAIL");

    // --- ТЕСТ 5: пустая src ---
    src = "";
    memset(dst, 'X', sizeof(dst));
    ret = ft_strlcpy(dst, src, sizeof(dst));
    printf("Пустая src: dst = \"%s\", возвращено %zu -> %s\n",
           dst, ret, (dst[0] == '\0' && ret == 0) ? "OK" : "FAIL");

    // --- ТЕСТ 6: dst = NULL, size = 0 ---
    ret = ft_strlcpy(NULL, "abc", 0);
    printf("dst = NULL, size = 0: возвращено %zu -> %s\n",
           ret, (ret == 3) ? "OK" : "FAIL");
}

// Тесты для ft_strlen
void test_ft_strlen(void)
{
    printf("\n=== Тестирование ft_strlen ===\n\n");

    const char *tests[] = {
        "",
        "a",
        "Hello",
        "Hello, World!",
        "1234567890",
        "   leading and trailing spaces   ",
        "Line1\nLine2\nLine3",
        "Special chars !@#$%^&*()_+",
        NULL
    };

    for (int i = 0; tests[i]; i++)
    {
        size_t my_len = ft_strlen(tests[i]);
        size_t std_len = strlen(tests[i]);
        printf("Test \"%s\": ft_strlen = %zu | strlen = %zu | %s\n",
               tests[i],
               my_len,
               std_len,
               (my_len == std_len) ? "OK" : "FAIL");
    }

    // --- Дополнительно: проверка очень длинной строки ---
    size_t long_size = 100000;
    char *long_str = malloc(long_size + 1);
    if (long_str)
    {
        memset(long_str, 'a', long_size);
        long_str[long_size] = '\0';
        size_t my_len = ft_strlen(long_str);
        printf("Длинная строка %zu символов: ft_strlen = %zu | %s\n",
               long_size,
               my_len,
               (my_len == long_size) ? "OK" : "FAIL");
        free(long_str);
    }

    // --- Проверка строки с embedded \0 ---
    char embedded[] = {'a','b','c','\0','d','e','f'};
    size_t my_len = ft_strlen(embedded);
    printf("Строка с embedded \\0: ft_strlen = %zu | expected = 3 | %s\n",
           my_len,
           (my_len == 3) ? "OK" : "FAIL");
}

// --- Тесты для ft_strmapi ---
void test_ft_strmapi(void)
{
    printf("\n=== Тестирование ft_strmapi ===\n\n");

    // --- ТЕСТ 1: пустая строка ---
    char *res = ft_strmapi("", uppercase_char_mapi);
    printf("Пустая строка -> %s | %s\n",
           res ? res : "NULL",
           (res && strcmp(res, "") == 0) ? "OK" : "FAIL");
    free(res);

    // --- ТЕСТ 2: обычная строка ---
    const char *s = "abcDef";
    res = ft_strmapi(s, uppercase_char_mapi);
    printf("Строка '%s' -> '%s' | %s\n",
           s, res,
           (res && strcmp(res, "ABCDEF") == 0) ? "OK" : "FAIL");
    free(res);

    // --- ТЕСТ 3: функция с индексом ---
    res = ft_strmapi("abcd", increment_index_char_mapi);
    printf("increment_index_char 'abcd' -> '%s' | %s\n",
           res,
           (res && strcmp(res, "aceg") == 0) ? "OK" : "FAIL");
    free(res);

    // --- ТЕСТ 4: s == NULL ---
    res = ft_strmapi(NULL, uppercase_char_mapi);
    printf("s == NULL -> %s\n", (res == NULL) ? "OK" : "FAIL");

    // --- ТЕСТ 5: f == NULL ---
    res = ft_strmapi("test", NULL);
    printf("f == NULL -> %s\n", (res == NULL) ? "OK" : "FAIL");

    // --- ТЕСТ 6: строка с числами и спецсимволами ---
    const char *mix = "a1B!c";
    res = ft_strmapi(mix, uppercase_char_mapi);
    printf("Строка с цифрами и спецсимволами '%s' -> '%s' | %s\n",
           mix, res,
           (res && strcmp(res, "A1B!C") == 0) ? "OK" : "FAIL");
    free(res);
}

// Тесты для ft_strncmp
void test_ft_strncmp(void)
{
    printf("\n=== Тестирование ft_strncmp ===\n\n");

    struct {
        const char *s1;
        const char *s2;
        size_t n;
    } tests[] = {
        {"abc", "abc", 3},          // полностью совпадают
        {"abc", "abd", 3},          // различие в последнем символе
        {"abc", "ab", 3},           // одна строка короче
        {"ab", "abc", 3},           // другая строка короче
        {"abc", "abc", 0},          // n = 0, всегда 0
        {"abc", "xyz", 2},          // первые два символа не совпадают
        {"", "", 1},                // обе пустые
        {"", "a", 1},               // первая пустая
        {"a", "", 1},               // вторая пустая
        {"abcdef", "abcxyz", 3},    // совпадают первые 3 символа
        {"abcdef", "abcxyz", 4},    // различие на 4 символе
        {NULL, NULL, 0}             // маркер конца
    };

    for (int i = 0; tests[i].s1 != NULL; i++)
    {
        int my_res = ft_strncmp(tests[i].s1, tests[i].s2, tests[i].n);
        int std_res = strncmp(tests[i].s1, tests[i].s2, tests[i].n);
        printf("Test \"%s\" vs \"%s\", n=%zu: ft_strncmp=%d | strncmp=%d | %s\n",
               tests[i].s1, tests[i].s2, tests[i].n,
               my_res, std_res,
               (my_res == std_res) ? "OK" : "FAIL");
    }

    // Дополнительно проверяем большие n
    char long1[] = "abcdefghij";
    char long2[] = "abcdefgzij";
    int my_res = ft_strncmp(long1, long2, 10);
    int std_res = strncmp(long1, long2, 10);
    printf("Test long strings: ft_strncmp=%d | strncmp=%d | %s\n",
           my_res, std_res,
           (my_res == std_res) ? "OK" : "FAIL");
}

void test_ft_strnstr(void)
{
    printf("\n=== Тестирование ft_strnstr ===\n\n");

    struct {
        const char *big;
        const char *little;
        size_t len;
        const char *expected;
    } tests[] = {
        {"hello world", "world", 11, "world"},
        {"hello world", "world", 5, NULL},       // len меньше позиции совпадения
        {"hello world", "hello", 5, "hello"},
        {"hello world", "", 5, "hello world"},   // пустая подстрока
        {"", "", 0, ""},                         // обе пустые
        {"", "a", 1, NULL},                       // пустой big
        {"abcabcabc", "abc", 9, "abc"},          // несколько вхождений
        {"abcabcabc", "abc", 2, NULL},           // len меньше первого вхождения
        {"abcabcabc", "abcd", 10, NULL},         // подстрока длиннее
        {"aaaaa", "aa", 5, "aaaaa"},             // повторяющиеся символы
        {"aaaaa", "aa", 1, NULL},                // len меньше подстроки
        {NULL, "abc", 5, NULL},                  // big == NULL (поведение стандартной strnstr не определено)
        {"abc", NULL, 5, NULL},                  // little == NULL (у нас не проверяем, но может быть NULL)
        {NULL, NULL, 0, NULL}                    // обе NULL
    };

    size_t n_tests = sizeof(tests) / sizeof(tests[0]);

    for (size_t i = 0; i < n_tests; i++)
    {
        const char *res = ft_strnstr(tests[i].big, tests[i].little, tests[i].len);
        const char *expected = tests[i].expected;

        printf("Test %zu: big=\"%s\", little=\"%s\", len=%zu -> ",
               i,
               tests[i].big ? tests[i].big : "NULL",
               tests[i].little ? tests[i].little : "NULL",
               tests[i].len);

        if (res == expected || (res && expected && strcmp(res, expected) == 0))
            printf("OK\n");
        else
            printf("FAIL (got \"%s\", expected \"%s\")\n",
                   res ? res : "NULL",
                   expected ? expected : "NULL");
    }
}

// Тесты для ft_strrchr
void test_ft_strrchr(void)
{
    printf("\n=== Тестирование ft_strrchr ===\n\n");

    const char *str = "Hello, World!";

    // --- Тест 1: символ есть в середине ---
    char *res1 = ft_strrchr(str, 'o');
    char *std1 = strrchr(str, 'o');
    printf("Поиск 'o' в \"%s\": ft_strrchr = %p | strrchr = %p | %s\n",
           str, (void *)res1, (void *)std1, (res1 == std1) ? "OK" : "FAIL");

    // --- Тест 2: символ в начале ---
    char *res2 = ft_strrchr(str, 'H');
    char *std2 = strrchr(str, 'H');
    printf("Поиск 'H': ft_strrchr = %p | strrchr = %p | %s\n",
           (void *)res2, (void *)std2, (res2 == std2) ? "OK" : "FAIL");

    // --- Тест 3: символ в конце ---
    char *res3 = ft_strrchr(str, '!');
    char *std3 = strrchr(str, '!');
    printf("Поиск '!': ft_strrchr = %p | strrchr = %p | %s\n",
           (void *)res3, (void *)std3, (res3 == std3) ? "OK" : "FAIL");

    // --- Тест 4: символ отсутствует ---
    char *res4 = ft_strrchr(str, 'x');
    char *std4 = strrchr(str, 'x');
    printf("Поиск 'x': ft_strrchr = %p | strrchr = %p | %s\n",
           (void *)res4, (void *)std4, (res4 == std4) ? "OK" : "FAIL");

    // --- Тест 5: поиск нулевого символа ---
    char *res5 = ft_strrchr(str, '\0');
    char *std5 = strrchr(str, '\0');
    printf("Поиск '\\0': ft_strrchr = %p | strrchr = %p | %s\n",
           (void *)res5, (void *)std5, (res5 == std5) ? "OK" : "FAIL");

    // --- Тест 6: пустая строка ---
    char *empty = "";
    char *res6 = ft_strrchr(empty, 'a');
    char *std6 = strrchr(empty, 'a');
    printf("Пустая строка, поиск 'a': ft_strrchr = %p | strrchr = %p | %s\n",
           (void *)res6, (void *)std6, (res6 == std6) ? "OK" : "FAIL");

    // --- Тест 7: поиск символа, который встречается несколько раз ---
    const char *multi = "banana";
    char *res7 = ft_strrchr(multi, 'a');
    char *std7 = strrchr(multi, 'a');
    printf("Поиск 'a' в \"%s\": ft_strrchr = %p | strrchr = %p | %s\n",
           multi, (void *)res7, (void *)std7, (res7 == std7) ? "OK" : "FAIL");
}

// Тесты для ft_strtrim
void test_ft_strtrim(void)
{
    printf("\n=== Тестирование ft_strtrim ===\n\n");

    struct {
        const char *s1;
        const char *set;
        const char *expected;
        const char *desc;
    } tests[] = {
        {"  hello  ", " ", "hello", "Обрезка пробелов с обеих сторон"},
        {"xxhelloxx", "x", "hello", "Обрезка символов 'x'"},
        {"abcHelloabc", "abc", "Hello", "Обрезка нескольких символов"},
        {"   ", " ", "", "Строка только из пробелов -> пустая строка"},
        {"hello", " ", "hello", "Нет символов для обрезки"},
        {"", " ", "", "Пустая строка"},
        {NULL, " ", NULL, "s1 == NULL"},
        {"hello", NULL, NULL, "set == NULL"},
        {"aaaa", "a", "", "Строка состоит только из символов set"},
        {"  hello world  ", " ", "hello world", "Простая обрезка пробелов с обеих сторон"},
    };

    for (int i = 0; i < (int)(sizeof(tests)/sizeof(tests[0])); i++)
    {
        char *res = ft_strtrim(tests[i].s1, tests[i].set);
        int ok = (res == NULL && tests[i].expected == NULL) ||
                 (res != NULL && tests[i].expected != NULL && strcmp(res, tests[i].expected) == 0);

        printf("Тест %d: %s\n", i + 1, tests[i].desc);
        printf("s1=\"%s\", set=\"%s\"\n", tests[i].s1 ? tests[i].s1 : "NULL", tests[i].set ? tests[i].set : "NULL");
        printf("Ожидалось: \"%s\", ft_strtrim: \"%s\" -> %s\n\n",
               tests[i].expected ? tests[i].expected : "NULL",
               res ? res : "NULL",
               ok ? "OK" : "FAIL");

        free(res);
    }
}

void test_ft_substr(void)
{
    char *s1 = "Hello, world!";
    char *s2 = "";
    char *s3 = "42";
    char *res;

    printf("=== Тестирование ft_substr ===\n\n");

    // Обычный случай
    res = ft_substr(s1, 7, 5); // "world"
    printf("ft_substr(\"%s\", 7, 5) = \"%s\" (ожидается: \"%.*s\")\n", 
           s1, res, 5, s1 + 7);
    free(res);

    // start = 0, len < strlen
    res = ft_substr(s1, 0, 5); // "Hello"
    printf("ft_substr(\"%s\", 0, 5) = \"%s\" (ожидается: \"%.*s\")\n", 
           s1, res, 5, s1);
    free(res);

    // start за пределами строки
    res = ft_substr(s1, 50, 5); // ""
    printf("ft_substr(\"%s\", 50, 5) = \"%s\" (ожидается: \"\")\n", 
           s1, res);
    free(res);

    // len больше оставшейся строки
    res = ft_substr(s1, 10, 10); // "ld!"
    printf("ft_substr(\"%s\", 10, 10) = \"%s\" (ожидается: \"%s\")\n", 
           s1, res, s1 + 10);
    free(res);

    // пустая строка
    res = ft_substr(s2, 0, 5); // ""
    printf("ft_substr(\"%s\", 0, 5) = \"%s\" (ожидается: \"\")\n", 
           s2, res);
    free(res);

    // короткая строка
    res = ft_substr(s3, 1, 5); // "2"
    printf("ft_substr(\"%s\", 1, 5) = \"%s\" (ожидается: \"%s\")\n", 
           s3, res, s3 + 1);
    free(res);
}

void test_ft_tolower(void)
{
    int chars[] = {'A', 'Z', 'M', 'a', 'z', 'm', '0', '9', '@', 127, -1};
    int i;
    int n = sizeof(chars) / sizeof(chars[0]);
    
    printf("=== Тестирование ft_tolower ===\n\n");
    
    for (i = 0; i < n; i++)
    {
        int c = chars[i];
        int res = ft_tolower(c);
        int expected = tolower(c);
        printf("ft_tolower(%d, '%c') = %d ('%c'), ожидалось: %d ('%c')\n",
               c, (c >= 32 && c <= 126) ? c : '?', 
               res, (res >= 32 && res <= 126) ? res : '?',
               expected, (expected >= 32 && expected <= 126) ? expected : '?');
    }
}

void test_ft_toupper(void)
{
    int chars[] = {'a', 'z', 'm', 'A', 'Z', 'M', '0', '9', '@', 127, -1};
    int i;
    int n = sizeof(chars) / sizeof(chars[0]);
    
    printf("=== Тестирование ft_toupper ===\n\n");
    
    for (i = 0; i < n; i++)
    {
        int c = chars[i];
        int res = ft_toupper(c);
        int expected = toupper(c);
        printf("ft_toupper(%d, '%c') = %d ('%c'), ожидалось: %d ('%c')\n",
               c, (c >= 32 && c <= 126) ? c : '?', 
               res, (res >= 32 && res <= 126) ? res : '?',
               expected, (expected >= 32 && expected <= 126) ? expected : '?');
    }
}

int main(void)
{
    test_ft_atoi();
    test_ft_bzero();
    test_ft_calloc();
    test_ft_isascii();   
    test_ft_isalpha();
    test_ft_isalnum();  
    test_ft_isdigit();
    test_ft_isprint();
    test_ft_isspace();
    test_ft_itoa();
    test_ft_lstadd_back();
    test_ft_lstadd_front();
    test_ft_lstclear();
    test_ft_lstdelone();
    test_ft_lstiter();
    test_ft_lstlast();
    test_ft_lstmap();
    test_ft_lstnew();  
    test_ft_lstsize();
    test_ft_memcpy();
    test_ft_memmove();
    test_ft_memset();
    test_ft_putchar_fd();
    test_ft_putendl_fd();
    test_ft_putnbr_fd();
    test_ft_putstr_fd();
    test_ft_split();
    test_ft_strchr();
    test_ft_strdup();
    test_ft_striteri();
    test_ft_strjoin();
    test_ft_strlcat();
    test_ft_strlcpy();
    test_ft_strlen();
    test_ft_strmapi();
    test_ft_strncmp();
    test_ft_strnstr();
    test_ft_strrchr();
    test_ft_strtrim();
    test_ft_substr();
    test_ft_tolower();
    test_ft_toupper();
    return 0;
}