/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psl_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:12:53 by ghambrec          #+#    #+#             */
/*   Updated: 2024/11/25 18:57:34 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (ft_lstsize_ps(*stack) >= 2)
	{
		temp = *stack;
		*stack = temp->next;
		temp->next = NULL;
		last = ft_lstlast_ps(*stack);
		last->next = temp;
	}
}

void	rotate_both(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
