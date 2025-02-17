/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <rdhaibi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:37:44 by rdhaibi           #+#    #+#             */
/*   Updated: 2025/02/13 17:44:07 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "0-push_swap.h"

char	*edges(char const *s, char c, int *i)
{
	int	l1;
	int	l2;

	while (s[*i] == c)
		(*i)++;
	l1 = *i;
	while (s[*i] != '\0' && s[*i] != c)
		(*i)++;
	l2 = *i;
	return (ft_substr(s, l1, l2 - l1));
}

int	wordsnum(char const *s, char c)
{
	int	n;

	n = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			n++;
			while (*s && *s != c)
				s++;
		}
	}
	return (n);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**str;

	if (!s)
		return (NULL);
	str = malloc ((sizeof(char *)) * (wordsnum(s, c) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (j < wordsnum(s, c))
	{
		str[j] = edges(s, c, &i);
		if (!str[j])
		{
			while (j--)
				free(str[j]);
			free(str);
			return (NULL);
		}
		j++;
	}
	str[j] = NULL;
	return (str);
}
