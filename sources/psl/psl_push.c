/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psl_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:46:39 by ghambrec          #+#    #+#             */
/*   Updated: 2024/12/04 13:46:25 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pa + pb
void	push(t_stack **src, t_stack **dest, char stack_name)
{
	t_stack	*temp;

	if (*src == NULL)
	{
		return ;
	}
	temp = *src;
	*src = (*src)->next;
	ft_lstadd_front_ps(dest, temp);
	if (ft_isalpha(stack_name))
	{
		ft_printf("p%c\n", stack_name);
	}
}
