/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:00:26 by ghambrec          #+#    #+#             */
/*   Updated: 2024/10/15 18:43:16 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_entry;

	if (lst == NULL)
	{
		return (NULL);
	}
	last_entry = lst;
	while (last_entry->next != NULL)
	{
		last_entry = last_entry->next;
	}
	return (last_entry);
}
