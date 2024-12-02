/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_get_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:37:58 by ghambrec          #+#    #+#             */
/*   Updated: 2024/12/02 20:48:06 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(t_stack *stack)
{
	int	size;

	while (stack)
	{
		size = stack->index;
		stack = stack->next;
	}
	return (size + 1);
}

t_stack	*get_max(t_stack *stack)
{
	t_stack	*max;

	max = stack;
	while (stack)
	{
		if (max->data < stack->data)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_stack	*get_min(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack)
	{
		if (min->data > stack->data)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_stack	*get_cheapest_node(t_stack *stack)
{
	t_stack	*cheapest;

	cheapest = stack;
	while (stack)
	{
		if (stack->push_cost < cheapest->push_cost)
		{
			cheapest = stack;
		}
		stack = stack->next;
	}
	return (cheapest);
}
