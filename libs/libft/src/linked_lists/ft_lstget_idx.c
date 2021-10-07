#include "libft.h"

int	ft_lstget_idx(t_list *lst, int value)
{
	int	i;

	i = 0;
	while (lst)
	{
		if ((long int)lst->data == value)
			break ;
		i++;
		lst = lst->next;
	}
	if (!lst)
		i = -1;
	return (i);
}
