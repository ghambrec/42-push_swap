/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:46:18 by ghambrec          #+#    #+#             */
/*   Updated: 2024/11/18 15:13:12 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_putchar_printf(char c);
int		ft_putnbr_printf(int n);
int		ft_putstr_printf(char *s);
size_t	ft_strlen_printf(const char *str);
char	*ft_strchr_printf(const char *str, int c);

int		ft_printf(const char *inputstring, ...);
int		ft_print_str_printf(char *str);
int		ft_print_nbr_printf(int n);
int		ft_print_unsigned_nbr_printf(unsigned long n);
int		ft_print_voidptr_printf(unsigned long long ptr);
int		ft_print_hex_nbr_pf(unsigned int n, int upper, int initlen);

#endif