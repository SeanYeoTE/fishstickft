/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   efficient.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:24:30 by seayeo            #+#    #+#             */
/*   Updated: 2024/03/20 16:58:44 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// something like midpoint theorem, if past midpoint of stack, use reverse rotate instead of rotate

/* fk me i need to check both stacks for efficiency of rotates and compare if both stacks can use the
same double rotates. 
i think check for double rotates and calculate total
then check for reverse rotate efficiency */
void	checkrr(t_nodule **ahead)
{
	t_nodule	*temp;

	temp = *ahead;
	while (temp)
	{
		if (temp->pre > 0 && temp->post > 0 )
		{
			if (temp->pre >= temp->post)
			{
				temp->doble  = temp->post;
				temp->pre -= temp->doble;
				temp->post = 0;
			}
			else if (temp->pre < temp->post)
			{
				temp->doble = temp->pre;
				temp->post -= temp->doble;
				temp->pre = 0;
			}
		}
		else if (temp->pre < 0 && temp->post < 0)
		{
			if (temp->pre >= temp->post)
			{
				temp->doble  = temp->pre;
				temp->post -= temp->doble;
				temp->pre = 0;
			}
			else if (temp->pre < temp->post)
			{
				temp->doble = temp->post;
				temp->pre -= temp->doble;
				temp->post = 0;
			}
		}
		temp = temp->next;
	}
}

void	setweight2(t_nodule **ahead, t_nodule **bhead)
{
	int	largest;
	int smallest;
	t_nodule	*tempahead;
	int	precount;

	largest = find_largest(bhead);
	smallest = find_smallest(bhead);
	tempahead = (*ahead);
	precount = 0;
	while (tempahead)
	{
		if (tempahead->value < smallest || tempahead->value > largest)
			// count rotates till largest is at the top
			tempahead->post = rotatetillbig(bhead);
		else
		{
			tempahead->post = rotateforbetween(bhead, tempahead);
			// rotate till tempahead->value < num, check that last value of stack > num;
		}
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
	int 		num;
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
