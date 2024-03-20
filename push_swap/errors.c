/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:27:24 by seayeo            #+#    #+#             */
/*   Updated: 2024/03/18 16:47:34 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_error(t_nodule **a, char *argv[], int num)
{
	free_matrix(argv);
	
	if (num == 0)
		free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}

int check_duplicate(t_nodule **head)
{
	t_nodule	*temp;
	t_nodule	*check;

	temp = *head;
	check = *head;
	while (temp)
	{
		while (check)
		{
			if (temp->value == check->value)
			{
				return (1);
			}
			check = check->next;
		}
		temp = temp->next;
	}
	return (0);
}

int	check_tabs(char *argv)
{
	if ((*argv == '+' || *argv == '-') && !(*argv >= '0' && *argv <= '9'))
		return (1);
	while (*argv)
	{
		if (!(*argv >= '0' && *argv <= '9'))
			return (1);
		argv++;
	}
	return (0);
}

/*
 * Ad hoc function to free the 2D array
 * created with the ft_split function
 * ATTENTION
 * You have to start from -1 
*/
void	free_matrix(char **argv)
{
	int	i;

	i = -1;
	if (NULL == argv || NULL == *argv)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv + 0);
}

/*
 * Ad hoc function to free a stack
*/
void	free_stack(t_nodule **stack)
{
	t_nodule	*tmp;
	t_nodule	*current;

	if (NULL == stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}