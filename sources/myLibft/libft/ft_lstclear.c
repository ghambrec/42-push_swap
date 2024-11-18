/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:52:00 by ghambrec          #+#    #+#             */
/*   Updated: 2024/10/16 12:02:55 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cur_entry;
	t_list	*next_entry;

	if (lst == NULL || del == NULL)
	{
		return ;
	}
	cur_entry = *lst;
	while (cur_entry != NULL)
	{
		del(cur_entry->content);
		next_entry = cur_entry->next;
		free(cur_entry);
		cur_entry = next_entry;
	}
	cur_entry = NULL;
	next_entry = NULL;
	*lst = NULL;
}
