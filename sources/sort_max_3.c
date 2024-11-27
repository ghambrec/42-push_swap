/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:37:52 by ghambrec          #+#    #+#             */
/*   Updated: 2024/11/27 16:00:42 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_2(t_stack **a)
{
	if (ft_lstsize_ps(*a) == 2)
		swap(*a);
}

void	sort_max_3(t_stack **a)
{
	sort_2(a);
	if (ft_lstsize_ps(*a) == 3)
	{
		if ((*a)->data > (*a)->next->data && \
		(*a)->next->data > (*a)->next->next->data)
		{
			swap(*a);
			reverse_rotate(a);
		}
		else if ((*a)->data > (*a)->next->next->data && \
		(*a)->next->next->data > (*a)->next->data)
			rotate(a);
		else if ((*a)->next->data > (*a)->data && \
		(*a)->data > (*a)->next->next->data)
			reverse_rotate(a);
		else if ((*a)->next->data > (*a)->next->next->data && \
		(*a)->next->next->data > (*a)->data)
		{
			swap(*a);
			rotate(a);
		}
		else if ((*a)->next->next->data > (*a)->data && \
		(*a)->data > (*a)->next->data)
			swap(*a);
	}
}
