/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:24:03 by ghambrec          #+#    #+#             */
/*   Updated: 2024/12/04 13:41:05 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	is_number(char *str)
{
	if (!*str)
	{
		return (FALSE);
	}
	if (ft_strchr("+-", *str))
	{
		str++;
		if (!*str)
		{
			return (FALSE);
		}
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			return (FALSE);
		}
		str++;
	}
	return (TRUE);
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

// error handling:
//		argument is not a number
//		argument is out of int range
//		duplicate values
// add numbers to the a-stack
static int	parse_input_data(char **data, t_stack **a)
{
	int		i;
	long	current_num;
	t_stack	*created_list;

	i = 0;
	while (data[i])
	{
		if (!is_number(data[i]))
			return (EXIT_FAILURE);
		current_num = ft_atol(data[i]);
		if (current_num < INT_MIN || current_num > INT_MAX)
			return (EXIT_FAILURE);
		if (check_duplicate(current_num, *a) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		created_list = ft_lstnew_ps(current_num);
		if (!created_list)
			return (EXIT_FAILURE);
		if (*a == NULL)
			*a = created_list;
		else
			ft_lstadd_back_ps(a, created_list);
		i++;
	}
	return (EXIT_SUCCESS);
}

// possible outputs:
//		EXIT_SUCCESS (0)
// 		EXIT_FAILURE (1)
int	start_parsing(int argc, char **argv, t_stack **a)
{
	int		parsing_result;
	char	**split;

	if (argc < 2)
	{
		return (EXIT_FAILURE);
	}
	if (argc == 2 && ft_strlen(argv[1]) > 0)
	{
		split = ft_split(argv[1], ' ');
		if (split == NULL)
		{
			return (EXIT_FAILURE);
		}
		parsing_result = parse_input_data(split, a);
		free_split(split);
		return (parsing_result);
	}
	if (argc > 2)
	{
		parsing_result = parse_input_data(argv + 1, a);
		return (parsing_result);
	}
	return (EXIT_FAILURE);
}
