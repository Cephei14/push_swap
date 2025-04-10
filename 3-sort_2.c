/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-sort_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <rdhaibi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:25:42 by rdhaibi           #+#    #+#             */
/*   Updated: 2025/03/27 14:41:59 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_small(t_stack **a, t_stack **b)
{
	int	n;

	n = list_len(*a);
	if (n == 1)
		return ;
	if (n == 2)
		sa(*a);
	else if (n == 3)
		sort_three(a);
	else if (n == 4 || n == 5)
	{
		push_to_b(a, b, &n);
		sort_three(a);
		while (*b)
			pa(a, b);
	}
}
