#include "libft.h"

t_list	*ft_lstdup(t_list *lst)
{
	t_list	*dup;
	t_list	*node;

	dup = 0;
	while (lst)
	{
		node = ft_lstnew(lst->data);
		if (!node)
		{
			ft_lstclear(&node, &free);
			return (0);
		}
		ft_lstadd_back(&dup, node);
		lst = lst->next;
	}
	return (dup);
}
