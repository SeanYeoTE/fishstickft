/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:39:56 by seayeo            #+#    #+#             */
/*   Updated: 2024/02/27 17:11:01 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nodule	**init_node(int value, t_nodule ** head)
{
	t_nodule	* new_node;
	t_nodule	* prev_node;


	if (head == NULL)
		{
			new_node = malloc(sizeof(t_nodule));
			new_node->next = NULL;
			new_node->value = value;
			new_node->prev = NULL;
		}
	else
		{
			prev_node = *head;
			
			new_node = malloc(sizeof(t_nodule));
			prev_node->prev = new_node;
			
			new_node->next = prev_node;
			new_node->value = value;
			new_node->prev = NULL;
		}
	*head = new_node;
	return (head);
}

t_nodule	**init_stack(int argc, char *argv[], t_nodule ** head)
{
	if (argc == 2)
		argv = ft_split(argv[1], ' ');

	int			count;
	int			value;
	
	count = 0;
	value = 0;
	head = NULL;
	while (count++ < argc)
	{
		value = atoi(argv[count]);
		head = init_node(value, head);
	}
	return (head);
}
