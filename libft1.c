/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <rdhaibi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:03:51 by rdhaibi           #+#    #+#             */
/*   Updated: 2025/02/26 17:14:46 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sign(const char *str, long int *i)
{
	if (str[*i] == '+' || str[*i] == '-')
	{
		(*i)++;
		if (!ft_isdigit((char)str[*i]))
			return (0);
		if (str[*i - 1] == '-')
			return (-1);
	}
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s1[i] == '+')
		i++;
	if (s2[j] == '+')
		j++;
	if (s1[i] == '-' && s2[j] == '-')
	{
		i++;
		j++;
	}
	while (s1[i] == '0')
		i++;
	while (s2[j] == '0')
		j++;
	while ((s1[i] == s2[j]) && s1[i] && s2[j])
	{
		i++;
		j++;
	}
	return (s1[i] - s2[j]);
}

int	lenn(const char *str, long int i)
{
	long int	l;

	l = 1;
	while (ft_isdigit(str[i]))
	{
		l = l * 10;
		i++;
	}
	return (l / 10);
}

int	assign(const char *str, long int i, long int l)
{
	long int	n;

	n = 0;
	while (l)
	{
		n = n + (str[i] - '0') * l;
		i++;
		l /= 10;
	}
	return (n);
}

long	ft_atoi(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > (LONG_MAX - (str[i] - '0')) / 10)
			return (sign == 1 ? LONG_MAX : LONG_MIN);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
