#include "libft.h"

t_list	*mergeSort(t_list *a, t_list *b)
{
	t_list	*res;

	res = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if ((long int)a->data <= (long int)b->data)
	{
		res = a;
		res->next = mergeSort(a->next, b);
	}
	else
	{
		res = b;
		res->next = mergeSort(a, b->next);
	}
	return (res);
}

void	split(t_list *src, t_list **a, t_list **b)
{
	t_list	*fast;
	t_list	*slow;

	slow = src;
	fast = src->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*a = src;
	*b = slow->next;
	slow->next = NULL;
}

void	ft_lstsort(t_list **lst)
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = *lst;
	if ((head == NULL) || (head->next == NULL))
		return ;
	split(head, &a, &b);
	ft_lstsort(&a);
	ft_lstsort(&b);
	*lst = mergeSort(a, b);
}
