/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:19:43 by seayeo            #+#    #+#             */
/*   Updated: 2024/03/02 23:56:33 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int print_stack(t_nodule **head)
{
    t_nodule    *start;
    int         count;

    count = 1;
    start = *head;
    while (start)
    {
        ft_printf("Node Counter: %d\n", count);
        ft_printf("Node Next: %s\n", start);
        ft_printf("Node Value: %d\n", start->value);
        ft_printf("Node Next: %s\n", start->next);
        ft_printf("Node Prev: %s\n", start->prev);
        ft_printf("***************\n\n");
        start = start->next;
        count++;
    }
    return (0);
}