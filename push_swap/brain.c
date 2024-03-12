/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:26:17 by seayeo            #+#    #+#             */
/*   Updated: 2024/03/12 16:42:49 by seayeo           ###   ########.fr       */
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
	while (checklength(ahead) > 3)
	{
		resetweights(ahead);
		setweight2(ahead, bhead);
		checkefficient(ahead);
		// print_full(ahead, 'a');
		executemission(ahead, bhead);
	}
	// print_stack(ahead, 'a');
	print_stack(bhead, 'b');
	simple_sort(ahead);
	dumpback(bhead, ahead);
	print_stack(ahead, 'a');
	int order = rotatetillsmall(ahead);
	while (order--)
		ra(ahead);
	print_stack(ahead, 'a');
}

void	dumpback(t_nodule **entrance, t_nodule **exit)
{
	t_nodule	*b;
	int			order;

	order = rotatetillbig(entrance);
	while (order--)
		rb(entrance);
	b = (*entrance);
	while (b)
	{
		if (find_largest(exit) < b->value)
			pa(entrance, exit);
		else
		{
			rotatebackpush(exit, b);
			pa(entrance, exit);
		}
		b = b->next;
	}
}

int	rotatebackpush(t_nodule **head, t_nodule *tempahead)
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
					break;
			}
			else
			{
				if (temp->prev->value < tempahead->value)
					break;
			}
		}
		ans++;
		temp = temp->next;
	}
	while (ans--)
			rra(head);
	return (ans);
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
		check = temp->pre + temp->post + temp->doble;
		if (check < lowestmoves)
		{
			lowestmoves = check;
			currentlowest = temp;
		}
		temp = temp->next;
	}
	while ((currentlowest->doble))
	{
		rr(ahead, bhead);
		currentlowest->doble--;
	}
	while ((currentlowest->pre))
	{
		ra(ahead);
		currentlowest->pre--;
	}		
	while ((currentlowest->post))
	{
		rb(bhead);
		currentlowest->post--;
	}
	pb(ahead, bhead);
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
// something like midpoint theorem, if past midpoint of stack, use reverse rotate instead of rotate

/* fk me i need to check both stacks for efficiency of rotates and compare if both stacks can use the
same double rotates. 
i think check for double rotates and calculate total
then check for reverse rotate efficiency */
void	checkefficient(t_nodule **ahead)
{
	// int	len;
	// int	rotatemoves;
	// int	rrmoves;
	t_nodule	*temp;

/* compare post and pre
whichever is more
then replace with doble =doublerotate post is single rotate */
	temp = (*ahead);
	while (temp)
	{
		if (temp->pre > temp->post)
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
		temp = temp->next;
	}
}

int	checklength(t_nodule **ahead)
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

void	simple_sort(t_nodule **ahead)
{
	t_nodule	*second;
	t_nodule	*third;

	while (checkifsorted(ahead))
	{
		second = (*ahead)->next;
		third = (*ahead)->next->next;
		if ((*ahead)->value > second->value && (*ahead)->value > third->value)
			ra(ahead);
		else if ((*ahead)->value > second->value)
			sa(ahead);
		else if ((*ahead)->value > third->value)
			ra(ahead);
	}
}
