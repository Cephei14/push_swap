/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <rdhaibi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:24:44 by rdhaibi           #+#    #+#             */
/*   Updated: 2025/02/13 17:44:13 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "0-push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t		l;
	const char	*s2;

	l = ft_strlen(s1);
	s2 = malloc((sizeof(char) * l) + 1);
	if (s2 == NULL)
		return (NULL);
	ft_strlcpy((char *)s2, s1, l + 1);
	return ((char *)s2);
}

int	ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	else
		return (0);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n != 0)
	{
		while ((src[i] != '\0') && i < n - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	l;
	size_t	n;

	if (!s)
		return (NULL);
	n = ft_strlen(s);
	if (start >= n)
		return (ft_strdup(""));
	if (start + len > n)
		l = n - start;
	else
		l = len;
	str = malloc((sizeof(char) * l) + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(((char *)str), (s + start), l + 1);
	return (str);
}
