/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <rdhaibi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:03:41 by rdhaibi           #+#    #+#             */
/*   Updated: 2025/03/17 12:48:15 by rdhaibi          ###   ########.fr       */
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
	int				rank;
	struct stack	*next;
}	t_stack;

//libft functions
int		sign(const char *str, long int *i);
int		ft_strcmp(char *s1, char *s2);
int		lenn(const char *str, long int i);
int		assign(const char *str, long int i, long int l);
long	ft_atoi(const char *str, int i, long result);
char	*edges(char const *s, char c, int *i);
int		wordsnum(char const *s, char c);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
int		ft_isdigit(int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
//linked list things
char	*ft_substr(char const *s, unsigned int start, size_t len);
t_stack	*create_node(int data);
t_stack	*add_node_top(t_stack *stack_ptr, int data);
t_stack	*add_node_bottom(t_stack *stack_ptr, int data);
t_stack	*remove_head(t_stack *stack_ptr);
t_stack	*remove_tail(t_stack *stack_ptr);
void	delete_node(t_stack *node);
void	free_stack(t_stack *stack);
void	free_args(char **args);
//general operations
void	assign_ranks(t_stack *a);
void	swap(t_stack *stack_ptr);
void	rotate(t_stack **stack_ptr);
void	reverse_rotate(t_stack **stack_ptr);
//stack operations
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
//sorting
void	push_swap(char **av, int i, int count, int size);
void	sort_three(t_stack **a);
void	sort_two(t_stack **a);
void	rotate_to_min(t_stack **a, int pos, int n);
void	push_to_b(t_stack **a, t_stack **b, int *n);
void	sort_small(t_stack **a, t_stack **b);
int		list_len(t_stack *stack);
int		is_sorted(t_stack *stack);
int		get_max_bits(int num);
void	radix_sort(t_stack **a, t_stack **b, int size);
int		find_max_pos(t_stack *stack);
void	init_chunk_params(t_stack **a, int chunk_size, int *params);
void	set_chunk_bounds(int i, int chunk_size, int size, int *bounds);
void	push_chunk_elements(t_stack **a, t_stack **b, int *bounds);
void	rotate_to_max(t_stack **b, int pos, int b_size);
void	chunk_sort(t_stack **a, t_stack **b, int chunk_size);
void	sort_medium(t_stack **a, t_stack **b);
int		find_min_pos(t_stack *stack, int *pos);

#endif
