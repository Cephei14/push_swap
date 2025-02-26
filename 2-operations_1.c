/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-operations_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <rdhaibi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 22:58:06 by rdhaibi           #+#    #+#             */
/*   Updated: 2025/02/20 21:50:32 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (stack_b == NULL || *stack_b == NULL)
		return ;
	temp = *stack_b;
	*stack_b = temp->next;
	if (*stack_b)
		(*stack_b)->previous = NULL;
	temp->next = *stack_a;
	if (*stack_a)
		(*stack_a)->previous = temp;
	*stack_a = temp;
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (stack_a == NULL || *stack_a == NULL)
		return ;
	temp = *stack_a;
	*stack_a = temp->next;
	if (*stack_a)
		(*stack_a)->previous = NULL;
	temp->next = *stack_b;
	if (*stack_b)
		(*stack_b)->previous = temp;
	*stack_b = temp;
	write(1, "pb\n", 3);
}

void	sa(t_stack *stack_a)
{
	if (stack_a->next == NULL)
		return ;
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack_b)
{
	if (stack_b->next == NULL)
		return ;
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
