/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:07:44 by ghambrec          #+#    #+#             */
/*   Updated: 2024/11/22 14:54:47 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../sources/myLibft/include/my_libft.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

#endif