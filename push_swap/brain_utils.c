/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:22:44 by seayeo            #+#    #+#             */
/*   Updated: 2024/03/25 15:55:39 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotatetillsmall(t_nodule **head)
{
	t_nodule	*temp;
	int			num;
	int			count;
	int			ans;

	temp = (*head);
	num = temp->value;
	count = 0;
	ans = 0;
	while (temp)
	{
		if (temp->value < num)
		{
			num = temp->value;
			ans = count;
		}
		temp = temp->next;
		count++;
	}
	return (ans);
}

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
