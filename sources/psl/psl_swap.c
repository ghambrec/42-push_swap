/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psl_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:24:06 by ghambrec          #+#    #+#             */
/*   Updated: 2024/12/04 13:46:33 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa + sb
void	swap(t_stack *stack, char stack_name)
{
	int	temp;

	if (ft_lstsize_ps(stack) <= 1)
	{
		return ;
	}
	temp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = temp;
	if (ft_isalpha(stack_name))
	{
		ft_printf("s%c\n", stack_name);
	}
}

// ss
void	swap_both(t_stack *a, t_stack *b, int print)
{
	swap(a, '0');
	swap(b, '0');
	if (print == TRUE)
	{
		ft_printf("ss\n");
	}
}
