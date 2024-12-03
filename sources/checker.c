/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghamnbrec <ghambrec@student.42heilbronn    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:30:00 by ghamnbrec         #+#    #+#             */
/*   Updated: 2024/12/03 14:58:38 by ghamnbrec        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_operation(char *operation, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(operation, "sa\n", 4))
		swap(*a, '0');
	else if (!ft_strncmp(operation, "sb\n", 4))
		swap(*b, '0');
	else if (!ft_strncmp(operation, "ss\n", 4))
		swap_both(*a, *b, FALSE);
	else if (!ft_strncmp(operation, "pa\n", 4))
		push(b, a, '0');
	else if (!ft_strncmp(operation, "pb\n", 4))
		push(a, b, '0');
	else if (!ft_strncmp(operation, "ra\n", 4))
		rotate(a, '0');
	else if (!ft_strncmp(operation, "rb\n", 4))
		rotate(b, '0');
	else if (!ft_strncmp(operation, "rr\n", 4))
		rotate_both(a, b, FALSE);
	else if (!ft_strncmp(operation, "rra\n", 5))
		reverse_rotate(a, '0');
	else if (!ft_strncmp(operation, "rrb\n", 5))
		reverse_rotate(b, '0');
	else if (!ft_strncmp(operation, "rrr\n", 5))
		reverse_rotate_both(a, b, FALSE);
	else
		exit(write(STDERR_FILENO, "Error\n", 6));
}

static void	read_operations(t_stack **a, t_stack **b)
{
	char	*operation;

	operation = NULL;
	while (TRUE)
	{
		operation = get_next_line(STDIN_FILENO);
		if (operation == NULL)
			break ;
		run_operation(operation, a, b);
		free(operation);
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
	read_operations(&a, &b);
	if (check_is_sorted(a) && ft_lstsize_ps(b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&a);
	free_stack(&b);
	return (EXIT_SUCCESS);
}
