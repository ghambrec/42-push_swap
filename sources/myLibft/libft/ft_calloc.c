/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:40:22 by ghambrec          #+#    #+#             */
/*   Updated: 2024/10/10 15:14:20 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*memory;

	memory = NULL;
	memory = (void *)malloc(count * size);
	if (memory != NULL)
	{
		ft_memset(memory, 0, count * size);
	}
	return (memory);
}
