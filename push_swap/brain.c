/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:26:17 by seayeo            #+#    #+#             */
/*   Updated: 2024/03/11 19:17:10 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	brain(t_nodule **ahead, t_nodule **bhead, int argc)
{
/* 	while (checkifsorted(ahead) != 0 && checklength(ahead) != argc)
	{
		if (checklength(ahead) >= 5 && checklength(bhead) < 2)
		{
			pb(ahead, bhead);
			pb(ahead, bhead);
			print_stack(bhead, 'b');
		}
		setweight(ahead, bhead);
		executemission(ahead, bhead);
	} */
	// ft_printf("length of stack a: %d\n", argc);
	if (checkifsorted(ahead) == 0)
		return ;
	if (argc - 1 >= 5)
	{ 
		pb(ahead, bhead);
		pb(ahead, bhead);
		// print_stack(bhead, 'b');
		// ft_printf("\n");
	}
	
	// print_full(ahead, 'a');
	while (checklength(ahead) > 3)
	{
		resetweights(ahead);
		setweight(ahead, bhead);
		checkefficient(ahead);
		print_full(ahead, 'a');
		executemission(ahead, bhead);
	}
	// print_stack(ahead, 'a');
	// print_stack(bhead, 'b');
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
			ft_printf("lowestmoves %d\n", lowestmoves);
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

// setting weight does not account for when number is greater than all values in the stack
// it also does not account for numbers that have to be pushed in between 2 current values
// that are in the stack

void	setweight(t_nodule **ahead, t_nodule **bhead)
{
	t_nodule	*temp;
	t_nodule	*top;
	int	counterforb;
	int counterfora;

	temp = (*ahead);
	counterfora = 0;
	while (temp)
	{
		// counts the number of rotates required in stack b before number is ready to be pushed
		counterforb = 0;
		top = (*bhead);
		while (top)
		{
			// two conditions; if value is greater than all, push, if value is less than all, also push without rotating
			if (temp->value < top->value)
			{
				// ft_printf("counterforb %d\n", counterforb);
				counterforb++;
				top = top->next;
			}
			else if (temp->value > top->value)
			{
				// ft_printf("counterforb %d\n", counterforb);
				temp->post = counterforb;
				break ;
			}
		}
		temp->pre = counterfora;
		temp = temp->next;
		counterfora++;
		// count the number of rotates to get specific number to top of stack
	}
	//checkefficient(ahead);
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
