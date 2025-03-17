/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-sort_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <rdhaibi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:25:42 by rdhaibi           #+#    #+#             */
/*   Updated: 2025/03/17 16:29:54 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(int max_num)
{
	int	bits;

	bits = 0;
	while (max_num)
	{
		bits++;
		max_num >>= 1;
	}
	return (bits);
}

void	radix_sort(t_stack **a, t_stack **b, int size)
{
	int	max_num;
	int	max_bits;
	int	i;
	int	j;
	int	num;

	i = 0;
	max_num = size - 1;
	max_bits = get_max_bits(max_num);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			num = (*a)->rank;
			if ((num >> i) & 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}

int	find_max_pos(t_stack *stack)
{
	int		max;
	int		pos;
	int		i;
	t_stack	*p;

	max = stack->rank;
	pos = 0;
	i = 0;
	p = stack;
	while (p)
	{
		if (p->rank > max)
		{
			max = p->rank;
			pos = i;
		}
		p = p->next;
		i++;
	}
	return (pos);
}

void	init_chunk_params(t_stack **a, int chunk_size, int *params)
{
	params[0] = list_len(*a);
	params[1] = (params[0] + chunk_size - 1) / chunk_size;
}

void	set_chunk_bounds(int i, int chunk_size, int size, int *bounds)
{
	bounds[0] = i * chunk_size;
	bounds[1] = (i + 1) * chunk_size - 1;
	if (bounds[1] >= size)
		bounds[1] = size - 1;
	bounds[2] = chunk_size;
	if (i == bounds[3] - 1)
		bounds[2] = size - i * chunk_size;
}
