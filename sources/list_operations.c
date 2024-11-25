/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:31:56 by ghambrec          #+#    #+#             */
/*   Updated: 2024/11/25 14:34:25 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew_ps(int content)
{
	t_stack	*new_entry;

	new_entry = (t_stack *)malloc(sizeof(t_stack));
	if (!new_entry)
	{
		return (NULL);
	}
	new_entry->data = content;
	new_entry->next = NULL;
	return (new_entry);
}

// int	ft_lstsize_ps(t_stack *lst)
// {
// 	int	size;

// 	size = 0;
// 	while (lst != NULL)
// 	{
// 		size++;
// 		lst = lst->next;
// 	}
// 	return (size);
// }

t_stack	*ft_lstlast_ps(t_stack *lst)
{
	t_stack	*last_entry;

	if (lst == NULL)
	{
		return (NULL);
	}
	last_entry = lst;
	while (last_entry->next != NULL)
	{
		last_entry = last_entry->next;
	}
	return (last_entry);
}

void	ft_lstadd_back_ps(t_stack **lst, t_stack *new)
{
	t_stack	*last_entry;

	if (new == NULL)
	{
		return ;
	}
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last_entry = ft_lstlast_ps(*lst);
	last_entry->next = new;
}

// void	ft_lstadd_front_ps(t_stack **lst, t_stack *new)
// {
// 	if (new != NULL)
// 	{
// 		new->next = *lst;
// 		*lst = new;
// 	}
// }
