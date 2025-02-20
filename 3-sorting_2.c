/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-sorting_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <rdhaibi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:27:02 by rdhaibi           #+#    #+#             */
/*   Updated: 2025/02/20 17:33:38 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	int		min_value;
	t_stack	*temp;

	min_value = stack->data;
	temp = stack->next;
	while (temp)
	{
		if (temp->data < min_value)
			min_value = temp->data;
		temp = temp->next;
	}
	return (min_value);
}

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->data;
	second = (*a)->next->data;
	third = (*a)->next->next->data;
	if (!a || !(*a) || !(*a)->next)
		return ;
	if (!(*a)->next->next)
	{
		if ((*a)->data > (*a)->next->data)
			sa(*a);
		return ;
	}
	if (first < second && second < third)
		return ;
	if (first > second && second < third && first < third)
		sa(*a);
	else if (first < second && second > third && first < third)
	{
		sa(*a);
		ra(a);
	}
	else if (first > second && second > third)
	{
		sa(*a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort_small(t_stack **a, t_stack **b)
{
	int	size;
	int	min_pos;

	size = list_size(*a);
	while (size > 3)
	{
		min_pos = position_of(*a, find_min(*a));
		if (min_pos <= size / 2)
		{
			while (min_pos--)
				ra(a);
		}
		else
		{
			min_pos = size - min_pos;
			while (min_pos--)
				rra(a);
		}
		pb(a, b);
		size--;
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}

void	sort_100_numbers(t_stack **a, t_stack **b)
{
	int	total;
	int	chunk_size;
	int	current_chunk;
	int	pushed;
	int	max;
	int	pos;
	int	size;

	normalize_stack(*a);
	total = list_size(*a);
	chunk_size = total / 5;
	current_chunk = chunk_size;
	pushed = 0;
	while (*a)
	{
		if ((*a)->data < current_chunk)
		{
			pb(a, b);
			pushed++;
			if (*b && (*b)->data < (current_chunk - (chunk_size / 2)))
				rb(b);
		}
		else
			ra(a);
		if (pushed == current_chunk && current_chunk < total)
			current_chunk += chunk_size;
	}
	while (*b)
	{
		max = find_max(*b);
		pos = position_of(*b, max);
		size = list_size(*b);
		if (pos <= size / 2)
		{
			while ((*b)->data != max)
				rb(b);
		}
		else
		{
			while ((*b)->data != max)
				rrb(b);
		}
		pa(a, b);
	}
}
