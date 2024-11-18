/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:10:03 by ghambrec          #+#    #+#             */
/*   Updated: 2024/10/14 22:33:44 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;

	if (!*s1)
	{
		return (ft_calloc(1, sizeof(char)));
	}
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
	{
		start++;
	}
	end = ft_strlen(s1) - 1;
	while (s1[end] && ft_strrchr(set, s1[end]))
	{
		end--;
	}
	len = end - start + 1;
	return (ft_substr(s1, start, len));
}
