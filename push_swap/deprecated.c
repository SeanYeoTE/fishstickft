/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deprecated.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:03:28 by seayeo            #+#    #+#             */
/*   Updated: 2024/03/27 12:03:51 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* something like midpoint theorem, if past midpoint of stack, 
use reverse rotate instead of rotate

fk me i need to check both stacks for efficiency of rotates 
and compare if both stacks can use the
same double rotates. 
i think check for double rotates and calculate total
then check for reverse rotate efficiency */
void	checkrr(t_nodule **ahead)
{
	t_nodule	*temp;

	temp = *ahead;
	while (temp)
	{
		if (temp->pre > 0 && temp->post > 0)
		{
			if (temp->pre >= temp->post)
			{
				temp->doble = temp->post;
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
				temp->doble = temp->pre;
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