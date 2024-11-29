/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psl_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:12:53 by ghambrec          #+#    #+#             */
/*   Updated: 2024/11/29 16:25:30 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rra + rrb
void	reverse_rotate(t_stack **stack, char stack_name)
{
	t_stack	*temp;
	t_stack	*last;

	if (ft_lstsize_ps(*stack) >= 2)
	{
		temp = *stack;
		last = ft_lstlast_ps(*stack);
		while (temp->next->next)
		{
			temp = temp->next;
		}
		temp->next = NULL;
		last->next = *stack;
		*stack = last;
	}
	if (ft_isalpha(stack_name))
	{
		ft_printf("rr%c\n", stack_name);
	}
}

// rrr
void	reverse_rotate_both(t_stack **a, t_stack **b)
{
	reverse_rotate(a, '0');
	reverse_rotate(b, '0');
	ft_printf("rrr\n");
}
