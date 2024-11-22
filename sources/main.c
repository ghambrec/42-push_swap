/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:03:25 by ghambrec          #+#    #+#             */
/*   Updated: 2024/11/22 14:59:50 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew_gha(int content)
{
	t_stack	*new_entry;

	new_entry = (t_stack *)malloc(sizeof(t_stack));
	if (!new_entry)
	{
		return (NULL);
	}
	new_entry->data = content;
	new_entry->next = NULL;
	return (new_entry);
}

int	ft_lstsize_gha(t_stack *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

t_stack	*ft_lstlast_gha(t_stack *lst)
{
	t_stack	*last_entry;

	if (lst == NULL)
	{
		return (NULL);
	}
	last_entry = lst;
	while (last_entry->next != NULL)
	{
		last_entry = last_entry->next;
	}
	return (last_entry);
}

void	ft_lstadd_back_gha(t_stack **lst, t_stack *new)
{
	t_stack	*last_entry;

	if (new == NULL)
	{
		return ;
	}
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last_entry = ft_lstlast_gha(*lst);
	last_entry->next = new;
}

// error handling:
// - no params - return(0) and nothing else
// - Error\n output in case:
//		arg is not an int
//		arg is bigger than an int
//		duplicate values


// parse data and return EXIT_FAILURE if there is a problem with the arguments
int	parse_input_data(int argc, char **argv, t_stack *a)
{
	//go on here: create new function in myLibft atol and use it here to convert the numbers
	//if the converted number not in the int range int_min int_max then return exit_failure
	// what happens if i try to convert a string through the atol function??
}


int	main(int argc, char *argv[])
{
	t_stack	*a;
	int		parsing_result;

	if (argc < 2)
	{
		return (EXIT_FAILURE);
	}
	a = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!a)
	{
		return (EXIT_FAILURE);
	}
	parsing_result = parse_input_data(argc, argv, a);
	if (parsing_result == EXIT_FAILURE)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
	}

	
	// t_stack *b;
	t_stack *temp;
	
	a = ft_lstnew_gha(1);
	temp = ft_lstnew_gha(20);
	ft_lstadd_back_gha(&a, temp);
	temp = ft_lstnew_gha(50);
	ft_lstadd_back_gha(&a, temp);

	printf("LONG_MIN: %ld\n", LONG_MIN);
	printf("LONG_MAX: %ld\n", LONG_MAX);

	printf("%s\n",argv[0]);
	printf("%s\n",argv[1]);
	printf("%s\n",argv[2]);

	temp = a;
	while (temp != NULL)
	{
		printf("%i\n", temp->data);
		temp = temp->next;
	}
	
	return (EXIT_SUCCESS);
}