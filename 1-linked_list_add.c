/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-linked_list_add.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <rdhaibi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:57:31 by rdhaibi           #+#    #+#             */
/*   Updated: 2025/03/27 14:40:38 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int data)
{
	t_stack	*p;

	p = malloc(sizeof(t_stack));
	if (p == NULL)
		return (NULL);
	p->previous = NULL;
	p->data = data;
	p->next = NULL;
	return (p);
}

t_stack	*add_node_bottom(t_stack *stack_ptr, int data)
{
	t_stack	*new_node;

	new_node = create_node(data);
	if (new_node == NULL)
		return (NULL);
	if (stack_ptr == NULL)
		return (new_node);
	new_node->next = stack_ptr;
	stack_ptr->previous = new_node;
	return (new_node);
}

t_stack	*add_node_top(t_stack *stack_ptr, int data)
{
	t_stack	*new_node;
	t_stack	*ptr;

	new_node = create_node(data);
	if (new_node == NULL)
		return (NULL);
	if (stack_ptr == NULL)
		return (new_node);
	ptr = stack_ptr;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new_node;
	new_node->previous = ptr;
	return (stack_ptr);
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
