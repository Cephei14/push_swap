/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <rdhaibi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:17:57 by rdhaibi           #+#    #+#             */
/*   Updated: 2025/02/17 19:15:28 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int arg_check(int count, char **av)
{
    int i;
    int j;

    i = 0;
    while (i < count)
    {
        j = 0;
        if (av[i][j] == '+' || av[i][j] == '-')
        {
            j++;
            if (av[i][j] == '\0')
                return (0);
        }
        while (av[i][j])
        {
            if (av[i][j] < '0' || av[i][j] > '9')
                return (0);   
            j++;
        }
        long num = ft_atoi(av[i]);
        if (num == LONG_MAX || num == LONG_MIN || num > INT_MAX || num < INT_MIN)
            return (0);
        i++;
    }
    return (1);
}

int dupl_check(int count, char **av)
{
    int i;
    int j;
    
    i = 0;
    while (i < count)
    {
        j = i + 1;
        while (j < count)
        {
            if (ft_atoi(av[i]) ==ft_atoi(av[j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

void print_stack(t_stack *stack)
{
    while (stack)
    {
        printf("%d ", stack->data);
        stack = stack->next;
    }
    printf("\n");
}

// Function to check if the stack is already sorted
int is_sorted(t_stack *stack)
{
    while (stack && stack->next)
    {
        if (stack->data > stack->next->data)
            return 0;
        stack = stack->next;
    }
    return 1;
}

void push_swap(t_stack **a, t_stack **b)
{
    if (is_sorted(*a))
        return;

    int size = list_size(*a);

    if (size <= 10)
    {
        sort_small(a, b);
    }
    else
    {
        sort_100_numbers(a, b);
    }
}

int main(int ac, char **av)
{
    t_stack *a = NULL;
    t_stack *b = NULL;
    char **args = NULL;
    int count;
    int i;

    if (ac == 1)
        return (0); // No output for no arguments
    if (ac == 2 && av[1][0] == '\0')
        return (0); // No output for empty string argument
    if (ac == 2)
    {
        args = ft_split(av[1], ' ');
        if (!args)
        {
            write(2, "Error\n", 6);
            return (-1);
        }
        count = 0;
        while (args[count])
            count++;
    }
    else
    {
        args = &av[1];
        count = ac - 1;
    }
    if (!arg_check(count, args) || dupl_check(count, args))
    {
        write(2, "Error\n", 6);
        if (ac == 2)
            free_args(args);
        return (-1);
    }
    i = 0;
    while (i < count)
    {
        a = add_node_bottom(a, ft_atoi(args[i]));
        i++;
    }
    if (ac == 2)
        free_args(args);
    push_swap(&a, &b);
    // print_stack(a);
    free_stack(a);
    free_stack(b);
    return (0);
}