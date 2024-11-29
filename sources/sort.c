/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:03:15 by ghambrec          #+#    #+#             */
/*   Updated: 2024/11/29 17:13:21 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// set index and name from the stack
void	init_stack_basics(t_stack *stack, char stack_name)
{
	int i;

	if (stack == NULL)
		return ;
	i = 0;
	while (stack)
	{
		stack->name = stack_name;
		stack->index = i;
		i++;
		stack = stack->next;
	}
}

t_stack *find_max(t_stack *stack)
{
	t_stack *max;

	max = stack;
	while (stack)
	{
		if (max->data < stack->data)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

void	find_target(t_stack *from, t_stack *to)
{
    t_stack	*temp_to;
    t_stack	*closest;
    int		closest_diff;

    while (from)
    {
        closest = NULL;
        closest_diff = INT_MAX;
        temp_to = to;
        while (temp_to)
        {
            if (temp_to->data < from->data && (from->data - temp_to->data) < closest_diff)
            {
                closest = temp_to;
                closest_diff = from->data - temp_to->data;
            }
            temp_to = temp_to->next;
        }
		if (!closest)
		{
			closest = find_max(to);
		}
        from->target = closest;
        from = from->next;
    }
}

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

int	above_median(t_stack *stack)
{
	int	median;
	
	median = get_stack_size(stack) / 2;
	if (stack->index <= median)
	{
		return (TRUE);
	}
	return (FALSE);
}

void	calc_push_cost(t_stack *from, t_stack *to)
{
	int	cost_a;
	int	cost_b;
	
	while (from)
	{
		if (above_median(from))
			cost_a = from->index;
		else
			cost_a = get_stack_size(from) - from->index;
		if (above_median(from->target))
			cost_b = from->target->index;
		else
			cost_b = get_stack_size(to) - from->target->index;
		if ((above_median(from) == above_median(from->target)))
		{
			if (cost_a > cost_b)
				from->push_cost = cost_a;
			else
				from->push_cost = cost_b;
		}
		else
			from->push_cost = cost_a + cost_b;
		from = from->next;
	}
}

void	init_stack(t_stack *from, t_stack *to, char name_from, char name_to)
{	
	init_stack_basics(from, name_from);
	init_stack_basics(to, name_to);
	find_target(from, to);
	find_target(to, from); // for testing no segfault
	calc_push_cost(from, to);

}

t_stack *get_cheapest_stack(t_stack *stack)
{
	t_stack *cheapest;

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

// function to move both nodes at the top of their stacks
void	move_to_top(t_stack *node1, t_stack *node2, t_stack **stack1, t_stack **stack2)
{
	if (above_median(node1) && above_median(node2))
	{
		while (node1 != *stack1 && node2 != *stack2)
			rotate_both(stack1, stack2);
	}
	if (!above_median(node1) && !above_median(node2))
	{
		while (node1 != *stack1 && node2 != *stack2)
			reverse_rotate_both(stack1, stack2);
	}
	while (node1 != *stack1)
	{
		if (above_median(node1))
			rotate(stack1, node1->name);
		else
			reverse_rotate(stack1, node1->name);
	}
	while (node2 != *stack2)
	{
		if (above_median(node2))
			rotate(stack2, node2->name);
		else
			reverse_rotate(stack2, node2->name);
	}
}

void	push_to_b(t_stack **a, t_stack **b)
{
	t_stack *cheapest;

	cheapest = get_cheapest_stack(*a);
	if (cheapest != *a || cheapest->target != *b)
	{
		move_to_top(cheapest, cheapest->target, a, b);
	}
	push(a, b, 'b');
	
}

void	sort(t_stack **a, t_stack **b)
{
	int	a_size;

	a_size = ft_lstsize_ps(*a);
	if (a_size > 3 && !check_is_sorted(*a))
	{
		a_size--;
		push(a, b, 'b');
	}
	if (a_size > 3 && !check_is_sorted(*a))
	{
		a_size--;
		push(a, b, 'b');
	}	
	while (a_size > 3 && !check_is_sorted(*a))
	{
		init_stack(*a, *b, 'a', 'b');
		push_to_b(a, b);
		a_size--;
	}
	sort_max_3(a);



}
