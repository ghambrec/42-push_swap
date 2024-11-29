/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:37:52 by ghambrec          #+#    #+#             */
/*   Updated: 2024/11/29 17:14:22 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_2(t_stack **a)
{
	if (ft_lstsize_ps(*a) == 2)
		swap(*a, 'a');
}

void	sort_max_3(t_stack **a)
{
	sort_2(a);
	if (ft_lstsize_ps(*a) == 3)
	{
		if ((*a)->data > (*a)->next->data && \
		(*a)->next->data > (*a)->next->next->data)
		{
			swap(*a, 'a');
			reverse_rotate(a, 'a');
		}
		else if ((*a)->data > (*a)->next->next->data && \
		(*a)->next->next->data > (*a)->next->data)
			rotate(a, 'a');
		else if ((*a)->next->data > (*a)->data && \
		(*a)->data > (*a)->next->next->data)
			reverse_rotate(a, 'a');
		else if ((*a)->next->data > (*a)->next->next->data && \
		(*a)->next->next->data > (*a)->data)
		{
			swap(*a, 'a');
			rotate(a, 'a');
		}
		else if ((*a)->next->next->data > (*a)->data && \
		(*a)->data > (*a)->next->data)
			swap(*a, 'a');
	}
}
