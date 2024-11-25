/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:03:25 by ghambrec          #+#    #+#             */
/*   Updated: 2024/11/25 16:52:51 by ghambrec         ###   ########.fr       */
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

void	check_is_sorted(t_stack **a)
{
	// go on here
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

	// check_is_sorted(&a);

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
