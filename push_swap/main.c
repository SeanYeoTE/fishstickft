/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:20:10 by seayeo            #+#    #+#             */
/*   Updated: 2024/03/03 00:00:26 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int			valid;
	t_nodule	*ahead;
	// t_nodule	**bhead;

	valid = validity_checks(argc, argv);
	if (valid == 0)
		return (0);
	ahead = NULL;
	// last_node = NULL;
	// bhead = NULL;
	// blast_node = NULL;
	init_stack(argc, argv, &ahead);
	print_stack(&ahead);
	//brain(ahead, bhead, argc);
}

int	validity_checks(int argc, char *argv[])
{
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (0);
	else
		return (1);
}
