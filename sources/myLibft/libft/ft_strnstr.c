/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:09:57 by ghambrec          #+#    #+#             */
/*   Updated: 2024/10/14 12:40:26 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *ndl, size_t len)
{
	size_t	ih;
	size_t	in;

	ih = 0;
	if (!ndl[0])
	{
		return ((char *)hay);
	}
	while (hay[ih] && ih < len)
	{
		in = 0;
		while (hay[ih + in] == ndl[in] && ndl[in] != '\0' && ih + in < len)
		{
			in++;
			if (!ndl[in])
			{
				return (&((char *)hay)[ih]);
			}
		}
		ih++;
	}
	return (NULL);
}
