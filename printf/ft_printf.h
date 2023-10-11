/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:16:31 by seayeo            #+#    #+#             */
/*   Updated: 2023/10/05 15:16:35 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

int	print_char(int c);
int	print_str(char *str);
int	print_digit(long n, int base);
int	print_hex(long n, int base, char c);
int	print_unsignedhex(unsigned long int n);
int	print_void(void *n);
int	print_unsigned(unsigned int n);
int	ft_printf(const char *str, ...);

#endif
