/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:01:14 by seayeo            #+#    #+#             */
/*   Updated: 2024/03/02 23:36:02 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include "printf/ft_printf.h"

typedef struct stack_node
{
	int					value;
	struct stack_node	*prev;
	struct stack_node	*next;
	struct stack_node	*current;
}	t_nodule;

// Data parsing
char	**ft_split(char const *str, char c);
int	ft_atoi(const char *str);

// Secondary functions
int	validity_checks(int argc, char *argv[]);
t_nodule    **brain(t_nodule **head, t_nodule **bhead, int total);

// Stack initialisation
int	init_node(int value, t_nodule ** head);
int	init_stack(int argc, char *argv[], t_nodule ** head);

// getters
t_nodule	*get_last(t_nodule *last);
int	find_largest(t_nodule **head);

// Sorting functions
t_nodule    **swap(t_nodule **head);
int	push(t_nodule **here, t_nodule **there);
t_nodule	**rotate(t_nodule **stack);
t_nodule	**reverse_rotate(t_nodule **stack);

int print_stack(t_nodule **head);

#endif