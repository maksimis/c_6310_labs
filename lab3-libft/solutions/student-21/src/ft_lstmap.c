#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *result;
    t_list *node;
    void   *content;

    if (!lst || !f || !del)
        return (NULL);
    result = NULL;
    while (lst)
    {
        content = f(lst->content);
        node = ft_lstnew(content);
        if (!node)
        {
            del(content);
            ft_lstclear(&result, del);
            return (NULL);
        }
        ft_lstadd_back(&result, node);
        lst = lst->next;
    }
    return (result);
}
