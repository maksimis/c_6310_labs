#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *result;
    t_list *new_elem;
    void *new_content;

    if (!lst || !f || !del)
        return (NULL);
    result = NULL;
    while (lst)
    {
        new_content = f(lst->content);
        new_elem = ft_lstnew(new_content);
        if (!new_elem)
        {
            ft_lstclear(&result, del);
            return (NULL);
        }
        ft_lstadd_back(&result, new_elem);
        lst = lst->next;
    }
    return (result);
}
