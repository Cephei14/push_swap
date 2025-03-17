/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-general_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <rdhaibi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:38:37 by rdhaibi           #+#    #+#             */
/*   Updated: 2025/03/16 14:58:56 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack_ptr)
{
	int	tmp;

	if (stack_ptr == NULL || stack_ptr->next == NULL)
		return ;
	tmp = stack_ptr->data;
	stack_ptr->data = (stack_ptr->next)->data;
	(stack_ptr->next)->data = tmp;
}

void	rotate(t_stack **stack_ptr)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack_ptr == NULL || (*stack_ptr)->next == NULL)
		return ;
	first = *stack_ptr;
	*stack_ptr = first->next;
	(*stack_ptr)->previous = NULL;
	last = *stack_ptr;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->previous = last;
	first->next = NULL;
}

void	reverse_rotate(t_stack **stack_ptr)
{
	t_stack	*last;
	t_stack	*second_last;

	if (*stack_ptr == NULL || (*stack_ptr)->next == NULL)
		return ;
	last = *stack_ptr;
	while (last->next != NULL)
		last = last->next;
	second_last = last->previous;
	second_last->next = NULL;
	last->previous = NULL;
	last->next = *stack_ptr;
	(*stack_ptr)->previous = last;
	*stack_ptr = last;
}
