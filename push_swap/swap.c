/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:24:12 by seayeo            #+#    #+#             */
/*   Updated: 2024/02/27 17:10:45 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nodule	**swap(t_nodule **head)
{
	if (head == NULL || (*head)->next == NULL)
		return (head);
	t_nodule	*first;
	t_nodule	*second;

	first = *head;
	second = first->next;

	*head = second;
	second->prev = NULL;
	second->next = first;
	first->next = NULL;
	first->prev = second;
	return (head);
}
