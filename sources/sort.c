/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:03:15 by ghambrec          #+#    #+#             */
/*   Updated: 2024/12/02 15:39:03 by ghambrec         ###   ########.fr       */
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

t_stack *find_min(t_stack *stack)
{
	t_stack *min;

	min = stack;
	while (stack)
	{
		if (min->data > stack->data)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

// closest smaller value
void	find_target_in_b(t_stack *a, t_stack *b)
{
    t_stack	*temp_b;
    t_stack	*closest;
    int		closest_diff;

    while (a)
    {
        closest = NULL;
        closest_diff = INT_MAX;
        temp_b = b;
        while (temp_b)
        {
            if (temp_b->data < a->data && (a->data - temp_b->data) < closest_diff)
            {
                closest = temp_b;
                closest_diff = a->data - temp_b->data;
            }
            temp_b = temp_b->next;
        }
		if (!closest)
		{
			closest = find_max(b);
		}
        a->target = closest;
        a = a->next;
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

// calculates the push cost for each node in stack a
//		= number of operations needed to bring both the origin node and 
// 		  his target node on top of their stacks
void	calc_push_cost(t_stack *a, t_stack *b)
{
	int	cost_a;
	int	cost_b;
	
	while (a)
	{
		if (above_median(a))
			cost_a = a->index;
		else
			cost_a = get_stack_size(a) - a->index;
		if (above_median(a->target))
			cost_b = a->target->index;
		else
			cost_b = get_stack_size(b) - a->target->index;
		if ((above_median(a) == above_median(a->target)))
		{
			if (cost_a > cost_b)
				a->push_cost = cost_a;
			else
				a->push_cost = cost_b;
		}
		else
			a->push_cost = cost_a + cost_b;
		a = a->next;
	}
}

// closest bigger value
void	find_target_in_a(t_stack *b, t_stack *a)
{
    t_stack	*closest;
	t_stack *temp_a;
    int		closest_diff;

	temp_a = a;
	closest = NULL;
	closest_diff = INT_MAX;
	while (temp_a)
	{
		if (temp_a->data > b->data && (temp_a->data - b->data) < closest_diff)
		{
			closest = temp_a;
			closest_diff = temp_a->data - b->data;
		}
		temp_a = temp_a->next;
	}
	if (!closest)
	{
		closest = find_min(a);
	}
	b->target = closest;
}



void	init_stack(t_stack *from, t_stack *to, char name_from, char name_to)
{	
	init_stack_basics(from, name_from);
	init_stack_basics(to, name_to);

	find_target_in_b(from, to); // for testing no segfault
	find_target_in_b(to, from); // for testing no segfault

	if (name_from == 'a')
	{
		// find_target_in_b(from, to);
		calc_push_cost(from, to);
	}
	else
	{
		find_target_in_a(from, to);
		
	}
	
	
	

}

t_stack *get_cheapest_node(t_stack *stack)
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

// push the cheapest node from the stack to the target stack
void	push_to_target_stack(t_stack **origin, t_stack **target)
{
	t_stack *push_node;

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

void	sort(t_stack **a, t_stack **b)
{
	int	a_size;
	int	b_size;

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
	
	// GO ON HERE:
	// my plan:
	// now push b back to a
	// conditions: closest bigger value (the opposite to push a to b)
	// again get both nodes on top (with move_to_top function)
	// then push_to_target_stack (test with this function)
	// at the end get the min value from stack a and move it to top
}
