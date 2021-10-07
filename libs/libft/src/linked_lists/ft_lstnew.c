/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmota <marmota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:04:32 by marmota           #+#    #+#             */
/*   Updated: 2021/09/10 15:50:12 by marmota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *data)
{
	t_list	*head;

	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
		return (0);
	head->data = data;
	head->next = 0;
	return (head);
}
