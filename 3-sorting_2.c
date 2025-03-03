/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-sorting_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <rdhaibi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:27:02 by rdhaibi           #+#    #+#             */
/*   Updated: 2025/02/20 18:05:40 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Helper function: Returns 1 if there's an element in stack a with data ≤ bound.
static int exists_in_a(t_stack *a, int bound)
{
    while (a)
    {
        if (a->data <= bound)
            return (1);
        a = a->next;
    }
    return (0);
}

int	find_min(t_stack *stack)
{
    int		min_value;
    t_stack	*temp;

    min_value = stack->data;
    temp = stack->next;
    while (temp)
    {
        if (temp->data < min_value)
            min_value = temp->data;
        temp = temp->next;
    }
    return (min_value);
}

void	sort_three(t_stack **a)
{
    int	first;
    int	second;
    int	third;

    first = (*a)->data;
    second = (*a)->next->data;
    third = (*a)->next->next->data;
    if (!a || !(*a) || !(*a)->next)
        return ;
    if (!(*a)->next->next)
    {
        if ((*a)->data > (*a)->next->data)
            sa(*a);
        return ;
    }
    if (first < second && second < third)
        return ;
    if (first > second && second < third && first < third)
        sa(*a);
    else if (first < second && second > third && first < third)
    {
        sa(*a);
        ra(a);
    }
    else if (first > second && second > third)
    {
        sa(*a);
        rra(a);
    }
    else if (first > second && second < third && first > third)
        ra(a);
    else if (first < second && second > third && first > third)
        rra(a);
}

void	sort_small(t_stack **a, t_stack **b)
{
    int	size;
    int	min_pos;

    size = list_size(*a);
    while (size > 3)
    {
        min_pos = position_of(*a, find_min(*a));
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

void sort_large_numbers(t_stack **a, t_stack **b)
{
    int total = list_size(*a);
    int chunks = (total <= 100 ? 5 : 11);
    int chunkSize = total / chunks + 1;
    int pushed_count = 0;
    int current_bound = chunkSize;

    // Normalize so values range from 0 to total - 1.
    normalize_stack(*a);

    while (pushed_count < total)
    {
        // If no element qualifies in the current chunk, broaden the range.
        if (!exists_in_a(*a, current_bound))
        {
            current_bound += chunkSize;
            continue;
        }
        if ((*a)->data <= current_bound)
        {
            pb(a, b);
            pushed_count++;
            if (*b && (*b)->data < current_bound - (chunkSize / 2))
                rb(b);
        }
        else
        {
            ra(a);
        }
    }

    // Push back from B to A in sorted order.
    while (*b)
    {
        int max_val = find_max(*b);
        int pos = position_of(*b, max_val);
        if (pos <= list_size(*b) / 2)
        {
            while ((*b)->data != max_val)
                rb(b);
        }
        else
        {
            while ((*b)->data != max_val)
                rrb(b);
        }
        pa(a, b);
    }
}