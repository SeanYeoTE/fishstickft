/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:26:17 by seayeo            #+#    #+#             */
/*   Updated: 2024/03/20 17:13:57 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	brain(t_nodule **ahead, t_nodule **bhead, int argc)
{
	if (checkifsorted(ahead) == 0)
		return ;
	if (argc - 1 >= 5)
	{ 
		pb(ahead, bhead);
		pb(ahead, bhead);
	}
	while (getlength(ahead) > 3)
	{
		resetweights(ahead);
		setweight2(ahead, bhead);
		checkefficient(ahead);
		checkrr(ahead);
		executemission(ahead, bhead);
	}
	simple_sort(ahead);
	int	order = rotatetillbig(bhead);
	while (order--)
		rb(bhead);
	dumpback(bhead, ahead);
	

	order = rotatetillsmall(ahead);
	while (order--)
		ra(ahead);
}


/* apparently so we have a possibility of normal rotates on 1 side and reverse rotates on the other
so efficiency checker needs to determine individually if pre and post rotates are better positive/negative

then checkrr only fills in for double rotates if calculated pre and post rotates are same signed. */


void	checkefficient(t_nodule **ahead)
{
	int	stack_len;
	t_nodule	*temp;

	stack_len = getlength(ahead);
	temp = *ahead;
	stack_len = stack_len/2;
	while (temp)
	{
		if (temp->pre > stack_len)
			temp->pre = temp->pre - getlength(ahead);
		if (temp->post > stack_len)
			temp->post = temp->post - getlength(ahead);
		temp = temp->next;
	}
}

// exception case here not handled causing infinite loop
void	dumpback(t_nodule **entrance, t_nodule **exit)
{
	// print_stack(entrance, 'b');
	while (*entrance)
	{
		if (find_largest(exit) < (*entrance)->value)
			pa(entrance, exit);
		if (find_smallest(exit) > (*entrance)->value)
		{
			if ((*exit)->value ==  find_smallest(exit))
				pa(entrance, exit);
		}
		else if ((*exit)->value > (*entrance)->value)
		{
			if ((*exit)->prev == NULL)
			{
				if (get_last(*exit)->value < (*entrance)->value)
					pa(entrance, exit);
			}
			else
			{
				if ((*exit)->prev->value < (*entrance)->value)
					pa(entrance, exit);
			}
		}
		rra(exit);
	}
	
}

void	executemission(t_nodule **ahead, t_nodule **bhead)
{
	int	lowestmoves;
	t_nodule	*temp;
	t_nodule	*currentlowest;
	int	check;

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
	while (temp->doble != 0 || temp->pre != 0 || temp->post != 0)
	{
		if (temp->doble < 0)
		{
			rr(ahead, bhead);
			temp->doble++;
		}
		else if (temp->doble > 0)
		{
			rrr(ahead, bhead);
			temp->doble--;
		}
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
	t_nodule	*second;
	t_nodule	*third;

	while (checkifsorted(ahead))
	{
		second = (*ahead)->next;
		third = (*ahead)->next->next;
		if (second->value > third->value)
			ra(ahead);
		else if ((*ahead)->value > second->value && (*ahead)->value > third->value)
			ra(ahead);
		else if ((*ahead)->value > second->value)
			sa(ahead);
		else if ((*ahead)->value > third->value)
			ra(ahead);
		else if (third->value == find_smallest(ahead))
			rra(ahead);
	}
}
