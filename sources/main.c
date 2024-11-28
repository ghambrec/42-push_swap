/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:03:25 by ghambrec          #+#    #+#             */
/*   Updated: 2024/11/28 13:04:09 by ghambrec         ###   ########.fr       */
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

void	test_print_stack(t_stack *stack, char *text)
{
	printf("%s", text);
	while (stack != NULL)
	{
		printf("%i: [%i] TG:[%i] COST: %i\n",stack->index, stack->data, stack->target->data, stack->push_cost);
		stack = stack->next;
	}
}

void leaks(void)
{
	system("leaks push_swap");
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		parsing_result;

	a = NULL;
	b = NULL;
	// atexit(leaks);
	parsing_result = start_parsing(argc, argv, &a);
	if (parsing_result == EXIT_FAILURE)
	{
		if (a != NULL)
			free_stack(&a);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return(EXIT_FAILURE);
	}
	// print stack a before sorting anything
	// test_print_stack(a, "a:------------------\n");
	if (check_is_sorted(a) == TRUE || ft_lstsize_ps(a) == 1)
	{
		test_print_stack(a, "SORTED--------------\n");
		free_stack(&a);
		return (EXIT_SUCCESS);
	}
	sort(&a, &b);
	// test_print_stack(a, "SORTED--------------\n");
	test_print_stack(a, "\nA:------------------\n");
	test_print_stack(b, "\nB:------------------\n");

	
	free_stack(&a);
	free_stack(&b);
	return (EXIT_SUCCESS);	
}
