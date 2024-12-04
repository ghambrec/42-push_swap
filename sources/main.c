/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:03:25 by ghambrec          #+#    #+#             */
/*   Updated: 2024/12/04 19:21:04 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		parsing_result;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (EXIT_SUCCESS);
	parsing_result = start_parsing(argc, argv, &a);
	if (parsing_result == EXIT_FAILURE)
	{
		if (a != NULL)
			free_stack(&a);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
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
