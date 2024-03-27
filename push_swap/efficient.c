/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   efficient.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:24:30 by seayeo            #+#    #+#             */
/*   Updated: 2024/03/27 12:04:21 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	setweight2(t_nodule **ahead, t_nodule **bhead)
{
	int			largest;
	int			smallest;
	t_nodule	*tempahead;
	int			precount;

	largest = find_largest(bhead);
	smallest = find_smallest(bhead);
	tempahead = (*ahead);
	precount = 0;
	while (tempahead)
	{
		if (tempahead->value < smallest || tempahead->value > largest)
			tempahead->post = rotatetillbig(bhead);
		else
			tempahead->post = rotateforbetween(bhead, tempahead);
		tempahead->pre = precount;
		tempahead = tempahead->next;
		precount++;
	}
}

int	rotateforbetween(t_nodule **head, t_nodule *tempahead)
{
	t_nodule	*temp;
	int			ans;

	temp = (*head);
	ans = 0;
	while (temp)
	{
		if (temp->value < tempahead->value)
		{
			if (temp->prev == NULL)
			{
				if (get_last(*head)->value > tempahead->value)
					return (ans);
			}
			else
			{
				if (temp->prev->value > tempahead->value)
					return (ans);
			}
		}
		ans++;
		temp = temp->next;
	}
	return (ans);
}

int	rotatetillbig(t_nodule **head)
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
		if (temp->value > num)
		{
			num = temp->value;
			ans = count;
		}
		temp = temp->next;
		count++;
	}
	return (ans);
}
