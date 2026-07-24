/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalacar <amalacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:57:15 by amalacar          #+#    #+#             */
/*   Updated: 2026/07/24 15:31:08 by amalacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(t_stack *stack_a)
{
	int		size;
	t_node	*current;

	size = 0;
	if (!stack_a)
		return (0);
	current = stack_a->head;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

double	calculate_disorder(t_stack *stack_a)
{
	long	inversions;
	long	n;
	t_node	*curr_i;
	t_node	*curr_j;

	inversions = 0;
	n = get_stack_size(stack_a);
	if (n <= 1)
		return (0.0);
	curr_i = stack_a->head;
	while (curr_i)
	{
		curr_j = curr_i->next;
		while (curr_j)
		{
			if (curr_i->value > curr_j->value)
				inversions++;
			curr_j = curr_j->next;
		}
		curr_i = curr_i->next;
	}
	return ((double)inversions / ((n * (n - 1)) / 2));
}

void	run_adaptive_strategy(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	double disorder;

	disorder = calculate_disorder(*stack_a);
	if (disorder < 0.2)
	{
		bench->strategy_name = "Adaptive";
		bench->complexity = "O(n^2)";
		simple_sort(*stack_a, *stack_b, bench);
	}
	else if (disorder < 0.5)
	{
		bench->strategy_name = "Adaptive";
		bench->complexity = "O(n*sqrt(n))";
		medium_sort(*stack_a, *stack_b, bench);
	}
	else
	{
		bench->strategy_name = "Adaptive";
		bench->complexity = "O(n log n)";
		complex_sort(*stack_a, *stack_b);
	}
}
