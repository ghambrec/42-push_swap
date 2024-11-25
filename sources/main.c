/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:03:25 by ghambrec          #+#    #+#             */
/*   Updated: 2024/11/25 17:18:18 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack *temp;

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

int	main(int argc, char *argv[])
{
	t_stack	*a;
	int		parsing_result;

	a = NULL;
	parsing_result = start_parsing(argc, argv, &a);
	if (parsing_result == EXIT_FAILURE)
	{
		if (a != NULL)
			free_stack(&a);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return(EXIT_FAILURE);
	}
	if (check_is_sorted(a) == TRUE)
	{
		return (EXIT_SUCCESS);
	}



	// print stack a
	t_stack *temp;
	temp = a;
	printf("-------------------\n");
	while (temp != NULL)
	{
		printf("[%i]\n", temp->data);
		temp = temp->next;
	}
	printf("-------------------\n");
	free_stack(&a);
	return (EXIT_SUCCESS);
}


// im parsing bei is_number TRUE oder FALSE anwenden anstatt 1 und 0