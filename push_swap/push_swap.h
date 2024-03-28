/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:01:14 by seayeo            #+#    #+#             */
/*   Updated: 2024/03/28 14:51:26 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>


# include "printf/ft_printf.h"

typedef struct s_stack_node
{
	int					value;
	int					post;
	int					pre;
	int					doble;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
	struct s_stack_node	*current;
}	t_nodule;

// Data parsing
char	**ft_split(char const *str, char c);
long	ft_atol(const char *str);


void print_error(t_nodule **a, char *argv[], int num);
int check_duplicate(t_nodule **head);
int	check_symbols(char *argv);

void	free_matrix(char **argv);
void	free_stack(t_nodule **stack);

// Secondary functions
int	checkifsorted(t_nodule **ahead);
int	getlength(t_nodule **ahead);
void	resetweights(t_nodule **head);


void	brain(t_nodule **ahead, t_nodule **bhead);
void	checkefficient(t_nodule **ahead, t_nodule **bhead);
void	executemission(t_nodule **ahead, t_nodule **bhead);
void	trigger(t_nodule **ahead, t_nodule **bhead, t_nodule *temp);

void	simple_sort(t_nodule **ahead);


// void	checkrr(t_nodule **ahead);



void	setweight2(t_nodule **ahead, t_nodule **bhead);
int	rotateforbetween(t_nodule **head, t_nodule *tempahead);
int	rotatetillbig(t_nodule **head);
int	rotatetillsmall(t_nodule **head);


// void	rotatebackpush(t_nodule **head, t_nodule *tempahead);

void	bigger_stack(t_nodule **ahead, t_nodule **bhead);
void	setweight3(t_nodule **src, t_nodule **dest);
int	rotateforbetween2(t_nodule **head, t_nodule *tempahead);
void	executemission2(t_nodule **ahead, t_nodule **bhead);
void	checkefficient2(t_nodule **bhead, t_nodule **ahead);

// Stack initialisation
int	init_node(int value, t_nodule ** head);
void	init_stack(int argc, char *argv[], t_nodule **head, int customs);

// getters
t_nodule	*get_last(t_nodule *last);
int	find_largest(t_nodule **head);
int	find_smallest(t_nodule **head);

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

// int print_full(t_nodule **head, char c);
// int print_stack(t_nodule **head, char c);
// int print_short(t_nodule **head);

#endif