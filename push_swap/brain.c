/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:26:17 by seayeo            #+#    #+#             */
/*   Updated: 2024/03/28 14:00:14 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	brain(t_nodule **ahead, t_nodule **bhead)
{
	int	second;
	int	max;

	second = 0;
	max = 2;
	if (checkifsorted(ahead) == 0)
		return ;
	if (getlength(ahead) > 3 && max != 0)
	{
		pb(ahead, bhead);
		second = 1;
		max--;
	}
	while (getlength(ahead) > 3)
	{
		resetweights(ahead);
		setweight2(ahead, bhead);
		checkefficient(ahead, bhead);
		executemission(ahead, bhead);
		second = 1;
	}
	simple_sort(ahead);
	if (second == 1)
		bigger_stack(ahead, bhead);
}

/* apparently so we have a possibility of normal rotates on 
1 side and reverse rotates on the other
so efficiency checker needs to determine individually if pre
 and post rotates are better positive/negative

then checkrr only fills in for double rotates if calculated 
pre and post rotates are same signed. */

void	checkefficient(t_nodule **ahead, t_nodule **bhead)
{
	int			stack_len_a;
	int			stack_len_b;
	t_nodule	*atemp;

	stack_len_a = getlength(ahead);
	stack_len_b = getlength(bhead);
	atemp = *ahead;
	stack_len_a = stack_len_a / 2;
	stack_len_b = stack_len_b / 2;
	while (atemp)
	{
		if (atemp->pre > stack_len_a)
			atemp->pre = atemp->pre - getlength(ahead);
		if (atemp->post > stack_len_b)
			atemp->post = atemp->post - getlength(bhead);
		atemp = atemp->next;
	}
}

void	executemission(t_nodule **ahead, t_nodule **bhead)
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
	trigger(ahead, bhead, currentlowest);
	pb(ahead, bhead);
}

void	trigger(t_nodule **ahead, t_nodule **bhead, t_nodule *temp)
{
	while (temp->pre != 0 || temp->post != 0)
	{
		if (temp->pre > 0)
		{
			ra(ahead);
			temp->pre--;
		}
		else if (temp->pre < 0)
		{
			rra(ahead);
			temp->pre++;
		}
		if (temp->post > 0)
		{
			rb(bhead);
			temp->post--;
		}
		else if (temp->post < 0)
		{
			rrb(bhead);
			temp->post++;
		}
	}
}

void	simple_sort(t_nodule **ahead)
{
	int	temp;

	temp = find_largest(ahead);
	if ((*ahead)->value == temp)
		ra(ahead);
	else if ((*ahead)->next->value == temp)
		rra(ahead);
	if ((*ahead)->value > (*ahead)->next->value)
		sa(ahead);
}
