/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:20:10 by seayeo            #+#    #+#             */
/*   Updated: 2024/02/27 16:59:17 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int			valid;
	t_nodule	**head;
	//t_nodule	**last_node;
	t_nodule	**bhead;
	// t_nodule	**blast_node;

	valid = validity_checks(argc, argv);
	if (valid == 0)
		return (0);
	head = NULL;
	// last_node = NULL;
	bhead = NULL;
	// blast_node = NULL;
	head = init_stack(argc, argv, head);
	head = sorter(head, bhead);
}

int	validity_checks(int argc, char *argv[])
{
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (0);
	else
		return (1);
}

// t_nodule	**sorter(t_nodule **head, t_nodule **bhead)
// {
	
// }
