/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghamnbrec <ghambrec@student.42heilbronn    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:03:25 by ghambrec          #+#    #+#             */
/*   Updated: 2024/12/03 14:53:33 by ghamnbrec        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	test_print_stack(t_stack *stack, char *text)
// {
// 	ft_printf("%s", text);
// 	while (stack != NULL)
// 	{
// 		// ft_printf("%i: [%i] TG:[%i] COST: %i NAME:%c\n",stack->index, stack->data, stack->target->data, stack->push_cost, stack->name);
// 		ft_printf("%i\n",stack->data);
// 		stack = stack->next;
// 	}
// 	ft_printf("\n");
// }

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
	if (check_is_sorted(a) == TRUE || ft_lstsize_ps(a) == 1)
	{
		free_stack(&a);
		return (EXIT_SUCCESS);
	}
	sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (EXIT_SUCCESS);	
}
