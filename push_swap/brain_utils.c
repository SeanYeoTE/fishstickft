/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:22:44 by seayeo            #+#    #+#             */
/*   Updated: 2024/03/19 13:06:54 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	getlength(t_nodule **ahead)
{
	int			count;
	t_nodule	*temp;

	count = 0;
	temp = *ahead;
	while (temp->next)
	{
		count++;
		temp = temp->next;
	}
	return (count + 1);
}

int	checkifsorted(t_nodule **ahead)
{
	t_nodule	*temp;

	temp = *ahead;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (-1);
		temp = temp->next;
	}
	return (0);
}

void	resetweights(t_nodule **head)
{
	t_nodule	*temp;
	
	temp = (*head);
	while (temp)
	{
		temp->pre = 0;
		temp->post = 0;
		temp->doble = 0;
		temp = temp->next;
	}
}
