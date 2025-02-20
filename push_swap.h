/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <rdhaibi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:03:41 by rdhaibi           #+#    #+#             */
/*   Updated: 2025/02/17 22:50:22 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct stack
{
	struct stack	*previous;
	int				data;
	struct stack	*next;
}	t_stack;
int		sign(const char *str, long int *i);
int		ft_strcmp(char *s1, char *s2);
int		lenn(const char *str, long int i);
int		assign(const char *str, long int i, long int l);
long	ft_atoi(const char *str);
char	*edges(char const *s, char c, int *i);
int		wordsnum(char const *s, char c);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
int		ft_isdigit(int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
t_stack	*create_node(int data);
t_stack	*add_node_top(t_stack *stack_ptr, int data);
t_stack	*add_node_bottom(t_stack *stack_ptr, int data);
t_stack	*remove_head(t_stack *stack_ptr);
t_stack	*remove_tail(t_stack *stack_ptr);
void	delete_node(t_stack *node);
void	free_stack(t_stack *stack);
void	free_args(char **args);
void	swap(t_stack *stack_ptr);
void	rotate(t_stack **stack_ptr);
void	reverse_rotate(t_stack **stack_ptr);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	push_swap(t_stack **a, t_stack **b);
int		list_size(t_stack *stack);
int		get_rank(t_stack *stack, int value);
void	normalize_stack(t_stack *stack);
int		find_max(t_stack *stack);
int		find_min(t_stack *stack);
void	sort_three(t_stack **a);
void	sort_small(t_stack **a, t_stack **b);
void	sort_100_numbers(t_stack **a, t_stack **b);
int		position_of(t_stack *stack, int value);
void	print_stack(t_stack *stack);
int		is_sorted(t_stack *stack);

#endif
