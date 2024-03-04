/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:20:10 by seayeo            #+#    #+#             */
/*   Updated: 2024/03/04 17:03:41 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int			valid;
	t_nodule	*ahead;
	t_nodule	*bhead;

	valid = validity_checks(argc, argv);
	if (valid == 0)
		return (0);
	ahead = NULL;
	// last_node = NULL;
	bhead = NULL;
	// blast_node = NULL;
	init_stack(argc, argv, &ahead);
	print_stack(&ahead);
	print_stack(&bhead);
	//brain(ahead, bhead, argc);
	
	pb(&ahead, &bhead);
	ft_printf("\n");
	print_stack(&ahead);
	print_stack(&bhead);
	
	print_full(&bhead);
	pa(&bhead, &ahead);
	ft_printf("\n");
	print_stack(&ahead);
	print_stack(&bhead);
}

int	validity_checks(int argc, char *argv[])
{
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (0);
	else
		return (1);
}
