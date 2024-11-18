/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:45:23 by ghambrec          #+#    #+#             */
/*   Updated: 2024/11/18 15:04:13 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_printf(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

int	ft_putchar_printf(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr_printf(int n)
{
	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		return (0);
	}
	if (n < 0)
	{
		if (ft_putchar_printf('-') == -1)
			return (-1);
		n = n * -1;
	}
	if (n >= 10)
	{
		if (ft_putnbr_printf(n / 10) == -1)
			return (-1);
	}
	if (ft_putchar_printf(n % 10 + '0') == -1)
		return (-1);
	return (0);
}

int	ft_putstr_printf(char *s)
{
	int	len;

	len = ft_strlen_printf(s);
	while (*s != '\0')
	{
		if (ft_putchar_printf(*s) == -1)
			return (-1);
		s++;
	}
	return (len);
}

char	*ft_strchr_printf(const char *str, int c)
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
