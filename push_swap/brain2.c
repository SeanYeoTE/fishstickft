/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:21:15 by seayeo            #+#    #+#             */
/*   Updated: 2024/03/25 15:59:45 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bigger_stack(t_nodule **ahead, t_nodule **bhead)
{
	int order;
	
	order = rotatetillbig(bhead);
	while (order--)
		rb(bhead);
	while (*bhead)
	{
		resetweights(bhead);
		setweight3(bhead, ahead);
		checkefficient2(bhead, ahead);
		// checkrr(bhead);
		executemission2(bhead, ahead);
	}
	order = rotatetillsmall(ahead);
	while (order--)
		ra(ahead);
}

void	checkefficient2(t_nodule **bhead, t_nodule **ahead)
{
	int			stack_len_a;
	int			stack_len_b;
	t_nodule	*btemp;

	stack_len_a = getlength(ahead);
	stack_len_b = getlength(bhead);
	btemp = *bhead;
	stack_len_a = stack_len_a / 2;
	stack_len_b = stack_len_b / 2;
	while (btemp)
	{
		if (btemp->pre > stack_len_a)
			btemp->pre = btemp->pre - getlength(ahead);
		if (btemp->post > stack_len_b)
			btemp->post = btemp->post - getlength(bhead);
		btemp = btemp->next;
	}
}

void	executemission2(t_nodule **ahead, t_nodule **bhead)
{
	int			lowestmoves;
	t_nodule	*temp;
	t_nodule	*currentlowest;
	int			check;

	check = 0;
	lowestmoves = 1000;
	temp = (*ahead);
	while (temp)
	{
		check = abs(temp->pre) + abs(temp->post) + abs(temp->doble);
		if (check < lowestmoves)
		{
			lowestmoves = check;
			currentlowest = temp;
		}
		temp = temp->next;
	}
	trigger(bhead, ahead, currentlowest);
	pa(ahead, bhead);
}

void	setweight3(t_nodule **src, t_nodule **dest)
{
	int			largest;
	int			smallest;
	t_nodule	*tempahead;
	int			postcount;

	largest = find_largest(dest);
	smallest = find_smallest(dest);
	tempahead = (*src);
	postcount = 0;
	while (tempahead)
	{
		if (tempahead->value < smallest || tempahead->value > largest)
			// count rotates till largest is at the top
			tempahead->pre = rotatetillsmall(dest);
		else
		{
			tempahead->pre = rotateforbetween2(dest, tempahead);
			// rotate till tempahead->value < num, check last value of stack > num;
		}
		tempahead->post = postcount;
		tempahead = tempahead->next;
		postcount++;
	}
}

int	rotateforbetween2(t_nodule **head, t_nodule *tempahead)
{
	t_nodule	*temp;
	int			ans;

	temp = (*head);
	ans = 0;
	while (temp)
	{
		if (temp->value > tempahead->value)
		{
			if (temp->prev == NULL)
			{
				if (get_last(*head)->value < tempahead->value)
					return (ans);
			}
			else
			{
				if (temp->prev->value < tempahead->value)
					return (ans);
			}
		}
		ans++;
		temp = temp->next;
	}
	return (ans);
}
