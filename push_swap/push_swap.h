/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:01:14 by seayeo            #+#    #+#             */
/*   Updated: 2024/02/27 17:32:14 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

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
t_nodule	**sorter(t_nodule **head, t_nodule **bhead);

// Stack initialisation
t_nodule	**init_node(int value, t_nodule ** head);
t_nodule	**init_stack(int argc, char *argv[], t_nodule ** head);

// Sorting functions
t_nodule    **swap(t_nodule **head);
t_nodule	**push(t_nodule **head, t_nodule **bhead);

#endif