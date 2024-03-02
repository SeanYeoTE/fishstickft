/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:06:36 by seayeo            #+#    #+#             */
/*   Updated: 2024/03/01 20:32:21 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_nodule **here, t_nodule **there)
{
	t_nodule	**start;
	t_nodule	**end;
	t_nodule	*node_to_shift;
	t_nodule	*new_first;
	t_nodule	*first_of_bhead;

	start = here;
	end = there;

	if (start == NULL)
		return (0);
	node_to_shift = *start;
	
	new_first = node_to_shift->next;
	new_first->prev = NULL;
	*here = new_first;

	first_of_bhead = *end;
	*there = node_to_shift;
	
	node_to_shift->next = first_of_bhead;
	first_of_bhead->prev = node_to_shift;
	return (1);
}
