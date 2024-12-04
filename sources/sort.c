/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:03:15 by ghambrec          #+#    #+#             */
/*   Updated: 2024/12/04 13:07:57 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_is_sorted(t_stack *a)
{
	while (a->next)
	{
		if (a->data > a->next->data)
		{
			return (FALSE);
		}
		a = a->next;
	}
	return (TRUE);
}

// function to move both nodes at the top of their stacks
void	move_to_top(t_stack *node1, t_stack *node2, \
					t_stack **stack1, t_stack **stack2)
{
	if (node1->above_median && node2->above_median)
	{
		while (node1 != *stack1 && node2 != *stack2)
			rotate_both(stack1, stack2, TRUE);
	}
	if (!node1->above_median && !node2->above_median)
	{
		while (node1 != *stack1 && node2 != *stack2)
			reverse_rotate_both(stack1, stack2, TRUE);
	}
	while (node1 != *stack1)
	{
		if (node1->above_median)
			rotate(stack1, node1->name);
		else
			reverse_rotate(stack1, node1->name);
	}
	while (node2 != *stack2)
	{
		if (node2->above_median)
			rotate(stack2, node2->name);
		else
			reverse_rotate(stack2, node2->name);
	}
}

// push the cheapest node from the stack to the target stack
void	push_to_target_stack(t_stack **origin, t_stack **target)
{
	t_stack	*push_node;

	if ((*origin)->name == 'a')
		push_node = get_cheapest_node(*origin);
	else
		push_node = *origin;
	if (push_node != *origin || push_node->target != *target)
	{
		move_to_top(push_node, push_node->target, origin, target);
	}
	push(origin, target, push_node->target->name);
}

void	check_min_on_top(t_stack **a)
{
	t_stack	*min;

	min = get_min(*a);
	if (*a != min)
	{
		if (min->above_median)
		{
			while (*a != min)
				rotate(a, 'a');
		}
		else
		{
			while (*a != min)
				reverse_rotate(a, 'a');
		}
	}
}

void	sort(t_stack **a, t_stack **b)
{
	int	a_size;
	int	b_size;

	a_size = ft_lstsize_ps(*a);
	if (a_size-- > 3 && !check_is_sorted(*a))
		push(a, b, 'b');
	if (a_size-- > 3 && !check_is_sorted(*a))
		push(a, b, 'b');
	while (a_size > 3 && !check_is_sorted(*a))
	{
		init_stack(*a, *b, 'a', 'b');
		push_to_target_stack(a, b);
		a_size--;
	}
	sort_max_3(a);
	b_size = ft_lstsize_ps(*b);
	while (b_size > 0)
	{
		init_stack(*b, *a, 'b', 'a');
		push_to_target_stack(b, a);
		b_size--;
	}
	init_stack_basics(*a, 'a');
	check_min_on_top(a);
}
