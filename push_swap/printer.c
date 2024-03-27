/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:19:43 by seayeo            #+#    #+#             */
/*   Updated: 2024/03/26 13:49:27 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int print_full(t_nodule **head, char c)
{
	t_nodule	*start;
	int			count;

	count = 1;
	start = *head;
	ft_printf("STACK: %c\n", c);
	while (start)
	{
		// ft_printf("Node Counter: %d\n", count);
		ft_printf("Node Value: %d\n", start->value);
		ft_printf("Node Post: %d\n", start->post);
		ft_printf("Node Pre: %d\n", start->pre);
		ft_printf("Node Doble: %d\n", start->doble);
		// if (start->prev == NULL)
		//     ft_printf("Node Prev: %s\n", start->prev);
		// else
		//     ft_printf("Node Prev: %d\n", start->prev->value);
		// if (start->next == NULL)
		//     ft_printf("Node Next: %s\n", start->next);
		// else
		//     ft_printf("Node Next: %d\n", start->next->value);
		ft_printf("***************\n\n");
		start = start->next;
		count++;
	}
	ft_printf("Total Nodes: %d\n", count);
	return (0);
}

int print_stack(t_nodule **head, char c)
{
	t_nodule	*start;
	int		count;

	count = 0;
	start = *head;
	ft_printf("STACK: %c\n", c);
	while (start)
	{
		// ft_printf("Node Counter: %d\n", count);
		ft_printf("Node Value: %d\n", start->value);
		ft_printf("***************\n");
		start = start->next;
		count++;
	}
	ft_printf("Total Nodes: %d\n", count);
	return (0);
}

int print_short(t_nodule **head)
{
	t_nodule	*start;

	start = *head;
	ft_printf("Stack\n");
	while (start)
	{
		ft_printf("%d\n", start->value);
		start = start->next;
	}
	return (0);
}
