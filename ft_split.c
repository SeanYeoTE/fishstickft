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

static void	ft_free(char *i)
{
	while (*i)
	{
		free(i);
		i++;
	}
	free (i);
}

static	int	ft_wordcount(const char *s, char c)
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

static char	*allocatestr(char *str, char c, int *k)
{
	char	*word;
	int		i;

	i = *k;
	word = NULL;
	while (str[*k] != '\0')
	{
		if (str[*k] != c)
		{
			while (str[*k] != '\0' && str[*k] != c)
				*k += 1;
			word = (char *)malloc(sizeof(char) *(*k + 1));
			if (word == NULL)
				return (NULL);
			break ;
		}
		*k += 1;
	}
	ft_strcpy(word, str, c, i);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**ans;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s || !c)
		return (NULL);
	words = ft_wordcount(s, c);
	ans = (char **)malloc(sizeof(char *) * (words + 1));
	if (ans == NULL)
		return (NULL);
	while (i < words)
	{
		ans[i] = allocatestr(((char *)s), c, &j);
		if (ans[i] == NULL)
			ft_free(ans[i]);
		i++;
	}
	return (ans);
}
