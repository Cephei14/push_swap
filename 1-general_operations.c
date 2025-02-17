/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-general_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <rdhaibi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:38:37 by rdhaibi           #+#    #+#             */
/*   Updated: 2025/02/17 19:15:28 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(t_stack *stack_ptr)
{
    int tmp;

    if (stack_ptr == NULL || stack_ptr->next == NULL)
        return;
    tmp = stack_ptr->data;
    stack_ptr->data = (stack_ptr->next)->data;
    (stack_ptr->next)->data = tmp;
}

void    rotate(t_stack **stack_ptr)
{
    t_stack *p;
    int tmp;

    if (*stack_ptr == NULL || (*stack_ptr)->next == NULL)
        return;
    tmp = (*stack_ptr)->data;
    p = *stack_ptr;
    *stack_ptr = (*stack_ptr)->next;
    (*stack_ptr)->previous = NULL;
    add_node_bottom(*stack_ptr, tmp);
    delete_node(p);
}

void    reverse_rotate(t_stack **stack_ptr)
{
    t_stack *p;
    int tmp;

    if (*stack_ptr == NULL || (*stack_ptr)->next == NULL)
        return;
    p = *stack_ptr;
    while (p->next != NULL)
        p = p->next;
    tmp = p->data;
    p->previous->next=NULL;
    *stack_ptr = add_node_top(*stack_ptr, tmp);
    delete_node(p);
}
