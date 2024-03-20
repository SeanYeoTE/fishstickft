/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:42:03 by seayeo            #+#    #+#             */
/*   Updated: 2024/03/15 18:34:11 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_nodule **stack)
{
	t_nodule	*first;
	t_nodule	*second;
	t_nodule	*last;
	
	first = *stack;
	last = get_last(*stack);
	second = first->next;
	second->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	*stack = second;
}

void	reverse_rotate(t_nodule **stack)
{
	t_nodule	*first;
	t_nodule	*secondlast;
	t_nodule	*last;

	first = *stack;
	last = get_last(*stack);
	secondlast = last->prev;
	last->next = first;
	first->prev = last;
	last->prev = NULL;
	secondlast->next = NULL;
	*stack = last;
}

void	rr(t_nodule **ahead, t_nodule **bhead)
{
	rotate(ahead);
	rotate(bhead);
	ft_printf("rr\n");
}

void	rrr(t_nodule **ahead, t_nodule **bhead)
{
	reverse_rotate(ahead);
	reverse_rotate(bhead);
	ft_printf("rrr\n");
}
