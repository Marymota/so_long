#include "libft.h"

void	ft_lstdel_first(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (lst == NULL || *lst == NULL)
		return ;
	tmp = *lst;
	tmp = tmp->next;
	del((*lst)->data);
	free(*lst);
	*lst = tmp;
}
