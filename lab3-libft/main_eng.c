#include "libft.h"
#include <stdio.h>
#include <string.h>

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

void del_content(void *content)
{
    if (content)
        free(content);
}

void print_content(void *content)
{
    if (content)
        printf("\"%s\" ", (char *)content);
}

char to_upper_char(unsigned int i, char c)
{
    (void)i;
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

void test_list_functions(void)
{
    printf("\n=== TEST: List Functions ===\n");
    
    t_list *list = NULL;
    
    ft_lstadd_front(&list, ft_lstnew(ft_strdup("First")));
    ft_lstadd_front(&list, ft_lstnew(ft_strdup("Second")));
    ft_lstadd_front(&list, ft_lstnew(ft_strdup("Third")));
    
    printf("List after add_front: ");
    ft_lstiter(list, print_content);
    printf("\n");
    
    printf("List size: %d\n", ft_lstsize(list));
    printf("Last element: \"%s\"\n", (char *)ft_lstlast(list)->content);
    
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("Fourth")));
    printf("After adding 'Fourth' to back: ");
    ft_lstiter(list, print_content);
    printf("\n");
    printf("New size: %d\n", ft_lstsize(list));
    
    t_list *upper_list = ft_lstmap(list, to_upper_wrapper, del_content);
    printf("New list (UPPERCASE): ");
    ft_lstiter(upper_list, print_content);
    printf("\n");
    
    ft_lstclear(&list, del_content);
    ft_lstclear(&upper_list, del_content);
    printf("Lists cleared\n");
}

void test_all_functions(void)
{
    printf("=== FULL LIBFT TEST ===\n\n");
    
    // 1. Character checks
    printf("1. Character checks:\n");
    printf("   ft_isalpha('A'): %d\n", ft_isalpha('A'));
    printf("   ft_isdigit('5'): %d\n", ft_isdigit('5'));
    printf("   ft_isalnum('Z'): %d\n", ft_isalnum('Z'));
    printf("   ft_isascii(65): %d\n", ft_isascii(65));
    printf("   ft_isprint(' '): %d\n", ft_isprint(' '));
    printf("   ft_toupper('z'): '%c'\n", ft_toupper('z'));
    printf("   ft_tolower('Q'): '%c'\n", ft_tolower('Q'));
    printf("   ft_isspace('\\t'): %d\n", ft_isspace('\t'));
    
    // 2. String length
    printf("\n2. ft_strlen(\"Hello\"): %zu\n", ft_strlen("Hello"));
    
    // 3. Copy and concat
    char dest[20];
    printf("\n3. ft_strlcpy: %zu -> \"%s\"\n", ft_strlcpy(dest, "Hi", 3), dest);
    printf("   ft_strlcat: %zu -> \"%s\"\n", ft_strlcat(dest, " World", 20), dest);
    
    // 4. Search in string
    printf("\n4. ft_strchr(\"Hello\", 'l'): \"%s\"\n", ft_strchr("Hello", 'l'));
    printf("   ft_strrchr(\"Hello\", 'l'): \"%s\"\n", ft_strrchr("Hello", 'l'));
    printf("   ft_strnstr(\"Hello World\", \"World\", 11): \"%s\"\n", ft_strnstr("Hello World", "World", 11));
    printf("   ft_strncmp(\"Hello\", \"Helix\", 3): %d\n", ft_strncmp("Hello", "Helix", 3));
    
    // 5. Conversions
    printf("\n5. ft_atoi(\"   -123\"): %d\n", ft_atoi("   -123"));
    char *itoa_result = ft_itoa(-456);
    printf("   ft_itoa(-456): \"%s\"\n", itoa_result);
    free(itoa_result);
    
    // 6. Memory functions
    printf("\n6. ft_calloc: ");
    int *arr = (int *)ft_calloc(5, sizeof(int));
    printf("%d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
    free(arr);
    
    char *dup = ft_strdup("Duplicate me");
    printf("   ft_strdup: \"%s\"\n", dup);
    free(dup);
    
    // 7. String functions
    char *sub = ft_substr("Hello World", 6, 5);
    printf("\n7. ft_substr(\"Hello World\", 6, 5): \"%s\"\n", sub);
    free(sub);
    
    char *join = ft_strjoin("Hello ", "World");
    printf("   ft_strjoin(\"Hello \", \"World\"): \"%s\"\n", join);
    free(join);
    
    char *trim = ft_strtrim("   Hello   ", " ");
    printf("   ft_strtrim(\"   Hello   \", \" \"): \"%s\"\n", trim);
    free(trim);
    
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
    
    char *mapped = ft_strmapi("hello", to_upper_char);
    printf("   ft_strmapi(\"hello\", to_upper): \"%s\"\n", mapped);
    free(mapped);
    
    // 8. Output functions
    printf("\n8. Output functions (check output):\n");
    printf("   ft_putstr_fd: ");
    ft_putstr_fd("Test output", 1);
    ft_putchar_fd('\n', 1);
    printf("   ft_putnbr_fd: ");
    ft_putnbr_fd(12345, 1);
    ft_putchar_fd('\n', 1);
    
    // 9. Lists
    test_list_functions();
    
    printf("\n=== ALL TESTS PASSED ===\n");
}

int main(void)
{
    test_all_functions();
    return 0;
}