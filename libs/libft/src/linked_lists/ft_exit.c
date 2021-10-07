#include "libft.h"

void	ft_exit(int exit_code, t_list **stack_a, t_list **stack_b)
{
	if (exit_code == 0)
	{
		ft_lstclear(stack_a, ft_lstdel_int);
		ft_lstclear(stack_b, ft_lstdel_int);
		exit(EXIT_SUCCESS);
	}
	else
	{
		if (exit_code >= 1)
			ft_lstclear(stack_a, ft_lstdel_int);
		if (exit_code >= 2)
			ft_lstclear(stack_b, ft_lstdel_int);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
