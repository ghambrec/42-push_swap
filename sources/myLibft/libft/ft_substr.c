/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:02:20 by ghambrec          #+#    #+#             */
/*   Updated: 2024/10/15 18:34:27 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_len_substr(size_t strlen, size_t start, size_t len)
{
	size_t	substrlen;

	if (start >= strlen)
	{
		return (0);
	}
	if (len < strlen - start)
	{
		substrlen = len;
	}
	else
	{
		substrlen = strlen - start;
	}
	return (substrlen);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	strlen;
	size_t	substrlen;
	size_t	i;
	char	*substr;

	if (!str)
		return (NULL);
	strlen = ft_strlen(str);
	substrlen = calc_len_substr(strlen, start, len);
	substr = (char *)malloc((substrlen + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	if (start >= strlen)
	{
		substr[0] = '\0';
		return (substr);
	}
	i = 0;
	while (i < substrlen && str[start])
	{
		substr[i] = str[start];
		start++;
		i++;
	}
	return (substr[i] = '\0', substr);
}
