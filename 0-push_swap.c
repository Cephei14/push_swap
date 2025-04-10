/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <rdhaibi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:17:57 by rdhaibi           #+#    #+#             */
/*   Updated: 2025/03/27 14:22:17 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arg_check(int count, char **av, int i)
{
	int		j;
	long	num;

	while (i < count)
	{
		j = 0;
		if (av[i][j] == '+' || av[i][j] == '-')
		{
			j++;
			if (av[i][j] == '\0')
				return (1);
		}
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
			j++;
		}
		num = ft_atoi(av[i], 0, 0);
		if (num == LONG_MAX || num == LONG_MIN
			|| num > INT_MAX || num < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	dupl_check(int count, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (ft_atoi(av[i], 0, 0) == ft_atoi(av[j], 0, 0))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ac_check(int ac, char ***av, int *count)
{
	if (ac == 2)
	{
		*av = ft_split((*av)[1], ' ');
		if (!*av)
			return (0);
		*count = 0;
		while ((*av)[*count])
			(*count)++;
		return (1);
	}
	else
	{
		*av = &(*av)[1];
		*count = ac - 1;
		return (0);
	}
}

void	push_swap(char **av, int i, int count, int size)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	while (i < count)
	{
		a = add_node_top(a, ft_atoi(av[i], 0, 0));
		i++;
	}
	size = list_len(a);
	if (is_sorted(a))
	{
		free_stack(a);
		return ;
	}
	assign_ranks(a);
	if (size <= 5)
		sort_small(&a, &b);
	else
		sort_big(&a, &b);
	free_stack(a);
	free_stack(b);
}

int	main(int ac, char **av)
{
	int	count;
	int	modified_av;

	if (ac == 1)
		return (0);
	modified_av = ac_check(ac, &av, &count);
	if (ac == 2 && count == 0)
	{
		if (modified_av)
			free_args(av);
		return (0);
	}
	if (count == 0 || (!modified_av && ac == 2)
		|| arg_check(count, av, 0) || dupl_check(count, av))
	{
		if (modified_av)
			free_args(av);
		write(2, "Error\n", 6);
		return (-1);
	}
	push_swap(av, 0, count, 0);
	if (modified_av)
		free_args(av);
	return (0);
}
