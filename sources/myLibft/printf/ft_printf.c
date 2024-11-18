/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:43:55 by ghambrec          #+#    #+#             */
/*   Updated: 2024/11/18 15:14:08 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_conversion(char conversion, va_list args)
{
	if (conversion == '%')
		return (ft_putchar_printf('%'));
	else if (conversion == 'c')
		return (ft_putchar_printf(va_arg(args, int)));
	else if (conversion == 's')
		return (ft_print_str_printf(va_arg(args, char *)));
	else if (conversion == 'p')
		return (ft_print_voidptr_printf(va_arg(args, unsigned long long)));
	else if (conversion == 'd' || conversion == 'i')
		return (ft_print_nbr_printf(va_arg(args, int)));
	else if (conversion == 'u')
		return (ft_print_unsigned_nbr_printf(va_arg(args, unsigned int)));
	else if (conversion == 'x')
		return (ft_print_hex_nbr_pf(va_arg(args, unsigned long long), 0, 0));
	else if (conversion == 'X')
		return (ft_print_hex_nbr_pf(va_arg(args, unsigned long long), 1, 0));
	else
		return (-1);
}

int	ft_printf(const char *inputstr, ...)
{
	int		res;
	int		len;
	va_list	args;

	va_start(args, inputstr);
	len = 0;
	while (*inputstr)
	{
		if (*inputstr == '%' && ft_strchr_printf("cspdiuxX%", *(inputstr + 1)))
		{
			inputstr++;
			res = ft_print_conversion(*inputstr, args);
			if (res == -1)
				return (va_end(args), -1);
			len += res;
		}
		else
		{
			if (ft_putchar_printf(*inputstr) == -1)
				return (va_end(args), -1);
			len++;
		}
		inputstr++;
	}
	return (va_end(args), len);
}
