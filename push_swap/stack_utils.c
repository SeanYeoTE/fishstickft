/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:39:56 by seayeo            #+#    #+#             */
/*   Updated: 2024/03/03 00:44:45 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_node(int value, t_nodule ** head)
{
	t_nodule	* new_node;
	t_nodule	* prev_node;

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

int	init_stack(int argc, char *argv[], t_nodule ** head)
{
	int			count;
	int			value;
	
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
	}
	count = 0;
	value = 0;
	while (argv[++count])
	{
		value = atoi(argv[count]);
		init_node(value, head);
	}
	return (0);
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

	ans = 0;
	start = *head;
	while (start->next != NULL)
	{
		if (start->value > ans)
			ans = start->value;
		start = start->next;
	}
	return (ans);
}
