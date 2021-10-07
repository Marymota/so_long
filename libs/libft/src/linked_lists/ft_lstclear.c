#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst && *lst)
	{
		while (*lst)
		{
			tmp = *lst;
			*lst = (*lst)->next;
			ft_lstdelone(tmp, del);
		}
		*lst = 0;
	}
}

void	ft_lstdel_int(void *data)
{
	(void)data;
}
