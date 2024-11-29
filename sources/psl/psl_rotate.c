/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psl_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:12:53 by ghambrec          #+#    #+#             */
/*   Updated: 2024/11/29 16:21:58 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ra + rb
void	rotate(t_stack **stack, char stack_name)
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
	if (ft_isalpha(stack_name))
	{
		ft_printf("r%c\n", stack_name);
	}
}

// rr
void	rotate_both(t_stack **a, t_stack **b)
{
	rotate(a, '0');
	rotate(b, '0');
	ft_printf("rr\n");
}
