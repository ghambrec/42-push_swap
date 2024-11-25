/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:07:44 by ghambrec          #+#    #+#             */
/*   Updated: 2024/11/25 17:02:55 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../sources/myLibft/include/my_libft.h"
# include <stdio.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

// PARSING
int		start_parsing(int argc, char **argv, t_stack **a);

// LIST OPERATIONS
t_stack	*ft_lstnew_ps(int content);
t_stack	*ft_lstlast_ps(t_stack *lst);
void	ft_lstadd_back_ps(t_stack **lst, t_stack *new);
int		ft_lstsize_ps(t_stack *lst);

#endif