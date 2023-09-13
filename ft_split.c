/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:51:35 by seayeo            #+#    #+#             */
/*   Updated: 2023/09/13 15:51:36 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	int	ft_wordcount(char *s, char c)
{
	int	words;

	words = 0;
	while (*s)
	{
		if (*s != c)
		{
			words++;
			while (*s != c && *s != '\0')
				s++;
			if (*s != '\0')
				return (words);
		}
		s++;
	}
	return (words);
}

char **ft_split(char const *s, char c)
{
	int	words;
	char **ans;
	int	i;

	i = 0;
	if (!s || !c)
		return (NULL);
	words = ft_wordcount(s, c);
	ans = (char **)malloc(sizeof(char *) * (words + 1));
	if (ans == NULL)
		return (NULL);
	whil

}