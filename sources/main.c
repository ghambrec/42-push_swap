/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:03:25 by ghambrec          #+#    #+#             */
/*   Updated: 2024/11/25 14:44:57 by ghambrec         ###   ########.fr       */
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


int	main(int argc, char *argv[])
{
	t_stack	*a;
	int		parsing_result;

	a = NULL;
	if (argc < 2)
	{
		return (EXIT_FAILURE);
	}
	parsing_result = start_parsing(argc, argv, &a);
	if (parsing_result == EXIT_FAILURE)
	{
		// free a-stack and all what is in there
		free_stack(&a);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return(EXIT_FAILURE);
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
