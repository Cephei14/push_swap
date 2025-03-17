/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-operations_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <rdhaibi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 23:10:05 by rdhaibi           #+#    #+#             */
/*   Updated: 2025/03/16 14:59:13 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}

void	assign_ranks(t_stack *a)
{
	t_stack	*p;
	t_stack	*q;
	int		rank;

	p = a;
	while (p)
	{
		rank = 0;
		q = a;
		while (q)
		{
			if (q->data < p->data)
				rank++;
			q = q->next;
		}
		p->rank = rank;
		p = p->next;
	}
}
