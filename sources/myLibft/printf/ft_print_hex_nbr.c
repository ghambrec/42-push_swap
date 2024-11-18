/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_nbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:06:06 by ghambrec          #+#    #+#             */
/*   Updated: 2024/11/18 15:12:42 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_nbr_pf(unsigned int n, int upper, int initlen)
{
	char		*hex;
	static int	len = 0;

	len = initlen;
	if (upper == 1)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n >= 16)
	{
		if (ft_print_hex_nbr_pf(n / 16, upper, len) == -1)
			return (-1);
	}
	if (ft_putchar_printf(hex[n % 16]) == -1)
		return (-1);
	len += 1;
	return (len);
}
