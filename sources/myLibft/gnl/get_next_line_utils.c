/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:04:12 by ghambrec          #+#    #+#             */
/*   Updated: 2024/11/18 14:52:43 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strdup_gnl(const char *str)
{
	size_t	len;
	size_t	i;
	char	*dup;

	i = 0;
	len = ft_strlen_gnl(str);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
	{
		return (NULL);
	}
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[len] = '\0';
	return (dup);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	char	*res;

	if (!s1)
		return (ft_strdup_gnl(s2));
	len = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	i = 0;
	while (*s1)
	{
		res[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		res[i] = *s2;
		s2++;
		i++;
	}
	return (res);
}

char	*ft_strchr_gnl(const char *str, int c)
{
	char	ch;

	ch = (char)c;
	while (*str != '\0')
	{
		if (*str == ch)
		{
			return ((char *)str);
		}
		str++;
	}
	if (ch == '\0')
	{
		return ((char *)str);
	}
	return (NULL);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen_gnl(src);
	if (dstsize != 0)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}
