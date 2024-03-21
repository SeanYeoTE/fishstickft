/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:24:12 by seayeo            #+#    #+#             */
/*   Updated: 2024/03/21 17:18:29 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_nodule **head)
{
	t_nodule	*first;
	t_nodule	*second;

	if (head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	second = first->next;
	if (second->next != NULL)
	{
		(second->next)->prev = first;
		first->next = second->next;
	}
	else
		first->next = NULL;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*head = second;
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
