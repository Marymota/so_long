#include "libft.h"

long int	ft_lstget_median(t_list *lst)
{
	t_list		*dup;
	t_list		*tmp;
	int			half_size;
	long int	median;

	dup = ft_lstdup(lst);
	half_size = ft_lstsize(dup) / 2;
	ft_lstsort(&dup);
	tmp = dup;
	while (half_size--)
		tmp = tmp->next;
	median = (long int)tmp->data;
	ft_lstclear(&dup, ft_lstdel_int);
	return (median);
}
