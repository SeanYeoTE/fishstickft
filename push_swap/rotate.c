/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:42:03 by seayeo            #+#    #+#             */
/*   Updated: 2024/03/01 20:32:50 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nodule	**rotate(t_nodule **stack)
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
	last->prev = NULL;
	last->next = first;
	*stack = second;
	return (stack); 
}

t_nodule	**reverse_rotate(t_nodule **stack)
{
	t_nodule	*first;
	t_nodule	*secondlast;
	t_nodule	*last;

	first = *stack;
	last = get_last(*stack);
	secondlast = last->prev;
	last->next = first;
	last->prev = NULL;
	first->prev = last;
	secondlast->next = NULL;
	*stack = last;
	return (stack);
}