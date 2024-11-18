/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:07:47 by ghambrec          #+#    #+#             */
/*   Updated: 2024/10/15 18:40:14 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_entry;

	new_entry = (t_list *)malloc(sizeof(t_list));
	if (!new_entry)
	{
		return (NULL);
	}
	new_entry->content = content;
	new_entry->next = NULL;
	return (new_entry);
}
