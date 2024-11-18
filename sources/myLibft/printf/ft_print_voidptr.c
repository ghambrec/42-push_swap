/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_voidptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:49:54 by ghambrec          #+#    #+#             */
/*   Updated: 2024/11/18 15:07:51 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_voidptr_printf(unsigned long long ptr, int len)
{
	char	*hex;
	int		res;

	res = 0;
	hex = "0123456789abcdef";
	if (ptr >= 16)
	{
		len = ft_put_voidptr_printf(ptr / 16, len);
		if (len == -1)
			return (-1);
	}
	res = ft_putchar_printf(hex[ptr % 16]);
	if (res == -1)
		return (-1);
	len += res;
	return (len);
}

int	ft_print_voidptr_printf(unsigned long long ptr)
{
	int	len;
	int	res;

	len = ft_putstr_printf("0x");
	if (len == -1)
		return (-1);
	if (ptr == 0)
	{
		res = ft_putchar_printf('0');
		if (res == -1)
			return (-1);
		return (len + res);
	}
	res = ft_put_voidptr_printf(ptr, 0);
	if (res == -1)
		return (-1);
	len += res;
	return (len);
}
