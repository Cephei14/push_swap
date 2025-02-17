/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-sorting_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <rdhaibi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:25:30 by rdhaibi           #+#    #+#             */
/*   Updated: 2025/02/14 16:14:03 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "0-push_swap.h"

/* Returns the number of nodes in a stack */
int list_size(t_stack *stack)
{
    int count = 0;
    while (stack)
    {
        count++;
        stack = stack->next;
    }
    return count;
}

/* Returns the number of nodes with data less than 'value' */
int get_rank(t_stack *stack, int value)
{
    int rank = 0;
    while (stack)
    {
        if (stack->data < value)
            rank++;
        stack = stack->next;
    }
    return rank;
}

/* Normalize the stack so each value is replaced by its rank (0 .. n-1) */
void normalize_stack(t_stack *stack)
{
    t_stack *tmp = stack;
    int orig;
    while (tmp)
    {
        orig = tmp->data;
        tmp->data = get_rank(stack, orig);
        tmp = tmp->next;
    }
}

/* Returns the maximum value in the stack */
int find_max(t_stack *stack)
{
    int max = -1;
    while (stack)
    {
        if (stack->data > max)
            max = stack->data;
        stack = stack->next;
    }
    return max;
}

/* Returns the 0-indexed position of 'value' in the stack */
int position_of(t_stack *stack, int value)
{
    int pos = 0;
    while (stack)
    {
        if (stack->data == value)
            return pos;
        pos++;
        stack = stack->next;
    }
    return pos;
}
