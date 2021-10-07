#include "libft.h"
/*Function to find the smallest value in a linked-list*/

int	ft_lstget_min(t_list *lst)
{
	int	min;

	if (!lst)
		return (INT_MIN);
	min = (long int)lst->data;
	while (lst)
	{
		if ((long int)lst->data < min)
			min = (long int)lst->data;
		lst = lst->next;
	}
	return (min);
}
