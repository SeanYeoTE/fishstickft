/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:20:10 by seayeo            #+#    #+#             */
/*   Updated: 2024/03/11 13:19:20 by seayeo           ###   ########.fr       */
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
	bhead = NULL;
	init_stack(argc, argv, &ahead);
	print_stack(&ahead, 'a');
	
	ft_printf("\n");
	ft_printf("is this sorted?? 0 for Yes, -1 for No.\n %d\n", checkifsorted(&ahead));
	brain(&ahead, &bhead, argc);
	ft_printf("\n");
	// print_stack(&ahead, 'a');
	// print_stack(&bhead, 'b');
}

int	validity_checks(int argc, char *argv[])
{
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (0);
	else
		return (1);
}

// testing for pushing
/* 	pb(&ahead, &bhead);
	ft_printf("\n");
	print_stack(&ahead);
	print_stack(&bhead);
	
	print_full(&bhead);
	pa(&bhead, &ahead);
	ft_printf("\n");
	print_stack(&ahead);
	print_stack(&bhead); */