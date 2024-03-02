/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:26:17 by seayeo            #+#    #+#             */
/*   Updated: 2024/03/01 15:56:23 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nodule    **brain(t_nodule **head, t_nodule **bhead, int total)
{
	t_nodule	*firsthalf;
	int			count;
	t_nodule	*secondhalf;
	
	count = 0;
	firsthalf = *head;

	// simple insertion sort first;
	while (count < total)
	{
		if (firsthalf->value > find_largest(head)/2)
		{
			// i have issues with this, maybe implement a struct for pointer access
			head, bhead = push(head, bhead);
			ft_printf("pb");
			count++;
		}
	}
	firsthalf = *head;
	firsthalf = insertionsort(firsthalf);
	secondhalf = *bhead;
	secondhalf = insertionsort(secondhalf);
	head = stackjoiner(firsthalf, secondhalf);
}

t_nodule	**insertionsort(t_nodule *start)
{
	t_nodule	*compare;

	while (start->next != NULL)
	{
		compare = start->next;
		if (start->value > compare->value)
		{
			start = swap(start);
			ft_printf("sa\n");
		}
		else
			start = compare;
	}
}