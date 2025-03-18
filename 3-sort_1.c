/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-sort_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <rdhaibi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:25:42 by rdhaibi           #+#    #+#             */
/*   Updated: 2025/03/18 14:48:46 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_len(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
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

int	find_min_pos(t_stack *stack, int *pos)
{
	int		min;
	int		i;
	int		min_pos;
	t_stack	*p;

	min = stack->data;
	i = 0;
	min_pos = 0;
	p = stack;
	while (p)
	{
		if (p->data < min)
		{
			min = p->data;
			min_pos = i;
		}
		p = p->next;
		i++;
	}
	*pos = min_pos;
	return (min);
}

void	push_to_b(t_stack **a, t_stack **b, int *n)
{
	int	pos;

	while (*n > 3)
	{
		find_min_pos(*a, &pos);
		rotate_to_min(a, pos, *n);
		pb(a, b);
		(*n)--;
	}
}
