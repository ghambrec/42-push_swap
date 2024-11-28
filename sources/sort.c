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

void	init_stack(t_stack *stack1, t_stack *stack2)
{	
	t_stack *target;
	t_stack	*temp;
	t_stack *temp1 = stack1;
	t_stack *temp2 = stack2;
	set_stack_index(stack1);
	set_stack_index(stack2);
	
	temp = stack2;
	while (stack1)
	{
		stack2 = temp;
		target = find_max(stack2);
		while (stack2)
		{
			if (stack1->data == 25)
			{
				printf("[target] --> %i\n",target->data);
				// 10 > 13 && 10 > 13 --> FALSE
				// 10 > 0  && 0  > 13 --> FALSE
				if (stack1->data > stack2->data && stack2->data < target->data)
				{
					printf("%i - true\n",stack2->data);
				} else
				{
					printf("%i - false\n",stack2->data);
				}
			}
			// if (stack1->data > stack2->data && stack2->data < target->data)
			// {
			// 	target = stack2;
			// }
			stack2 = stack2->next;
		}
		stack1->target = target;
		stack1 = stack1->next;
	}





	while (temp2)
	{
		temp2->target = temp1;

		temp2 = temp2->next;
	}
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
	}
	init_stack(*a, *b);
	// while (a_size > 3 && !check_is_sorted(*a))
	// {
	// 	init_stack(*a);


	// 	a_size--;
	// }
}