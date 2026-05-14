#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = NULL;
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}