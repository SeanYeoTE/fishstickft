/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:06:36 by seayeo            #+#    #+#             */
/*   Updated: 2024/02/27 17:32:17 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nodule	**push(t_nodule **head, t_nodule **bhead)
{
	t_nodule	**start;
	t_nodule	**end;
	t_nodule	*node_to_shift;
	t_nodule	*new_first;
	t_nodule	*first_of_bhead;

	start = head;
	end = bhead;

	if (start == NULL)
		return (head, bhead);
	node_to_shift = *start;
	
	new_first = node_to_shift->next;
	new_first->prev = NULL;
	*head = new_first;

	*end = first_of_bhead;
	*bhead = node_to_shift;
	
	node_to_shift->next = first_of_bhead;
	first_of_bhead->prev = node_to_shift;
	return (head, bhead);
}
