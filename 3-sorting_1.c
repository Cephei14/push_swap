/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-sorting_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <rdhaibi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:25:30 by rdhaibi           #+#    #+#             */
/*   Updated: 2025/02/20 17:21:04 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_size(t_stack *stack)
{
	int count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int	get_rank(t_stack *stack, int value)
{
	int	rank;

	rank = 0;
	while (stack)
	{
		if (stack->data < value)
			rank++;
		stack = stack->next;
	}
	return (rank);
}

void	normalize_stack(t_stack *stack)
{
	t_stack *tmp;
	int		orig;

	tmp = stack;
	while (tmp)
	{
		orig = tmp->data;
		tmp->data = get_rank(stack, orig);
		tmp = tmp->next;
	}
}

int	find_max(t_stack *stack)
{
	int	max;

	max = -1;
	while (stack)
	{
		if (stack->data > max)
			max = stack->data;
		stack = stack->next;
	}
	return (max);
}

int	position_of(t_stack *stack, int value)
{
	int pos;

	pos = 0;
	while (stack)
	{
		if (stack->data == value)
			return pos;
		pos++;
		stack = stack->next;
	}
	return (pos);
}
