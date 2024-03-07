/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:24:12 by seayeo            #+#    #+#             */
/*   Updated: 2024/03/04 18:02:09 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_nodule **head)
{
	if (head == NULL || (*head)->next == NULL)
		return ;
	t_nodule	*first;
	t_nodule	*second;

	first = *head;
	second = first->next;

	// *head = (*head)->next;
	*head = second;
	second->prev = NULL;
	first->next = second->next;
	second->next = first;
	first->prev = second;
}

void	sa(t_nodule **head)
{
	swap(head);
	ft_printf("sa\n");
}

void	sb(t_nodule **head)
{
	swap(head);
	ft_printf("sb\n");
}

void	ss(t_nodule **ahead, t_nodule **bhead)
{
	swap(ahead);
	swap(bhead);
	ft_printf("ss\n");
}