/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:07:44 by ghambrec          #+#    #+#             */
/*   Updated: 2024/11/25 18:45:01 by ghambrec         ###   ########.fr       */
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
void	ft_lstadd_front_ps(t_stack **lst, t_stack *new);

// PUSH-SWAP LANGUAGE
void	swap(t_stack *stack);
void	swap_both(t_stack *a, t_stack *b);
void	push(t_stack **src, t_stack **dest);
void	rotate(t_stack **stack);
void	rotate_both(t_stack **a, t_stack **b);
void	reverse_rotate(t_stack **stack);
void	reverse_rotate_both(t_stack **a, t_stack **b);

#endif