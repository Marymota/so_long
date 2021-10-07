#include "libft.h"

int	ft_lstget_data(t_list *lst, int pos)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (i == pos)
			return ((long int)lst->data);
		lst = lst->next;
		++i;
	}
	return (-2147483648);
}
