/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalacar <amalacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:57:15 by amalacar          #+#    #+#             */
/*   Updated: 2026/07/21 15:57:29 by amalacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> // malloc, free, exit
# include <unistd.h> // read, write
# include "libft.h" 
# include <limits.h> // INT_MAX, INT_MIN
# include <stdint.h> // int32_t

typedef struct s_node
{
	int				value;
	int				target_index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node			*head;
	int				size;
}	t_stack;

typedef struct s_bench
{
	int	active;
	char	*strategy_name;
	char	*complexity;
}	t_bench;

// push_swap
int	main(int argc, char **argv); // brauch ich das?

// Operations_one
void	swap(t_stack *stack, char c, int print);
void	ss(t_stack *stack_a, t_stack *stack_b, int print);
void	push(t_stack *dest, t_stack *src, char c, int print);

// Operations_two
void	rotate(t_stack *stack, char c, int print);
void	rr(t_stack *stack_a, t_stack *stack_b, int print);
void	reverse_rotate(t_stack *stack, char c, int print);
void	rrr(t_stack *stack_a, t_stack *stack_b, int print);

// utils
int		integer_sqrt_small(int number);
int		get_min_position(t_stack *stack);
int		get_max_index(t_stack *stack);
void	move_min_to_top(t_stack *stack, char c);
void	sort_array(int *arr, int size);

// helpers
int	is_number(char *str);
t_node	*create_node(int value);
void	assign_indices(t_stack *stack, int *arr);
void	index_stack(t_stack *stack);

// simple_sort
void	sort_three(t_stack *stack);
void	move_min_to_top(t_stack *stack, char c);
void	simple_sort(t_stack *stack_a, t_stack *stack_b, t_bench *bench);

// medium_sort
void	process_chunks(t_stack *stack_a, t_stack *stack_b, int chunk_size);
void	return_to_a(t_stack *stack_a, t_stack *stack_b);
void	medium_sort(t_stack *stack_a, t_stack *stack_b, t_bench *bench);

// complex_sort
void	complex_sort(t_stack *stack_a, t_stack *stack_b);

// strategies
int		get_stack_size(t_stack *stack_a);
double	calculate_disorder(t_stack *stack_a);
void	run_adaptive_strategy(t_stack **stack_a, t_stack **stack_b, t_bench *bench);

// benchmark
void	print_benchmark(t_stack *stack_a, t_bench *bench, int total_ops, int *op_counts);

// parsing
int		check_arguments(int argc, char **argv);
int		check_duplicates(int argc, char **argv);
int		is_int(char *str);
void	free_split(char **split);
int		count_split(char **split);

// stack
void	build_stack(int argc, t_stack *stack, char **argv);
void	add_back(t_stack *stack, t_node *new_node);

#endif