/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-linked_list_remove.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <rdhaibi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:56:17 by rdhaibi           #+#    #+#             */
/*   Updated: 2025/02/20 16:45:50 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*remove_head(t_stack *stack_ptr)
{
	t_stack	*p;

	if (stack_ptr == NULL || stack_ptr->next == NULL)
		return (NULL);
	p = stack_ptr;
	stack_ptr = stack_ptr->next;
	stack_ptr->previous = NULL;
	delete_node(p);
	return (stack_ptr);
}

t_stack	*remove_tail(t_stack *stack_ptr)
{
	t_stack	*p;

	if (stack_ptr == NULL)
		return (NULL);
	if (stack_ptr->next == NULL)
	{
		delete_node(stack_ptr);
		return (NULL);
	}
	p = stack_ptr;
	while (p->next != NULL)
		p = p->next;
	p->previous->next = NULL;
	delete_node(p);
	return (stack_ptr);
}

void	delete_node(t_stack *node)
{
	if (node == NULL)
		return ;
	free(node);
}

void	free_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*next;

	current = stack;
	while (current != NULL)
	{
		next = current->next;
		delete_node(current);
		current = next;
	}
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
