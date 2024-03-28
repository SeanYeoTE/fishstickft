/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:20:10 by seayeo            #+#    #+#             */
/*   Updated: 2024/03/28 14:36:57 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_nodule	*ahead;
	t_nodule	*bhead;
	int			customs;
	
	customs = 0;
	ahead = NULL;
	bhead = NULL;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		customs = 1;
	}
	init_stack(argc, argv, &ahead, customs);
	brain(&ahead, &bhead);
	free_stack(&ahead);
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