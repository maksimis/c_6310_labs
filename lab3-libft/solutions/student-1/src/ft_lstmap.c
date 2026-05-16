#include "libft.h"

static t_list	*new_and_add_back(t_list **new_list, void *content)
{
	t_list	*node;

	node = ft_lstnew(content);
	if (!node)
		return (NULL);
	ft_lstadd_back(new_list, node);
	return (node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*node;
	void	*new_content;

	if (!f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		if (!new_content)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		node = new_and_add_back(&new_list, new_content);
		if (!node)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (new_list);
}
