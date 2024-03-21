/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:06:36 by seayeo            #+#    #+#             */
/*   Updated: 2024/03/21 17:19:18 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* apparently assigning pointer to a dereferenced pointer 
to null causes seg fault
thus need to handle second stack being empty seperately */
void	push(t_nodule **here, t_nodule **there)
{
	t_nodule	*node_to_shift;
	t_nodule	*first_of_bhead;

	if (here == NULL)
		return ;
	node_to_shift = *here;
	*here = (*here)->next;
	if (*here)
		(*here)->prev = NULL;
	node_to_shift->prev = NULL;
	if (*there == NULL)
	{
		*there = node_to_shift;
		node_to_shift->next = NULL;
	}
	else
	{
		first_of_bhead = *there;
		*there = node_to_shift;
		node_to_shift->next = first_of_bhead;
		first_of_bhead->prev = node_to_shift;
	}
}

void	pa(t_nodule **bhead, t_nodule **ahead)
{
	push(bhead, ahead);
	ft_printf("pa\n");
}

void	pb(t_nodule **ahead, t_nodule **bhead)
{
	push(ahead, bhead);
	ft_printf("pb\n");
}
