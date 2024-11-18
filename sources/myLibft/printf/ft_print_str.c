/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:32:59 by ghambrec          #+#    #+#             */
/*   Updated: 2024/11/18 15:05:59 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str_printf(char *str)
{
	if (!str)
	{
		return (ft_putstr_printf("(null)"));
	}
	return (ft_putstr_printf(str));
}
