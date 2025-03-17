/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-sort_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <rdhaibi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:25:42 by rdhaibi           #+#    #+#             */
/*   Updated: 2025/03/17 16:28:31 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->data;
	second = (*a)->next->data;
	third = (*a)->next->next->data;
	if (first > second && second < third && first < third)
		sa(*a);
	else if (first > second && second > third)
	{
		sa(*a);
		rra(a);
	}
	else if (first > second && second < third)
		ra(a);
	else if (first < second && second > third && first > third)
		rra(a);
	else if (first < second && second > third && first < third)
	{
		sa(*a);
		ra(a);
	}
}

void	sort_two(t_stack **a)
{
	if ((*a)->data > (*a)->next->data)
		sa(*a);
}

void	rotate_to_min(t_stack **a, int pos, int n)
{
	if (pos < n - pos)
	{
		while (pos--)
			ra(a);
	}
	else
	{
		while (n - pos++)
			rra(a);
	}
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
