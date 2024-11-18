/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:23:46 by ghambrec          #+#    #+#             */
/*   Updated: 2024/10/15 12:16:46 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	len;
	char	ch;

	len = ft_strlen(str);
	ch = (char)c;
	if (ch == '\0')
	{
		return (&((char *)str)[len]);
	}
	while (len > 0)
	{
		len--;
		if (str[len] == ch)
		{
			return (&((char *)str)[len]);
		}
	}
	return (NULL);
}
