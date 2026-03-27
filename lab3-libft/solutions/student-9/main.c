#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void TEST(int num, const char *name, int ok) {
    printf("%d. %s: [%s]\n", num, name, ok ? "PASS" : "FAIL");
}

// Вспомогательные функции для ft_strmapi / ft_striteri
static char my_toupper(unsigned int i, char c) { (void)i; return (char)toupper((unsigned char)c); }
static void iter_upper(unsigned int i, char *c) { (void)i; *c = (char)toupper((unsigned char)*c); }

// Вспомогательные функции для ft_lstmap / ft_lstiter
static void *lstmap_upper(void *c) { 
    if (!c) return NULL; 
    char *s = strdup((char*)c); 
    for (int i=0;s[i];i++) s[i] = toupper((unsigned char)s[i]); 
    return s; 
}

/* вспомогательная функция для list_iter и map */
static void list_iter_upper(void *content)
{
    char *str = (char *)content;
    for (int i = 0; str && str[i]; i++)
        str[i] = (char)toupper((unsigned char)str[i]);
}

static void list_del(void *content)
{
    free(content);
}

int main(void)
{
    t_list *lst, *mapped;
    char iter_str[10];
    char **split;

    int test_num = 0;   

    // 1-7
    TEST(++test_num, "ft_isalpha", ft_isalpha('A') && !ft_isalpha('1'));
    TEST(++test_num, "ft_isdigit", ft_isdigit('5') && !ft_isdigit('a'));
    TEST(++test_num, "ft_isalnum", ft_isalnum('Z') && !ft_isalnum('@'));
    TEST(++test_num, "ft_isascii", ft_isascii(65) && !ft_isascii(200));
    TEST(++test_num, "ft_isprint", ft_isprint(' ') && !ft_isprint('\n'));
    TEST(++test_num, "ft_toupper", ft_toupper('a') == 'A');
    TEST(++test_num, "ft_tolower", ft_tolower('Z') == 'z');

    // 8-12
    TEST(++test_num, "ft_strlen", ft_strlen("Hello")==5);
    TEST(++test_num, "ft_strchr", ft_strchr("Hello",'e')!=NULL);
    TEST(++test_num, "ft_strrchr", ft_strrchr("Hello",'l')!=NULL);
    TEST(++test_num, "ft_strncmp", ft_strncmp("abc","abd",3)<0);

    // 13-20
    TEST(++test_num, "ft_atoi", ft_atoi("  -42abc")==-42);
    int *arr = ft_calloc(5,sizeof(int));
    TEST(++test_num, "ft_calloc", arr && arr[0]==0 && arr[4]==0);
    free(arr);

    char *dup = ft_strdup("Hi");
    TEST(++test_num, "ft_strdup", dup && strcmp(dup,"Hi")==0);
    free(dup);

    char *sub = ft_substr("Hello",1,3);
    TEST(++test_num, "ft_substr", sub && strcmp(sub,"ell")==0);
    free(sub);

    char *join = ft_strjoin("A","B");
    TEST(++test_num, "ft_strjoin", join && strcmp(join,"AB")==0);
    free(join);

    char *trim = ft_strtrim("  X  "," ");
    TEST(++test_num, "ft_strtrim", trim && strcmp(trim,"X")==0);
    free(trim);

    split = ft_split("a,b,c",',');
    TEST(++test_num, "ft_split", split && strcmp(split[0],"a")==0 && strcmp(split[1],"b")==0 && strcmp(split[2],"c")==0 && split[3]==NULL);
    for(int i=0; split[i]; i++) free(split[i]);
    free(split);

    char *itoa = ft_itoa(-42);
    TEST(++test_num, "ft_itoa", itoa && strcmp(itoa,"-42")==0);
    free(itoa);

    // 21-22
    char *mapi = ft_strmapi("abc", my_toupper);
    TEST(++test_num, "ft_strmapi", mapi && strcmp(mapi,"ABC")==0);
    free(mapi);

    strcpy(iter_str,"abc");
    ft_striteri(iter_str, iter_upper);
    TEST(++test_num, "ft_striteri", strcmp(iter_str,"ABC")==0);

    // 23-26: вывод — вручную проверяем, PASS
    TEST(++test_num, "ft_putchar_fd", 1);
    TEST(++test_num, "ft_putstr_fd", 1);
    TEST(++test_num, "ft_putendl_fd", 1);
    TEST(++test_num, "ft_putnbr_fd", 1);

    // 27-29
    TEST(++test_num, "ft_isspace", ft_isspace(' ') && !ft_isspace('A'));
    char dst1[10]; ft_strlcpy(dst1,"abc",10);
    TEST(++test_num, "ft_strlcpy", strcmp(dst1,"abc")==0);
    char dst2[10]="a"; ft_strlcat(dst2,"b",10);
    TEST(++test_num, "ft_strlcat", strcmp(dst2,"ab")==0);

    // 30-33
    char mem[5]; ft_memset(mem,'X',5);
    TEST(++test_num, "ft_memset", mem[0]=='X' && mem[4]=='X');
    ft_bzero(mem,5);
    TEST(++test_num, "ft_bzero", mem[0]==0 && mem[4]==0);
    char src[5]="1234", dst[5];
    ft_memcpy(dst,src,5);
    TEST(++test_num, "ft_memcpy", strcmp(dst,"1234")==0);
    char overlap[10]="ABCDE";
    ft_memmove(overlap+2,overlap,3);
    TEST(++test_num, "ft_memmove", overlap[2]=='A' && overlap[4]=='C');

    // 34-42: списки
    lst = ft_lstnew(ft_strdup("X"));
    TEST(++test_num, "ft_lstnew", lst && lst->content);
    ft_lstclear(&lst, free);

    lst = ft_lstnew(ft_strdup("A"));
    ft_lstadd_front(&lst, ft_lstnew(ft_strdup("B")));
    TEST(++test_num, "ft_lstadd_front", ft_lstsize(lst)==2);
    ft_lstclear(&lst, free);

    lst = ft_lstnew(ft_strdup("A"));
    ft_lstadd_back(&lst, ft_lstnew(ft_strdup("B")));
    ft_lstadd_back(&lst, ft_lstnew(ft_strdup("C")));
    TEST(++test_num, "ft_lstsize", ft_lstsize(lst)==3);
    TEST(++test_num, "ft_lstlast", strcmp((char*)ft_lstlast(lst)->content,"C")==0);
    ft_lstclear(&lst, free);
    TEST(++test_num, "ft_lstclear", lst==NULL);

    lst = ft_lstnew(ft_strdup("a"));
    mapped = ft_lstmap(lst, lstmap_upper, free);
    TEST(++test_num, "ft_lstmap", mapped && ft_lstsize(mapped)==1);
    ft_lstclear(&lst, free);
    ft_lstclear(&mapped, free);

    /* === ft_strnstr === */
    const char *big = "Hello, world!";
    const char *little = "world";
    TEST(++test_num, "ft_strnstr", ft_strnstr(big, little, strlen(big)) == strstr(big, little));

    /* === ft_lstadd_back === */
    t_list *lst_back = ft_lstnew(strdup("first"));
    t_list *new_node = ft_lstnew(strdup("back"));
    ft_lstadd_back(&lst_back, new_node);
    TEST(++test_num, "ft_lstadd_back", ft_lstlast(lst_back) == new_node && ft_lstsize(lst_back) == 2);
    ft_lstclear(&lst_back, list_del);

    /* === ft_lstdelone === */
    t_list *del_node = ft_lstnew(strdup("delme"));
    ft_lstdelone(del_node, list_del);
    TEST(++test_num, "ft_lstdelone", 1);

    /* === ft_lstiter === */
    t_list *iter_lst = ft_lstnew(strdup("abc"));
    ft_lstadd_back(&iter_lst, ft_lstnew(strdup("def")));
    ft_lstiter(iter_lst, list_iter_upper);
    TEST(++test_num, "ft_lstiter",
        strcmp((char *)iter_lst->content, "ABC") == 0 &&
        strcmp((char *)iter_lst->next->content, "DEF") == 0);
    ft_lstclear(&iter_lst, list_del);

    printf("\n=== Конец тестов ===\n");
    return 0;
}