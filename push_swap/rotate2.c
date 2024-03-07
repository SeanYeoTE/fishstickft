/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:07:42 by seayeo            #+#    #+#             */
/*   Updated: 2024/03/07 16:12:23 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_nodule **ahead)
{
	rotate(ahead);
	ft_printf("ra\n");
	print_full(ahead);
}

void	rb(t_nodule **bhead)
{
	rotate(bhead);
	ft_printf("rb\n");
}

void	rra(t_nodule **ahead)
{
	reverse_rotate(ahead);
	ft_printf("rra\n");
}

void	rrb(t_nodule **bhead)
{
	reverse_rotate(bhead);
	ft_printf("rrb\n");
}
