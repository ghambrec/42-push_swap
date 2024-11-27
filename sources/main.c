/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:03:25 by ghambrec          #+#    #+#             */
/*   Updated: 2024/11/27 13:56:54 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL)
	{
		return ;
	}
	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

int	check_is_sorted(t_stack *a)
{
	int	prev_number;

	prev_number = INT_MIN;
	if (ft_lstsize_ps(a) > 1)
	{
		while (a != NULL)
		{
			if (a->data < prev_number)
			{
				return (FALSE);
			}
			prev_number = a->data;
			a = a->next;
		}
	}
	return (TRUE);
}

void	test_print_stack(t_stack *stack, char *text)
{
	printf("%s", text);
	while (stack != NULL)
	{
		printf("[%i]\n", stack->data);
		stack = stack->next;
	}
}

void	sort_2(t_stack **a)
{
	if (ft_lstsize_ps(*a) == 2)
		swap(*a);
}

void	sort_max_3(t_stack **a)
{
	sort_2(a);
	if (ft_lstsize_ps(*a) == 3)
	{
		if ((*a)->data > (*a)->next->data && \
		(*a)->next->data > (*a)->next->next->data)
		{
			swap(*a);
			reverse_rotate(a);
		}
		else if ((*a)->data > (*a)->next->next->data && \
		(*a)->next->next->data > (*a)->next->data)
			rotate(a);
		else if ((*a)->next->data > (*a)->data && \
		(*a)->data > (*a)->next->next->data)
			swap(*a);
		else if ((*a)->next->data > (*a)->next->next->data && \
		(*a)->next->next->data > (*a)->data)
		{
			swap(*a);
			rotate(a);
		}
		else if ((*a)->next->next->data > (*a)->data && \
		(*a)->data > (*a)->next->data)
			reverse_rotate(a);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		parsing_result;

	a = NULL;
	b = NULL;
	parsing_result = start_parsing(argc, argv, &a);
	if (parsing_result == EXIT_FAILURE)
	{
		if (a != NULL)
			free_stack(&a);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return(EXIT_FAILURE);
	}
	// print stack a before sorting anything
	test_print_stack(a, "a:------------------\n");
	if (check_is_sorted(a) == TRUE || ft_lstsize_ps(a) == 1)
	{
		test_print_stack(a, "SORTED--------------\n");
		free_stack(&a);
		return (EXIT_SUCCESS);
	}
	if (ft_lstsize_ps(a) <= 3)
	{
		sort_max_3(&a);
	}
	test_print_stack(a, "SORTED--------------\n");
	free_stack(&a);
	free_stack(&b);
	return (EXIT_SUCCESS);	
}
