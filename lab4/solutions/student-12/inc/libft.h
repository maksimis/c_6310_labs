// Это инструкция для компилятора. Когда он читает main.c и видит там неизвестную функцию, 
// но благодаря строчке #include "libft.h", он заглядывает в этот файл и видит, что такая функция существует
// #ifndef #define...#endif - Защита от двойного включения. Если не определено - то читает файл LIBFT_H и сразу помечает как прочитанный (#define)
#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h> // для типа size_t и функций malloc/free.
#include <unistd.h> // для системного вызова write (для вывода текста) и типа ssize_t

// Описание структуры (t_list), описание узла односвязного списка
typedef struct s_list
{
    void *content; // указатель на любые данные (строку, число, другую структуру)
    struct s_list *next; // адрес следующего «вагончика» в цепочке
} t_list; // переименование, чтобы не писать вещде struct s_list

// Прототипы функций (декларации)
// Они показывают три вещи: как функция называется, что она принимает на вход и что возвращает
int ft_isalpha(int c); // int - тип возвращаемого значения, название функции и её аргументы
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
int ft_toupper(int c);
int ft_tolower(int c);
size_t ft_strlen(const char *s);
char *ft_strchr(const char *s, int c);
char *ft_strrchr(const char *s, int c);
char *ft_strnstr(const char *big, const char *little, size_t len);
int ft_strncmp(const char *s1, const char *s2, size_t n);
int ft_atoi(const char *nptr);
void *ft_calloc(size_t nmemb, size_t size);
char *ft_strdup(const char *s);
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strtrim(char const *s1, char const *set);
char **ft_split(char const *s, char c);
char *ft_itoa(int n);
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
void ft_striteri(char *s, void (*f)(unsigned int, char*));
void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(char *s, int fd);
void ft_putendl_fd(char *s, int fd);
void ft_putnbr_fd(int n, int fd);
t_list *ft_lstnew(void *content);
void ft_lstadd_front(t_list **lst, t_list *new);
int ft_lstsize(t_list *lst);
t_list *ft_lstlast(t_list *lst);
void ft_lstadd_back(t_list **lst, t_list *new);
void ft_lstdelone(t_list *lst, void (*del)(void*));
void ft_lstclear(t_list **lst, void (*del)(void*));
void ft_lstiter(t_list *lst, void (*f)(void *));
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int ft_isspace(int c);
size_t ft_strlcpy(char *dst, const char *src, size_t size);
size_t ft_strlcat(char *dst, const char *src, size_t size);
void *ft_memset(void *s, int c, size_t n);
void ft_bzero(void *s, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_memmove(void *dest, const void *src, size_t n);

#endif