/* Iterates through or linked_list to find duplicates */
#include "libft.h"

int	ft_lstcheck_dup(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (lst->data == tmp->data)
				return (1);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (0);
}
