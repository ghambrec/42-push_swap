/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:03:15 by ghambrec          #+#    #+#             */
/*   Updated: 2024/11/28 15:07:48 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_stack_index(t_stack *stack)
{
	int i;

	if (stack == NULL)
		return ;
	i = 0;
	while (stack)
	{
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

int	above_median(int size, int index)
{
	int	median;

	median = size / 2;
	if (index <= median)
	{
		return (TRUE);
	}
	return (FALSE);
}


void	calc_push_cost(t_stack *from, t_stack *to)
{
	int	size_from;
	int	size_to;
	int	cost_a;
	int	cost_b;

	size_from = ft_lstsize_ps(from);
	size_to = ft_lstsize_ps(to);
	while (from)
	{
		if (above_median(size_from, from->index))
			cost_a = from->index;
		else
			cost_a = size_from - from->index;
		if (above_median(size_to, from->target->index))
			cost_b = from->target->index;
		else
			cost_b = size_to - from->target->index;
		if ((above_median(size_from, from->index) == above_median(size_to, from->target->index)))
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

void	init_stack(t_stack *from, t_stack *to)
{	
	set_stack_index(from);
	set_stack_index(to);
	find_target(from, to);
	find_target(to, from); // for testing no segfault
	calc_push_cost(from, to);

}


void	sort(t_stack **a, t_stack **b)
{
	int	a_size;

	a_size = ft_lstsize_ps(*a);
	if (a_size <= 3)
	{
		sort_max_3(a);
		return ;
	}
	if (a_size > 3 && !check_is_sorted(*a))
	{
		a_size--;
		push(a, b);
	}
	if (a_size > 3 && !check_is_sorted(*a))
	{
		a_size--;
		push(a, b);
		push(a, b); // for testing
	}
	init_stack(*a, *b);
	// while (a_size > 3 && !check_is_sorted(*a))
	// {
	// 	init_stack(*a);


	// 	a_size--;
	// }
}