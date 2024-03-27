/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:27:24 by seayeo            #+#    #+#             */
/*   Updated: 2024/03/27 12:26:37 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(t_nodule **a, char *argv[], int num)
{
	free_stack(a);
	if (num == 1)
		free_matrix(argv);
	write(2, "Error\n", 6);
	exit(1);
}

int	check_duplicate(t_nodule **head)
{
	t_nodule	*temp;
	t_nodule	*check;
	int			counter;

	temp = *head;
	while (temp)
	{
		check = *head;
		counter = 0;
		while (check)
		{
			if (temp->value == check->value)
			{
				counter++;
			}
			check = check->next;
		}
		if (counter > 1)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	check_symbols(char *argv)
{
	if ((*argv == '+' || *argv == '-') && !(*argv >= '0' && *argv <= '9'))
		argv++;
	while (*argv)
	{
		if (!(*argv >= '0' && *argv <= '9'))
			return (1);
		argv++;
	}
	return (0);
}

void	free_matrix(char **argv)
{
	char	**temp;

	if (!argv)
		return ;
	temp = argv;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(argv);
}

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
