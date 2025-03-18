/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-sort_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <rdhaibi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:25:42 by rdhaibi           #+#    #+#             */
/*   Updated: 2025/03/18 14:51:09 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunk_elements(t_stack **a, t_stack **b, int *bounds)
{
	int	j;
	int	rotations;

	j = 0;
	while (j < bounds[2] && *a)
	{
		rotations = 0;
		while (*a && ((*a)->rank < bounds[0] || (*a)->rank > bounds[1])
			&& rotations < list_len(*a))
		{
			ra(a);
			rotations++;
		}
		if (rotations == list_len(*a) || !*a)
			break ;
		pb(a, b);
		if ((*b)->rank > (bounds[0] + bounds[1]) / 2)
			rb(b);
		j++;
	}
}

void	chunk_sort(t_stack **a, t_stack **b, int chunk_size)
{
	int	params[2];
	int	bounds[4];
	int	i;
	int	pos;

	i = 0;
	init_chunk_params(a, chunk_size, params);
	while (i < params[1])
	{
		set_chunk_bounds(i, chunk_size, params[0], bounds);
		bounds[3] = params[1];
		push_chunk_elements(a, b, bounds);
		i++;
	}
	while (*b)
	{
		pos = find_max_pos(*b);
		rotate_to_max(b, pos, list_len(*b));
		pa(a, b);
	}
}

void	sort_medium(t_stack **a, t_stack **b)
{
	int	size;
	int	chunk_size;

	size = list_len(*a);
	chunk_size = 20;
	if (size > 100)
		chunk_size = 50;
	chunk_sort(a, b, chunk_size);
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
