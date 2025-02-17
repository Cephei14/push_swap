/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-sorting_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <rdhaibi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:27:02 by rdhaibi           #+#    #+#             */
/*   Updated: 2025/02/14 16:22:30 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "0-push_swap.h"

int find_min(t_stack *stack)
{
    int min_value = stack->data;
    t_stack *temp = stack->next;

    while (temp)
    {
        if (temp->data < min_value)
            min_value = temp->data;
        temp = temp->next;
    }

    return min_value;
}

void sort_three(t_stack **a)
{
    if (!a || !(*a) || !(*a)->next)
        return;

    if (!(*a)->next->next) {
        // Only two elements in the stack
        if ((*a)->data > (*a)->next->data)
            sa(*a);  // Swap the first and second elements
        return;
    }

    int first = (*a)->data;
    int second = (*a)->next->data;
    int third = (*a)->next->next->data;

    if (first < second && second < third)
        return;
    if (first > second && second < third && first < third)
        sa(*a);  // Swap the first element
    else if (first < second && second > third && first < third)
    {
        sa(*a);  // Swap the first element
        ra(a);   // Rotate the stack
    }
    else if (first > second && second > third)
    {
        sa(*a);  // Swap the first element
        rra(a);  // Reverse rotate the stack
    }
    else if (first > second && second < third && first > third)
        ra(a);   // Rotate the stack
    else if (first < second && second > third && first > third)
        rra(a);  // Reverse rotate the stack
}

void sort_small(t_stack **a, t_stack **b)
{
    int size = list_size(*a);

    while (size > 3)
    {
        int min_pos = position_of(*a, find_min(*a));  // Find position of the smallest element

        if (min_pos <= size / 2)
        {
            while (min_pos--)
                ra(a);
        }
        else
        {
            min_pos = size - min_pos;
            while (min_pos--)
               rra(a);
        }
        pb(a, b);
        size--;
    }
    sort_three(a);
    while (*b)
        pa(a, b);
}
void sort_100_numbers(t_stack **a, t_stack **b)
{
    normalize_stack(*a);
    int total = list_size(*a);
    int chunk_size = total / 5; // For 100 numbers, chunk_size is 20.
    int current_chunk = chunk_size;
    int pushed = 0;
    
    while (*a)
    {
        if ((*a)->data < current_chunk)
        {
            pb(a, b);
            pushed++;
            if (*b && (*b)->data < (current_chunk - (chunk_size / 2)))
                rb(b);
        }
        else
            ra(a);
        if (pushed == current_chunk && current_chunk < total)
            current_chunk += chunk_size;
    }
    
    /* Push back from B to A in sorted order */
    while (*b)
    {
        int max = find_max(*b);
        int pos = position_of(*b, max);
        int size = list_size(*b);
        if (pos <= size / 2)
        {
            while ((*b)->data != max)
                rb(b);
        }
        else
        {
            while ((*b)->data != max)
                rrb(b);
        }
        pa(a, b);
    }
}