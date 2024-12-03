/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghamnbrec <ghambrec@student.42heilbronn    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:07:44 by ghambrec          #+#    #+#             */
/*   Updated: 2024/12/03 14:23:09 by ghamnbrec        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../sources/myLibft/include/my_libft.h"
# include <stdio.h>
# include <limits.h>
# include <stdlib.h> // for testing

# define TRUE 1
# define FALSE 0

// THE STACK
typedef struct s_stack
{
	int				data;
	int				index; // calc above median over this
	int				push_cost; // calc cheapest node over this
	int				above_median;
	char			name; // a or b
	struct s_stack	*target; // target node from the other stack
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
void	free_stack(t_stack **stack);

// PUSH-SWAP LANGUAGE
void	swap(t_stack *stack, char stack_name);
void	swap_both(t_stack *a, t_stack *b, int print);
void	push(t_stack **src, t_stack **dest, char stack_name);
void	rotate(t_stack **stack, char stack_name);
void	rotate_both(t_stack **a, t_stack **b, int print);
void	reverse_rotate(t_stack **stack, char stack_name);
void	reverse_rotate_both(t_stack **a, t_stack **b, int print);

// SORTING
void	sort_max_3(t_stack **a);
void	sort(t_stack **a, t_stack **b);
int		check_is_sorted(t_stack *a);

// INITIALIZATION
void	init_stack(t_stack *from, t_stack *to, char name_from, char name_to);
void	init_stack_basics(t_stack *stack, char stack_name);

// LIST GET FUNCTIONS
int		get_stack_size(t_stack *stack);
t_stack *get_max(t_stack *stack);
t_stack *get_min(t_stack *stack);
t_stack	*get_cheapest_node(t_stack *stack);

#endif