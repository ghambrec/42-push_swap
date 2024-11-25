/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psl_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:46:39 by ghambrec          #+#    #+#             */
/*   Updated: 2024/11/25 18:01:15 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **src, t_stack **dest)
{
	t_stack *temp;

	if (*src == NULL)
	{
		return ;
	}
	temp = *src;
	*src = (*src)->next;
	ft_lstadd_front_ps(dest, temp);
}
