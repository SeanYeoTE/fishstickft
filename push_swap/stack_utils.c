/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:39:56 by seayeo            #+#    #+#             */
/*   Updated: 2024/03/22 17:18:56 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_node(int value, t_nodule **head)
{
	t_nodule	*new_node;
	t_nodule	*prev_node;

	new_node = malloc(sizeof(t_nodule));
	if (!new_node)
		return (-1);
	new_node->next = NULL;
	new_node->value = value;
	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
	}
	else
	{
		prev_node = get_last(*head);
		prev_node->next = new_node;
		new_node->prev = prev_node;
	}
	return (0);
}

void	init_stack(int argc, char *argv[], t_nodule **head)
{
	int			count;
	long		value;
	int			customs;

	customs = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		customs = 1;
	}
	count = 0;
	value = 0;
	while (argv[++count])
	{
		// if (check_tabs(argv[count]) == 1)
		// 	print_error(head, argv, 0);
		value = ft_atol(argv[count]);
		if (value > INT_MAX || value < INT_MIN)
			print_error(head, argv, customs);
		init_node((int)value, head);
		if (check_duplicate(head) == 1)
			print_error(head, argv, customs);
	}
	if (customs == 1)
		free_matrix(argv);
	return (customs);
}

t_nodule	*get_last(t_nodule *last)
{
	while (last->next != NULL)
		last = last->next;
	return (last);
}

int	find_largest(t_nodule **head)
{
	t_nodule	*start;
	int			ans;

	start = *head;
	ans = start->value;
	while (start)
	{
		if (start->value > ans)
			ans = start->value;
		start = start->next;
	}
	return (ans);
}

int	find_smallest(t_nodule **head)
{
	t_nodule	*temp;
	int			ans;

	temp = (*head);
	ans = temp->value;
	while (temp)
	{
		if (temp->value < ans)
			ans = temp->value;
		temp = temp->next;
	}
	return (ans);
}
