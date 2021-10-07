#include "libft.h"

void	ft_lstadd_next(t_list *lst, t_list *node)
{
	node->next = lst->next;
	lst->next = node;
}
