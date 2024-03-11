/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:01:14 by seayeo            #+#    #+#             */
/*   Updated: 2024/03/11 16:11:55 by seayeo           ###   ########.fr       */
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
	int					post;
	int					pre;
	int					doble;
	struct stack_node	*prev;
	struct stack_node	*next;
	struct stack_node	*current;
}	t_nodule;

// Data parsing
char	**ft_split(char const *str, char c);
int	ft_atoi(const char *str);

// Secondary functions
int	validity_checks(int argc, char *argv[]);
int	checkifsorted(t_nodule **ahead);
void	brain(t_nodule **ahead, t_nodule **bhead, int argc);
void	simple_sort(t_nodule **ahead);
void	setweight(t_nodule **ahead, t_nodule **bhead);
int	checklength(t_nodule **ahead);
void	checkefficient(t_nodule **ahead);
void	executemission(t_nodule **ahead, t_nodule **bhead);
void	resetweights(t_nodule **head);


// Stack initialisation
int	init_node(int value, t_nodule ** head);
int	init_stack(int argc, char *argv[], t_nodule ** head);

// getters
t_nodule	*get_last(t_nodule *last);
int	find_largest(t_nodule **head);

// Sorting functions
void	swap(t_nodule **head);
void	push(t_nodule **here, t_nodule **there);
void	rotate(t_nodule **stack);
void	reverse_rotate(t_nodule **stack);

void	sa(t_nodule **head);
void	sb(t_nodule **head);
void	ss(t_nodule **ahead, t_nodule **bhead);
void	pa(t_nodule **bhead, t_nodule **ahead);
void	pb(t_nodule **ahead, t_nodule **bhead);
void	ra(t_nodule **ahead);
void	rb(t_nodule **bhead);
void	rr(t_nodule **ahead, t_nodule **bhead);
void	rra(t_nodule **ahead);
void	rrb(t_nodule **bhead);
void	rrr(t_nodule **ahead, t_nodule **bhead);

int print_full(t_nodule **head, char c);
int print_stack(t_nodule **head, char c);

#endif