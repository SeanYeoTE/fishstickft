/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:20:10 by seayeo            #+#    #+#             */
/*   Updated: 2024/03/27 12:23:47 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int			valid;
	t_nodule	*ahead;
	t_nodule	*bhead;
	int			customs;
	
	customs = 0;
	valid = validity_checks(argc, argv);
	if (valid == 0)
		print_error(&ahead, argv, 0);
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