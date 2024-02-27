/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:01:14 by seayeo            #+#    #+#             */
/*   Updated: 2024/02/26 18:20:19 by seayeo           ###   ########.fr       */
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

char	**ft_split(char const *str, char c);
int	ft_atoi(const char *str);

#endif