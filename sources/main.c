/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:03:25 by ghambrec          #+#    #+#             */
/*   Updated: 2024/11/24 20:08:08 by ghambrec         ###   ########.fr       */
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



static int	is_number(char *str)
{
	if (ft_strchr("+-", *str))
	{
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

static int	check_duplicate(int num, t_stack *a)
{
	while (a != NULL)
	{
		if (a->data == num)
		{
			return (EXIT_FAILURE);
		}
		a = a->next;
	}
	return (EXIT_SUCCESS);
}

static int	parse_input_data(char **data, t_stack *a)
{
	int		i;
	long	current_num;

	i = 0;
	while (data[i])
	{
		if (!is_number(data[i]))
		{
			return (EXIT_FAILURE);
		}
		current_num = ft_atol(data[i]);
		if (current_num < INT_MIN || current_num > INT_MAX)
		{
			return (EXIT_FAILURE);
		}
		if (check_duplicate(current_num, a) == EXIT_FAILURE)
		{
			return (EXIT_FAILURE);
		}
		// malloc space for t_stack and add the number to the t_stack
		// linked list pointer explanation >>>>TODO<<<<
		
		// printf("%s\n",data[i]);
		i++;
	}

	return (EXIT_SUCCESS);
}

// parse data and return EXIT_FAILURE if there is a problem with the arguments
// possible outputs: EXIT_FAILURE (1) || EXIT_SUCCESS (0)
int	start_parsing(int argc, char **argv, t_stack *a)
{
	//go on here: create new function in myLibft atol and use it here to convert the numbers
	//if the converted number not in the int range int_min int_max then return exit_failure
	// what happens if i try to convert a string through the atol function?? >>>> retur = 0 >>>> darf nur atol anwenden
	//   wenn zahl auch eine zahl ist


	
	if (argc == 2)
	{
		// call ft_split and with this result parse, after that free ft_split result
	}
	if (argc > 2)
	{
		// argv+1 weitergeben zum parsen
		return(parse_input_data(argv + 1, a));
	}



	return (5);
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
	parsing_result = start_parsing(argc, argv, a);
	if (parsing_result == EXIT_FAILURE)
	{
		// free a-stack and all what is in there
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return(EXIT_FAILURE);
	}
	
	
	t_stack *temp;
	// // to testing
	// temp = a;
	// temp->data = NULL;
	// while (temp != NULL)
	// {
	// 	printf("%i\n", temp->data);
	// 	temp = temp->next;
	// }
	return (0);
	

	

	
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


	return (EXIT_SUCCESS);
}